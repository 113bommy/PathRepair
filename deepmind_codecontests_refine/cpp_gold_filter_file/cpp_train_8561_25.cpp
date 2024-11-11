#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
static int n;
static double x[25005], y[25005], dx[25005], dy[25005];
struct dir {
  int x, y;
  dir(int x, int y) : x(x), y(y) {
    if (y < 0) x = -x, y = -y;
  }
  bool operator<(const dir& b) const { return x * b.y < y * b.x; }
};
struct car {
  int x, y, dx, dy;
};
void read_stdin() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    double s;
    cin >> x[i] >> y[i] >> dx[i] >> dy[i] >> s;
    double sc = sqrt(dx[i] * dx[i] + dy[i] * dy[i]);
    s /= sc;
    dx[i] *= s;
    dy[i] *= s;
  }
}
void generate() {
  mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
  n = 25000;
  uniform_real_distribution<double> urd1(1, 1000), urd0(-1000, 1000);
  for (int i = 0; i < n; i++) {
    x[i] = urd0(eng);
    y[i] = urd0(eng);
    dx[i] = urd1(eng);
    dy[i] = urd1(eng);
  }
}
double solve_brute_generic() {
  double sol = 1e18;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double u = dx[j] * dy[i] - dx[i] * dy[j];
      double o = dy[j] * (x[i] - x[j]) - dx[j] * (y[i] - y[j]);
      if (abs(u) > 1e-9) {
        double ti = o / u;
        double tj = (dx[i] * ti + x[i] - x[j]) / dx[j];
        if (ti >= 0 && tj >= 0) {
          sol = min(sol, max(ti, tj));
        }
      } else if (abs(o) < 1e-9) {
        double t = 1e18;
        if ((dx[i] < 0) == (dx[j] < 0)) {
          if (dx[i] > 0) {
            t = abs(x[i] - x[j]) / (x[i] < x[j] ? dx[i] : dx[j]);
          } else {
            t = -abs(x[i] - x[j]) / (x[i] < x[j] ? dx[j] : dx[i]);
          }
        } else if ((dx[i] > 0) == (x[i] < x[j])) {
          t = abs(x[i] - x[j]) / (abs(dx[i]) + abs(dx[j]));
        }
        sol = min(sol, t);
      }
    }
  }
  return sol;
}
double solve_parallel() {
  double sol = 1e18;
  return sol;
}
void print_sol(double sol) {
  if (sol > 1e17) {
    cout << "No show :(\n";
  } else {
    cout << setprecision(20) << fixed << sol << '\n';
  }
}
int main() {
  ios::sync_with_stdio(!cin.tie(0));
  read_stdin();
  print_sol(min(solve_parallel(), solve_brute_generic()));
}
