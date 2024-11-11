#include <bits/stdc++.h>
using namespace std;
struct E {
  int x, y, w;
  E() {}
  E(int x, int y, int w) : x(x), y(y), w(w) {}
  bool operator<(const E& rhs) const { return w < rhs.w; }
};
int n, m, q;
vector<E> edge;
int sz[500010], p[500010];
int finds(int x) { return p[x] == x ? x : finds(p[x]); }
stack<pair<int, int> > s;
bool Union(int x, int y, bool flag) {
  int a = finds(x), b = finds(y);
  if (a == b) return 0;
  if (sz[a] < sz[b]) swap(a, b);
  p[b] = a, sz[a] += sz[b];
  if (flag) s.push(pair<int, int>(a, b));
  return 1;
}
void undo() {
  while (!s.empty()) {
    pair<int, int> tmp = s.top();
    s.pop();
    int x = tmp.first, y = tmp.second;
    p[y] = y, sz[x] -= sz[y];
  }
}
bool ans[500010];
struct Q {
  int x, y, id;
  Q() {}
  Q(int x, int y, int id) : x(x), y(y), id(id) {}
};
vector<Q> que[500010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    edge.push_back(E(x, y, w));
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int sz;
    scanf("%d", &sz);
    for (int j = 1; j <= sz; j++) {
      int ii;
      scanf("%d", &ii);
      ii--;
      que[edge[ii].w].push_back(Q(edge[ii].x, edge[ii].y, i));
    }
  }
  sort(edge.begin(), edge.end());
  int cur = 0;
  for (int i = 1; i <= n; i++) sz[i] = 1, p[i] = i;
  for (int i = 1; i < 500010; i++) {
    int pre_id = -1;
    for (auto e : que[i]) {
      if (e.id != pre_id) undo(), pre_id = e.id;
      if (!Union(e.x, e.y, 1)) ans[e.id] = 1;
    }
    while (!s.empty()) s.pop();
    while (cur < edge.size() && edge[cur].w <= i)
      Union(edge[cur].x, edge[cur].y, 0), cur++;
  }
  for (int i = 1; i <= q; i++) puts(ans[i] ? "NO" : "YES");
  return 0;
}
