#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const double eps = 1e-14;
int n, m, pre[N], tot;
double X, Y, a[N], b[N];
inline double dist(double x, double y) { return sqrt(x * x + y * y); }
struct dat {
  double tht;
  int id;
  inline bool operator<(const dat& rhs) const { return tht < rhs.tht; }
} p[N];
namespace bit {
int b[N];
inline void add(int i, int x) {
  for (; i <= tot; i += i & -i) b[i] += x;
}
inline int ask(int i) {
  int x = 0;
  for (; i; i &= i - 1) x += b[i];
  return x;
}
}  // namespace bit
bool get_cross(double x, double y, double r, double k, double b, double& X0,
               double& Y0, double& X1, double& Y1) {
  double Y = y - b;
  double A = 1 + k * k, B = -2 * x - 2 * Y * k, C = x * x + Y * Y - r * r;
  double dt = B * B - 4 * A * C;
  if (dt < 0) return 0;
  dt = sqrt(dt);
  X0 = (-B + dt) / (2 * A), X1 = (-B - dt) / (2 * A);
  Y0 = k * X0 + b, Y1 = k * X1 + b;
  return 1;
}
void get_cross2(double k0, double b0, double k1, double b1, double& x,
                double& y) {
  x = (b1 - b0) * 1. / (k0 - k1), y = k0 * x + b0;
}
long long Count(double R) {
  long long res = 0;
  tot = 0;
  for (int i = 1; i <= n; ++i) {
    double X0, Y0, X1, Y1;
    if (get_cross(X, Y, R, a[i], b[i], X0, Y0, X1, Y1)) {
      p[++tot] = (dat){atan2(Y0 - Y, X0 - X), i};
      p[++tot] = (dat){atan2(Y1 - Y, X1 - X), i};
    }
  }
  sort(p + 1, p + tot + 1);
  for (int i = 1; i <= tot; ++i)
    if (!pre[p[i].id]) {
      pre[p[i].id] = i;
      bit::add(i, 1);
    } else {
      int& x = pre[p[i].id];
      res += bit::ask(i) - bit::ask(x);
      bit::add(x, -1);
      x = 0;
    }
  return res;
}
double solve(double R) {
  if (R < eps) return 0;
  double res = 0;
  int ct = 0;
  tot = 0;
  set<pair<double, int> > st;
  for (int i = 1; i <= n; ++i) {
    double X0, Y0, X1, Y1;
    if (get_cross(X, Y, R, a[i], b[i], X0, Y0, X1, Y1)) {
      p[++tot] = (dat){atan2(Y0 - Y, X0 - X), i};
      p[++tot] = (dat){atan2(Y1 - Y, X1 - X), i};
    }
  }
  sort(p + 1, p + tot + 1);
  for (int i = 1; i <= tot; ++i)
    if (!pre[p[i].id]) {
      pre[p[i].id] = i;
      st.insert(make_pair(p[i].tht, p[i].id));
    } else {
      int& x = pre[p[i].id];
      st.erase(st.lower_bound(make_pair(p[x].tht - eps, p[i].id)));
      auto itL = st.lower_bound(make_pair(p[x].tht + eps, 0));
      auto itR = st.lower_bound(make_pair(p[i].tht - eps, 0));
      if (p[i].tht - p[x].tht >= eps)
        for (auto it = itL; it != itR; ++it) {
          double x0, y0;
          get_cross2(a[p[i].id], b[p[i].id], a[it->second], b[it->second], x0,
                     y0);
          double dis = dist(X - x0, Y - y0);
          if (dis < R && fabs(dis - R) > eps) {
            ++ct;
            res += dis;
            if (ct == m) return res;
          }
        }
      x = 0;
    }
  res += R * (m - ct);
  return res;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> X >> Y >> m;
  X /= 1000, Y /= 1000;
  for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i], a[i] /= 1000, b[i] /= 1000;
  double l = 0, r = 1e10;
  for (int T = 1; T <= 80; ++T) {
    const double mid = (l + r) / 2;
    if (Count(mid) >= m)
      r = mid;
    else
      l = mid;
  }
  cout << fixed << setprecision(15) << solve(r) << '\n';
  return 0;
}
