#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int h[N], A, R, M, n;
long long sum[N], ans = 998244353;
long long calc(long long i) {
  int p = lower_bound(h + 1, h + n + 1, i) - h - 1;
  long long Sum = i * n, res = 0;
  if (Sum > sum[n]) {
    long long w = 1ll * i * p - sum[p] - (Sum - sum[n]);
    res = w * M + A * (Sum - sum[n]);
  } else {
    long long w = (sum[n] - sum[p]) - 1ll * i * (n - p) - (sum[n] - Sum);
    res = w * M + R * (sum[n] - Sum);
  }
  ans = min(ans, res);
  return res;
}
int main() {
  scanf("%d%d%d%d", &n, &A, &R, &M);
  M = min(M, A + R);
  for (int i = 1; i <= n; i++) scanf("%d", h + i);
  sort(h + 1, h + n + 1);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + h[i];
  long long lx = 1, rx = 1e9;
  for (int i = 1; i <= 100; i++) {
    long long x1 = lx + (rx - lx) / 3, x2 = rx - (rx - lx) / 3;
    if (calc(x1) > calc(x2))
      lx = x1;
    else
      rx = x2;
  }
  printf("%lld\n", ans);
  return 0;
}
