#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  int f1 = 0, f2 = 0, f3 = 0, dif = 0;
  scanf("%d %d %d", &a, &b, &c);
  if (a + b > c) {
    f1 = 1;
  }
  if (b + c > a) {
    f2 = 1;
  }
  if (a + c > b) {
    f3 = 1;
  }
  if (f1 == 1 && f2 == 1 && f3 == 1) {
    printf("0");
    return 0;
  }
  if ((a + b) <= c) {
    dif = fabs(c - (a + b)) + 1;
    printf("%d", dif);
    return 0;
  }
  if ((c + b) <= a) {
    dif = fabs(a - (c + b)) + 1;
    printf("%d", dif);
    return 0;
  }
  if ((a + c) <= b) {
    dif = fabs(b - (a + c)) + 1;
    printf("%d", dif);
    return 0;
  }
}
