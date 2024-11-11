#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long M = 1e9 + 7;
long long mod(long long x) { return ((x % M + M) % M); }
long long addMod(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mulMod(long long a, long long b) { return mod(mod(a) * mod(b)); }
long long powMod(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a % M;
  long long res = 1;
  while (b) {
    if (b % 2 == 1) res = mulMod(res, a);
    a = mulMod(a, a);
    b = b / 2;
  }
  return res;
}
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / (gcd(a, b)); }
long long findGCD(long long A[], long long n) {
  long long res = A[0];
  for (long long i = 1; i < n; i++) {
    res = gcd(A[i], res);
    if (res == 1) return 1;
  }
  return res;
}
long long setBit(long long n, long long x) { return n | (1 << x); }
long long clearBit(long long n, long long x) { return n & ~(1 << x); }
long long toggleBit(long long n, long long x) { return n ^ (1 << x); }
bool getBit(long long n, long long x) { return (bool)(n & (1 << x)); }
void solve() {
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string ans;
  for (long long i = 0; i < n; i++) {
    if (k == 0) {
      ans.push_back(s[i]);
      continue;
    }
    if (s[i] <= 'm') {
      if (k > ('z' - s[i])) {
        k = k - ('z' - s[i]);
        ans.push_back('z');
      } else {
        ans.push_back(k + s[i]);
        k = 0;
      }
    } else {
      if (k > (s[i] - 'a')) {
        k = k - (s[i] - 'a');
        ans.push_back('a');
      } else {
        ans.push_back(s[i] - k);
        k = 0;
      }
    }
  }
  if (k == 0)
    cout << ans;
  else
    cout << -1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  { solve(); }
  return 0;
}
