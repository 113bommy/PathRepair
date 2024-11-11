#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, f[maxn];
double A, B, x[maxn], y[maxn];
double calc(double x, double y) { return x * x + y * y; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf %lf", &x[i], &y[i]);
  }
  for (int i = n; i >= 1; i--) {
    if (calc(A - x[i], B - y[i]) < calc(A + x[i], B + y[i])) {
      A -= x[i], B -= x[i], f[i] = -1;
    } else {
      A += x[i], B += x[i], f[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", f[i]);
  }
  return 0;
}
