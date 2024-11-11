#include <bits/stdc++.h>
using namespace std;
struct point {
  long double x;
  long double y;
};
vector<point> ps;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  point p;
  cin >> n;
  cin >> p.x >> p.y;
  long double mi = 4000000;
  long double ma = 0;
  point c;
  point ax;
  ax.x = 0;
  ax.y = 0;
  long double dis;
  long long zn = n;
  while (n--) {
    cin >> c.x >> c.y;
    c.x -= p.x;
    c.y -= p.x;
    ps.push_back(c);
    dis = sqrtl(powl(c.x - ax.x, 2) + powl(c.y - ax.y, 2));
    mi = fminl(dis, mi);
    ma = fmaxl(dis, ma);
  }
  n = zn;
  point ne;
  for (int i = 0; i < n; i++) {
    c.x = ps[i].x;
    c.y = ps[i].y;
    ne.x = ps[(i + 1) % n].x;
    ne.y = ps[(i + 1) % n].y;
    dis = 4000000;
    if (c.x == ne.x) {
      if (c.y * ne.y < 0) {
        dis = c.x;
      }
    } else if (c.y == ne.y) {
      if (c.x * ne.x < 0) {
        dis = c.y;
      }
    } else {
      long double kl = (c.y - ne.y) / (c.x - ne.x);
      long double kl2 = (-1) / kl;
      long double b = c.y - (kl * c.x);
      long double xi = b / (kl2 - kl);
      long double yi = (kl * xi) + b;
      point ka;
      ka.x = xi;
      ka.y = yi;
      if ((ka.x >= fminl(c.x, ne.x)) && (ka.y >= fminl(c.y, ne.y)) &&
          (ka.x <= fmaxl(c.x, ne.x)) && (ka.y <= fmaxl(c.y, ne.y))) {
        dis = sqrtl(powl(ax.x - ka.x, 2) + powl(ax.y - ka.y, 2));
      }
    }
    mi = fminl(dis, mi);
  }
  long double ans =
      ((2 * acos(0)) * powl(ma, 2.0)) - ((2 * acos(0)) * powl(mi, 2.0));
  cout << setprecision(16) << fixed << ans << endl;
}
