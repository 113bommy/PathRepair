#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> g;
vector<long long> pred;
vector<bool> used;
long long temp = 0;
void dfs(long long v) {
  used[v] = 1;
  for (auto to : g[v]) {
    if (used[to]) continue;
    pred[to] = v;
    if (v == 0) {
      temp++;
    }
    dfs(to);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, d;
  cin >> n >> m >> d;
  g.resize(n);
  pred.resize(n);
  used.resize(n, 0);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    g[l - 1].push_back(r - 1);
    g[r - 1].push_back(l - 1);
  }
  if (g[0].size() < d) {
    cout << "NO";
    return 0;
  }
  dfs(0);
  if (temp > d) {
    cout << "NO";
    return 0;
  }
  d -= temp;
  cout << "YES\n";
  for (int i = 0; i < g[0].size() && d > 0; i++) {
    if (pred[g[0][i]] != 0) {
      pred[g[0][i]] = 0;
      d--;
    }
  }
  for (int i = 1; i < n; i++) {
    cout << i + 1 << ' ' << pred[i] + 1 << '\n';
  }
  return 0;
}
