#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
struct edge {
  int v, l, r;
  edge(int v = 0, int l = 0, int r = 0) : v(v), l(l), r(r) {}
  bool operator<(const edge &w) const { return l > w.l; }
};
vector<edge> g[1200000];
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >,
               greater<pair<pair<int, int>, int> > >
    pq;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int x, y, l, r;
    scanf("%d%d%d%d", &x, &y, &l, &r);
    g[x << 1].push_back(edge(y << 1 | 1, l, r));
    g[x << 1 | 1].push_back(edge(y << 1, l, r));
    g[y << 1].push_back(edge(x << 1 | 1, l, r));
    g[y << 1 | 1].push_back(edge(x << 1, l, r));
  }
  for (int i = 2; i <= n * 2 + 1; ++i) sort(g[i].begin(), g[i].end());
  ans = 0x3f3f3f3f;
  pq.push(make_pair(make_pair(0, 0), 2));
  while (!pq.empty()) {
    pair<pair<int, int>, int> pr = pq.top();
    pq.pop();
    pair<int, int> du = pr.first;
    int u = pr.second;
    if (u / 2 == n) ans = min(ans, du.first);
    while (!g[u].empty()) {
      edge i = *g[u].rbegin();
      int v = i.v, l = i.l, r = i.r;
      if (du.second < l) break;
      g[u].pop_back();
      pair<int, int> dv = make_pair(max(l, du.first + 1), r);
      if (dv.first % 2 != v % 2) ++dv.first;
      if (dv.second % 2 != v % 2) --dv.second;
      if (dv.first > dv.second) continue;
      pq.push(make_pair(dv, v));
    }
  }
  printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans);
  return 0;
}
