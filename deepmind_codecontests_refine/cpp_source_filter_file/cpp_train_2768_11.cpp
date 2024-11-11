#include <bits/stdc++.h>
using namespace std;
double x[1007], y[1007];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  double res = numeric_limits<double>::max();
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      double dx = x[j] - x[i];
      double dy = y[j] - y[i];
      double db = dx * dx + dy * dy;
      double dist = sqrt(db);
      res = min(res, dist);
    }
    int j = i + 2;
    if (i + 2 == n) j = 0;
    double dx = x[j] - x[i];
    double dy = y[j] - y[i];
    double db = dx * dx + dy * dy;
    double dist = sqrt(db);
    dist = sqrt(db);
    {
      double a = x[j] * y[i] - y[j] * x[i];
      for (int k = 0; k < n; k++) {
        if (i == k || j == k) continue;
        double ip = (x[k] - x[i]) * dx + (y[k] - y[i]) * dy;
        if (0 > ip || ip > db) continue;
        res = min(res, abs(dy * x[k] - dx * y[k] + a) / dist);
      }
    }
  }
  cout << setprecision(10) << res / 2 << endl;
}
