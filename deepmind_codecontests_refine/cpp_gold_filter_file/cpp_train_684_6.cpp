#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1 << 30;
int n, m, val[N], in[N];
vector<int> G[N];
set<int, greater<int>> st;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) in[i] = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    G[v].push_back(u);
    in[u]++;
  }
  for (int i = 1; i <= n; i++) {
    val[i] = -1;
    if (in[i] == 0) st.insert(i);
  }
  int lbl = n;
  while (!st.empty()) {
    int v = *st.begin();
    if (val[v] == -1)
      val[v] = lbl--;
    else
      continue;
    st.erase(st.begin());
    for (auto u : G[v]) {
      if (--in[u] == 0) st.insert(u);
    }
  }
  for (int i = 1; i <= n; i++) cout << val[i] << ' ';
}
