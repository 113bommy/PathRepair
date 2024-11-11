#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, c[N], p = -1, uu;
vector<int> a[N];
void dfs(int u, int l = -1) {
  c[u] = 1;
  for (int v : a[u]) {
    if (v != l) {
      dfs(v, u);
      c[u] += c[v];
    }
  }
  if (c[u] == n - c[u]) {
    uu = u;
    p = l;
  }
}
void solve() {
  for (int i = 1; i <= n; i++) {
    a[i].clear();
    c[i] = 1;
    p = -1;
  }
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1);
  if (p == -1) {
    cout << 1 << " " << a[1][0] << "\n";
    cout << 1 << " " << a[1][0] << "\n";
  } else {
    for (int i : a[p]) {
      if (i != uu) {
        cout << i << " " << p << "\n";
        cout << i << " " << uu << "\n";
        break;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
