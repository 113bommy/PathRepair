#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int inf = 1 << 29;
int n, m, p, q;
bool ans[maxn << 1];
struct point {
  int x, y;
} po[maxn << 1];
struct rect {
  int lx, ly, rx, ry, id;
} re[maxn << 1];
bool cx(const point& a, const point& b) { return a.x < b.x; }
bool cy(const point& a, const point& b) { return a.y < b.y; }
bool cmpy(const rect& a, const rect& b) { return a.ry < b.ry; }
bool cmpx(const rect& a, const rect& b) { return a.rx < b.rx; }
int mi[maxn << 2];
void build(int l, int r, int rt) {
  mi[rt] = 0;
  if (l == r) return;
  int m = (l + r) >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
}
void modify(int p, int v, int l, int r, int rt) {
  if (l == r) {
    mi[rt] = v;
    return;
  }
  int m = (l + r) >> 1;
  if (p <= m)
    modify(p, v, l, m, rt << 1);
  else
    modify(p, v, m + 1, r, rt << 1 | 1);
  mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
}
int query(int ql, int qr, int l, int r, int rt) {
  if (ql <= l && r <= qr) return mi[rt];
  int m = (l + r) >> 1, res = inf;
  if (ql <= m) res = min(res, query(ql, qr, l, m, rt << 1));
  if (qr > m) res = min(res, query(ql, qr, m + 1, r, rt << 1 | 1));
  return res;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &p, &q);
  for (int i = 0; i < p; i++) {
    scanf("%d%d", &po[i].x, &po[i].y);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d%d", &re[i].lx, &re[i].ly, &re[i].rx, &re[i].ry);
    re[i].id = i;
  }
  sort(po, po + p, cy);
  sort(re, re + q, cmpy);
  int pos = 0;
  build(1, n, 1);
  for (int i = 0; i < q; i++) {
    while (pos < p && po[pos].y <= re[i].ry) {
      modify(po[pos].x, po[pos].y, 1, n, 1);
      pos++;
    }
    if (query(re[i].lx, re[i].rx, 1, n, 1) >= re[i].ly) ans[re[i].id] = 1;
  }
  sort(po, po + p, cx);
  sort(re, re + q, cmpx);
  pos = 0;
  build(1, m, 1);
  for (int i = 0; i < q; i++) {
    while (pos < p && po[pos].x <= re[i].rx) {
      modify(po[pos].y, po[pos].x, 1, m, 1);
      pos++;
    }
    if (query(re[i].ly, re[i].ry, 1, m, 1) >= re[i].lx) ans[re[i].id] = 1;
  }
  for (int i = 0; i < q; i++)
    if (ans[i])
      puts("YES");
    else
      puts("NO");
}
