#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long add() { return 0; }
template <typename T, typename... Types>
T add(T var1, Types... var2) {
  return (((((long long)(var1)) % mod + (long long)(add(var2...))) % mod) +
          mod) %
         mod;
}
long long mul() { return 1; }
template <typename T, typename... Types>
T mul(T var1, Types... var2) {
  return (((long long)(var1)) % mod * (long long)(mul(var2...))) % mod;
}
long long T;
signed main() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "YES" << '\n';
    cout << 2 << " " << 1 << '\n';
    cout << 1 << " " << 2 << '\n';
    return 0;
  }
  if (n % 2 == 0) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
    long long cnt = 0;
    cout << 2 * n + 4 << " " << n * (n + 2) << '\n';
    for (long long i = 1; i <= n + 2; i++) {
      for (long long j = i + 1; j <= n + 2; j++) {
        if (j - i == 1 && (j == 2 || j % 2 == 1)) continue;
        cout << i << " " << j << '\n';
        cout << i + n + 2 << " " << j + n + 2 << '\n';
      }
    }
    cout << 2 << " " << 2 + n << '\n';
  }
  return 0;
}
