#include <bits/stdc++.h>
using namespace std;
int a[305], b[305], t[305];
int n, m, d;
long long f[150005], mx = -(1LL << 60);
long long q[150005], g[305 * 2];
long long ub(int j, int i) {
  return (long long)(t[i] - t[i - 1]) * d + (long long)j;
}
long long lb(int j, int i) {
  return (long long)j - (long long)(t[i] - t[i - 1]) * d;
}
void getmax(long long k) {
  int l = 0, r = 0;
  long long st = min((long long)n, k - 1);
  memset(q, 0LL, sizeof(q));
  for (long long i = 1LL; i <= st; i++) {
    while (l <= r && f[q[r]] <= f[i]) r--;
    q[++r] = i;
    if (i == 1LL)
      g[i] = f[i];
    else
      g[i] = max(g[i - 1], f[i]);
  }
  for (long long i = k; i <= (long long)n; i++) {
    while (l <= r && f[q[r]] <= f[i]) r--;
    q[++r] = i;
    while (q[l] <= i - k) l++;
    g[i] = f[q[l]];
  }
  for (int i = 1; i <= n; i++) {
    if (i == 1)
      g[i + n] = f[n];
    else
      g[i + n] = max(g[i + n - 1], f[n - i + 1]);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 1; i <= m; i++) scanf("%d%d%d", &a[i], &b[i], &t[i]);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (ub(j, i) <= (long long)n)
        f[j] = g[ub(j, i)] + b[i] - abs(a[i] - j);
      else if (lb(j, i) >= 1LL)
        f[j] = g[2 * n - lb(j, i) + 1] + b[i] - abs(a[i] - j);
      else
        f[j] = g[2 * n] + b[i] - abs(a[i] - j);
    }
    if (i < m) getmax(2LL * (t[i + 1] - t[i]) * d + 1);
  }
  for (int i = 1; i <= n; i++) mx = max(mx, f[i]);
  printf("%I64d\n", mx);
  return 0;
}
