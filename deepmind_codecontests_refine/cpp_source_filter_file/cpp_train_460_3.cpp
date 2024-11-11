#include <bits/stdc++.h>
using namespace std;
const int MaxN = 901;
const int oo = 1e9;
int t, n, m, low[MaxN], id[MaxN], cnt, cntScc, deg[MaxN], scc[MaxN], ans,
    root[MaxN];
vector<int> f[MaxN], leaf;
bool mark[MaxN];
stack<int> st;
void tarjan(int u, int p) {
  low[u] = id[u] = ++cnt;
  mark[u] = true;
  st.push(u);
  for (int v : f[u]) {
    if (v == p) continue;
    if (id[v])
      low[u] = min(low[u], id[v]);
    else {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    }
  }
  if (id[u] == low[u]) {
    cntScc++;
    int v;
    do {
      v = st.top();
      scc[v] = cntScc;
      st.pop();
      id[v] = low[v] = oo;
    } while (v != u);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  while (t--) {
    cin >> n >> m;
    if (n == 2 && n == 1) {
      cout << -1;
      return 0;
    }
    for (int i = 1; i <= n; i++) {
      f[i].clear();
      low[i] = 0;
      id[i] = 0;
      scc[i] = 0;
      deg[i] = 0;
      mark[i] = false;
    }
    leaf.clear();
    cntScc = 0;
    cnt = 0;
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      f[u].push_back(v);
      f[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
      if (!id[i]) tarjan(i, 0);
    }
    for (int i = 1; i <= n; i++) {
      for (int j : f[i]) {
        if (scc[i] != scc[j]) {
          deg[scc[i]]++;
          deg[scc[j]]++;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      root[scc[i]] = i;
    }
    for (int i = 1; i <= cntScc; i++) {
      if (deg[i] == 2) leaf.push_back(root[i]);
    }
    ans = (int)leaf.size();
    if ((ans + 1) / 2 == 0) {
      cout << 0 << '\n' << '\n';
      continue;
    }
    cout << (ans + 1) / 2 << '\n';
    for (int i = 0; i < (ans + 1) / 2; i++) {
      cout << leaf[i] << " " << leaf[i + ans / 2] << '\n';
    }
    cout << '\n';
  }
}
