#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void check_max(T& actual, T check) {
  if (actual < check) {
    actual = check;
  }
}
template <class T>
inline void check_min(T& actual, T check) {
  if (actual > check) {
    actual = check;
  }
}
const double EPS = 1e-9;
const int IINF = 1000000000;
const double PI = acos(-1.0);
const long long LINF = 6000000000000000000LL;
namespace Solution {
double x1, y1, x2, y2, vmax, t, vx, vy, wx, wy;
void cleanup() {}
double dist(double X1, double Y1, double X2, double Y2) {
  return sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));
}
bool can(double tm) {
  double x, y;
  if (tm <= t) {
    x = x1 + tm * vx;
    y = y1 + tm * vy;
  } else {
    x = x1 + t * vx + (tm - t) * wx;
    y = y1 + t * vy + (tm - t) * wy;
  }
  double d = dist(x, y, x2, y2) / vmax;
  return d <= tm;
}
bool Read() {
  cleanup();
  if (scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2) == 4) {
    scanf("%lf%lf", &vmax, &t);
    scanf("%lf%lf", &vx, &vy);
    scanf("%lf%lf", &wx, &wy);
    return true;
  }
  return false;
}
void Run() {
  double lo = 0.0, hi = 1e12;
  for (int it = 0; it < 300; ++it) {
    double mid = (lo + hi) * 0.5;
    if (can(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  printf("%.12lf\n", (hi + lo) * 0.5);
}
}  // namespace Solution
namespace StressTest {
long long GetTime() {
  srand(time(NULL));
  return rand() << 16LL;
}
void GenerateInput() {
  FILE* output = fopen("input.txt", "w");
  srand(GetTime());
  fclose(output);
}
void BruteForce() {
  FILE* input = fopen("input.txt", "r");
  FILE* output = fopen("brute.out", "w");
  fclose(input);
  fclose(output);
}
}  // namespace StressTest
int main() {
  while (Solution::Read()) {
    Solution::Run();
  }
  return 0;
}
