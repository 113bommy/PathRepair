#include <bits/stdc++.h>
using namespace std;
long long bin(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = res * a % 1000000007;
    }
    a = a * a % 1000000007;
    b /= 2;
  }
  return res;
}
inline long long inver(long long a) { return bin(a, 1000000007 - 2); }
long long fact[20000], inv[20000];
long long c(long long n, long long k) {
  if (inv[k] == 0) {
    inv[k] = inver(fact[k]);
  }
  if (inv[n - k] == 0) {
    inv[n - k] = inver(fact[n - k]);
  }
  return fact[n] * inv[k] % 1000000007 * inv[n - k] % 1000000007;
}
int n;
map<int, int> m;
long long ans = 1;
void init() {
  cin >> n;
  for (int a, i = 0; i < n; ++i) {
    cin >> a;
    for (int j = 2; j * j <= a; ++j) {
      while (a % j == 0) {
        ++m[j], a /= j;
      }
    }
    if (a != 1) {
      ++m[a];
    }
  }
  fact[0] = 1;
  for (long long i = 1; i < 20000; ++i) {
    fact[i] = fact[i - 1] * i % 1000000007;
  }
}
int main() {
  init();
  for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
    ans = ans * c(it->second + n - 1, n - 1) % 1000000007;
  }
  cout << ans << "\n";
  return 0;
}
