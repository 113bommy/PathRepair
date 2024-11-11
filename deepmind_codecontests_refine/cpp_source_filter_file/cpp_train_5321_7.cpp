#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 101;
constexpr int MAXP = 11;
constexpr double INF = numeric_limits<double>::max();
constexpr double EPS = 1.e-3;
double F[MAXN][MAXP];
int n;
int a[MAXN], p[MAXN];
vector<pair<int, int>> ap;
double C, T;
inline double eval(double cte, double mul, double t) {
  return cte + t + mul / (1.0 + C * t);
}
inline double tern(double cte, double mul) {
  double lb = 0;
  double ub = T;
  int its = 1000;
  while (fabs(ub - lb) > EPS and its) {
    its--;
    double m1 = (ub - lb) / 3 + lb;
    double m2 = ub - (ub - lb) / 3;
    double vm1 = eval(cte, mul, m1);
    double vm2 = eval(cte, mul, m2);
    if (vm1 > vm2) {
      lb = m1;
    } else {
      ub = m2;
    }
  }
  return eval(cte, mul, (ub + lb) / 2.0);
}
int solve() {
  cin >> n >> C >> T;
  ap.clear();
  for (int i = 0; i < n; i++) {
    int ai, pi;
    cin >> ai >> pi;
    ap.push_back({ai, pi});
  }
  sort(ap.begin(), ap.end());
  for (int i = n - 1; i >= 0; i--) {
    tie(a[n - i - 1], p[n - i - 1]) = ap[i];
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 10 * n; j++) F[i][j] = INF;
  F[0][0] = 0.0;
  for (int i = 0; i < n; i++) {
    for (int k = i; k >= 0; k--) {
      double d = pow(0.9, k + 1);
      for (int x = 0; x <= 10 * k; x++) {
        F[k + 1][x + p[i]] = min(F[k + 1][x + p[i]], F[k][x] + a[i] / d);
      }
    }
  }
  for (int x = 10 * n; x > 0; x--) {
    for (int k = 1; k <= n; k++) {
      if (F[k][x] == INF) continue;
      if (tern(k * 10, F[k][x]) <= T + EPS) {
        return x;
      }
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) cout << solve() << '\n';
}
