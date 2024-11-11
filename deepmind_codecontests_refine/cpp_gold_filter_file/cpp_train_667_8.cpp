#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v, i, j, a[100], b[100];
  double sum = 0, num = 0, minn = 1000000;
  scanf("%d %d", &n, &v);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    num = b[i] * 1.00 / a[i];
    if (num < minn) minn = num;
  }
  for (i = 0; i < n; i++) {
    sum += minn * a[i] * 1.00;
  }
  if (sum >= v)
    printf("%lf", v * 1.00);
  else
    printf("%lf", sum);
}
