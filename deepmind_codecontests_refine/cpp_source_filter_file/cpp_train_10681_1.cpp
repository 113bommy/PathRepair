#include <bits/stdc++.h>
int N, n;
double F, H, K, l[1005], r[1005];
double calc(double x, double y) {
  x = abs(x), y = abs(y);
  if (x > y) std::swap(x, y);
  if (y - K * x > -1e-9) return x * (1 + K) * H;
  double h = 2 * H * (K * y - x) / (K - 1) / (x + y),
         w = x * (F - H + h) / (F - H);
  return ((x + w) * h + (y + w) * (2 * H - h)) / 2;
}
int main() {
  scanf("%d%lf%lf", &n, &H, &F), K = (F + H) / (F - H);
  for (int i = 1; i <= n; i++) {
    N++, scanf("%lf%lf", &l[N], &r[N]);
    if (l[N] < 0 && r[n] > 0) r[N + 1] = r[N], r[N] = 0, l[++N] = 0;
  }
  double ans = 0;
  for (int i = 1; i <= N; i++) ans += (r[i] - l[i]) * (1 + K) * H * 2;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      if ((l[i] < 0 && l[j] < 0) || (r[i] > 0 && r[j] > 0))
        ans -= calc(l[i], l[j]) + calc(r[i], r[j]) - calc(l[i], r[j]) -
               calc(l[j], r[i]);
  printf("%.9lf\n", ans);
}
