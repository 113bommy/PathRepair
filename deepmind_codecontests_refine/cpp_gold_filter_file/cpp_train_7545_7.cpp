#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<bool> used(n);
  for (int i = 0; i < k; ++i) {
    int v;
    cin >> v;
    used[v - 1] = true;
  }
  vector<vector<int>> g(n);
  vector<int> deg(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
    deg[a - 1]++, deg[b - 1]++;
  }
  auto check = [&](double x) mutable {
    queue<int> que;
    auto cur = deg;
    auto erased = used;
    for (int i = 0; i < n; ++i) {
      if (erased[i]) que.push(i);
    }
    while (!que.empty()) {
      const int v = que.front();
      que.pop();
      for (auto adj : g[v]) {
        if (erased[adj]) continue;
        if (--cur[adj] < x * deg[adj]) {
          erased[adj] = true;
          que.push(adj);
        }
      }
    }
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      if (!erased[i]) res.push_back(i + 1);
    }
    return res;
  };
  vector<int> ans;
  double lb = -1, ub = 2e5;
  for (int lp = 0; lp < 60; ++lp) {
    const auto mid = (lb + ub) / 2;
    auto tans = check(mid);
    if (tans.empty()) {
      ub = mid;
    } else {
      lb = mid;
      ans = move(tans);
    }
  }
  const int r = ans.size();
  cout << r << endl;
  for (int i = 0; i < r; ++i) {
    cout << ans[i] << " \n"[i + 1 == r];
  }
}
