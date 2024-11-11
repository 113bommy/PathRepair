#include <bits/stdc++.h>
using namespace std;
void optimise() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long int mod = 1e9 + 7;
void normalize(long long int &a) { a = (a + mod) % mod; }
long long int modmul(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  normalize(a);
  normalize(b);
  return (a * b) % mod;
}
long long int modadd(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  normalize(a);
  normalize(b);
  return (a + b) % mod;
}
long long int modsub(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  normalize(a);
  normalize(b);
  return (a - b + mod) % mod;
}
long long int me(long long int x, long long int n) {
  x %= mod;
  if (n == 0) return 1;
  long long int u = me(x, n / 2) % mod;
  u = (u * u) % mod;
  if (n % 2) u = (u * x) % mod;
  return u;
}
long long int me1(long long int x, long long int n) {
  if (n == 0) return 1;
  long long int u = me1(x, n / 2);
  u = u * u;
  if (n % 2) u = u * x;
  return u;
}
inline long long int modInv(long long int a) { return me(a, mod - 2); }
inline long long int modDiv(long long int a, long long int b) {
  return modmul(a, modInv(b));
}
void solve() {
  long long int n, x;
  cin >> n >> x;
  long long int a[n];
  long long int max1 = 0;
  long long int sum = 0;
  map<long long int, long long int> m;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    max1 = max(max1, a[i]);
    sum += a[i];
  }
  for (long long int i = 0; i < n; i++) {
    m[sum - a[i]]++;
  }
  for (auto it = m.begin(); it != m.end(); it++) {
    long long int cnt = it->second;
    long long int x1 = x;
    long long int k = 0;
    while (cnt % x1 == 0) {
      k++;
      x1 *= x;
    }
    if (k != 0) {
      x1 /= x;
      cnt /= x1;
      m[k + it->first] += cnt;
      it->second = 0;
    } else
      break;
  }
  long long int s1 = 0;
  for (auto k = m.begin(); k != m.end(); k++) {
    if (k->second != 0) {
      s1 = k->first;
      break;
    }
  }
  cout << me(x, (long long int)min(sum, s1));
}
signed main() {
  optimise();
  long long int t;
  t = 1;
  cout << fixed << setprecision(6);
  while (t--) {
    solve();
    cout << endl;
  }
}
