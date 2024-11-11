#include <bits/stdc++.h>
using namespace std;
int to[128];
struct SegmentTree {
  int c[200002 * 4];
  void upd(int k, int l, int r, int x, int y) {
    c[k] += y;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (x <= mid)
      upd(k * 2, l, mid, x, y);
    else
      upd(k * 2 + 1, mid + 1, r, x, y);
  }
  int count(int k, int l, int r, int L, int R) {
    if (L <= l && r <= R) return c[k];
    int res = 0, mid = (l + r) >> 1;
    if (L <= mid) res += count(k * 2, l, mid, L, R);
    if (R > mid) res += count(k * 2 + 1, mid + 1, r, L, R);
    return res;
  }
  int left(int k, int l, int r) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (c[k * 2])
      return left(k * 2, l, mid);
    else
      return left(k * 2 + 1, mid + 1, r);
  }
  int right(int k, int l, int r) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (c[k * 2 + 1])
      return right(k * 2 + 1, mid + 1, r);
    else
      return left(k * 2, l, mid);
  }
} st[3];
int n, q;
char s[200002];
int getAns(int i) {
  int res = st[i].c[1], j = (i + 1) % 3, k = (i + 2) % 3;
  if (!st[k].c[1])
    return res;
  else if (!st[j].c[1])
    return 0;
  else {
    int l = st[j].right(1, 1, n), r = st[k].right(1, 1, n);
    if (l < r) res -= st[i].count(1, 1, n, l, r);
    l = st[k].left(1, 1, n), r = st[j].left(1, 1, n);
    if (l < r) res -= st[i].count(1, 1, n, l, r);
    return res;
  }
}
int main() {
  to['R'] = 0, to['S'] = 1, to['P'] = 2;
  scanf("%d%d%s", &n, &q, s + 1);
  for (int i = 1; i <= n; ++i) st[to[s[i]]].upd(1, 1, n, i, 1);
  printf("%d\n", getAns(0) + getAns(1) + getAns(2));
  while (q--) {
    int p;
    scanf("%d", &p);
    char c = getchar();
    while (c != 'R' && c != 'S' && c != 'P') c = getchar();
    st[to[s[p]]].upd(1, 1, n, p, -1);
    st[to[c]].upd(1, 1, n, p, 1);
    s[p] = c;
    printf("%d\n", getAns(0) + getAns(1) + getAns(2));
  }
}
