#include <bits/stdc++.h>
using namespace std;
int IN() {
  int c, f, x;
  while (!isdigit(c = getchar()) && c != '-')
    ;
  c == '-' ? (f = 1, x = 0) : (f = 0, x = c - '0');
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + c - '0';
  return !f ? x : -x;
}
const int N = 100000 + 19;
const double eps = 1e-9;
const double Eps = 1e-10;
struct Point {
  double x, y;
};
Point operator-(Point A, Point B) { return (Point){A.x - B.x, A.y - B.y}; }
double dot(Point A, Point B) { return A.x * B.x + A.y * B.y; }
double cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }
struct Seg {
  Point A, B;
  bool p;
  double k;
  Seg() {}
  Seg(Point __A, Point __B) {
    A = __A;
    B = __B;
    p = (fabs(A.x - B.x) < eps);
    if (!p) k = (B.y - A.y) / (B.x - A.x);
  }
  double Value(double x) {
    if (p) return A.y;
    return A.y + k * (x - A.x);
  }
};
double x;
bool operator<(Seg A, Seg B) { return A.Value(x) < B.Value(x); }
bool onSeg(Point A, Point B, Point P) {
  if (fabs(P.x - A.x) < eps && fabs(P.y - A.y) < eps) return 1;
  if (fabs(P.x - B.x) < eps && fabs(P.y - B.y) < eps) return 1;
  B = B - P;
  A = A - P;
  double tmp = dot(A, B);
  tmp /= sqrt(dot(A, A));
  tmp /= sqrt(dot(B, B));
  return fabs(tmp + 1) < eps;
}
bool Inter(Seg A, Seg B, double &res) {
  if (A.p && B.p) {
    if (fabs(A.A.x - B.A.x) > eps) return 0;
    if (fabs(A.A.y - B.A.y) > eps) return 0;
    res = A.A.x;
    return 1;
  }
  if (B.p) swap(A, B);
  if (A.p) {
    if (!onSeg(B.A, B.B, A.A)) return 0;
    res = A.A.x;
    return 1;
  }
  double tmp = cross(B.B - B.A, A.B - A.A);
  if (fabs(tmp) < eps) {
    res = 1e60;
    if (onSeg(A.A, A.B, B.A)) res = min(res, B.A.x);
    if (onSeg(A.A, A.B, B.B)) res = min(res, B.B.x);
    if (onSeg(B.A, B.B, A.A)) res = min(res, A.A.x);
    if (onSeg(B.A, B.B, A.B)) res = min(res, A.B.x);
    if (res > 1e50) return 0;
    return 1;
  } else {
    res = ((A.A.y - A.k * A.A.x) - (B.A.y - B.k * B.A.x)) / (B.k - A.k);
    if (!onSeg(A.A, A.B, (Point){res, A.Value(res)})) return 0;
    if (!onSeg(B.A, B.B, (Point){res, B.Value(res)})) return 0;
    return 1;
  }
}
const int Top = 3500000;
struct QType {
  double x;
  int f, id;
  Seg A;
  bool operator<(const QType &B) const {
    if (fabs(x - B.x) > eps) return x < B.x;
    return f > B.f;
  }
} V[Top];
multiset<Seg>::iterator I[Top];
multiset<Seg> S;
int num, Vcnt;
double res = 1e60;
void addSeg(double X1, double Y1, double X2, double Y2) {
  Seg A = Seg((Point){X1, Y1}, (Point){X2, Y2});
  V[Vcnt++] = ((QType){X1, 1, ++num, A});
  V[Vcnt++] = ((QType){X2, -1, num, A});
}
void Sweepline() {
  sort(V, V + Vcnt);
  for (int i = 0; i < Vcnt; i++) {
    if (V[i].x >= res) break;
    double nxt = (i < Vcnt - 1 ? min(V[i + 1].x, res) : res), tmpx;
    x = (V[i].x * 9 + nxt) / 10;
    if (V[i].f == 1) {
      multiset<Seg>::iterator it = S.insert(V[i].A), pre, suf;
      I[V[i].id] = it;
      if (it != S.begin()) {
        pre = it;
        pre--;
        if (Inter(*pre, *it, tmpx)) res = min(res, tmpx);
      }
      suf = it;
      suf++;
      if (suf != S.end()) {
        if (Inter(*suf, *it, tmpx)) res = min(res, tmpx);
      }
    } else {
      multiset<Seg>::iterator it = I[V[i].id], pre, suf;
      pre = suf = it;
      if (it != S.begin() && ++suf != S.end()) {
        pre = it;
        pre--;
        if (Inter(*pre, *suf, tmpx)) res = min(res, tmpx);
      }
      S.erase(I[V[i].id]);
    }
  }
}
struct Edge {
  int y, nxt;
} E[N * 2];
int las[N], sz[N], son[N], fa[N], id[N], top[N], dep[N];
int cnt, n, m, tot;
void Link(int x, int y) {
  E[cnt] = (Edge){y, las[x]};
  las[x] = cnt++;
  E[cnt] = (Edge){x, las[y]};
  las[y] = cnt++;
}
void dfs(int x) {
  sz[x] = 1;
  for (int i = las[x], y; ~i; i = E[i].nxt)
    if ((y = E[i].y) != fa[x]) {
      fa[y] = x;
      dep[y] = dep[x] + 1;
      dfs(y);
      sz[x] += sz[y];
      if (sz[y] > sz[son[x]]) son[x] = y;
    }
}
void dfs(int x, int anc) {
  id[x] = ++tot;
  top[x] = anc;
  if (son[x]) dfs(son[x], anc);
  for (int i = las[x], y; ~i; i = E[i].nxt)
    if ((y = E[i].y) != fa[x] && y != son[x]) dfs(y, y);
}
int LCA(int x, int y) {
  int a = top[x], b = top[y];
  while (a != b) {
    if (dep[a] > dep[b]) swap(a, b), swap(x, y);
    y = fa[b], b = top[y];
  }
  return dep[x] < dep[y] ? x : y;
}
void getQuery() {
  int t, c, x, y, z, a, b;
  double l, r, tmp;
  t = IN(), c = IN(), x = IN(), y = IN();
  z = LCA(x, y);
  l = t, r = t + 1.0 * (dep[x] + dep[y] - 2 * dep[z]) / c;
  a = top[x], b = top[y];
  while (a != b)
    if (dep[a] > dep[b]) {
      tmp = 1.0 * (dep[x] - dep[a] + 1) / c;
      addSeg(l, id[x], l + tmp - Eps, id[a] - 1 + Eps);
      l += tmp;
      x = fa[a], a = top[x];
    } else {
      tmp = 1.0 * (dep[y] - dep[b] + 1) / c;
      addSeg(r - tmp + Eps, id[b] - 1 + Eps, r, id[y]);
      r -= tmp;
      y = fa[b], b = top[y];
    }
  addSeg(l, id[x], r, id[y]);
}
int main() {
  memset(las, -1, sizeof(las));
  n = IN(), m = IN();
  for (int i = 1; i < n; i++) Link(IN(), IN());
  dfs(1);
  dfs(1, 1);
  for (int i = 1; i < m + 1; i++) getQuery();
  Sweepline();
  if (res > 1e50) {
    puts("-1");
  } else {
    printf("%.20lf\n", res);
  }
}
