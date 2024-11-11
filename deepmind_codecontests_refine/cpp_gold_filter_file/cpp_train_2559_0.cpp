#include <bits/stdc++.h>
using namespace std;
const int N = 20005;
int n, m, head[N], f[N], v[N * 2], w[N * 2], ans[N], dp[N], fa[N], q[N], uu[N],
    vv[N];
char up[N], s[N];
vector<pair<int, int>> vec[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    cin >> uu[i] >> vv[i] >> s[i];
    ++head[uu[i]];
    ++head[vv[i]];
  }
  for (int i = 1; i <= n; i++) head[i + 1] += head[i];
  for (int i = 1; i < n; i++) {
    --head[uu[i]];
    v[head[uu[i]]] = vv[i];
    w[head[uu[i]]] = s[i];
    --head[vv[i]];
    v[head[vv[i]]] = uu[i];
    w[head[vv[i]]] = s[i];
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    vec[x].push_back({y, i});
  }
  for (int i = 1; i <= n; i++)
    if (!vec[i].empty()) {
      int fr = 0, ed = 0;
      q[++ed] = i;
      fa[i] = up[i] = dp[i] = f[i] = 0;
      while (fr < ed) {
        int nd = q[++fr];
        for (int i = head[nd]; i < head[nd + 1]; i++)
          if (v[i] != fa[nd]) {
            fa[v[i]] = nd;
            up[v[i]] = w[i];
            dp[v[i]] = dp[nd] + 1;
            q[++ed] = v[i];
          }
      }
      for (auto &j : vec[i]) {
        int p = j.first, l = dp[p];
        s[l + 1] = 0;
        while (p != i) s[dp[p]] = up[p], p = fa[p];
        int ret = 0;
        for (int k = 2; k <= n; k++) {
          int nd = q[k];
          if (f[fa[nd]])
            f[nd] = f[fa[nd]];
          else
            f[nd] = (up[nd] < s[dp[nd]]) - (up[nd] > s[dp[nd]]);
          ret += (f[nd] == 1 || (!f[nd] && dp[nd] < l));
        }
        ans[j.second] = ret;
      }
    }
  for (int i = 1; i <= m; i++) cout << ans[i] << endl;
  return 0;
}
