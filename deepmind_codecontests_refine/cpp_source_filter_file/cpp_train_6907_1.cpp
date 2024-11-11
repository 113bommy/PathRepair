#include <bits/stdc++.h>
using namespace std;
long long inf = 1e9, mod = 1e9 + 7;
struct point {
  long long first, second;
  bool operator<(const point &b) const {
    if (second != b.second) return second < b.second;
    return first < b.first;
  }
};
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long n, m;
  cin >> n >> m;
  vector<vector<pair<long long, long long>>> gr(
      n, vector<pair<long long, long long>>());
  vector<long long> d(n, inf), p(n, -1);
  gr.resize(n, vector<pair<long long, long long>>(m));
  for (long long i = 0; i < m; ++i) {
    long long a, b, w;
    cin >> a >> b >> w;
    gr[a - 1].emplace_back(b - 1, w);
    gr[b - 1].emplace_back(a - 1, w);
  }
  set<point> s;
  d[0] = 0;
  s.insert({0, 0});
  while (!s.empty()) {
    auto v = *s.begin();
    s.erase(*s.begin());
    for (auto to : gr[v.first]) {
      if (d[to.first] > d[v.first] + to.second) {
        s.erase({to.first, d[to.first]});
        d[to.first] = d[v.first] + to.second;
        p[to.first] = v.first;
        s.insert({to.first, d[to.first]});
      }
    }
  }
  if (d[n - 1] == inf) {
    cout << -1;
    return 0;
  }
  stack<long long> ans;
  long long ind = n - 1;
  while (ind != -1) {
    ans.push(ind + 1);
    ind = p[ind];
  }
  while (!ans.empty()) {
    cout << ans.top() << " ";
    ans.pop();
  }
}
