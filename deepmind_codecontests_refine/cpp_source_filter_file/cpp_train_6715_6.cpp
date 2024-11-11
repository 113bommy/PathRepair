#include <bits/stdc++.h>
using namespace std;
const long long mm = 1e9 + 7;
int n, k, cnt;
int a[1005000], c[1005000];
long long ans, l, p, x, s[1005000];
vector<vector<long long> > f;
int main() {
  scanf("%d%lld%d", &n, &l, &k);
  f.resize(k + 1);
  for (int i = 0; i <= k; i++) f[i].resize(n + 1);
  p = l % n;
  x = l / n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), c[i] = a[i];
  sort(c + 1, c + 1 + n);
  cnt = unique(c + 1, c + 1 + n) - c - 1;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(c + 1, c + 1 + cnt, a[i]) - c;
  for (int i = 1; i <= cnt; i++) f[1][i] = 1;
  ans = l % mm;
  for (int i = 2; i <= k; i++) {
    for (int j = 1; j <= cnt; j++) s[j] = (s[j - 1] + f[i - 1][j]) % mm;
    if (i > 2 && x - i + 2 > 0) (ans += (x - i + 2) % mm * s[cnt] % mm) %= mm;
    for (int j = 1; j <= n; j++) (f[i][a[j]] += s[a[j]]) %= mm;
    if (x - i + 2 > 0)
      for (int j = 1; j <= p; j++) (ans += s[a[j]]) %= mm;
  }
  for (int j = 1; j <= cnt; j++) s[j] = (s[j - 1] + f[k][j]) % mm;
  if (k > 1 && x - k + 1 > 0) (ans += (x - k + 1) % mm * s[cnt] % mm) %= mm;
  printf("%lld\n", ans);
  return 0;
}
