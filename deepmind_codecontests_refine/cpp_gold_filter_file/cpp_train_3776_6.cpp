#include <bits/stdc++.h>
using namespace std;
const int N = 300005, M = 998244353, L = 20;
int l[N], r[N], num[41][1 << L | 1], x[L], y[L], ans, vis[N], fac[N], inv[N],
    cnt[N], n, m;
inline int ksm(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1, x = (long long)x * x % M)
    if (y & 1) ans = (long long)ans * x % M;
  return ans;
}
inline int C(int x, int y) {
  if (x < y || y < 0 || x < 0) return 0;
  return (long long)fac[x] * inv[y] % M * inv[x - y] % M;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &l[i], &r[i]), cnt[l[i]]++, cnt[r[i] + 1]--;
  for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
  for (int i = 0; i < m; i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = 0; i < 1 << m; i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++)
      if (((1 << j) & i)) {
        cnt += !vis[x[j]];
        cnt += !vis[y[j]];
        vis[x[j]] = vis[y[j]] = 1;
      }
    num[cnt][i] += __builtin_popcount(i) & 1 ? -1 : 1;
    for (int j = 0; j < m; j++) vis[x[j]] = vis[y[j]] = 0;
  }
  for (int i = 0; i <= m * 2; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < 1 << m; k++)
        if (k & (1 << j)) num[i][k] += num[i][k ^ (1 << j)];
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= n; i++)
    fac[i] = (long long)fac[i - 1] * i % M, inv[i] = ksm(fac[i], M - 2);
  for (int i = 1; i <= n; i++) {
    int s = 0;
    for (int j = 0; j < m; j++)
      if (l[x[j]] <= i && r[x[j]] >= i && l[y[j]] <= i && r[y[j]] >= i)
        s |= 1 << j;
    for (int j = 0; j <= 2 * m; j++)
      if (num[j][s])
        ans = (ans + (long long)num[j][s] * C(cnt[i] - j, i - j)) % M;
  }
  printf("%d\n", (ans + M) % M);
}
