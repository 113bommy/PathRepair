#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
bool rev(long long x, long long y) { return x > y; }
bool sortinrev(const pair<long long, long long>& a,
               const pair<long long, long long>& b) {
  return (a.first > b.first);
}
long long modulo(long long x, long long N) { return (x % N + N) % N; }
long long max(long long a, long long b) {
  if (a >= b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a <= b)
    return a;
  else
    return b;
}
long long diff(long long a, long long b) {
  if (a >= b)
    return a - b;
  else
    return b - a;
}
void pairsort(long long a[], long long b[], long long n) {
  pair<long long, long long> pairt[n];
  for (long long i = 0; i < n; i++) {
    pairt[i].first = a[i];
    pairt[i].second = b[i];
  }
  sort(pairt, pairt + n);
  for (long long i = 0; i < n; i++) {
    a[i] = pairt[i].first;
    b[i] = pairt[i].second;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long isPrime(long long n) {
  if (n < 2) return 0;
  if (n < 4) return 1;
  if (n % 2 == 0 or n % 3 == 0) return 0;
  for (long long i = 5; i * i <= n; i += 6)
    if (n % i == 0 or n % (i + 2) == 0) return 0;
  return 1;
}
long long C(long long n, long long r) {
  if (r > n - r) r = n - r;
  long long ans = 1;
  long long i;
  for (i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }
  return ans;
}
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % mod;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % mod;
    res %= mod;
  }
  return res;
}
uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t m) {
  long double x;
  uint64_t c;
  int64_t r;
  if (a >= m) a %= m;
  if (b >= m) b %= m;
  x = a;
  c = x * b / m;
  r = (int64_t)(a * b - c * m) % (int64_t)m;
  return r < 0 ? r + m : r;
}
vector<long long> rabin_karp(string const& s, string const& t) {
  const long long p = 31;
  const long long m = 1e9 + 9;
  long long S = s.size(), T = t.size();
  vector<long long> p_pow(max(S, T));
  p_pow[0] = 1;
  for (long long i = 1; i < (long long)p_pow.size(); i++)
    p_pow[i] = (p_pow[i - 1] * p) % m;
  vector<long long> h(T + 1, 0);
  for (long long i = 0; i < T; i++)
    h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
  long long h_s = 0;
  for (long long i = 0; i < S; i++)
    h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
  vector<long long> occurences;
  for (long long i = 0; i < T - S + 1; i++) {
    long long cur_h = (h[i + S] + m - h[i]) % m;
    if (cur_h == h_s * p_pow[i] % m) occurences.push_back(i);
  }
  return occurences;
}
long long sti(string s) {
  long long ans = 0;
  long long p = 1;
  for (long long i = s.size() - 1; i >= 0; i--) {
    ans = (ans + ((long long)(s[i] - '0') * p) % mod) % mod;
    p = (p * 10) % mod;
  }
  return ans;
}
void time() {}
const long long N = 1e6 + 5;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string x, z;
  cin >> x >> z;
  for (long long i = 0; i < x.size(); i++) {
    if (x[i] - 'a' < z[i] - 'a') {
      cout << -1 << "\n";
      return 0;
    }
  }
  for (long long i = 0; i < x.size(); i++) {
    if (x[i] - 'a' == z[i] - 'a') {
      cout << char(x[i] + 1);
    } else if (x[i] - 'a' > z[i] - 'a')
      cout << z[i];
  }
  return 0;
}
