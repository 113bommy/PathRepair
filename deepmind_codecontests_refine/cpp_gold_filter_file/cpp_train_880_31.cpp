#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
} a[200010];
struct rec {
  int x1, y1, x2, y2, id;
} b[200010];
int seg[200010 << 2], ban[200010], n, m, K, Q;
bool cmp(const node &a, const node &b) { return a.x > b.x; }
bool cmp2(const rec &a, const rec &b) { return a.x1 > b.x1; }
bool cmp3(const node &a, const node &b) { return a.y > b.y; }
bool cmp4(const rec &a, const rec &b) { return a.y1 > b.y1; }
void upd(int x) { seg[x] = max(seg[(x << 1)], seg[(x << 1 | 1)]); }
void modify(int p, int v, int l, int r, int x) {
  if (l == r) {
    seg[x] = min(seg[x], v);
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    modify(p, v, l, mid, (x << 1));
  else
    modify(p, v, mid + 1, r, (x << 1 | 1));
  upd(x);
}
int ask(int ql, int qr, int l, int r, int x) {
  if (ql <= l && r <= qr) return seg[x];
  int mid = (l + r) >> 1, ret = 0;
  if (ql <= mid) ret = max(ret, ask(ql, qr, l, mid, (x << 1)));
  if (mid < qr) ret = max(ret, ask(ql, qr, mid + 1, r, (x << 1 | 1)));
  return ret;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &K, &Q);
  for (int i = 1; i <= K; i++) scanf("%d%d", &a[i].x, &a[i].y);
  for (int i = 1; i <= Q; i++)
    scanf("%d%d%d%d", &b[i].x1, &b[i].y1, &b[i].x2, &b[i].y2), b[i].id = i;
  sort(a + 1, a + K + 1, cmp);
  sort(b + 1, b + Q + 1, cmp2);
  memset(seg, 63, sizeof(seg));
  int j = 0, k = 0;
  for (int i = n; i; i--) {
    while (j + 1 <= K && a[j + 1].x == i) {
      j++;
      modify(a[j].y, a[j].x, 1, m, 1);
    }
    while (k + 1 <= Q && b[k + 1].x1 == i) {
      k++;
      if (ask(b[k].y1, b[k].y2, 1, m, 1) <= b[k].x2) ban[b[k].id] = 1;
    }
  }
  sort(a + 1, a + K + 1, cmp3);
  sort(b + 1, b + Q + 1, cmp4);
  memset(seg, 63, sizeof(seg));
  j = 0, k = 0;
  for (int i = m; i; i--) {
    while (j + 1 <= K && a[j + 1].y == i) {
      j++;
      modify(a[j].x, a[j].y, 1, n, 1);
    }
    while (k + 1 <= Q && b[k + 1].y1 == i) {
      k++;
      if (ask(b[k].x1, b[k].x2, 1, n, 1) <= b[k].y2) ban[b[k].id] = 1;
    }
  }
  for (int i = (1); i <= (Q); i++) printf("%s\n", ban[i] ? "YES" : "NO");
  return 0;
}
