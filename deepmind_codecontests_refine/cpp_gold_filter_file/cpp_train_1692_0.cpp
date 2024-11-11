#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long int mod = 1e9 + 7;
const long double eps = 1e-9;
const long long int maxn = 1e6;
long long int fact[maxn + 3];
template <typename T>
void add(T &a, T b) {
  a += b;
  if (a >= mod) a -= mod;
}
template <typename T>
void sub(T &a, T b) {
  a -= b;
  if (a < 0) a += mod;
}
template <typename T>
void mul(T &a, T b) {
  a *= b;
  if (a >= mod) a %= mod;
}
void calcfac() {
  fact[0] = 1;
  fact[1] = 1;
  for (long long int i = 2; i <= maxn; i++) fact[i] = (fact[i - 1] * i) % mod;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int fastexp(long long int a, long long int b) {
  a %= mod;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long int inverse(long long int n) { return fastexp(n, mod - 2); }
long long int ncr(long long int n, long long int r) {
  if (n < r || (n < 0) || (r < 0)) return 0;
  return (((fact[n] * inverse(fact[r])) % mod) * inverse(fact[n - r])) % mod;
}
int pct(int x) { return __builtin_popcount(x); }
int bits(int x) { return 31 - __builtin_clz(x); }
void solve() {
  long long int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << "0\n";
    return;
  } else if (a < b) {
    if (b % a == 0) {
      long long int div = b / a;
      long long int count = 0;
      while (div % 2 == 0) {
        count++;
        div /= 2;
      }
      if (div != 1) {
        cout << "-1\n";
        return;
      } else {
        long long int ans = count / 3;
        if (count % 3) ans++;
        cout << ans << '\n';
        return;
      }
    } else {
      cout << "-1\n";
      return;
    }
  } else {
    long long int lead = 0;
    long long int c = a;
    while (c % 2 == 0) {
      lead++;
      c /= 2;
    }
    long long int d = a >> lead;
    if (d > b) {
      cout << "-1\n";
      return;
    }
    if (a % b == 0) {
      long long int div = a / b;
      long long int count = 0;
      while (div % 2 == 0) {
        count++;
        div /= 2;
      }
      if (div != 1) {
        cout << "-1\n";
        return;
      } else {
        long long int ans = count / 3;
        if (count % 3) ans++;
        cout << ans << '\n';
        return;
      }
    } else {
      cout << "-1\n";
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TC;
  TC = 1;
  cin >> TC;
  for (int t = 0; t < TC; t++) solve();
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
