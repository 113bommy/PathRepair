#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long ret = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
  return ret * f;
}
const long long maxn = 1505, INF = 2e9;
long long n;
long long tot = 0, lnk[maxn], nxt[maxn * 2], son[maxn * 2], fa[maxn], num[maxn];
inline void add_edge(long long x, long long y) {
  tot++;
  son[tot] = y;
  nxt[tot] = lnk[x];
  lnk[x] = tot;
}
struct point {
  long long id, x, y;
};
double cross(double x1, double y1, double x2, double y2) {
  return (x1 * y2 - x2 * y1);
}
double compare(point a, point b, point c) {
  return cross((b.x - a.x), (b.y - a.y), (c.x - a.x), (c.y - a.y));
}
point a[maxn];
point s, c;
long long ans[maxn];
void build_tree(long long x) {
  num[x] = 1;
  for (long long i = lnk[x]; i; i = nxt[i])
    if (son[i] != fa[x])
      fa[son[i]] = x, build_tree(son[i]), num[x] += num[son[i]];
}
bool cmp(point a, point b) {
  if (compare(c, a, b) == 0)
    return a.x < b.x;
  else
    return compare(c, a, b) > 0;
}
inline void DFS(long long id, long long p, vector<point> vec) {
  ans[id] = p;
  c = a[id];
  sort(vec.begin(), vec.end(), cmp);
  vector<point> vec_nxt;
  point nxt_s;
  long long j = 0;
  for (long long i = lnk[p]; i; i = nxt[i])
    if (son[i] != fa[p]) {
      vec_nxt.clear();
      nxt_s.y = INF;
      long long tmp = 0;
      for (long long k = j; k < j + num[son[i]] + tmp; k++) {
        if (vec[k].id == id) {
          tmp = 1;
          continue;
        }
        vec_nxt.push_back(vec[k]);
        if (vec[k].y < nxt_s.y) nxt_s = vec[k];
      }
      j += num[son[i]] + tmp;
      DFS(nxt_s.id, son[i], vec_nxt);
    }
}
signed main() {
  n = read();
  for (long long i = 1; i < n; i++) {
    long long x = read(), y = read();
    add_edge(x, y);
    add_edge(y, x);
  }
  build_tree(1);
  vector<point> all_vec;
  all_vec.clear();
  s.y = INF;
  for (long long i = 1; i <= n; i++) {
    a[i].x = read(), a[i].y = read();
    a[i].id = i;
    all_vec.push_back(a[i]);
    if (a[i].y < s.y) s = a[i];
  }
  DFS(s.id, (long long)1, all_vec);
  for (long long i = 1; i <= n; i++) printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}
