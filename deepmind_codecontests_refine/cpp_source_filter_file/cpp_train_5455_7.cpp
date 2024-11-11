#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9, maxn = (int)1e5 + 1;
const double eps = (double)1e-8;
int main() {
  long long n, m, s, mx, k, kk;
  cin >> n >> m >> s;
  mx = 0;
  for (int i = 1; i <= n; i++) {
    if ((i - 1) / s + (n - i) / s > mx) {
      mx = (i - 1) / s + (n - i) / s;
      k = 1;
    } else if ((i - 1) / s + (n - i) / s == mx)
      k++;
  }
  mx = 0;
  kk = 0;
  for (int i = 1; i <= m; i++) {
    if ((i - 1) / s + (m - i) / s > mx) {
      mx = (i - 1) / s + (m - i) / s;
      kk = 1;
    } else if ((i - 1) / s + (m - i) / s == mx)
      kk++;
  }
  cout << kk * k;
  return 0;
}
