#include <bits/stdc++.h>
using namespace std;
struct P {
  int i;
  int p;
  bool operator<(const P& o) const { return p < o.p; }
};
int main() {
  ios::sync_with_stdio(false);
  unordered_map<int, vector<P>> groups;
  int n, w, h;
  cin >> n >> w >> h;
  vector<int> at(n);
  for (int i = 0; i < n; ++i) {
    int g, p, t;
    cin >> g >> p >> t;
    groups[p - t].push_back(P{i, (g == 1 ? p : -p)});
  }
  for (auto& gg : groups) {
    auto& g = gg.second;
    sort(g.begin(), g.end());
    int s = count_if(g.begin(), g.end(), [](const P& x) { return x.p < 0; });
    for (int i = 0; i < g.size(); ++i) at[g[i].i] = g[(i + s) % g.size()].p;
  }
  for (int p : at) {
    if (p < 0)
      cout << w << ' ' << -p << '\n';
    else
      cout << p << ' ' << p << '\n';
  }
  return 0;
}
