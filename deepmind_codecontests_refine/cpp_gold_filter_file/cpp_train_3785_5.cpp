#include <bits/stdc++.h>
using namespace std;
const int Mod = 1000000007;
const int MAX = 10000 + 10;
const int MAXN = 120 + 10;
int n, m, w[MAX], sum[MAX], f[MAXN][MAXN], q[MAXN], mod[MAX];
int get(int deep) {
  long long ans = 1;
  int i;
  for (i = 1; i <= deep; ++i) ans = (ans * sum[q[i]]) % Mod;
  return (int)ans;
}
int dfs(int deep, int last) {
  long long ans = get(deep - 1);
  if (deep >= 7) return ans;
  int i, j;
  for (i = last; i <= m / 2; ++i)
    if (sum[i] && !f[deep - 1][i] && !f[deep - 1][m - i]) {
      if (deep < 6) {
        for (j = 0; j < m; ++j) f[deep][j] = 0;
        for (j = 0; j < m; ++j)
          if (f[deep - 1][j])
            f[deep][j] = f[deep][mod[j - i + m]] = f[deep][mod[j + i]] = 1;
      }
      q[deep] = i;
      ans += dfs(deep + 1, i + 1);
      if (ans > Mod) ans -= Mod;
    }
  return (int)ans;
}
int main() {
  int i;
  cin >> i >> m >> n;
  for (i = 1; i <= n; ++i) {
    cin >> w[i];
    w[i] %= m;
    ++sum[min(w[i], m - w[i])];
  }
  for (i = 0; i < MAX; ++i) mod[i] = i % m;
  f[0][0] = 1;
  long long ans = dfs(1, 1);
  cout << ans << endl;
}
