#include <bits/stdc++.h>
using std::map;
using std::max;
using std::min;
const int N = 300005;
int t[N << 2], lim[N], n, m, l, r, x, opt, y, ans, t2[N << 2];
map<int, int> c, tag;
void setmax(int k, int L, int R, int l, int r, int x) {
  if (L == l && R == r) {
    t[k] = min(t[k], x);
    return;
  }
  int mid = (L + R) >> 1;
  if (r <= mid)
    setmax(k << 1, L, mid, l, r, x);
  else if (l > mid)
    setmax(k << 1 | 1, mid + 1, R, l, r, x);
  else {
    setmax(k << 1, L, mid, l, mid, x);
    setmax(k << 1 | 1, mid + 1, R, mid + 1, r, x);
  }
}
int qry(int k, int l, int r, int x) {
  int ret = t[k];
  while (l < r) {
    int mid = l + r >> 1;
    if (x <= mid)
      r = mid, k = k << 1;
    else
      l = mid + 1, k = k << 1 | 1;
    ret = min(ret, t[k]);
  }
  return ret;
}
void modify(int k, int l, int r, int x, int y) {
  if (l == r) {
    t2[k] = y;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    modify(k << 1, l, mid, x, y);
  else
    modify(k << 1 | 1, mid + 1, r, x, y);
  t2[k] = max(t2[k << 1], t2[k << 1 | 1]);
}
int query(int k, int L, int R, int l, int r) {
  if (L == l && R == r) return t2[k];
  int mid = (L + R) >> 1;
  if (r <= mid)
    return query(k << 1, L, mid, l, r);
  else if (l > mid)
    return query(k << 1 | 1, mid + 1, R, l, r);
  return max(query(k << 1, L, mid, l, mid),
             query(k << 1 | 1, mid + 1, R, mid + 1, r));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= 4 * n; i++) t[i] = 2e9, t2[i] = -1;
  for (int i = 1; i <= n; i++) lim[i] = 2e9 + 1;
  while (m--) {
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d%d%d", &l, &r, &x);
      int now = query(1, 1, n, l, r);
      if (now > x) {
        puts("NO");
        return 0;
      }
      if (now < x) tag[x] = 1, ans |= x;
      setmax(1, 1, n, l, r, x);
    } else {
      scanf("%d%d", &x, &y);
      if (lim[x] == 2e9 + 1) lim[x] = qry(1, 1, n, x);
      modify(1, 1, n, x, y);
    }
  }
  for (int i = 1; i <= n; i++)
    if (lim[i] == 2e9 + 1) lim[i] = qry(1, 1, n, i);
  for (int i = 1; i <= n; i++) c[lim[i]]++;
  for (auto i : tag)
    if (!c[i.first]) {
      puts("NO");
      return 0;
    }
  printf("YES\n");
  if (c[2e9] >= 2) {
    for (int i = 1; i <= n; i++)
      if (lim[i] == 2e9) {
        lim[i] = 1e9, c[2e9]--;
        if (c[2e9] == 0) lim[i] = (1 << 29) - 1;
      }
    for (int i = 1; i <= n; i++) printf("%d ", lim[i]);
    return 0;
  }
  int orresult = 0;
  for (int i = 1; i <= n; i++) {
    if (lim[i] == 0 || lim[i] == 2e9) continue;
    c[lim[i]]--;
    if (c[lim[i]]) {
      int temp = lim[i], pow = 0;
      while (temp) pow++, temp /= 2;
      lim[i] = (1 << (pow - 1)) - 1;
    }
    ans |= lim[i];
  }
  int tobe = 0;
  for (int cur = 29; cur >= 0; cur--) {
    if (orresult & (1 << cur)) continue;
    if (tobe + (1 << cur) > 1e9) continue;
    tobe += (1 << cur);
  }
  for (int i = 1; i <= n; i++) {
    if (lim[i] == 2e9)
      printf("%d ", tobe);
    else
      printf("%d ", lim[i]);
  }
}
