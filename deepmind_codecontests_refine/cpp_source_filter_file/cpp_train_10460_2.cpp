#include <bits/stdc++.h>
using namespace std;
int L = 30;
int n, m, d[100005], si[100005], tin[100005], tout[100005], up[100005][30], cnt;
vector<int> adj[100005];
void dfs(int s = 1, int p = 0) {
  tin[s] = cnt++;
  up[s][0] = p;
  d[s] = d[p] + 1;
  si[s] = 1;
  for (int i = 1; i < L; i++) up[s][i] = up[up[s][i - 1]][i - 1];
  for (auto i : adj[s]) {
    if (i == p) continue;
    dfs(i, s);
    si[s] += si[i];
  }
  tout[s] = cnt++;
}
bool is_anc(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }
int go_up(int a, int b) {
  for (int i = L - 1; i >= 0; i--) {
    if (!is_anc(up[a][i], b)) a = up[a][i];
  }
  return a;
}
int lca(int a, int b) {
  if (is_anc(b, a))
    return b;
  else if (is_anc(a, b))
    return a;
  else {
    return up[go_up(a, b)][0];
  }
}
void solve() {
  int a, b;
  cin >> a >> b;
  int l = lca(a, b);
  if (a == b)
    cout << n;
  else if (d[a] - d[l] == d[b] - d[l]) {
    a = go_up(a, l);
    b = go_up(b, l);
    cout << n - si[a] - si[b];
  } else {
    if (d[a] < d[b]) swap(a, b);
    int dist = d[a] + d[b] - 2 * d[l];
    if (dist % 2 == 1) {
      cout << 0;
    } else {
      dist /= 2;
      int t = a;
      for (int i = L - 1; i >= 0; i--) {
        if (d[a] - d[up[t][0]] < dist) t = up[t][0];
      }
      int mid = up[t][0];
      cout << si[mid] - si[t];
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  while (test--) {
    int u, v;
    cin >> n;
    for (long long i = 0; i < (n - 1); ++i) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs();
    cin >> m;
    for (long long i = 0; i < (m); ++i) {
      solve();
      cout << "\n";
    }
  }
}
