#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
mt19937 gen;
struct point {
  long long x, y;
} x[100010];
struct vect {
  long long x, y;
  vect(point a, point b) : x(b.x - a.x), y(b.y - a.y){};
};
long double dist(point a, point b) {
  return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
long long scalmul(vect a, vect b) { return a.x * b.x + a.y * b.y; }
long long vectmul(vect a, vect b) { return (a.x * b.y - a.y * b.x); }
vector<long double> d;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(20);
  int n;
  point p;
  cin >> n >> p.x >> p.y;
  for (int i = 0; i < n; ++i) {
    cin >> x[i].x >> x[i].y;
    d.push_back(dist(x[i], p));
  }
  x[n] = x[0];
  for (int i = 0; i < n; ++i) {
    if (scalmul(vect(p, x[i]), vect(x[i + 1], x[i])) >= 0 &&
        scalmul(vect(p, x[i + 1]), vect(x[i], x[i + 1])) >= 0)
      d.push_back(vectmul(vect(p, x[i]), vect(x[i], x[i + 1])) / 1. /
                  dist(x[i], x[i + 1]));
  }
  sort((d).begin(), (d).end());
  long double ans =
      3.1415926535897932384626433832795 * (d.back() * d.back() - d[0] * d[0]);
  cout << ans;
  cerr << "\nTime Elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms";
}
