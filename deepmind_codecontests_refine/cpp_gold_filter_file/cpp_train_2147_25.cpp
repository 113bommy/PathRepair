#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k1, k2, k3, t1, t2, t3, n;
  cin >> k1 >> k2 >> k3 >> t1 >> t2 >> t3 >> n;
  vector<long long> c(n), c1(n), c2(n), c3(n);
  for (int i = 0; i < n; ++i) scanf("%I64d", &c[i]);
  for (int i = 0; i < n; ++i) {
    if (i - k1 < 0)
      c1[i] = c[i] + t1;
    else
      c1[i] = max(c1[i - k1], c[i]) + t1;
  }
  for (int i = 0; i < n; ++i) {
    if (i - k2 < 0)
      c2[i] = c1[i] + t2;
    else
      c2[i] = max(c2[i - k2], c1[i]) + t2;
  }
  for (int i = 0; i < n; ++i) {
    if (i - k3 < 0)
      c3[i] = c2[i] + t3;
    else
      c3[i] = max(c3[i - k3], c2[i]) + t3;
  }
  long long ma = 0;
  for (int i = 0; i < n; ++i)
    if (c3[i] - c[i] > ma) ma = c3[i] - c[i];
  cout << ma;
  return 0;
}
