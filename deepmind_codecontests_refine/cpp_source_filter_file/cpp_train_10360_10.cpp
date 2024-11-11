#include <bits/stdc++.h>
using namespace std;
using DB = double;
const DB EPS = 1e-8;
const DB PI = acos(-1);
const DB INF = 1e100;
inline DB sqr(DB x) { return x * x; }
struct PT {
  DB x, y;
  PT(DB x = 0, DB y = 0) : x(x), y(y) {}
  void in() {
    scanf("%lf%lf", &x, &y);
    x /= 1000, y /= 1000;
  }
};
PT operator+(PT a, PT b) { return PT(a.x + b.x, a.y + b.y); }
PT operator-(PT a, PT b) { return PT(a.x - b.x, a.y - b.y); }
PT operator*(PT a, DB b) { return PT(a.x * b, a.y * b); }
PT operator/(PT a, DB b) { return PT(a.x / b, a.y / b); }
DB dis2(PT p) { return sqr(p.x) + sqr(p.y); }
DB dis(PT p) { return sqrt(dis2(p)); }
DB scal(PT a, PT b) { return a.x * b.x + a.y * b.y; }
DB getAngle(PT p) { return atan2(p.y, p.x); }
int posCirLine(PT p, DB r, PT p1, PT p2, PT *q) {
  DB a = dis2(p1 - p2);
  DB b = scal(p - p1, p2 - p1);
  DB c = dis2(p - p1) - sqr(r);
  DB d2 = sqr(b) - a * c;
  if (d2 < EPS) return 0;
  DB d = sqrt(fabs(d2));
  q[0] = p1 + (p2 - p1) * ((b + d) / a);
  q[1] = p1 + (p2 - p1) * ((b - d) / a);
  return 1;
}
const int N = 55000;
const int M = N + N;
PT A[N], B[N];
struct Line {
  DB a, b;
  void in() {
    scanf("%lf%lf", &a, &b);
    a /= 1000, b /= 1000;
  }
  Line(DB a = 0, DB b = 0) : a(a), b(b) {}
  PT cross(Line l) {
    if (fabs(a - l.a) < EPS) return PT(INF, INF);
    DB x = (l.b - b) / (a - l.a);
    DB y = a * x + b;
    return PT(x, y);
  }
} L[N];
int b[M];
void add(int idx, int v) {
  for (idx++; idx < M; idx += idx & -idx) b[idx] += v;
}
int get(int idx) {
  int ret = 0;
  for (idx++; idx; idx -= idx & -idx) ret += b[idx];
  return ret;
}
struct query {
  DB val;
  int id, sig;
  query(DB val = 0, int id = 0, int sig = 1) : val(val), id(id), sig(sig) {}
  bool operator<(const query &q) const { return val < q.val; }
};
int n, m;
PT P;
query VQ[M];
int to[M], id[M];
int vec[M], tmp[M];
long long can(DB r, bool CALC, DB &sum) {
  int vqn = 0;
  for (int i = 0; i < n; i++) {
    PT tem[2];
    if (posCirLine(P, r, A[i], B[i], tem)) {
      DB ang[2];
      for (int j = 0; j < 2; j++) ang[j] = getAngle(tem[j] - P);
      if (ang[1] < ang[0]) swap(ang[0], ang[1]);
      VQ[vqn++] = query(ang[0], i, 1);
      VQ[vqn++] = query(ang[1], i, -1);
    }
  }
  for (int i = 0; i < vqn; i++) id[i] = i;
  sort(id, id + vqn, [](int a, int b) { return VQ[a].val < VQ[b].val; });
  sum = 0;
  long long cnt = 0;
  memset(b, 0, sizeof b);
  int vn = 0;
  int now = 0, all = 0;
  for (int i = 0; i < vqn; i++) {
    query t = VQ[id[i]];
    if (t.sig == 1) {
      to[t.id] = now;
      add(now, 1);
      ++all;
      if (CALC) vec[vn++] = t.id;
    } else {
      cnt += (all - get(to[t.id]));
      add(to[t.id], -1);
      --all;
      if (CALC) {
        int tn = 0;
        while (vn && vec[vn - 1] != t.id) {
          int a = t.id, b = vec[vn - 1];
          assert(fabs(L[a].a - L[b].a) > EPS);
          sum += dis(P - L[a].cross(L[b]));
          tmp[tn++] = b;
          vn--;
        }
        if (vn) vn--;
        while (tn) {
          vec[vn++] = tmp[tn - 1];
          --tn;
        }
      }
    }
    ++now;
  }
  return cnt;
}
int main() {
  scanf("%d", &n);
  P.in();
  scanf("%d", &m);
  for (int i = 0; i < n; i++) {
    L[i].in();
    A[i] = PT(0, L[i].b);
    B[i] = PT(1, L[i].a + L[i].b);
  }
  DB st = 0, en = 1e10;
  DB ans;
  int now = clock();
  for (int times = 0; times < 60; times++) {
    DB md = (st + en) / 2;
    if (can(md, 0, ans) <= m)
      st = md;
    else
      en = md;
  }
  long long cnt = can(st, 1, ans);
  printf("%.10lf\n", ans + st * (m - cnt));
  return 0;
}
