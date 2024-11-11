#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long fact[1000001];
long long inv[1000001];
long long primes[100007];
long long arr[1000007];
long long modPower(long long b, long long p) {
  if (p == 0) return 1;
  long long halfpow = modPower(b, p / 2);
  long long toReturn = (halfpow * halfpow) % mod;
  if (p % 2) toReturn = (toReturn * b) % mod;
  return toReturn;
}
long long fastPower(long long b, long long p) {
  if (p == 0) return 1;
  long long ans = fastPower(b, p / 2);
  ans = (ans * ans);
  if (p % 2 != 0) ans = (ans * b);
  return ans;
}
long long GcdRecursive(long long a, long long b) {
  if (b == 0) return a;
  return GcdRecursive(b, a % b);
}
long long modLCM(long long a, long long b) {
  long long val = GcdRecursive(a, b);
  long long tmp = ((a % mod) * (b % mod)) % mod;
  long long finalVal = ((tmp % mod) * (arr[val] % mod)) % mod;
  return finalVal;
}
long long LCM(long long a, long long b) { return (a * b) / GcdRecursive(a, b); }
void move1step(long long& a, long long& b, long long q) {
  long long c = a - q * b;
  a = b;
  b = c;
}
long long GcdIterative(long long a, long long b) {
  while (b) move1step(a, b, a / b);
  return a;
}
void pre(long long n) {
  fact[0] = 1;
  inv[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
    inv[i] = modPower(fact[i], mod - 2);
    arr[i] = modPower(i, mod - 2);
  }
}
long long npr(long long n, long long r) {
  return ((fact[n] * inv[n - r]) % mod);
}
long long ncr(long long n, long long r) {
  return ((((fact[n] * inv[n - r]) % mod) * inv[r]) % mod);
}
void sieve(long long val) {
  memset(primes, 1, sizeof primes);
  primes[0] = primes[1] = false;
  for (int i = 2; i <= val; i++) {
    if (primes[i]) {
      for (int j = i * i; j <= val; j += i) {
        primes[j] = 0;
      }
    }
  }
}
long double dot(complex<long double> a, complex<long double> b) {
  return (conj(a) * b).real();
}
long double cross(complex<long double> a, complex<long double> b) {
  return (conj(a) * b).imag();
}
long double angleBetVec(complex<long double> a, complex<long double> b) {
  long double d = dot(a, b);
  d /= abs(a);
  d /= abs(b);
  return acos(d) * 180 / acos(-1);
}
complex<long double> RotateAbout(complex<long double> a,
                                 complex<long double> about,
                                 long double angle) {
  return (a - about) * polar((long double)1.0, angle) + about;
}
set<long long> GetDivisors(long long val) {
  set<long long> st;
  for (int i = 1; i < sqrt(val) + 1; i++)
    if (val % i == 0) st.insert(i), st.insert(val / i);
  return st;
}
const long long MOD = 998244353;
const long long N = 1e6 + 7;
const long long inf = 1e18 + 5;
long long t, n, a, b;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    char brr[51][51];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) cin >> brr[i][j];
    bool can = true;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1; j++) {
        if (brr[i][j] == '1' && brr[i + 1][j] == '0' && brr[i][j + 1] == '0') {
          can = false;
          break;
        }
      }
    }
    if (can)
      cout << "YES";
    else
      cout << "NO";
    cout << "\n";
  }
}
