#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-9;
double zero(double d) { return d < EPS ? 0.0 : d; }
bool nn[201];
int solve(int neg, int n) {
  if (nn[neg]) {
    return neg;
  }
  nn[neg] = true;
  int pos = 2 * n - 1 - neg;
  int m = neg;
  for (int i = 0; i <= n; i++) {
    int p = n - i;
    if (pos + i - p >= 0 && neg - i + p >= 0) {
      m = min(m, solve(neg - i + p, n));
    }
  }
  return m;
}
int main() {
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(7);
  memset(nn, 0, sizeof(nn));
  int n;
  cin >> n;
  int a[2 * n - 1];
  int neg = 0;
  for (int i = 0; i < 2 * n - 1; ++i) {
    int t;
    cin >> t;
    a[i] = abs(t);
    if (t < 0) neg++;
  }
  sort(a, a + 2 * n - 1);
  int negNum = solve(neg, n);
  for (int i = 0; i < negNum; ++i) {
    a[i] *= -1;
  }
  cout << accumulate(a, a + 2 * n - 1, 0) << endl;
  return 0;
}
