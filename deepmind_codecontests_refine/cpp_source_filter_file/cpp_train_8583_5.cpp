#include <bits/stdc++.h>
using namespace std;
struct info {
  long long int x;
  int y, z;
  info() { x = y = z = 0; }
  info(long long int xx, int yy = 0, int zz = 0) {
    x = xx;
    y = yy;
    z = zz;
  }
  bool operator<(const info &b) const { return x < b.x; }
};
bool cmpx(info x, info y) { return x.x < y.x; }
bool cmpy(info x, info y) { return x.y < y.y; }
long long int n, d;
info h[100000 + 100];
long long int p = 0;
info pnt[3 * 100000 + 100];
map<long long int, int> mp;
int par[100000 + 100];
info segTree[10 * 100000 + 100];
void update(int node, int st, int ed, int p, info v) {
  if (ed < p || st > p) return;
  if (st == p && ed == p) {
    segTree[node] = v;
    return;
  }
  int lft = node << 1, rgt = (node << 1) + 1, md = (st + ed) >> 1;
  ;
  update(lft, st, md, p, v);
  update(rgt, md + 1, ed, p, v);
  segTree[node] = max(segTree[lft], segTree[rgt]);
}
info query(int node, int st, int ed, int l, int r) {
  if (l > r || ed < l || st > r) return info();
  if (st >= l && ed <= r) return segTree[node];
  int lft = node << 1, rgt = (node << 1) + 1, md = (st + ed) >> 1;
  ;
  return max(query(lft, st, md, l, r), query(rgt, md + 1, ed, l, r));
}
int main() {
  scanf("%I64d %I64d", &n, &d);
  for (int i = 1; i <= n; i++) scanf("%I64d", &h[i].x);
  for (int i = 1; i <= n; i++) {
    if (!mp[h[i].x]) {
      p++;
      pnt[p].x = h[i].x;
      pnt[p].y = p;
      mp[h[i].x] = 1;
    }
    if (h[i].x - d >= 0 && !mp[h[i].x - d]) {
      p++;
      pnt[p].x = h[i].x - d;
      pnt[p].y = p;
      mp[h[i].x - d] = 1;
    }
    if (!mp[h[i].x + d]) {
      p++;
      pnt[p].x = h[i].x + d;
      pnt[p].y = p;
      mp[h[i].x + d] = 1;
    }
  }
  sort(pnt + 1, pnt + p + 1, cmpx);
  for (int i = 1; i <= p; i++) mp[pnt[i].x] = i;
  for (int i = 1; i <= n; i++) h[i].z = mp[h[i].x];
  for (int i = 1; i <= n; i++) {
    info ans, a, b;
    a = query(1, 1, p, 1, mp[h[i].x - d]);
    b = query(1, 1, p, mp[h[i].x + d], p);
    ans = max(a, b);
    ans.x++;
    par[i] = ans.y;
    ans.y = i;
    update(1, 1, p, h[i].z, ans);
  }
  long long int ans = segTree[1].x;
  int last = segTree[1].y;
  stack<int> stk;
  while (last) {
    stk.push(last);
    last = par[last];
  }
  printf("%I64d\n", ans);
  while (!stk.empty()) {
    printf("%d", stk.top());
    stk.pop();
    if (!stk.empty()) printf(" ");
  }
  printf("\n");
  return 0;
}
