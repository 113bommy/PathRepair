#include <bits/stdc++.h>
using namespace std;
const int N = 105, mod = 1e9 + 7;
int T, n, m, x, y, soncnt, cnt[N][N], dep[N], son[N];
long long ans;
vector<int> G[N];
long long f[N][N];
inline void dfs(int x, int fa, int col) {
  dep[x] = dep[fa] + 1, ++cnt[col][dep[x]];
  for (auto y : G[x])
    if (y != fa) dfs(y, x, col);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m, ans = 0;
    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 1; i < n; ++i) {
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    if (m == 2) {
      cout << (n * (n - 1) / 2) << endl;
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      memset(cnt, 0, sizeof cnt);
      dep[i] = soncnt = 0;
      for (auto y : G[i]) dfs(y, i, y), son[++soncnt] = y;
      for (int D = 1; D <= n; ++D) {
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int j = 1; j <= soncnt; ++j) {
          f[j][0] = f[j - 1][0];
          for (int k = 1; k <= j; ++k)
            f[j][k] =
                (f[j - 1][k - 1] * cnt[son[j]][D] % mod + f[j - 1][k]) % mod;
        }
        (ans += f[soncnt][m]) %= mod;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
