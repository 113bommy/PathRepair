#include <bits/stdc++.h>
using namespace std;
const int NN = 305000;
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1)
      --b, res = (res * a) % 1000000007;
    else
      b /= 2, a = (a * a) % 1000000007;
  }
  return res;
}
long long inverse(long long a, long long b) {
  return (a * power(b, 1000000007 - 2)) % 1000000007;
}
long long n, m, k, f[NN], ans = 0;
int main() {
  cin >> n >> m >> k;
  if (!n) {
    if (m == 1) {
      if (k == 1)
        cout << 1;
      else
        cout << 0;
      return 0;
    }
    if (k == 0)
      cout << 1;
    else
      cout << 0;
    return 0;
  }
  if (!m) {
    if (n % 2 != k)
      cout << 1;
    else
      cout << 0;
    return 0;
  }
  if (m == 1) {
    for (int i = 0; i < n; i++) {
      if (i % 2 == k) ++ans;
    }
    if (n % 2 != k) ++ans;
    cout << ans;
    return 0;
  }
  f[0] = 1;
  for (int i = 1; i <= n + m; i++) f[i] = (f[i - 1] * i) % 1000000007;
  for (int i = 0; i <= n; i++) {
    if (i % 2 != k) continue;
    ans = (ans + inverse(inverse(f[n + m - i - 1], f[n - i]), f[m - 1])) %
          1000000007;
  }
  cout << ans;
  return 0;
}
