#include <bits/stdc++.h>
using namespace std;
int read() {
  int out = 0;
  char c;
  while (!isdigit(c = getchar()))
    ;
  for (; isdigit(c); c = getchar()) out = out * 10 + c - '0';
  return out;
}
const int INF = 1e9 + 1;
struct UFS {
  int odd;
  vector<int> f, s;
  struct Change {
    int x, y, s;
  };
  stack<Change> c;
  void init(int n) {
    f.resize(n + 1, 0);
    s.resize(n + 1, 1);
    for (int i = 1; i <= n; ++i) f[i] = i;
    odd = n;
  }
  int find(int x) { return x == f[x] ? x : find(f[x]); }
  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (s[x] < s[y]) swap(x, y);
    c.push({x, y, s[x]});
    if ((s[x] & 1) && (s[y] & 1)) odd -= 2;
    s[x] += s[y];
    f[y] = x;
  }
  void rollback(int x) {
    while ((int)c.size() > x) {
      Change t = c.top();
      c.pop();
      if ((t.s & 1) && (s[t.y] & 1)) odd += 2;
      s[t.x] = t.s;
      f[t.y] = t.y;
    }
  }
  int status() const { return c.size(); }
} ufs;
struct Edge {
  int u, v, w, id;
  bool operator<(const Edge& b) const { return w < b.w; }
  bool in(int x1, int y1, int x2, int y2) const {
    return id >= x1 && id <= x2 && w >= y1 && w <= y2;
  }
};
vector<int> ans;
void solve(int xl, int xr, int yl, int yr, vector<Edge>& e) {
  if (xl > xr) return;
  if (yl == yr) {
    for (int i = xl; i <= xr; ++i) ans[i] = yl;
    return;
  }
  int ver1 = ufs.status();
  int xmid = (xl + xr) >> 1;
  int p;
  for (p = 0; p < (int)e.size() && e[p].w < yl; ++p)
    if (e[p].in(xl, 0, xmid, yl - 1)) ufs.merge(e[p].u, e[p].v);
  int ver2 = ufs.status();
  for (int i = p; i < (int)e.size(); ++i) {
    if (e[i].in(0, yl, xmid, yr)) {
      ufs.merge(e[i].u, e[i].v);
      if (!ufs.odd) {
        ans[xmid] = e[i].w;
        break;
      }
    }
  }
  vector<Edge> le, re;
  for (auto x : e)
    if (x.in(0, 0, xr, ans[xmid]) && !x.in(0, 0, xmid, yl - 1)) re.push_back(x);
  for (auto x : e)
    if (x.in(0, 0, xmid - 1, yr) && !x.in(0, 0, xl - 1, ans[xmid] - 1))
      le.push_back(x);
  ufs.rollback(ver2);
  solve(xmid + 1, xr, yl, ans[xmid], re);
  if (ans[xmid] < INF) {
    ufs.rollback(ver1);
    for (int i = p; i < (int)e.size(); ++i)
      if (e[i].in(0, yl, xl - 1, ans[xmid] - 1)) ufs.merge(e[i].u, e[i].v);
    solve(xl, xmid - 1, ans[xmid], yr, le);
  }
  ufs.rollback(ver1);
}
int main() {
  int n = read();
  int m = read();
  vector<Edge> e;
  for (int i = 0; i < m; ++i) {
    int u = read();
    int v = read();
    int w = read();
    e.push_back({u, v, w, i});
  }
  sort(e.begin(), e.end());
  ans.resize(m, INF);
  ufs.init(n);
  solve(0, m - 1, 1, INF, e);
  for (auto x : ans) printf("%d\n", x == INF ? -1 : x);
  return 0;
}
