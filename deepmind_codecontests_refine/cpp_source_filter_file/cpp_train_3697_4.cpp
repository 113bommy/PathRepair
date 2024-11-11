#include <bits/stdc++.h>
using namespace std;
double x[2005], y[2005];
double d[2005];
double eps = 1e-10;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    x[i] = 1.0 * a * c / (a * a + b * b);
    y[i] = 1.0 * b * c / (a * a + b * b);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (abs(x[i] - x[j]) <= eps) {
        if (abs(y[i] - y[j]) > eps)
          d[j] = 214748364.0;
        else
          d[j] = -214748364.0;
      } else
        d[j] = 1.0 * (y[i] - y[j]) / (x[i] - x[j]);
    }
    sort(d + 1, d + i);
    d[0] = -214748364.0;
    int cnt = 1;
    for (int j = 1; j < i; j++) {
      if (d[j] == -214748364.0)
        ans += (i - j - 1);
      else if (abs(d[j] - d[j - 1]) > eps) {
        ans += cnt * (cnt - 1) / 2;
        cnt = 1;
      } else
        cnt++;
    }
    ans += cnt * (cnt - 1) / 2;
  }
  printf("%d\n", ans);
  return 0;
}
