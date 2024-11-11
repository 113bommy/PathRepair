#include <bits/stdc++.h>
using namespace std;
const int N = 200010, M = 1e9 + 7;
int n, m, K, c[N], low[N], num[N], cnt[N], cnt1, ans;
stack<int> st;
vector<int> a[N], tmp;
vector<vector<int> > V;
void DFS(int u) {
  num[u] = low[u] = ++cnt1;
  st.push(u);
  for (auto v : a[u]) {
    if (num[v])
      low[u] = min(low[u], num[v]);
    else {
      DFS(v);
      low[u] = min(low[u], low[v]);
    }
  }
  if (low[u] >= num[u]) {
    int v;
    tmp.clear();
    do {
      v = st.top();
      st.pop();
      tmp.push_back(c[v]);
      low[v] = num[v] = M;
    } while (v != u);
    V.push_back(tmp);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> K;
  for (int i = 1; i <= n; i++) cin >> c[i];
  int u, v;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (num[i] == 0) DFS(i);
  for (int i = 0; i < V.size(); i++) {
    int mx = 0, k = 0;
    for (int j = 0; j < V[i].size(); j++) {
      if (cnt[V[i][j]] == 0) k++;
      cnt[V[i][j]]++;
      if (cnt[j] > mx) mx = cnt[V[i][j]];
    }
    if (k >= 2) ans += V[i].size() - mx;
    for (int j = 0; j < V[i].size(); j++) cnt[V[i][j]] = 0;
  }
  cout << ans;
  return 0;
}
