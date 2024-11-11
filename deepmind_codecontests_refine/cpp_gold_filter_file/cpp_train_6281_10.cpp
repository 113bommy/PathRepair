#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 9, lg = 20;
int s[MAX], c, par[MAX][lg], in[MAX], n, q;
long long h[MAX], k[MAX], ans;
set<int> st;
vector<pair<int, int> > g[MAX];
void dfs(int v, int p = -1) {
  s[v] = c, in[c++] = v;
  for (auto u : g[v])
    if (u.first != p) {
      h[u.first] = h[v] + u.second, k[u.first] = k[v] + 1, par[u.first][0] = v;
      for (int i = 1; i < lg; i++)
        par[u.first][i] = par[par[u.first][i - 1]][i - 1];
      dfs(u.first, v);
    }
}
int parent(int v, int h) {
  for (int i = 0; i < lg; i++)
    if (h >> i & 1) v = par[v][i];
  return v;
}
int lca(int v, int u) {
  if (k[v] > k[u]) swap(v, u);
  u = parent(u, k[u] - k[v]);
  if (v == u) return v;
  for (int i = lg - 1; i >= 0; i--)
    if (par[v][i] != par[u][i]) v = par[v][i], u = par[u][i];
  return par[v][0];
}
long long dis(int v, int u) { return h[v] + h[u] - 2 * h[lca(v, u)]; }
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, v, u, w; i < n; i++)
    cin >> v >> u >> w, v--, u--, g[v].push_back({u, w}),
        g[u].push_back({v, w});
  dfs(0), cin >> q;
  while (q--) {
    char ch;
    cin >> ch;
    int v;
    if (ch == '?')
      cout << ans / 2 << '\n';
    else {
      cin >> v, v--;
      if (ch == '+') {
        st.insert(s[v]);
        auto it = st.find(s[v]);
        auto itt = it;
        int u, w;
        if (it == st.begin())
          u = in[*st.rbegin()];
        else
          it--, u = in[*it];
        itt++;
        if (itt == st.end())
          w = in[*st.begin()];
        else
          w = in[*itt];
        ans += dis(u, v) + dis(v, w) - dis(u, w);
      }
      if (ch == '-') {
        auto it = st.find(s[v]);
        auto itt = it;
        int u, w;
        if (it == st.begin())
          u = in[*st.rbegin()];
        else
          it--, u = in[*it];
        itt++;
        if (itt == st.end())
          w = in[*st.begin()];
        else
          w = in[*itt];
        ans -= dis(u, v) + dis(v, w) - dis(u, w);
        st.erase(s[v]);
      }
    }
  }
}
