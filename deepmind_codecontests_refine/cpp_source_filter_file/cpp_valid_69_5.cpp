#include <bits/stdc++.h>
using namespace std;
long long MOD;
inline void modulas(long long a) { MOD = a; }
inline void normal(long long &a) {
  a %= MOD;
  (a < 0) && (a += MOD);
}
inline long long modMul(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a * b) % MOD;
}
inline long long modAdd(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a + b) % MOD;
}
inline long long modSub(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, MOD - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
vector<bool> isPrime(10000010, true);
inline void seivePrime(long long L, long long R) {
  long long lim = sqrt(R);
  for (long long i = 2; i <= lim; ++i) {
    for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
      isPrime[j - L] = false;
  }
  if (L == 1) isPrime[0] = false;
}
inline long long chckPrime(long long L, long long prme) {
  return isPrime[prme - L];
}
inline long long cntPrime(long long L, long long R) {
  return count(isPrime.begin(), isPrime.begin() + R - L + 1, true);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  vector<long long> pow2;
  for (int i = 0; i <= 45; i++) pow2.push_back(1LL << i);
  while (t--) {
    long long n;
    cin >> n;
    string s;
    s = to_string(n);
    int sol = 199999;
    for (auto x : pow2) {
      string y = to_string(x);
      int tmp1 = 0, tmp2 = 0;
      int j = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == y[j]) {
          tmp1++;
          j++;
        }
      }
      int z = s.size();
      int w = y.size();
      sol = min(sol, z - tmp1 + w - tmp1);
    }
    cout << sol << "\n";
  }
  return 0;
}
