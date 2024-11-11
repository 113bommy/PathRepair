#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 1000000000;
const int MOD = 1000000007;
long long b(long long a, long long n, long long mod) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return a % mod;
  }
  long long t = b(a, n / 2, mod);
  t *= t;
  t %= mod;
  if (n % 2) {
    t *= a;
  }
  t %= mod;
  return t;
}
int main() {
  long long n, m;
  cin >> n >> m;
  cout << (b(3, n, m) - 1 + m) % m;
  return 0;
}
