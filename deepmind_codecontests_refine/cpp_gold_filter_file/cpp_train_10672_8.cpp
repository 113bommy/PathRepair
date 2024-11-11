#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
long long A[MAX], total[MAX];
int main() {
  int n;
  long long p, l, r;
  double pro1, ans = 0, x, y;
  cin >> n >> p;
  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    A[i] = r / p - (l - 1) / p;
    total[i] = r - l + 1;
  }
  for (int i = 0; i < n; ++i) {
    if (i == n - 1) {
      x = A[0];
      y = A[n - 1];
      pro1 = (x / total[0]) * ((total[n - 1] - y) / total[n - 1]) +
             (y / total[n - 1]) * ((total[0] - x) / total[0]) +
             (y / total[n - 1]) * (x / total[0]);
      ans += 2000.0 * pro1;
    } else {
      x = A[i];
      y = A[i + 1];
      pro1 = (x / total[i]) * ((total[i + 1] - y) / total[i + 1]) +
             (y / total[i + 1]) * ((total[i] - x) / total[i]) +
             (y / total[i + 1]) * (x / total[i]);
      ans += 2000.0 * pro1;
    }
  }
  printf("%.9lf\n", ans);
  return 0;
}
