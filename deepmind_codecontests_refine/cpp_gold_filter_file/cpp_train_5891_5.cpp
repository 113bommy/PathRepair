#include <bits/stdc++.h>
using namespace std;
pair<double, double> ar[200001];
int main() {
  double n, p1x, p1y, p2x, p2y, p3x, p3y, d, m, ans = 100000000000000;
  long int i, tempn;
  cin >> n;
  tempn = n;
  for (i = 0; i < n; i++) {
    cin >> ar[i].first >> ar[i].second;
  }
  for (i = 0; i < n; i++) {
    if (i < n - 2) {
      p1x = ar[i].first;
      p1y = ar[i].second;
      p2x = ar[i + 1].first;
      p2y = ar[i + 1].second;
      p3x = ar[i + 2].first;
      p3y = ar[i + 2].second;
      if (p1x == p3x) {
        d = abs(p1x - p2x) / 2;
        ans = min(ans, d);
      } else {
        m = (p1y - p3y) / (p1x - p3x);
        d = (p2y - p1y - m * p2x + m * p1x) / sqrt(1 + pow(m, 2));
        d = d / 2;
        d = abs(d);
        ans = min(ans, d);
      }
    } else {
      p1x = ar[i].first;
      p1y = ar[i].second;
      p2x = ar[(i + 1) % tempn].first;
      p2y = ar[(i + 1) % tempn].second;
      p3x = ar[(i + 2) % tempn].first;
      p3y = ar[(i + 2) % tempn].second;
      if (p1x == p3x) {
        d = abs(p1x - p2x) / 2;
        ans = min(ans, d);
      } else {
        m = (p1y - p3y) / (p1x - p3x);
        d = (p2y - p1y - m * p2x + m * p1x) / sqrt(1 + pow(m, 2));
        d = d / 2;
        d = abs(d);
        ans = min(ans, d);
      }
    }
  }
  cout << fixed << setprecision(8) << ans;
  return 0;
}
