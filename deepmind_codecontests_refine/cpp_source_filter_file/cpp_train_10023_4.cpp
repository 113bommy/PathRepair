#include <bits/stdc++.h>
using namespace std;
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
long long mod(long long x, long long M) { return ((x % M + M) % M); }
long long add(long long a, long long b, long long M) {
  return mod(mod(a, M) + mod(b, M), M);
}
long long mul(long long a, long long b, long long M) {
  return mod(mod(a, M) * mod(b, M), M);
}
long long powerM(long long a, long long b, long long M) {
  long long res = 1ll;
  while (b) {
    if (b % 2ll == 1ll) {
      res = mul(a, res, M);
    }
    a = mul(a, a, M);
    b /= 2ll;
  }
  return res;
}
long long nCr(long long n, long long k) {
  if (n < k) return 0;
  if (k == 0) return 1;
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
long long modInverse(long long n, long long M) { return powerM(n, M - 2, M); }
long long nCrM(long long n, long long r, long long M) {
  if (n < r) return 0;
  if (r == 0) return 1;
  vector<long long> fact(n + 1);
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = mul(fact[i - 1], i, M);
  }
  return mul(mul(fact[n], modInverse(fact[r], M), M),
             modInverse(fact[n - r], M), M);
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long c1 = 0, c2 = 0;
  for (long long i = 0; i < n; i++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == d) {
      c1++;
    }
    if (b == c) {
      c2++;
    }
  }
  if (m % 2) {
    cout << "NO\n";
    return;
  } else {
    if (c1 < 1) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 0;
  cin >> t;
  while (t--) solve();
  return 0;
}
