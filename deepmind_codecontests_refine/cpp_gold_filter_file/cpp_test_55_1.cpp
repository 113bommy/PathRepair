#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long extgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = extgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
long long revrsno(long long n) {
  long long k = 0;
  vector<long long> z;
  while (n > 0) {
    z.push_back(n % 10);
    n /= 10;
  }
  for (long long i = 0; i < z.size(); i++) k = k * 10 + z[i];
  return k;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
long long powm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long divide(long long a, long long b) {
  return (a % 1000000007) * powm(b, 1000000007 - 2) % 1000000007;
}
long long mul(long long a, long long b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
long long add(long long a, long long b) {
  return (a % 1000000007 + b % 1000000007) % 1000000007;
}
long long Totfun(long long n) {
  long long z = n;
  if (n % 2 == 0) {
    while (n % 2 == 0) {
      n /= 2;
    }
    z /= 2;
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    if (isPrime(i) && n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      z -= z / i;
    }
  }
  if (n > 1) {
    z -= z / n;
  }
  return z;
}
long long maxPrimeFactor(long long n) {
  long long maxPrime = -1;
  while (n % 2 == 0) {
    maxPrime = 2;
    n >>= 1;
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      maxPrime = i;
      n = n / i;
    }
  }
  if (n > 2) maxPrime = n;
  return maxPrime;
}
long long fact[100001];
long long nCr(long long n, long long r) {
  if (r > n || r < 0) return 0;
  long long z = fact[n];
  z = mul(z, powm(fact[n - r], 1000000007 - 2));
  z = mul(z, powm(fact[r], 1000000007 - 2));
  return z;
}
void solve() {
  long long n;
  cin >> n;
  long long ans = powm(4, pow(2, n) - 2);
  ans %= 1000000007;
  ans *= 6;
  ans %= 1000000007;
  cout << ans << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
