#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:36777216")
#pragma GCC optimize("O2")
template <class T>
inline void RD(T &);
template <class T>
inline void OT(const T &);
inline int RD() {
  int x;
  RD(x);
  return x;
}
template <class T>
inline T &_RD(T &x) {
  RD(x);
  return x;
}
inline void RC(char &c) { scanf(" %c", &c); }
inline void RS(char *s) { scanf("%s", s); }
template <class T0, class T1>
inline void RD(T0 &x0, T1 &x1) {
  RD(x0), RD(x1);
}
template <class T0, class T1, class T2>
inline void RD(T0 &x0, T1 &x1, T2 &x2) {
  RD(x0), RD(x1), RD(x2);
}
template <class T0, class T1, class T2, class T3>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3) {
  RD(x0), RD(x1), RD(x2), RD(x3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6) {
  RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6);
}
template <class T0, class T1>
inline void OT(T0 &x0, T1 &x1) {
  OT(x0), OT(x1);
}
template <class T0, class T1, class T2>
inline void OT(T0 &x0, T1 &x1, T2 &x2) {
  OT(x0), OT(x1), OT(x2);
}
template <class T0, class T1, class T2, class T3>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3) {
  OT(x0), OT(x1), OT(x2), OT(x3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4) {
  OT(x0), OT(x1), OT(x2), OT(x3), OT(x4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5) {
  OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6) {
  OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5), OT(x6);
}
template <class T>
inline void RST(T &A) {
  memset(A, 0, sizeof(A));
}
template <class T0, class T1>
inline void RST(T0 &A0, T1 &A1) {
  RST(A0), RST(A1);
}
template <class T0, class T1, class T2>
inline void RST(T0 &A0, T1 &A1, T2 &A2) {
  RST(A0), RST(A1), RST(A2);
}
template <class T0, class T1, class T2, class T3>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3) {
  RST(A0), RST(A1), RST(A2), RST(A3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4) {
  RST(A0), RST(A1), RST(A2), RST(A3), RST(A4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5) {
  RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6) {
  RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5), RST(A6);
}
template <class T>
inline void CLR(T &A) {
  A.clear();
}
template <class T0, class T1>
inline void CLR(T0 &A0, T1 &A1) {
  CLR(A0), CLR(A1);
}
template <class T0, class T1, class T2>
inline void CLR(T0 &A0, T1 &A1, T2 &A2) {
  CLR(A0), CLR(A1), CLR(A2);
}
template <class T0, class T1, class T2, class T3>
inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3) {
  CLR(A0), CLR(A1), CLR(A2), CLR(A3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4) {
  CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5) {
  CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6) {
  CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5), CLR(A6);
}
template <class T>
inline void CLR(T &A, int n) {
  for (int i = 0; i < int(n); ++i) CLR(A[i]);
}
template <class T>
inline void FLC(T &A, int x) {
  memset(A, x, sizeof(A));
}
template <class T0, class T1>
inline void FLC(T0 &A0, T1 &A1, int x) {
  FLC(A0, x), FLC(A1, x);
}
template <class T0, class T1, class T2>
inline void FLC(T0 &A0, T1 &A1, T2 &A2) {
  FLC(A0), FLC(A1), FLC(A2);
}
template <class T0, class T1, class T2, class T3>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3) {
  FLC(A0), FLC(A1), FLC(A2), FLC(A3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4) {
  FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5) {
  FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4), FLC(A5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6) {
  FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4), FLC(A5), FLC(A6);
}
template <class T>
inline void SRT(T &A) {
  sort(A.begin(), A.end());
}
template <class T, class C>
inline void SRT(T &A, C B) {
  sort(A.begin(), A.end(), B);
}
const int MOD = 1000000007;
const int INF = 0x7fffffff;
const double PI = acos(-1.0);
const double EPS = 1e-6;
const double OO = 1e15;
template <class T>
inline void checkMin(T &a, const T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkMax(T &a, const T b) {
  if (b > a) a = b;
}
template <class T, class C>
inline void checkMin(T &a, const T b, C c) {
  if (c(b, a)) a = b;
}
template <class T, class C>
inline void checkMax(T &a, const T b, C c) {
  if (c(a, b)) a = b;
}
template <class T>
inline T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <class T>
inline T max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <class T>
inline T sqr(T a) {
  return a * a;
}
template <class T>
inline T cub(T a) {
  return a * a * a;
}
int Ceil(int x, int y) { return (x - 1) / y + 1; }
inline bool _1(int x, int i) { return x & 1 << i; }
inline int _1(int i) { return 1 << i; }
inline int _U(int i) { return _1(i) - 1; };
inline int count_bits(int x) {
  x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
  x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
  x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
  x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
  x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
  return x;
}
template <class T>
inline T low_bit(T x) {
  return x & -x;
}
template <class T>
inline T high_bit(T x) {
  T p = low_bit(x);
  while (p != x) x -= p, p = low_bit(x);
  return p;
}
inline void INC(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
inline int sum(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
inline void DEC(int &a, int b) {
  a -= b;
  if (a < 0) a += MOD;
}
inline int dff(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
inline void MUL(int &a, int b) { a = (long long)a * b % MOD; }
inline int pdt(int a, int b) { return (long long)a * b % MOD; }
template <class T>
inline void RD(T &x) {
  char c;
  for (c = getchar(); c < '0'; c = getchar())
    ;
  x = c - '0';
  for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';
}
int ____Case;
template <class T>
inline void OT(const T &x) {
  printf("%d\n", x);
}
int t, T, L, mb, mdb, ans, d[100005], z[100005], g[100005], o[100005],
    fa[100005], FA[100005], p[100005 * 2], nxt[100005 * 2];
struct d_tree {
  int g, t, l[100005], r[100005], z[100005], a[100005], x[100005], y[100005],
      fa[100005], root[100005];
  void put(int i, int j) {
    if (i && j) z[i] = !z[i], a[i] = !a[i], swap(x[i], y[i]);
  }
  void lazy(int i) { put(l[i], z[i]), put(r[i], z[i]), z[i] = 0; }
  void rt(int i, int j) {
    if (l[i] == j)
      l[i] = r[j], fa[r[j]] = i, r[j] = i;
    else
      r[i] = l[j], fa[l[j]] = i, l[j] = i;
    root[j] = root[i], root[i] = 0;
    if (l[fa[i]] == i)
      l[fa[i]] = j;
    else if (r[fa[i]] == i)
      r[fa[i]] = j;
    fa[j] = fa[i], fa[i] = j;
    x[i] = x[l[i]] + x[r[i]] + a[i], y[i] = y[l[i]] + y[r[i]] + 1 - a[i];
    ;
    x[j] = x[l[j]] + x[r[j]] + a[j], y[j] = y[l[j]] + y[r[j]] + 1 - a[j];
    ;
  }
  void splay(int i, int j) {
    if (root[i]) lazy(i);
    while (!root[i]) {
      lazy(fa[i]);
      lazy(i);
      rt(fa[i], i);
    };
    if (j) {
      root[g = r[i]] = 1;
      r[i] = 0;
      x[i] = x[l[i]] + x[r[i]] + a[i], y[i] = y[l[i]] + y[r[i]] + 1 - a[i];
      ;
    }
  }
  void access(int i) {
    splay(t = i, 1);
    while (fa[i]) {
      splay(t = fa[i], 1);
      r[t] = 1, rt(t, i);
    };
  }
  void cover(int i) {
    access(i);
    splay(L, 0);
    ans += x[r[L]] - y[r[L]];
    put(r[L], 1);
  }
} TREE;
void link(int a, int b) { nxt[++t] = d[a], d[a] = t, p[t] = b; }
int find(int i) { return (FA[i] == i) ? i : FA[i] = find(FA[i]); }
void dfs(int i, int h) {
  z[++t] = i, o[i] = t;
  for (int k = d[i], j = p[k]; k; k = nxt[k], j = p[k])
    if ((h ^ k) != 1) {
      if (o[j]) {
        mb = k;
        for (int I = o[j]; I <= t; I++) g[++T] = z[I];
      } else
        dfs(j, k);
    };
  t--;
}
void dfs2(int i, int h) {
  for (int k = d[i], j = p[k]; k; k = nxt[k], j = p[k])
    if ((h ^ k) != 1 && ((k ^ mb) > 1)) {
      fa[j] = i;
      dfs2(j, k);
    };
}
int main() {
  int n, m, a, b, mdb = 0;
  t = 1;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a, &b);
    link(a, b);
    link(b, a);
  };
  t = 0;
  dfs(1, 0);
  dfs2(g[1], 0);
  for (int i = 0; i < 100005; i++) o[i] = 0;
  for (int i = 1; i <= T; i++) o[g[i]] = i;
  for (int i = 1; i <= n; i++) FA[i] = o[i] ? i : fa[i];
  for (int i = 1; i <= n; i++) find(i);
  for (int i = 1; i <= n; i++) {
    TREE.fa[i] = fa[i];
    TREE.y[i] = TREE.root[i] = 1;
  };
  g[0] = g[T], L = g[T + 1] = g[1];
  ans = n;
  while (m--) {
    scanf("%d%d", &a, &b);
    int Fa = FA[a], Fb = FA[b];
    int d1 = abs(o[Fa] - o[Fb]);
    int g1, g2;
    g1 = g[o[Fa] + 1], g2 = g[o[Fa] - 1];
    TREE.cover(a);
    TREE.cover(b);
    if (T - d1 < d1 || T - d1 == d1 && g1 > g2 ^ o[Fa] > o[Fb]) {
      mdb = !mdb;
      if (mdb)
        ans--;
      else
        ans++;
      TREE.cover(g[T]);
    };
    TREE.access(g[T]);
    int al = TREE.x[g[T]] + mdb == T;
    printf("%d\n", ans + al);
  };
  return 0;
}
