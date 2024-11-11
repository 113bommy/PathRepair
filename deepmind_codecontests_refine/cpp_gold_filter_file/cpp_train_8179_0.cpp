#include <bits/stdc++.h>
using namespace std;
const int maxn = 200100;
const double eps = 1e-9;
int n, m, top;
double dis[maxn];
struct node {
  int x, y;
} a[maxn];
node operator+(const node &A, const node &B) {
  return (node){A.x + B.x, A.y + B.y};
}
node operator-(const node &A, const node &B) {
  return (node){A.x - B.x, A.y - B.y};
}
struct Line {
  double bx, by;
  int kx, ky;
  void print() { fprintf(stderr, "(%dx+%.1f,%dy+%.1f)\n", kx, bx, ky, by); }
};
Line operator-(const Line &A, const Line &B) {
  Line res;
  res.kx = (A.kx - B.kx), res.bx = (A.bx - B.bx);
  res.ky = (A.ky - B.ky), res.by = (A.by - B.by);
  return res;
}
struct event {
  int a;
  double b, c, l, r;
  double f(double x) { return a * x * x + b * x + c; }
  void print() {
    cerr << a << "x^2+" << b << "x+" << c << endl;
    fprintf(stderr, "[%.1f,%.1f]\n", l, r);
  }
} stk[maxn];
struct segment {
  double l, r;
} b[maxn];
struct point {
  int fr, v;
  double p;
} c[maxn * 3];
bool cmpc(const point &A, const point &B) { return A.p < B.p; }
int dcmp(int x, int y) {
  if (x > y) return 1;
  if (x < y) return -1;
  return 0;
}
int dcmp(double x, double y) {
  if (x > y + eps) return 1;
  if (x < y - eps) return -1;
  return 0;
}
Line getLine(int p, double l) {
  Line res;
  res.bx = a[p].x, res.kx = dcmp(a[p + 1].x, a[p].x);
  res.by = a[p].y, res.ky = dcmp(a[p + 1].y, a[p].y);
  res.bx = res.bx + res.kx * (l - dis[p]);
  res.by = res.by + res.ky * (l - dis[p]);
  return res;
}
double len;
int Abs(int x) { return x > 0 ? x : -x; }
void solve(Line A, double l, double r) {
  event B;
  B.a = A.kx * A.kx + A.ky * A.ky;
  B.b = (A.kx * A.bx + A.ky * A.by) * 2;
  B.c = A.bx * A.bx + A.by * A.by;
  B.l = l, B.r = r - l;
  stk[++top] = B;
}
double getpl(event A, double l, double r, double D) {
  double mid;
  while (r - l > eps) {
    mid = (l + r) / 2.0;
    if (A.f(mid) > D)
      l = mid;
    else
      r = mid;
  }
  return r;
}
double getpr(event A, double l, double r, double D) {
  double mid;
  while (r - l > eps) {
    mid = (l + r) / 2.0;
    if (A.f(mid) > D)
      r = mid;
    else
      l = mid;
  }
  return r;
}
bool pd(double D) {
  D = D * D;
  static int vis[maxn], cnt[maxn];
  for (int i = 0; i <= m; i++) vis[i] = 0, cnt[i] = 0;
  double l, r, mid;
  int num = 0, tp = 0;
  for (int i = 1; i <= top; i++) {
    if (stk[i].a == 0) {
      if (stk[i].c <= D) b[++num] = (segment){stk[i].l, stk[i].l + stk[i].r};
    } else {
      mid = -stk[i].b / (stk[i].a * 2);
      if (mid > stk[i].r) mid = stk[i].r;
      if (mid < 0) mid = 0;
      if (stk[i].f(mid) > D) continue;
      l = getpl(stk[i], 0, mid, D);
      r = getpr(stk[i], mid, stk[i].r, D);
      b[++num] = (segment){stk[i].l + l, stk[i].l + r};
      if (dcmp(D, sqrt(2.0)) == 0) {
        cerr << b[num].l << endl;
      }
    }
  }
  int s, t;
  for (int i = 1; i <= num; i++) {
    s = (int)floor(b[i].l / len) + 1;
    t = (int)floor(b[i].r / len) + 1;
    if (s == t) {
      c[++tp] = (point){s, 1, b[i].l - len * (s - 1)};
      c[++tp] = (point){s, -1, b[i].r - len * (s - 1)};
    } else {
      vis[s + 1]++;
      vis[t]--;
      c[++tp] = (point){s, 1, b[i].l - len * (s - 1)};
      c[++tp] = (point){t, 1, 0};
      c[++tp] = (point){t, -1, b[i].r - len * (t - 1)};
    }
  }
  int tot = 0, ltot = 0;
  for (int i = 1; i <= m; i++) {
    vis[i] = vis[i - 1] + vis[i];
    if (vis[i] == 0) tot++;
  }
  sort(c + 1, c + tp + 1, cmpc);
  for (int i = 1; i <= tp; i++) {
    if (vis[c[i].fr]) continue;
    if (c[i].v == 1) {
      if (!cnt[c[i].fr]) ltot++;
      cnt[c[i].fr]++;
    } else {
      cnt[c[i].fr]--;
      if (!cnt[c[i].fr]) ltot--;
    }
    if (ltot >= tot) return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  for (int i = n + 1; i <= n * 2; i++) a[i] = a[i - n];
  for (int i = 1; i <= n * 2; i++) {
    dis[i + 1] =
        dis[i] + Abs(a[i % n + 1].x + a[i % n + 1].y - a[i].x - a[i].y);
  }
  len = dis[n + 1] / m;
  int r = 1;
  while (dis[r] < len) r++;
  double p = 0;
  Line s1, s2;
  for (int l = 1; l <= n; l++) {
    while (dis[r] < dis[l + 1] + len) {
      s1 = getLine(r - 1, p + len);
      s2 = getLine(l, p);
      solve(s1 - s2, p, dis[r] - len);
      p = dis[r] - len;
      r++;
    }
    s1 = getLine(r - 1, p + len);
    s2 = getLine(l, p);
    solve(s1 - s2, p, dis[l + 1]);
    p = dis[l + 1];
  }
  double L = 0, R = 4000, mid;
  while (R - L > eps) {
    mid = (L + R) / 2.0;
    if (pd(mid))
      R = mid;
    else
      L = mid;
  }
  printf("%.8f\n", L);
  return 0;
}
