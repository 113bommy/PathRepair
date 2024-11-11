#include <bits/stdc++.h>
using namespace std;
void getint(int &v) {
  char ch, fu = 0;
  for (ch = '*'; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') fu = 1, ch = getchar();
  for (v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = v * 10 + ch - '0';
  if (fu) v = -v;
}
const int INF = 1e9 + 10;
map<int, int> M;
int n, k, d, a[500010], ansL, ans, N, le, re, sm[500010], bi[500010], U, Le, Ri,
    Rt, tp[500010];
struct node {
  int A, B, C, D, tagmn, tagmx;
} T[1000010];
void pushup(int rt) {
  T[rt].A = min(T[rt << 1].A, T[rt << 1 | 1].A);
  T[rt].B = min(T[rt << 1].B, T[rt << 1 | 1].B);
  T[rt].C = min(T[rt << 1].C, T[rt << 1 | 1].C);
  T[rt].D = min(T[rt << 1].D, T[rt << 1 | 1].D);
}
void build(int l, int r, int rt) {
  T[rt].tagmn = T[rt].tagmx = INF;
  if (l == r) {
    T[rt].A = T[rt].B = T[rt].C = T[rt].D = 0;
    return;
  }
  int m = l + r >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  pushup(rt);
}
void TAGMN(int rt, int x) {
  T[rt].tagmn = x;
  T[rt].B = -x + T[rt].D;
  T[rt].A = -x + T[rt].C;
}
void TAGMX(int rt, int x) {
  T[rt].tagmx = x;
  T[rt].C = x + T[rt].D;
  T[rt].A = x + T[rt].B;
}
void pushdown(int rt) {
  if (T[rt].tagmn < INF) {
    TAGMN(rt << 1, T[rt].tagmn);
    TAGMN(rt << 1 | 1, T[rt].tagmn);
    T[rt].tagmn = INF;
  }
  if (T[rt].tagmx < INF) {
    TAGMX(rt << 1, T[rt].tagmx);
    TAGMX(rt << 1 | 1, T[rt].tagmx);
    T[rt].tagmx = INF;
  }
}
void updMN(int l, int r, int rt, int L, int R, int x) {
  if (l >= L && r <= R) {
    TAGMN(rt, x);
    return;
  }
  pushdown(rt);
  int m = l + r >> 1;
  if (L <= m) updMN(l, m, rt << 1, L, R, x);
  if (R > m) updMN(m + 1, r, rt << 1 | 1, L, R, x);
  pushup(rt);
}
void updMX(int l, int r, int rt, int L, int R, int x) {
  if (l >= L && r <= R) {
    TAGMX(rt, x);
    return;
  }
  pushdown(rt);
  int m = l + r >> 1;
  if (L <= m) updMX(l, m, rt << 1, L, R, x);
  if (R > m) updMX(m + 1, r, rt << 1 | 1, L, R, x);
  pushup(rt);
}
void que(int l, int r, int rt, int L, int R) {
  if (l >= L && r <= R) {
    if (T[rt].A <= U) {
      if (l < Le) Le = l, Ri = r, Rt = rt;
    }
    return;
  }
  pushdown(rt);
  int m = l + r >> 1;
  if (L <= m) que(l, m, rt << 1, L, R);
  if (R > m) que(m + 1, r, rt << 1 | 1, L, R);
}
int fnd(int l, int r, int rt) {
  if (l == r) return l;
  pushdown(rt);
  int m = l + r >> 1;
  if (T[rt << 1].A <= U)
    return fnd(l, m, rt << 1);
  else
    return fnd(m + 1, r, rt << 1 | 1);
}
void doit() {
  M.clear();
  build(1, n, 1);
  le = 1;
  for (int r = 1; r <= n; ++r) {
    U = r + k;
    if (M.find(a[r]) != M.end()) le = max(le, M[a[r]] + 1);
    M[a[r]] = r;
    sm[r] = bi[r] = r - 1;
    while (sm[r] && a[sm[r]] > a[r]) sm[r] = sm[sm[r]];
    while (bi[r] && a[bi[r]] < a[r]) bi[r] = bi[bi[r]];
    updMN(1, n, 1, sm[r] + 1, r, a[r]);
    updMX(1, n, 1, bi[r] + 1, r, a[r]);
    Le = n + 1;
    que(1, n, 1, le, r);
    if (Le <= n) {
      int t = fnd(Le, Ri, Rt);
      if (r - t + 1 > ans || r - t + 1 == ans && t + re < ansL) {
        ans = r - t + 1;
        ansL = t + re;
      }
    }
  }
}
int main() {
  cin >> n >> k >> d;
  for (int i = 1; i <= n; ++i) getint(a[i]);
  if (!d) {
    int t = 1;
    for (int i = 2; i <= n; ++i)
      if (a[i] != a[i - 1]) {
        if (t > ans) ans = t, ansL = i - t;
        t = 1;
      } else
        ++t;
    if (t > ans) ans = t, ansL = n + 1 - t;
    cout << ansL << ' ' << ansL + ans - 1 << endl;
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    tp[i] = a[i] / d;
    while (tp[i] * d > a[i]) --tp[i];
    while ((tp[i] + 1) * d <= a[i]) ++tp[i];
    a[i] = a[i] - tp[i] * d;
    swap(a[i], tp[i]);
  }
  N = n;
  int l = 1;
  for (int i = 2; i <= N + 1; ++i)
    if (i > N || tp[i] != tp[i - 1]) {
      re = l - 1;
      n = 0;
      for (int j = l; j <= i - 1; ++j) a[++n] = a[j];
      doit();
      l = i;
    }
  cout << ansL << ' ' << ansL + ans - 1 << endl;
  return 0;
}
