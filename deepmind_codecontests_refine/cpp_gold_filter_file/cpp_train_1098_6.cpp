#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
struct unit {
  int x, y1, y2;
};
struct unit a[100010], b[100010];
struct node {
  int val, ta, tc, tag, s;
};
struct node t[4000010];
int n, m, nt;
bool operator<(unit A, unit B) {
  return A.x < B.x || (A.x == B.x && A.y1 > B.y1);
}
void build(int p, int l, int r) {
  t[p].tag = -1;
  t[p].tc = 1;
  if (l == r) {
    t[p].val = (l == 1);
    return;
  }
  build(p * 2, l, (l + r) / 2);
  build(p * 2 + 1, (l + r) / 2 + 1, r);
}
void push_down(int p, int l, int r) {
  int i;
  i = p * 2;
  t[i].val = (t[i].val * t[p].tc + t[p].ta) % mod;
  t[i].tc *= t[p].tc;
  t[i].ta = (t[i].ta * t[p].tc + t[p].ta) % mod;
  i = p * 2 + 1;
  t[i].val = (t[i].val * t[p].tc + t[p].ta) % mod;
  t[i].tc *= t[p].tc;
  t[i].ta = (t[i].ta * t[p].tc + t[p].ta) % mod;
  t[p].tc = 1;
  t[p].ta = 0;
  if (t[p].tag == 1) {
    i = p * 2;
    t[i].tag = 1;
    t[i].s = (l + r) / 2 - l + 1;
    i = p * 2 + 1;
    t[i].tag = 1;
    t[i].s = r - (l + r) / 2;
  } else if (t[p].tag == 0) {
    i = p * 2;
    t[i].tag = 0;
    t[i].s = 0;
    i = p * 2 + 1;
    t[i].tag = 0;
    t[i].s = 0;
  }
  t[p].tag = -1;
}
void change_zero(int p, int l, int r, int x, int y, int z) {
  if (l > y || r < x) return;
  if (l >= x && r <= y) {
    if (z == 1) {
      t[p].tag = 1;
      t[p].s = r - l + 1;
    } else {
      t[p].tag = 0;
      t[p].s = 0;
    }
    return;
  }
  push_down(p, l, r);
  change_zero(p * 2, l, (l + r) / 2, x, y, z);
  change_zero(p * 2 + 1, (l + r) / 2 + 1, r, x, y, z);
  t[p].s = t[p * 2].s + t[p * 2 + 1].s;
}
void change_cover(int p, int l, int r, int x, int y) {
  if (l > y || r < x) return;
  if (l >= x && r <= y) {
    t[p].tc = 0;
    t[p].ta = 0;
    t[p].val = 0;
    return;
  }
  push_down(p, l, r);
  change_cover(p * 2, l, (l + r) / 2, x, y);
  change_cover(p * 2 + 1, (l + r) / 2 + 1, r, x, y);
  t[p].s = t[p * 2].s + t[p * 2 + 1].s;
}
void change_add(int p, int l, int r, int x, int y, int z) {
  if (l > y || r < x) return;
  if (l >= x && r <= y) {
    t[p].ta = (t[p].ta + z) % mod;
    t[p].val = (t[p].val + z) % mod;
    return;
  }
  push_down(p, l, r);
  change_add(p * 2, l, (l + r) / 2, x, y, z);
  change_add(p * 2 + 1, (l + r) / 2 + 1, r, x, y, z);
  t[p].s = t[p * 2].s + t[p * 2 + 1].s;
}
int query_zero(int p, int l, int r, int x) {
  int ret = 0;
  if (r < x || t[p].s == 0) return m + 1;
  if (l == r) return l >= x ? l : m + 1;
  push_down(p, l, r);
  ret = query_zero(p * 2, l, (l + r) / 2, x);
  if (ret < m + 1) return ret;
  return query_zero(p * 2 + 1, (l + r) / 2 + 1, r, x);
}
int query_val(int p, int l, int r, int x) {
  if (l == r) return t[p].val;
  push_down(p, l, r);
  if (x <= (l + r) / 2)
    return query_val(p * 2, l, (l + r) / 2, x);
  else
    return query_val(p * 2 + 1, (l + r) / 2 + 1, r, x);
}
int main() {
  int i, j, j1, k, last, last1, x, x1, y1, x2, y2;
  scanf("%d%d%d", &n, &m, &nt);
  for (i = 1; i <= nt; i++) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    a[i] = (unit){x1, y1, y2};
    b[i] = (unit){x2, y1, y2};
  }
  a[nt + 1] = (unit){1, m + 1, m + 1};
  b[nt + 1] = (unit){n, m + 1, m + 1};
  b[nt + 2] = (unit){0, 2, m};
  m++;
  nt++;
  build(1, 1, m);
  sort(a + 1, a + nt + 1);
  sort(b + 1, b + nt + 1 + 1);
  j = last = 1;
  j1 = last1 = 1;
  for (i = 1; i <= n; i++) {
    last1 = j1;
    while (j1 <= nt + 1 && b[j1].x == i - 1) j1++;
    for (k = last1; k < j1; k++) change_zero(1, 1, m, b[k].y1, b[k].y2, 0);
    last = j;
    while (j <= nt && a[j].x == i) j++;
    for (k = last; k < j; k++) {
      change_zero(1, 1, m, a[k].y1, a[k].y2, 1);
      change_cover(1, 1, m, a[k].y1, a[k].y2);
    }
    for (k = last1; k < j1; k++) {
      x = query_zero(1, 1, m, b[k].y1);
      change_add(1, 1, m, b[k].y1, x - 1, query_val(1, 1, m, b[k].y1 - 1));
    }
  }
  printf("%d\n", query_val(1, 1, m, m - 1));
  return 0;
}
