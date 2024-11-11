#include <bits/stdc++.h>
using namespace std;
int x[100010];
int y[100010];
int l[100010];
int n, m, a, b;
int getpos(double k) {
  int kk = k;
  return upper_bound(x, x + n, kk) - x;
}
double cal(int a, int b, int c, int d) {
  return sqrt(1.0 * (a - c + 0.0) * (a - c + 0.0) +
              1.0 * (b - d + 0.0) * (b - d + 0.0));
}
int main() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  for (int i = 0; i < m; i++) scanf("%d", &y[i]);
  for (int i = 0; i < m; i++) scanf("%d", &l[i]);
  double ans = cal(0, 0, a, x[0]) + cal(a, x[0], b, y[0]) + l[0];
  int xf = 0, yf = 0;
  for (int i = 0; i < m; i++) {
    double t = 1.0 * a * y[i] / (b * 1.0);
    int pos = getpos(t);
    int lowb = max(0, pos - 2);
    for (int j = lowb; j < n && j <= lowb + 5; j++) {
      double temp = cal(0, 0, a, x[j]) + cal(a, x[j], b, y[i]) + 1.0 * l[i];
      if (temp < ans) {
        ans = temp;
        xf = j;
        yf = i;
      }
    }
  }
  printf("%d %d\n", xf + 1, yf + 1);
  return 0;
}
