#include <stdio.h>
#include <math.h>
#include <limits.h>

double from_str_to_double1(const char s[125]) {
    if (s[0] == '-') {
        printf("%s", " Should be positive! EVERETHING\n");
        return -1;
    }
    int i = 0, flagdot = 0;
    double sum = 0, d = 1;
    while (s[i] != '\0') {
        if (s[i] != '.') {
            if (s[i] <= '9' && s[i] >= '0' && sum < INT_MAX / 100) {
                if (flagdot) { d *= 10; }
                sum = sum * 10 + (s[i] - '0');
                i++;
            } else {
                printf("%s", "Should be NUMBER!\n");
                return -1;
            }
        } else {
            if (flagdot == 1) {
                return -1;
            }
            flagdot = 1;
            i++;
        }
    }
    if (flagdot) {
        return sum / d;
    }
    return sum;
}


int task1() {
    double x, part, sum = 0, eps, diff;
    int n = 0, i = 1;
    char s_x[125], s_eps[125];
    printf("Enter argument and infelicity\n");
    scanf("%s %s", s_x, s_eps);
    x = from_str_to_double1(s_x);
    eps = from_str_to_double1(s_eps);

    while (x>=M_PI){
        x = x-2*M_PI;
    }
    while (x<=-M_PI){
        x = x+2*M_PI;
    }

    if (eps > 0 && eps < 1 && x != -1) {
        diff = 1 + eps;
        part = x;

        for (i = 1; diff > eps; i++) {

            sum += part;
            part *= (-1) * x * x / (2. * i) / (2. * i + 1.);
            diff = fabs(sin(x) - sum);
            n++;
        }
        printf("%s  %lf\n", "The built-in sin: ", sin(x));
        printf("%s %lf %s %lf %s %d", "x = ", x, " sum = ", sum, " n = ", n);




//    0		0.001	0
//    3.14		0.0001	0.00161324
//    1.57		0.00001	1
//    1.05		0.0001	0.86602
//    2.06		0.0001	0.869296   // mine is  0.882776



    } else { printf("%s", "Invalid data"); }
    return 0;
}