#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int p = 1e9 + 7;
int ksm(int a, int b, int p) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % p;
    b >>= 1, a = 1ll * a * a % p;
  }
  return ans;
}
int fac[maxn], inv[maxn];
int sta[maxn], f[1 << 15];
int dp[1 << 15][maxn];
int fa[maxn], a[maxn];
int in[maxn];
int getfa(int t) {
  if (fa[t] == t) return t;
  return fa[t] = getfa(fa[t]);
}
int C(int n, int m) {
  if (n < m) return 0;
  return 1ll * fac[n] * inv[m] % p * inv[n - m] % p;
}
vector<int> g[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (a[j] % a[i] == 0) {
        fa[getfa(j)] = getfa(i);
        ++in[j];
      }
    }
  }
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % p;
  inv[n] = ksm(fac[n], p - 2, p);
  for (int i = n - 1; i >= 1; --i) inv[i] = 1ll * (i + 1) * inv[i + 1] % p;
  int nowtot = 0, ans = 1;
  for (int i = 1; i <= n; ++i) g[getfa(i)].emplace_back(i);
  for (int i = 1; i <= n; ++i) {
    if (g[i].size() > 1) {
      memset(f, 0, sizeof f);
      memset(dp, 0, sizeof dp);
      vector<int> s;
      for (auto v : g[i])
        if (!in[v]) s.emplace_back(v);
      int cnt = 0;
      int num = 1 << s.size();
      for (auto v : g[i]) {
        if (in[v]) {
          ++cnt;
          for (int j = 0; j < (int)s.size(); ++j)
            if (a[v] % a[s[j]] == 0) sta[v] |= (1 << j);
          ++f[sta[v]];
        }
      }
      for (int k = 0; k < (int)s.size(); ++k)
        for (int j = 0; j < num; ++j)
          if (j & (1 << k)) f[j] += f[j ^ (1 << k)];
      dp[0][0] = 1;
      for (int j = 0; j < num; ++j) {
        for (int k = 0; k <= cnt; ++k) {
          if (dp[j][k]) {
            if (k < f[j])
              dp[j][k + 1] =
                  1ll * (dp[j][k + 1] + 1ll * dp[j][k] * (f[j] - k)) % p;
            for (auto v : g[i])
              if (in[v] && (sta[v] & j) != sta[v] && ((sta[v] & j) == j))
                dp[j | sta[v]][k + 1] = (dp[j | sta[v]][k + 1] + dp[j][k]) % p;
          }
        }
      }
      ans = 1ll * ans * dp[num - 1][cnt] % p * C(nowtot + cnt - 1, cnt - 1) % p;
      nowtot += cnt - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
