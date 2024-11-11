#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const double inf = 1e6, eps = 1e-8;
const double pi = acos(-1);
int n, tdn, ql, qr, qid[N], found;
double ans = -1, ds[123][123];
struct edge {
  int to, nx;
  double w;
} ee[N * 2];
int eq[N], en;
int vis[N], V;
double dep[N];
struct point {
  double x, y;
  void init() { scanf("%lf %lf", &x, &y); }
} p[N], sp[N];
point operator+(const point& a, const point& b) {
  return (point){a.x + b.x, a.y + b.y};
}
point operator-(const point& a, const point& b) {
  return (point){a.x - b.x, a.y - b.y};
}
point operator*(const point& a, const double& b) {
  return (point){a.x * b, a.y * b};
}
double cj(const point& a, const point& b) { return a.x * b.y - a.y * b.x; }
double dj(const point& a, const point& b) { return a.x * b.x + a.y * b.y; }
double dist(const point& a, const point& b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
point rot90(const point& a) { return (point){-a.y, a.x}; }
struct line {
  point p, v;
  double angle;
  int i;
  bool rig(const point& t) { return cj(v, t - p) <= 0; }
} td[N], que[N];
point intersec(line a, line b) {
  double t = cj(b.p - a.p, b.v) / cj(a.v, b.v);
  return a.p + a.v * t;
}
bool cmp_angle(const line& lz, const line& rz) { return lz.angle < rz.angle; }
void link(int u, int v, double w) {
  ee[++en] = (edge){v, eq[u], w}, eq[u] = en;
}
void dfs(int u, int pr) {
  vis[u] = V;
  for (int j = eq[u], v; v = ee[j].to, j; j = ee[j].nx)
    if (v != pr) {
      if (vis[v] == V) {
        if (fabs(dep[u] + dep[v] + ee[j].w) > eps) found = 1;
      } else {
        dep[v] = dep[u] + ee[j].w;
        dfs(v, u);
      }
    }
}
double getA(point v) { return atan2(v.y, v.x); }
double check(point cen) {
  double ret = inf;
  for (int i = 1; i <= n; ++i) {
    ret = min(ret, dist(cen, p[i]));
  }
  found = 0;
  for (int i = 1; i <= n; ++i) eq[i] = 0;
  en = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (i != j && fabs(cj(p[j] - p[i], cen - p[i])) > eps &&
          ds[i][j] < ret - eps) {
        double delta = getA(p[j] - cen) - getA(p[i] - cen);
        while (delta >= pi) delta -= 2 * pi;
        while (delta < -pi) delta += 2 * pi;
        link(i, j, delta);
      }
  ++V;
  dep[1] = 0;
  dfs(1, 0);
  return found ? ret : -1;
}
void solve(int o) {
  tdn = 0;
  td[++tdn] = (line){(point){-inf, -inf}, (point){1, 0}};
  td[++tdn] = (line){(point){inf, -inf}, (point){0, 1}};
  td[++tdn] = (line){(point){inf, inf}, (point){-1, 0}};
  td[++tdn] = (line){(point){-inf, inf}, (point){0, -1}};
  for (int i = 1; i <= n; ++i)
    if (i != o) {
      td[++tdn] = (line){(p[o] + p[i]) * 0.5, rot90(p[i] - p[o])};
      td[tdn].i = i;
    }
  for (int i = 1; i <= tdn; ++i) {
    td[i].angle = atan2(td[i].v.y, td[i].v.x);
  }
  sort(td + 1, td + tdn + 1, cmp_angle);
  que[ql = qr = 1] = td[1];
  qid[1] = td[1].i;
  for (int i = 2; i <= tdn; ++i) {
    while (ql < qr && td[i].rig(sp[qr - 1])) --qr;
    while (ql < qr && td[i].rig(sp[ql])) ++ql;
    if (fabs(cj(td[i].v, que[qr].v)) < eps) {
      continue;
    }
    que[++qr] = td[i];
    qid[qr] = td[i].i;
    sp[qr - 1] = intersec(que[qr - 1], que[qr]);
  }
  while (ql < qr - 1 && que[ql].rig(sp[qr - 1])) --qr;
  que[qr + 1] = que[ql];
  qid[qr + 1] = qid[ql];
  for (int i = ql; i <= qr; ++i)
    if (qid[i] && qid[i + 1]) {
      ans = max(ans, check(intersec(que[i], que[i + 1])));
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    p[i].init();
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      ds[i][j] = dist(p[i], p[j]) / 2;
    }
  for (int i = 1; i <= n; ++i) {
    solve(i);
  }
  if (ans < 0)
    printf("-1\n");
  else
    printf("%lf\n", ans);
}
