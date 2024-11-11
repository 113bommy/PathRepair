#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
struct Tpair {
  int x, y;
  Tpair *p;
  Tpair(int _x = 0, int _y = 0, Tpair *_p = NULL) { x = _x, y = _y, p = _p; }
  inline bool operator<(const Tpair &b) const {
    return x != b.x ? x < b.x : y < b.y;
  }
  inline bool operator!=(const Tpair &b) const { return x != b.x || y != b.y; }
};
typedef Tpair *Tpair_;
struct Tfind {
  int n;
  struct Tsqy {
    int f, s, c;
    Tpair *p, *q;
    inline void set(int _f, int _s, int _c = 0) { f = _f, s = _s, c = _c; }
  } F[maxn * maxn];
  void set(int _n) {
    int i;
    n = _n;
    for (i = 0; i <= n; ++i) F[i].set(i, 1);
  }
  int find(int x) { return x != F[x].f ? F[x].f = find(F[x].f) : x; }
  Tsqy &get(int x) { return F[find(x)]; }
  inline void add(int a, int b) {
    a = find(a), b = find(b);
    F[b].s += F[a].s, F[a].f = b;
  }
} Fd;
struct Tcmp {
  Tpair x;
  inline int F(int x, int y) const {
    if (!x && !y) return 1;
    int d = max(abs(x), abs(y)), l = 2 * d, Fc = (2 * d - 1) * (2 * d - 1);
    if (-x == d && -d < y && y <= d) Fc += y + d - 1;
    if (y == d && -d < x && x <= d) Fc += l + x + d - 1;
    if (x == d && -d <= y && y < d) Fc += 2 * l + d - y - 1;
    if (-y == d && -d <= x && x < d) Fc += 3 * l + d - x - 1;
    return Fc + 1;
  }
  inline bool operator()(const Tpair &a, const Tpair &b) const {
    return F(a.x - x.x, a.y - x.y) < F(b.x - x.x, b.y - x.y);
  }
} cmp;
int n, m, A[maxn][maxn], B[maxn][maxn];
map<int, Tpair> C;
Tpair S;
inline int F1(Tpair x) { return x.x * m + x.y; }
inline int F1(int x, int y) { return x * m + y; }
namespace Ninit {
map<int, Tpair_> D, E;
Tpair Bbuf[maxn * maxn];
int Bn;
void init() {
  int i, j, x;
  scanf("%d%d", &n, &m);
  Fd.set(n * m);
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) {
      scanf("%d", A[i] + j);
      if (C.count(A[i][j])) Fd.add(F1(i, j), F1(C[A[i][j]]));
      C[A[i][j]] = Tpair(i, j);
    }
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) {
      scanf("%d", B[i] + j);
      if (B[i][j] == -1) continue;
      if (!C.count(B[i][j])) C[B[i][j]] = Tpair(-1, -1);
      Bbuf[Bn] = Tpair(i, j);
      if (D.count(A[i][j]))
        D[A[i][j]]->p = Bbuf + Bn;
      else
        E[A[i][j]] = Bbuf + Bn;
      D[A[i][j]] = Bbuf + Bn, Bn++;
    }
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) {
      x = F1(i, j);
      if (Fd.find(x) == x) {
        Fd.F[x].c = A[i][j];
        Fd.F[x].p = E[A[i][j]];
        Fd.F[x].q = D[A[i][j]];
      }
    }
  scanf("%d%d", &S.x, &S.y), --S.x, --S.y;
}
}  // namespace Ninit
namespace Nsolve {
int ans;
Tpair H[maxn * maxn], a[maxn * maxn];
void solve() {
  int i, j, l, r, an;
  Tpair u, *p;
  for (l = 0, r = 1, H[1] = S; l++ != r;) {
    u = H[l];
    Tfind::Tsqy &x = Fd.get(F1(u));
    if (x.c == 0 || x.c == B[u.x][u.y]) continue;
    for (an = 0, p = x.p; p; p = p->p) a[an++] = *p;
    cmp.x = u, sort(a, a + an, cmp);
    for (i = 0; i < an; ++i) H[++r] = a[i];
    ans += x.s, x.p = NULL;
    i = F1(u), j = F1(C[B[u.x][u.y]]);
    j < 0 ? (C[B[u.x][u.y]] = C[x.c], C[x.c] = Tpair(-1, -1), x.c = B[u.x][u.y])
          : (C[x.c] = Tpair(-1, -1), Fd.add(i, j), 0);
  }
  cout << ans << endl;
}
}  // namespace Nsolve
int main() {
  Ninit::init();
  Nsolve::solve();
  return 0;
}
