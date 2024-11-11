#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
using namespace std;
template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}
template <class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}
const int N = 1e5 + 5;
vector<int> nodes[N];
int n, k;
int used[N];
vector<pair<int, int>> solve() {
  if (nodes[0].size() != 1) return {};
  int vis_nodes = 1;
  vector<pair<int, int>> res;
  for (int i = 1; i < N; ++i) {
    if (nodes[i].empty()) break;
    int prev_ind = 0;
    for (int v : nodes[i]) {
      int u = nodes[i - 1][prev_ind];
      while (used[u] == k && prev_ind != ((int)(nodes[i - 1].size()))) {
        ++prev_ind;
        u = nodes[i - 1][prev_ind];
      }
      if (prev_ind == ((int)(nodes[i - 1].size()))) return res;
      ++used[u];
      ++used[v];
      res.emplace_back(u, v);
      ++vis_nodes;
    }
  }
  if (vis_nodes != n) return {};
  return res;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    nodes[d].emplace_back(i + 1);
  }
  auto res = solve();
  if (res.empty()) {
    cout << -1 << '\n';
    return 0;
  }
  cout << ((int)(res.size())) << '\n';
  for (auto p : res) {
    cout << p.first << " " << p.second << '\n';
  }
  return 0;
}
