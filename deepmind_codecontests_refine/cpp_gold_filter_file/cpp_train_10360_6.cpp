#include <bits/stdc++.h>
using namespace std;
const double ovo = 0.001;
const double eps = 1e-14;
double x, y, k[50005], b[50005];
struct node {
  double p, q;
  int tp, tq, id;
} t[50005];
struct qwq {
  int pos, t, td, del;
} c[100005];
double a[100005], d[100005];
int n, m, p[100005], sz;
inline void add(int a, int del) {
  while (a <= sz) p[a] += del, a += (a & (-a));
}
inline int query(int a) {
  int s = 0;
  while (a) s += p[a], a -= (a & (-a));
  return s;
}
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
inline bool cmp(qwq a, qwq b) { return a.t < b.t; }
inline double get(double x, double y, double r) {
  return (y < 0 ? x - r : r - x);
}
inline long long cal(double r) {
  int i, cnt = 0, num = 0, o = 0;
  long long ans = 0;
  for (i = 1; i <= n; i++) {
    double c1 = k[i] * k[i] + 1.0, c2 = 2.0 * k[i] * b[i],
           c3 = b[i] * b[i] - r * r;
    if (c2 * c2 - 4.0 * c1 * c3 < eps) continue;
    double del = sqrt(c2 * c2 - 4 * c1 * c3);
    double px = (-c2 + del) / (2.0 * c1), py = k[i] * px + b[i],
           p = get(px, py, r);
    double qx = (-c2 - del) / (2.0 * c1), qy = k[i] * qx + b[i],
           q = get(qx, qy, r);
    t[++cnt].p = p;
    t[cnt].q = q;
    t[cnt].id = i;
    a[++num] = p;
    a[++num] = q;
  }
  sort(a + 1, a + num + 1);
  d[++o] = a[1];
  for (i = 2; i <= num; i++) {
    if (fabs(a[i] - a[i - 1]) > eps) d[++o] = a[i];
  }
  for (i = 1; i <= cnt; i++) {
    t[i].tp = lower_bound(d + 1, d + o + 1, t[i].p - eps) - d;
    t[i].tq = lower_bound(d + 1, d + o + 1, t[i].q - eps) - d;
    c[i * 2 - 1].pos = t[i].id;
    c[i * 2 - 1].t = min(t[i].tp, t[i].tq);
    c[i * 2 - 1].del = 1;
    c[i * 2].pos = t[i].id;
    c[i * 2].t = max(t[i].tp, t[i].tq);
    c[i * 2].del = -1;
    c[i * 2].td = c[i * 2 - 1].t;
  }
  sort(c + 1, c + 2 * cnt + 1, cmp);
  sz = c[2 * cnt].t;
  for (i = 1; i <= 2 * cnt; i++) {
    if (c[i].del == 1) {
      add(c[i].t, 1);
    } else {
      ans += query(sz) - query(c[i].td);
      add(c[i].td, -1);
    }
  }
  return ans;
}
inline double get(int p, int q) {
  double x = (b[q] - b[p]) / (k[p] - k[q]), y = k[p] * x + b[p];
  return sqrt(x * x + y * y);
}
set<pair<int, int> > ss;
set<pair<int, int> >::iterator it;
inline double _cal(double r) {
  if (r < eps) return 0;
  int i, j, cnt = 0, num = 0, o = 0;
  double res = 0;
  for (i = 1; i <= n; i++) {
    double c1 = k[i] * k[i] + 1.0, c2 = 2.0 * k[i] * b[i],
           c3 = b[i] * b[i] - r * r;
    if (c2 * c2 - 4.0 * c1 * c3 < eps) continue;
    double del = sqrt(c2 * c2 - 4 * c1 * c3);
    double px = (-c2 + del) / (2.0 * c1), py = k[i] * px + b[i],
           p = get(px, py, r);
    double qx = (-c2 - del) / (2.0 * c1), qy = k[i] * qx + b[i],
           q = get(qx, qy, r);
    t[++cnt].p = p;
    t[cnt].q = q;
    t[cnt].id = i;
    a[++num] = p;
    a[++num] = q;
  }
  sort(a + 1, a + num + 1);
  d[++o] = a[1];
  for (i = 2; i <= num; i++) {
    if (fabs(a[i] - a[i - 1]) > eps) d[++o] = a[i];
  }
  for (i = 1; i <= cnt; i++) {
    t[i].tp = lower_bound(d + 1, d + o + 1, t[i].p - eps) - d;
    t[i].tq = lower_bound(d + 1, d + o + 1, t[i].q - eps) - d;
    c[i * 2 - 1].pos = t[i].id;
    c[i * 2 - 1].t = min(t[i].tp, t[i].tq);
    c[i * 2 - 1].del = 1;
    c[i * 2].pos = t[i].id;
    c[i * 2].t = max(t[i].tp, t[i].tq);
    c[i * 2].del = -1;
    c[i * 2].td = c[i * 2 - 1].t;
  }
  o = 0;
  sort(c + 1, c + 2 * cnt + 1, cmp);
  for (i = 1; i <= 2 * cnt; i++) {
    if (c[i].del == -1) {
      it = ss.lower_bound(make_pair(c[i].td, c[i].pos));
      while (it != ss.end()) {
        if ((*it).second == c[i].pos) {
          it++;
          continue;
        }
        double dis = get(c[i].pos, (*it).second);
        if (fabs(dis - r) > eps) {
          res += dis;
          o++;
        }
        it++;
      }
      ss.erase(ss.lower_bound(make_pair(c[i].td, c[i].pos)));
    } else {
      ss.insert(make_pair(c[i].t, c[i].pos));
    }
  }
  int rm = m - o;
  res += 1.0 * rm * r;
  return res;
}
int main() {
  int i, j, p, q, qwq = 70;
  scanf("%d%d%d%d", &n, &p, &q, &m);
  x = 1.0 * p * ovo;
  y = 1.0 * q * ovo;
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &p, &q);
    k[i] = 1.0 * p * ovo;
    b[i] = 1.0 * q * ovo;
    b[i] -= (y - k[i] * x);
  }
  double l = 0, r = 3e9;
  while (qwq--) {
    double mid = (l + r) / 2.0;
    if (cal(mid) < m) {
      l = mid;
    } else {
      r = mid;
    }
  }
  double ans = _cal(l - (1e-7));
  printf("%.12lf\n", ans);
  return 0;
}
