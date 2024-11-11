#include <bits/stdc++.h>
using namespace std;
const int C = 1e9;
const int N = 1e5;
int c[N];
int u[N];
int v[N];
int pos[N];
vector<int> adj[N];
int n, m;
bool is_cycle(int cost, vector<int>& rev) {
  vector<bool> seen(n);
  int t = 0;
  function<void(int)> dfs = [&](int nd) {
    if (seen[nd]) return;
    seen[nd] = true;
    for (auto z : adj[nd]) {
      if (c[z] > cost) dfs(v[z]);
    }
    pos[nd] = t++;
  };
  for (int i = 0; i < n; i++) dfs(i);
  for (int i = 0; i < m; i++) {
    if (pos[u[i]] > pos[v[i]]) continue;
    if (c[i] > cost)
      return true;
    else
      rev.push_back(i);
  }
  return false;
}
int bin_sea(int a, int b) {
  if (a == b) return a;
  int mid = (a + b) / 2;
  vector<int> tmp;
  if (is_cycle(mid, tmp))
    return bin_sea(mid + 1, b);
  else
    return bin_sea(a, mid);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i] >> c[i];
    u[i]--;
    v[i]--;
    adj[u[i]].push_back(i);
  }
  int ans = bin_sea(0, C);
  vector<int> rev;
  is_cycle(ans, rev);
  sort(rev.begin(), rev.end());
  cout << ans << " " << rev.size() << endl;
  for (auto z : rev) cout << z + 1 << " ";
  cout << endl;
  return 0;
}
