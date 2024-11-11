#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
struct quji {
  int l, r, mid, laz, mn, ct, tag;
  long long he;
} c[200012 << 2];
struct node {
  int l, r, wh;
} b[200012];
int n, a[200012], m, s1[200012], tot1, s2[200012], tot2;
long long ans[200012];
inline bool cmp(node n1, node n2) { return n1.r < n2.r; }
void pushup(int ind) {
  c[ind].mn = min(c[ind << 1].mn, c[ind << 1 | 1].mn);
  c[ind].ct = 0;
  if (c[ind << 1].mn == c[ind].mn) c[ind].ct += c[ind << 1].ct;
  if (c[ind << 1 | 1].mn == c[ind].mn) c[ind].ct += c[ind << 1 | 1].ct;
}
void bt(int ind, int l, int r) {
  c[ind].l = l;
  c[ind].r = r;
  c[ind].mid = (l + r) >> 1;
  if (l == r) {
    c[ind].mn = l - 1;
    c[ind].ct = 1;
    return;
  }
  bt(ind << 1, l, c[ind].mid);
  bt(ind << 1 | 1, c[ind].mid + 1, r);
  pushup(ind);
}
void pushdown(int ind) {
  c[ind << 1].mn += c[ind].laz;
  c[ind << 1].laz += c[ind].laz;
  c[ind << 1 | 1].mn += c[ind].laz;
  c[ind << 1 | 1].laz += c[ind].laz;
  c[ind].laz = 0;
  if (c[ind << 1].mn == c[ind].mn) {
    c[ind << 1].he += 1ll * c[ind].tag * c[ind << 1].ct;
    c[ind << 1].tag += c[ind].tag;
  }
  if (c[ind << 1 | 1].mn == c[ind].mn) {
    c[ind << 1 | 1].he += 1ll * c[ind].tag * c[ind << 1 | 1].ct;
    c[ind << 1 | 1].tag += c[ind].tag;
  }
  c[ind].tag = 0;
}
void chng(int ind, int l, int r, int x) {
  if (l > r) return;
  if (l <= c[ind].l && c[ind].r <= r) {
    c[ind].mn += x;
    c[ind].laz += x;
    return;
  }
  pushdown(ind);
  if (l <= c[ind].mid) chng(ind << 1, l, r, x);
  if (r > c[ind].mid) chng(ind << 1 | 1, l, r, x);
  pushup(ind);
}
long long ask(int ind, int l, int r) {
  if (l <= c[ind].l && c[ind].r <= r) return c[ind].he;
  long long ret = 0;
  pushdown(ind);
  if (l <= c[ind].mid) ret += ask(ind << 1, l, r);
  if (r > c[ind].mid) ret += ask(ind << 1 | 1, l, r);
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &b[i].l, &b[i].r), b[i].wh = i;
  sort(b + 1, b + 1 + m, cmp);
  int R = 0;
  bt(1, 1, n);
  for (int i = 1; i <= m; i++) {
    while (R < b[i].r) {
      R++;
      chng(1, 1, n, -1);
      while (tot1 && a[s1[tot1]] < a[R]) {
        chng(1, s1[tot1 - 1] + 1, s1[tot1], a[R] - a[s1[tot1]]);
        tot1--;
      }
      s1[++tot1] = R;
      while (tot2 && a[s2[tot2]] > a[R]) {
        chng(1, s2[tot2 - 1] + 1, s2[tot2], a[s2[tot2]] - a[R]);
        tot2--;
      }
      s2[++tot2] = R;
      c[1].tag++;
      c[1].he += c[1].ct;
    }
    ans[b[i].wh] = ask(1, b[i].l, b[i].r);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
