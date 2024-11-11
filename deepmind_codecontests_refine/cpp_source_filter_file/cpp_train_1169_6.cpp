#include <bits/stdc++.h>
using namespace std;
const int N = 55, M = 200005, P = 998244353;
using ll = long long;
int n, m, kk, idx, C[N][N], w[N][N], ans[N];
ll f[N], t[N], g[N], cnt[N], p[M];
void ins(ll x) {
  for (int i = 0; i < m; i++)
    if (x & (1 << i)) {
      if (f[i])
        x ^= f[i];
      else {
        f[i] = x;
        ++kk;
        return;
      }
    }
}
void dfs(int kk, ll x) {
  if (kk == idx)
    cnt[__builtin_popcountll(x)]++;
  else
    dfs(kk + 1, x), dfs(kk + 1, x ^ t[kk]);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 2 % P;
  ll x;
  for (int i = 1; i <= n; i++) cin >> x, ins(x);
  for (int i = m - 1; i >= 0; --i)
    for (int j = i + 1; j < m; j++)
      if (f[i] & (1 << j)) f[i] ^= f[j];
  if (kk <= m / 2) {
    for (int i = 0; i < m; i++)
      if (f[i]) t[idx++] = f[i];
    dfs(0, 0);
    for (int i = 0; i <= m; i++) cout << cnt[i] * p[n - kk] % P << ' ';
    return 0;
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) g[i] |= ((f[j] >> i) & 1) << j;
  for (int i = 0; i < m; i++)
    if ((g[i] ^= 1ll << i)) t[idx++] = g[i];
  kk = m - kk;
  dfs(0, 0);
  for (int i = 0; i <= m; i++) C[i][0] = 1;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= i; k++)
        w[i][j] =
            (w[i][j] + ll(k & 1 ? P - C[j][k] : C[j][k]) * C[m - j][i - k]) % P;
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= m; j++) ans[i] = (ans[i] + w[i][j] * 1ll * cnt[j]) % P;
  ll tt = p[n + kk - m];
  for (int i = 1; i <= kk; i++) tt = tt * (P + 1) / 2 % P;
  for (int i = 0; i <= m; i++) cout << ans[i] * tt % P << ' ';
  return 0;
}
