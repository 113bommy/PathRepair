#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long phi(long long n) {
  long long ret = n;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      ret -= ret / i;
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) {
    ret -= ret / n;
  }
  return ret;
}
int f(long long k, long long n) {
  if (!k) return n;
  if (n == 1) return 1;
  return f(k - 1, phi(n));
}
int main() {
  long long n, k;
  cin >> n >> k;
  cout << f((k + 1) / 2, n) % mod << '\n';
}
