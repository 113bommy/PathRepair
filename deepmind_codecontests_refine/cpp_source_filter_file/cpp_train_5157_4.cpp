#include <bits/stdc++.h>
const long long inf = 1e9 + 5;
const long long linf = 5e18 + 5;
const long double eps = 1e-9;
const long long dd = 2e6 + 7;
const long long maxn = 2e3 + 10;
const long long mod = 1e9 + 7;
const long long cc = 1 << 19;
using namespace std;
int x[dd], y[dd];
int main() {
  ios_base::sync_with_stdio(0);
  if (0) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  } else {
    if (!01) {
      freopen(
          "shopping"
          ".dat",
          "r", stdin);
      freopen(
          "shopping"
          ".sol",
          "w", stdout);
    }
  }
  int n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  int cnt = 0;
  for (long long i = 0; i < n; ++i) {
    int x1 = x[i];
    int y1 = y[i];
    int x2 = x[(i + 1) % n];
    int y2 = y[(i + 1) % n];
    int x3 = x[(i + 2) % n];
    int y3 = y[(i + 2) % n];
    if (x1 < x2 && y1 < y3) cnt++;
    if (y2 < y1 && x1 < x2) cnt++;
    if (x2 < x1 && y1 > y3) cnt++;
    if (y1 < y2 && x3 < x2) cnt++;
  }
  cout << cnt;
  return 0;
}
