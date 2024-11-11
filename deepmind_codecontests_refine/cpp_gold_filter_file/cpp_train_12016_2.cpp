#include <bits/stdc++.h>
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
using namespace std;
vector<int> node[111111];
int anc[111111][20], depth[111111], id[111111], reid[111111], label = 0;
int n, K;
void dfs(int u) {
  id[u] = ++label;
  reid[label] = u;
  depth[u] = depth[anc[u][0]] + 1;
  for (int i = 1; i < 20; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
  for (int i = 0; i < node[u].size(); i++) {
    if (anc[u][0] == node[u][i]) continue;
    anc[node[u][i]][0] = u;
    dfs(node[u][i]);
  }
}
int lca(int u1, int u2) {
  if (depth[u1] < depth[u2]) swap(u1, u2);
  int d = depth[u1] - depth[u2];
  for (int i = 0; i < 20; i++)
    if ((d >> i) & 1) u1 = anc[u1][i];
  if (u1 == u2) return u1;
  for (int i = 20 - 1; i >= 0; i--)
    if (anc[u1][i] != anc[u2][i]) u1 = anc[u1][i], u2 = anc[u2][i];
  return anc[u1][0];
}
set<int> st;
int get(int u) {
  if (st.empty()) return 1;
  set<int>::iterator it = st.lower_bound(id[u]);
  int R = reid[it == st.end() ? *st.begin() : *it];
  int L = reid[it == st.begin() ? *st.rbegin() : *--it];
  return depth[u] + depth[lca(L, R)] - depth[lca(u, L)] - depth[lca(u, R)];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> K;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    node[u].push_back(v);
    node[v].push_back(u);
  }
  dfs(1);
  int all = 0, ans = 1;
  for (int i = 1, j = 0; i <= n; i++) {
    while (j + 1 <= n && all + get(j + 1) <= K) {
      all += get(++j);
      st.insert(id[j]);
    }
    ans = max(ans, j - i + 1);
    st.erase(id[i]);
    all -= get(i);
  }
  cout << ans << endl;
  return 0;
}
