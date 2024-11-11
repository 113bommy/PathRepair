#include <bits/stdc++.h>
using namespace std;
int n, m;
double fpow(double a, int p) {
  if (p == 0) return 1.0;
  double t = fpow(a, p / 2);
  t *= t;
  if (p & 1)
    return a * t;
  else
    t;
}
namespace Alice {
void work() {
  double ans = 0;
  if (m == 0) {
    ans = n;
  } else {
    ans = n;
    for (int l = 1; l <= n; l++)
      for (int h = 1; h <= m; h++) {
        double tmp = 1.0;
        tmp *= n - l;
        tmp *=
            (1 << h) - (1 << (h - 1)) * (1 + (l - 1) * (1.0 / ((1 << h) - 1)));
        tmp *= 1.0 / (1 << h);
        tmp *= 1.0 / (1 << h);
        tmp *= fpow(1.0 * ((1 << h) - 1) / (1 << h), l - 1);
        ans += tmp;
      }
  }
  cout << fixed << setprecision(9) << ans << endl;
}
}  // namespace Alice
namespace Bob {
void work() {
  double ans = n;
  cout << fixed << setprecision(9) << ans << endl;
}
}  // namespace Bob
int main() {
  ios::sync_with_stdio(false);
  string name;
  cin >> name >> n >> m;
  if (name[0] == 'A') {
    Alice::work();
  } else if (name[0] == 'B') {
    Bob::work();
  }
  return 0;
}
