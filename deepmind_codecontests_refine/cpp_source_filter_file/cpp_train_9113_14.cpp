#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6 + 3;
long long my_pow(long long a, long long b) {
  if (b == 0) return 1;
  long long c = my_pow(a, b / 2);
  if (b % 2 == 0) return c * c % mod;
  return (((c * c) % mod) * a) % mod;
}
long long inverse(long long x) {
  x = x % mod;
  return my_pow(x, mod - 2);
}
long long two(long long x) {
  if (x == 0) return x;
  return x / 2 + two(x / 2);
}
int main() {
  long long n, k;
  cin >> n >> k;
  if (n <= 60) {
    if ((1LL << n) <= k - 1) {
      cout << 1 << " " << 1 << endl;
      return 0;
    }
  }
  long long q = n + two(k - 1);
  long long b = my_pow(2, n);
  b = my_pow(b, k);
  b = (b * inverse(my_pow(2, q))) % mod;
  if (k >= mod) {
    cout << 0 << " " << b << endl;
    return 0;
  }
  long long t = my_pow(2, n), ans = 1;
  for (int i = 1; i < k; i++) {
    long long now = (t - i + mod) % mod;
    int d = 1;
    while (now % (2 * d) == 0) d = d * 2;
    ans = ans * (now * inverse(d) % mod) % mod;
  }
  cout << (b - ans + mod) % mod << " " << b << endl;
  return 0;
}
