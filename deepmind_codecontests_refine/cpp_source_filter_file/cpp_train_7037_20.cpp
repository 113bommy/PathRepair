#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
bool Max(T1& a, T2 b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T1, typename T2>
bool Min(T1& a, T2 b) {
  return a > b ? a = b, 1 : 0;
}
const int N = 101;
const int M = 100002;
vector<pair<int, int> > g[N];
void dfs(int i, int p, double tm) {
  double t = 2.0 / g[i].size();
  for (auto& e : g[i])
    if (e.first != p) {
      tm += t;
      if (tm > 2.0) tm -= 2.0;
      if (tm <= 1.0) {
        cout << 1 << " " << e.second << " " << e.first << " " << i << " "
             << 1.0 - tm << '\n';
        dfs(e.first, i, tm + 1.0);
      } else {
        cout << 1 << " " << e.second << " " << i << " " << e.second << " "
             << 2.0 - tm << '\n';
        dfs(e.first, i, tm - 1.0);
      }
    }
}
void solve() {
  int n, u, v;
  cin >> n;
  for (int i = 1; i <= (n - 1); ++i) {
    cin >> u >> v;
    g[u].emplace_back(v, i);
    g[v].emplace_back(u, i);
  }
  cout << n - 1 << '\n';
  dfs(1, 0, 0.01);
}
void init() {}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(20);
  init();
  int TC = 1;
  for (int TI = 1; TI <= (TC); ++TI) {
    solve();
  }
  return 0;
}
