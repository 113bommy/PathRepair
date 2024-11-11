#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int nmax = 1e5 + 5;
int n, m;
vector<pair<int, int> > inc, out;
struct adj_v {
  vector<pair<int, int> > con;
};
adj_v graph[nmax];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (b) {
      inc.emplace_back(a, i);
    } else {
      out.emplace_back(a, i);
    }
  }
  sort(inc.begin(), inc.end());
  sort(out.begin(), out.end());
  int o_idx = 0;
  int ifill = 0, jfill = 1;
  for (int i = 0; i < n - 1; ++i) {
    while (o_idx < out.size() && out[o_idx].first < inc[i].first) {
      if (o_idx + 1 > (i * (i + 1)) / 2 - i) {
        cout << -1 << endl;
        return 0;
      }
      while (jfill >= ifill) {
        ++ifill;
        jfill = 1;
      }
      graph[jfill].con.emplace_back(ifill, out[o_idx].second);
      ++jfill;
      ++o_idx;
    }
    graph[0].con.emplace_back(i + 1, inc[i].second);
  }
  while (o_idx < out.size()) {
    while (jfill >= ifill) {
      ++ifill;
      jfill = 1;
    }
    graph[jfill].con.emplace_back(ifill, out[o_idx].second);
    ++o_idx;
    ++jfill;
  }
  vector<pair<int, pair<int, int> > > res;
  for (int i = 0; i < n; ++i) {
    for (auto cur : graph[i].con) {
      res.emplace_back(cur.second, make_pair(i + 1, cur.first + 1));
    }
  }
  sort(res.begin(), res.end());
  for (auto cur : res) {
    printf("%d %d\n", cur.second.first, cur.second.second);
  }
  return 0;
}
