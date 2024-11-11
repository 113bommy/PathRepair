#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 15;
vector<int> adj[N];
stack<int> st;
int order[N], scc[N], sz[N];
int spos = 0, pos = 1;
int dfs(int root) {
  int ret = order[root] = pos++;
  st.push(root);
  for (int i = 0; i < adj[root].size(); ++i) {
    int u = adj[root][i];
    if (!order[u]) {
      ret = min(ret, dfs(u));
    } else if (scc[u] == -1)
      ret = min(ret, order[u]);
  }
  if (ret == order[root]) {
    while (1) {
      int u = st.top();
      st.pop();
      scc[u] = spos;
      ++sz[spos];
      if (u == root) break;
    }
    ++spos;
  }
  return ret;
}
int h[N];
int check(int i, int j, int H) {
  if ((h[i] + 1) % H == h[j]) return 1;
  return 0;
}
int deg[N];
int main() {
  int n, m, H;
  memset(scc, -1, sizeof(scc));
  scanf("%d%d%d", &n, &m, &H);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &h[i]);
  }
  int u, v;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v);
    if (check(u, v, H)) adj[u].push_back(v);
    if (check(v, u, H)) adj[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i)
    if (!order[i]) {
      dfs(i);
    }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < adj[i].size(); ++j) {
      u = adj[i][j];
      if (scc[u] != scc[i]) {
        ++deg[scc[i]];
      }
    }
  }
  int ss = 1e9, id;
  for (int i = 0; i < spos; ++i) {
    if (ss > sz[i] && deg[i] == 0) {
      ss = sz[i];
      id = i;
    }
  }
  cout << ss << endl;
  for (int i = 1; i <= n; ++i)
    if (scc[i] == id) printf("%d ", i);
  cout << endl;
}
