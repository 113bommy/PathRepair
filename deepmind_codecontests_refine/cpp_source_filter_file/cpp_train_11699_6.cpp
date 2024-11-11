#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
double comb(long long nn, long long mm) {
  double ret = 1.0;
  for (long long i = 1; i <= mm; i++) {
    ret = ret * (nn - mm + i);
    ret = ret / i;
  }
  return ret;
}
signed main() {
  cin >> n >> m >> k;
  if (n + k < m) {
    puts("0");
    return 0;
  }
  if (k >= m) {
    puts("1");
    return 0;
  }
  double ans = 1;
  for (long long i = 0; i <= k; i++) ans *= (double)(m - i) / (n + i);
  cout << 1.0 - ans << endl;
  return 0;
}
