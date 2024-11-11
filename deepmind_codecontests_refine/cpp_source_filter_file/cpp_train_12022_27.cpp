#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> l(n);
  vector<int> r(n);
  for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
  double result = 0;
  for (int mask = 1; mask < (1 << n); ++mask) {
    for (int p = 1; p <= 10; ++p) {
      for (int j = 0; j < n; ++j)
        if (!(mask >> j & 1) && p < r[j]) {
          int lo = max(p + 1, l[j]);
          double pr = double(r[j] - lo + 1) / (r[j] - l[j] + 1);
          for (int i = 0; i < n; ++i) {
            if (i == j) continue;
            if (mask >> i & 1) {
              if (p >= l[i] && p <= r[i])
                pr *= 1.0 / (r[i] - l[i] + 1);
              else
                pr *= 0;
            } else {
              int hi = min(p - 1, r[i]);
              if (hi < l[i])
                pr *= 0;
              else
                pr *= double(hi - l[i] + 1) / (r[i] - l[i] + 1);
            }
          }
          result += pr * p;
        }
      if (__builtin_popcount(mask) <= 1) continue;
      double pr = 1;
      for (int i = 0; i < n; ++i) {
        if (mask >> i & 1) {
          if (p >= l[i] && p <= r[i])
            pr *= 1.0 / (r[i] - l[i] + 1);
          else
            pr *= 0;
        } else {
          int hi = min(p - 1, r[i]);
          if (hi < l[i])
            pr *= 0;
          else
            pr *= double(hi - l[i] + 1) / (r[i] - l[i] + 1);
        }
      }
      result += pr * p;
    }
  }
  cout << setprecision(10) << fixed << result << endl;
  return 0;
}
