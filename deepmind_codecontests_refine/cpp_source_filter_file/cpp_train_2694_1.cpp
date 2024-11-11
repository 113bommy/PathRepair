#include <stdio.h>
#include <algorithm>
using namespace std;
int n, ret;
int main() {
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;
        ret = 999999999;
        for(int a = 0; a <= 13; a++) {
            for(int b = 0; b <= 9; b++) {
                for(int c = 0; c <= 5; c++) {
                    int value = a * 200 + b * 300 + c * 500;
                    if(n == value) {
                        ret = min(ret, (a / 5) * 1520 + (a % 5) * 380 + (b / 4) * 1870 * (b % 4) * 550 + (c / 3) * 2244 + (c % 3) * 850;
                    }
                }
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}