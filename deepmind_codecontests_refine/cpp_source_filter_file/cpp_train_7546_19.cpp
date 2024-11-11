#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e18;
const long long mod = (long long)1e9 + 7;
const double pi = acos(-1.0);
const double eps = (double)1e-9;
const int N = 100500;
int n;
long long fact[N], rv[N];
inline long long bp(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  cin >> n;
  fact[0] = 1;
  rv[0] = bp(fact[0], mod - 2);
  for (int i = 1; i <= n + n - 1; i++) {
    fact[i] = fact[i - 1] * i;
    rv[i] = bp(fact[i], mod - 2);
  }
  cout << (fact[n + n - 1] * rv[n] % mod * rv[n - 1] % mod * 2 % mod - n +
           mod) %
              mod;
  return 0;
}
