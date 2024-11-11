#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
};
double getarea(point a, point b, point c) {
  return 0.5 * (abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)));
}
double getdist(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
  long long n;
  cin >> n;
  struct point p[1005];
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    p[i] = {x, y};
  }
  double final = 1e18;
  for (long long i = 1; i <= n; i++) {
    double a = getarea(p[(i - 1 + n) % n], p[i], p[(i + 1) % n]);
    final = min({final, (a / double(getdist(p[(i - 1 + n) % n], p[i]))),
                 (a / double(getdist(p[(i - 1 + n) % n], p[(i + 1) % n]))),
                 (a / double(getdist(p[(i + 1) % n], p[i])))});
  }
  printf("%.9lf\n", final);
}
