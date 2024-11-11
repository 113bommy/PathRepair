#include <bits/stdc++.h>
using namespace std;
const int mod = 7340033;
int main() {
  long long a[31][1001];
  long long b[1001];
  for (int i = 0; i <= 30; ++i) {
    a[i][0] = 1;
    for (int j = 1; j <= 1000; ++j) a[i][j] = 0;
  }
  b[0] = 1;
  for (int i = 1; i <= 1000; ++i) b[i] = 0;
  for (int i = 1; i <= 30; ++i) {
    for (int j = 0; j <= 999; ++j)
      for (int k = 999 - j; k >= 0; --k) a[i][j + k + 1] += b[j] * b[k];
    for (int j = 0; j <= 1000; ++j) {
      a[i][j] %= mod;
      b[j] = 0;
    }
    for (int j = 0; j <= 1000; ++j)
      for (int k = 1000 - j; k >= 0; --k) b[j + k] += a[i][j] * a[i][k];
    for (int j = 0; j <= 1000; ++j) b[j] %= mod;
  }
  int q, n, k;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    int m = 0;
    for (; n % 2; n /= 2) ++m;
    if (n == 0) --m;
    cout << a[m][k] << '\n';
  }
  return 0;
}
