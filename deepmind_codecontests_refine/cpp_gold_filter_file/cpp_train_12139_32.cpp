#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n, k, q, ans;
int v[MAXN << 5], ls[MAXN << 5], rs[MAXN << 5];
int tot, rt[MAXN];
int a[MAXN], lst[MAXN];
vector<int> s[MAXN];
inline int read() {
  int tot = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    tot = tot * 10 + c - '0';
    c = getchar();
  }
  return tot * f;
}
inline void modify(int &o, int pre, int l, int r, int p, int w) {
  v[o = ++tot] = v[pre];
  ls[o] = ls[pre];
  rs[o] = rs[pre];
  v[o] += w;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (p <= mid)
    modify(ls[o], ls[pre], l, mid, p, w);
  else
    modify(rs[o], rs[pre], mid + 1, r, p, w);
}
inline int query(int r1, int r2, int l, int r, int x, int y) {
  if (x <= l && r <= y) return v[r1] - v[r2];
  int mid = (l + r) >> 1, res = 0;
  if (x <= mid) res += query(ls[r1], ls[r2], l, mid, x, y);
  if (y > mid) res += query(rs[r1], rs[r2], mid + 1, r, x, y);
  return res;
}
signed main() {
  n = read();
  k = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) {
    if (s[a[i]].size() >= k) lst[i] = s[a[i]][s[a[i]].size() - k];
    s[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) modify(rt[i], rt[i - 1], 0, n, lst[i], 1);
  q = read();
  ans = 0;
  while (q--) {
    int x = read(), y = read();
    int l = (x + ans) % n + 1, r = (y + ans) % n + 1;
    if (l > r) swap(l, r);
    printf("%d\n", ans = query(rt[r], rt[l - 1], 0, n, 0, l - 1));
  }
  return 0;
}
