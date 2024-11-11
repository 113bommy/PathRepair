#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int INF = 1 << 30;
inline int Min(const int &a, const int &b) { return a < b ? a : b; }
inline int Max(const int &a, const int &b) { return a > b ? a : b; }
inline char get(void) {
  static char buf[100000], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 100000, stdin);
    if (p1 == p2) return EOF;
  }
  return *p1++;
}
inline void read(int &x) {
  x = 0;
  static char c;
  for (; !(c >= '0' && c <= '9'); c = get())
    ;
  for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = get())
    ;
}
int n, m, K, a[N], dp[N][20], mn[N];
void Init(int n) {
  mn[0] = -1;
  for (int i = 1; i <= n; i++) {
    mn[i] = ((i & (i - 1)) == 0) ? mn[i - 1] + 1 : mn[i - 1];
    dp[i][0] = a[i];
  }
  for (int j = 1; j <= mn[n]; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      dp[i][j] = Min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }
}
int Rmq(int L, int R) {
  int k = mn[R - L + 1];
  return Min(dp[L][k], dp[R - (1 << k) + 1][k]);
}
int ls[N * 100], rs[N * 100], tag[N * 100], k, Mn[N * 100], rt;
inline int L(int o) {
  if (!ls[o]) ls[o] = ++k;
  return ls[o];
}
inline int R(int o) {
  if (!rs[o]) rs[o] = ++k;
  return rs[o];
}
inline int WorkMn(int l, int r) {
  if (r - l > n) return Rmq(1, n);
  l %= n, r %= n;
  if (l == 0) l = n;
  if (r == 0) r = n;
  if (r >= l) return Rmq(l, r);
  return Min(Rmq(1, r), Rmq(l, n));
}
inline void pushDown(int o, int l, int r) {
  if (tag[o] > 0) {
    tag[L(o)] = tag[R(o)] = tag[o];
    Mn[L(o)] = Mn[R(o)] = tag[o];
    tag[o] = 0;
  } else if (tag[o] == -1) {
    tag[L(o)] = tag[R(o)] = tag[o];
    int mid = (l + r) >> 1;
    Mn[L(o)] = WorkMn(l, mid), Mn[R(o)] = WorkMn(mid + 1, r);
    tag[o] = 0;
  }
}
inline void Set(int &o, int l, int r, int L, int R, int x) {
  if (!o) o = ++k;
  if (l == L && r == R) {
    Mn[o] = tag[o] = x;
    return;
  }
  pushDown(o, l, r);
  int mid = (l + r) >> 1;
  if (R <= mid)
    Set(ls[o], l, mid, L, R, x);
  else if (L > mid)
    Set(rs[o], mid + 1, r, L, R, x);
  else
    Set(ls[o], l, mid, L, mid, x), Set(rs[o], mid + 1, r, mid + 1, R, x);
  Mn[o] = Min(Mn[ls[o]], Mn[rs[o]]);
}
inline int Query(int &o, int l, int r, int L, int R) {
  pushDown(o, l, r);
  if (l == L && r == R) return Mn[o];
  int mid = (l + r) >> 1;
  if (R <= mid)
    return Query(ls[o], l, mid, L, R);
  else if (L > mid)
    return Query(rs[o], mid + 1, r, L, R);
  else
    return Min(Query(ls[o], l, mid, L, mid),
               Query(rs[o], mid + 1, r, mid + 1, R));
}
int main(void) {
  read(n), read(K);
  for (int i = 1; i <= n; i++) read(a[i]);
  Init(n);
  read(m);
  int op, l, r, x;
  rt = k = 1, tag[rt] = -1, Mn[rt] = Rmq(1, n);
  while (m--) {
    read(op), read(l), read(r);
    if (op % 2)
      read(x), Set(rt, 1, n * K, l, r, x);
    else
      printf("%d\n", Query(rt, 1, n * K, l, r));
  }
  return 0;
}
