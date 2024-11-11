#include <bits/stdc++.h>
using namespace std;
long long int t1, t2, x1, x2, t0;
inline bool better(double new_t, double optimal_t, double t0) {
  if (new_t >= t0) {
    return abs(new_t - t0) < abs(optimal_t - t0);
  }
  return false;
}
inline double temp(int y1, int y2) {
  double den = (double)(y1 + y2);
  if (abs(den) < 1e-8) return 0.0;
  return (t1 * y1 + t2 * y2) / den;
}
int main(int argc, const char *argv[]) {
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  int y1 = 0;
  int y2 = 0;
  int best_y1 = -1;
  int best_y2 = -1;
  double optimal_t = -1;
  for (int i = x1; i >= 0; i--) {
    y1 = i;
    double new_t;
    int l = 0, r = x2;
    while (l != r) {
      y2 = (l + r) / 2;
      if (temp(y1, y2) >= t0) {
        r = y2;
      } else {
        l = y2 + 1;
      }
    }
    y2 = l;
    if (y1 == 0) y2 = x2;
    if (t1 == t2) y1 = x1, y2 = x2;
    new_t = temp(y1, y2);
    if (better(new_t, optimal_t, t0)) {
      optimal_t = new_t;
      best_y1 = y1;
      best_y2 = y2;
    }
  }
  cout << best_y1 << " " << best_y2 << endl;
  return 0;
}
