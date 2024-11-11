#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[11];
  for (int i = 0; i <= 10; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 10; i >= 0; i--) {
    double res = sqrt(abs(a[i]) * 1.0) + a[i] * a[i] * a[i] * 5;
    if (res >= 400) {
      printf("f(%d) = MAGNA NIMIS!\n", a[i]);
    } else {
      printf("f(%d) = %.2f\n", a[i], res);
    }
  }
  return 0;
}
