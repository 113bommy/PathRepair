#include <bits/stdc++.h>
using namespace std;
double pi = 3.14159265358979;
struct pt {
  double x;
  double y;
};
struct line {
  double a;
  double b;
  double c;
};
line to(pt a, pt b) {
  line l;
  l.a = (b.y - a.y);
  l.b = (a.x - b.x);
  l.c = (-a.x * l.a - a.y * l.b);
  return l;
}
pt perec(line l1, line l2) {
  pt o;
  o.y = (l2.c * l1.a - l1.c * l2.a) / (l2.a * l1.b - l1.a * l2.b);
  o.x = (l2.c * l1.b - l1.c * l2.b) / (l2.b * l1.a - l1.b * l2.a);
  return o;
}
double dist(pt a, pt b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15) << "";
  long long n;
  cin >> n;
  if (n <= 4) {
    cout << "No solution";
    return 0;
  }
  vector<pt> u;
  for (long long i = 0; i < n; ++i) {
    double f = (2.0 * pi * i / (n + 0.0));
    pt z;
    z.x = sin(f);
    z.y = cos(f);
    u.push_back(z);
  }
  vector<line> z;
  for (long long i = 0; i < n; ++i) {
    z.push_back(to(u[i], u[(i + 1) % n]));
  }
  if (n >= 10) {
    for (long long i = 0; i < n; ++i) {
      z[i].c *= 1000;
      z[i].c += (i / (1000.0));
    }
  } else {
    for (long long i = 0; i < n; ++i) {
      z[i].c *= 500;
      z[i].c += (i / (1.0));
    }
  }
  vector<pt> ans(n);
  for (long long i = 0; i < n; ++i) {
    ans[i] = perec(z[i], z[(i + 1) % n]);
  }
  reverse(ans.begin(), ans.end());
  for (long long i = 0; i < n; ++i) {
    cout << ans[i].x << ' ' << ans[i].y << endl;
  }
  return 0;
}
