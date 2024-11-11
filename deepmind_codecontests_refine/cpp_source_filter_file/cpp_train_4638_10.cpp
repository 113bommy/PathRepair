#include <bits/stdc++.h>
using namespace std;
double eps = 1e-14;
const int INF = 1e9 + 7;
const int MAXN = int(3e5 + 7);
int n;
double vh, vs, t, ans;
struct pt {
  double x, y, z;
  double dist(pt &a) const {
    return sqrt((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y) +
                (a.z - z) * (a.z - z));
  }
} a[MAXN], h;
int main() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].z;
  }
  cin >> vh >> vs >> h.x >> h.y >> h.z;
  for (int i = 1; i <= n; i++) {
    double dist = a[i].dist(a[i - 1]);
    t += dist / vs;
    if (a[i].dist(h) / vh - t < eps) {
      t -= dist / vs;
      pt l = {0, 0, 0},
         r = {a[i].x - a[i - 1].x, a[i].y - a[i - 1].y, a[i].z - a[i - 1].z};
      for (int j = 0; j < 300; j++) {
        pt m = {(r.x + l.x) / 2, (r.y + l.y) / 2, (r.z + l.z) / 2};
        pt temp = {a[i - 1].x + m.x, a[i - 1].y + m.y, a[i - 1].z + m.z};
        if (temp.dist(h) / vh - t - a[i - 1].dist(temp) / vs < eps)
          r = m;
        else
          l = m;
      }
      r.x += a[i - 1].x, r.y += a[i - 1].y, r.z += a[i - 1].z;
      ans = r.dist(h);
      printf("YES\n%.9f\n%.9f %.9f %.9f", ans, r.x, r.y, r.z);
      return 0;
    }
  }
  puts("NO");
  return 0;
}
