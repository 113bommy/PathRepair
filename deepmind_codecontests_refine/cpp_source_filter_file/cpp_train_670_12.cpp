#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
const int INF = 1e9 + 9;
int n, t, l[N];
double p[N];
double d[2][N];
const double eps = 1e-8;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> t;
  for (int i = int(1); i <= int(n); ++i) {
    cin >> p[i] >> l[i];
    p[i] /= 100;
  }
  l[n + 1] = t;
  double ans = 0;
  d[0][0] = 1;
  for (int i = int(1); i <= int(n); ++i) {
    int xi = (i & 1);
    double fail = 1;
    for (int j = int(1); j <= int(l[i] - 1); ++j) fail = fail * (1 - p[i]);
    double cur = 0;
    d[xi][0] = 0;
    for (int j = int(1); j <= int(t); ++j) {
      d[xi][j] = 0;
      cur *= (1 - p[i]);
      if (j >= l[i]) {
        double old_boy = d[xi ^ 1][j - l[i]] * fail;
        cur -= old_boy;
        d[xi][j] = old_boy;
      }
      cur += d[xi ^ 1][j - 1];
      d[xi][j] += cur * p[i];
      if (d[xi][j] < eps) d[xi][j] = 0;
    }
    double fail_nxt = 1;
    for (int j = int(t); j >= int(t - l[i + 1] + 1); --j) {
      ans += i * d[xi][j] * fail_nxt;
      fail_nxt *= (1 - p[i + 1]);
    }
  }
  cout << fixed << setprecision(7);
  cout << ans << "\n";
  return 0;
}
