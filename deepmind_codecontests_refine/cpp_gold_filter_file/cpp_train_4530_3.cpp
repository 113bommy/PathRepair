#include <bits/stdc++.h>
using namespace std;
const long long INF = (int)1e9 + 70;
const long long MOD = 1e9 + 7;
const int MAXN = 100005;
int main() {
  if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
  int(N);
  scanf("%d", &N);
  double r, v;
  cin >> r >> v;
  double w = v / r;
  double PI = acos(-1);
  w = w - (int)(w / (2.0 * PI)) * (2.0 * PI);
  for (int tc = (0); tc < (N); tc++) {
    int ee, ff;
    scanf("%d%d", &ee, &ff);
    double dist = ff - ee;
    double lo = 0;
    double hi = 1e10;
    for (int rr = (0); rr < (100); rr++) {
      double mid = (hi + lo) / 2.0;
      double t = mid;
      double alpha = w * t;
      double delta = abs(cos((PI - alpha) / 2) - cos((PI + alpha) / 2));
      if (r * delta + v * t < dist) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    printf("%.12f\n", (hi + lo) / 2.0);
  }
  return 0;
}
