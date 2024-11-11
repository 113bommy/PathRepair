#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &s) {
  s = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) s = ((s + (s << 2)) << 1) + ch - '0', ch = getchar();
}
int n, A[310000], m, a[310000];
struct Point {
  int Max, l, r;
  long long lval, rval;
} t[310000 << 2];
inline void MakeNew(int now, long long val) {
  t[now].lval = t[now].rval = val;
  if (val) t[now].l = t[now].r = t[now].Max = 1;
}
inline bool Sign(long long t) { return t > 0; }
inline void Update(int now, int l, int r) {
  int mid = l + r >> 1, sizl = mid - l + 1, sizr = r - mid;
  t[now].l = t[now << 1].l, t[now].lval = t[now << 1].lval;
  t[now].r = t[now << 1 | 1].r, t[now].rval = t[now << 1 | 1].rval;
  t[now].Max = max(t[now << 1].Max, t[now << 1 | 1].Max);
  if (t[now << 1].rval && t[now << 1 | 1].lval &&
      Sign(t[now << 1].rval) >= Sign(t[now << 1 | 1].lval)) {
    t[now].Max = max(t[now].Max, t[now << 1].r + t[now << 1 | 1].l);
    if (t[now << 1].Max == sizl) t[now].l += t[now << 1 | 1].l;
    if (t[now << 1 | 1].Max == sizr) t[now].r += t[now << 1].r;
  }
}
inline void Build(int now, int l, int r) {
  if (l == r) return (void)(MakeNew(now, a[l]));
  int mid = l + r >> 1;
  Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r), Update(now, l, r);
}
inline void Modify(int now, int l, int r, int x, int val) {
  if (l == r) return (void)(MakeNew(now, t[now].lval + val));
  int mid = l + r >> 1;
  if (mid < x)
    Modify(now << 1 | 1, mid + 1, r, x, val);
  else
    Modify(now << 1, l, mid, x, val);
  Update(now, l, r);
}
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) read(A[i]);
  for (int i = 1; i < n; ++i) a[i] = A[i + 1] - A[i];
  if (n > 1) Build(1, 1, n - 1);
  read(m);
  for (int i = 1, l, r, d; i <= m; ++i) {
    read(l), read(r), read(d);
    if (n == 1) {
      puts("1");
      continue;
    }
    if (r != n) Modify(1, 1, n - 1, r, -d);
    if (l != 1) Modify(1, 1, n - 1, l - 1, d);
    printf("%d\n", t[1].Max + 1);
  }
  return 0;
}
