#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const long long M = 1e8;
long long power(long long a, long long b) {
  long long result = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      result *= a;
    }
    a *= a;
    b /= 2;
  }
  return result;
}
long long gcd(long long x, long long y) {
  long long r;
  while (y != 0 && (r = x % y) != 0) {
    x = y;
    y = r;
  }
  return y == 0 ? x : y;
}
long long countSetBits(long long x) {
  long long Count = 0;
  while (x > 0) {
    if (x & 1) Count++;
    x = x >> 1;
  }
  return Count;
}
bool isPerfectSquare(long long n) {
  long long sr = sqrt(n);
  if (sr * sr == n)
    return true;
  else
    return false;
}
long long mod(long long x) { return ((x % M + M) % M); }
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }
long long powerM(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2 == 1) {
      res = mul(a, res);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res;
}
long long modInverse(long long n) { return powerM(n, M - 2); }
long long nCrM(long long n, long long r) {
  if (n < r) return 0;
  if (r == 0) return 1;
  vector<long long> fact(n + 1);
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  return mul(mul(fact[n], modInverse(fact[r])), modInverse(fact[n - r]));
}
void solve() {
  long long a, b;
  cin >> a >> b;
  long long ans = -1;
  for (long long i = 0; i <= 61; i++) {
    if ((a & ((long long)1 << i)) ^ (b & ((long long)1 << i))) {
      ans = i;
    }
  }
  if (ans > 0)
    cout << power(2, ans + 1) - 1 << endl;
  else
    cout << 0 << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
