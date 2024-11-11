#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int M = 205;
const int md = 1000000007;
const int inf = 2000000000;
int n, m, x, y, k, kk, ak, hk, i, j, ans, d[N], f[N], u[N];
char c;
vector<int> q[N], w[N];
char dfs(int v, int c, int t) {
  u[v] = kk;
  f[v] = c;
  k += c;
  ++hk;
  for (int i = 0; i < q[v].size(); ++i) {
    int to = q[v][i];
    int o;
    if (w[v][i] == t)
      o = c;
    else
      o = 1 - c;
    if (!u[to]) dfs(to, o, t);
    if (f[to] != o) return false;
  }
  return true;
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (i = 1; i <= m; ++i) {
    cin >> x >> y >> c;
    q[x].push_back(y);
    q[y].push_back(x);
    if (c == 'R')
      w[x].push_back(1), w[y].push_back(1);
    else
      w[x].push_back(0), w[y].push_back(0);
  }
  ans = n + 1;
  for (i = 0; i < 2; ++i) {
    bool qq = true;
    bool dd[N];
    for (j = 1; j <= n; ++j)
      if (!u[j]) {
        ++kk;
        qq = dfs(j, 1, i);
        if (!qq) break;
        ak += min(k, hk - k);
        if (k <= hk - k)
          dd[k] = true;
        else
          dd[k] = false;
        k = 0;
        hk = 0;
      }
    if (qq && ak < ans) {
      ans = 0;
      for (j = 1; j <= n; ++j)
        if (dd[u[j]] == f[j]) ++ans, d[ans] = j;
    }
    for (j = 1; j <= n; ++j) u[j] = 0;
    k = 0;
  }
  if (ans == n + 1) {
    cout << -1;
    return 0;
  }
  cout << ans << "\n";
  for (i = 1; i <= ans; ++i) cout << d[i] << " ";
}
