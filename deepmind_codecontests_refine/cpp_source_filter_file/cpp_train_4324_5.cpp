#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void dbg(Args... args) {
  ((cout << args << " "), ...);
}
const int INF = 1e9, N = 1e6;
vector<pair<int, int>> g[N];
vector<int> ans[N];
bitset<N> used;
int main() {
  int n;
  cin >> n;
  int maxi = 0;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v, i), g[v].emplace_back(u, i);
    maxi = max(maxi, (int)(max(g[u].size(), g[v].size())));
  }
  dbg(maxi, "\n");
  queue<pair<int, int>> q;
  q.push({1, 1});
  while (!q.empty()) {
    auto [v, d] = q.front();
    q.pop();
    int day = 1;
    for (auto &[c, e] : g[v]) {
      if (!used[e]) {
        used[e] = 1;
        ans[day += (day == d)].emplace_back(e);
        q.push({c, day});
        ++day;
      }
    }
  }
  for (int i = 1; i <= maxi; ++i) {
    dbg(ans[i].size());
    for (auto &e : ans[i]) dbg(e);
    dbg("\n");
  }
}
