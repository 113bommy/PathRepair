#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long p, long long mod) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    p /= 2;
  }
  return ret;
}
long long power(long long a, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a);
    a = (a * a);
    p /= 2;
  }
  return ret;
}
int main() {
  int i, j, tmp;
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long m, n, k, ans, a, b, x, y;
  cin >> n >> m >> k;
  if (k >= (n + m - 1)) {
    cout << -1 << endl;
    return 0;
  }
  a = max(n, m);
  b = min(n, m);
  if (k <= (a - 1)) {
    x = (a / (k + 1)) * b;
    y = (b / (k + 1)) * a;
    cout << max(x, y) << endl;
    return 0;
  }
  x = (a / (k - b + 2));
  y = (b / (k - a + 2));
  cout << max(x, y) << endl;
  return 0;
}
