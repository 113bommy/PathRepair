#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long mx_ll = numeric_limits<long long>::max();
const int mx_int = numeric_limits<int>::max();
const long double PI = (long double)(3.1415926535897932384626433832795);
inline bool ispow2(int x) { return (x != 0 && (x & (x - 1)) == 0); }
int msb(unsigned x) {
  union {
    double a;
    int b[2];
  };
  a = x;
  return (b[1] >> 20) - 1023;
}
template <class T>
inline void cinarr(T a, int n) {
  for (int i = 0; i < n; ++i) cin >> a[i];
}
inline long long powmod(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
inline long long gcd(long long a, long long b) {
  long long t;
  while (b) {
    a = a % b;
    t = a;
    a = b;
    b = t;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline int next() {
  int x;
  scanf("%d", &x);
  return x;
}
const int maxN = 1e7 + 1;
int pp[maxN + 1];
vector<int> prime, sp;
inline void pre_sieve() {
  sp.resize(maxN);
  for (long long i = 2; i < maxN; i++)
    if (pp[i] == 0) {
      sp[i] = i;
      for (long long j = i * i; j < maxN; j += i)
        if (pp[j] == 0) {
          sp[j] = i;
          pp[j] = 1;
        }
    }
  for (int i = 2; i < maxN; i++)
    if (pp[i] == 0) prime.push_back(i);
}
unsigned long long cnt[maxN + 2];
unsigned long long cnt2[maxN + 2];
unsigned long long power_of_p[maxN + 2];
bool ok(unsigned long long md) {
  int pr_sz = prime.size();
  bool res = true;
  for (int i = 0; i < pr_sz; i++) {
    unsigned long long pwr = 0ull;
    unsigned long long tmp = md;
    while (tmp) {
      tmp /= prime[i];
      pwr += tmp;
    }
    if (pwr < power_of_p[i]) {
      res = false;
      return res;
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int k = next();
  unsigned long long mx = 0ull;
  ;
  unsigned long long low = 0ll;
  unsigned long long high = 0ull;
  for (int i = 1; i <= k; i++) {
    int x = next();
    cnt[x]++;
    high += x;
    if (x > mx) mx = x;
  }
  if (mx == 1) {
    cout << 1 << "\n";
    return 0;
  }
  pre_sieve();
  for (int i = mx; i >= 2; i--) {
    unsigned long long t = i;
    while (t > 1) {
      cnt2[sp[t]] += cnt[i];
      t /= sp[t];
    }
    cnt[i - 1] += cnt[i];
  }
  int pr_sz = prime.size();
  for (int i = 0; i < pr_sz; i++) {
    power_of_p[i] = cnt2[prime[i]];
  }
  while (low < high) {
    unsigned long long md = ((low + high) >> 1);
    if (ok(md)) {
      high = md - 1;
    } else {
      low = md + 1;
    }
  }
  cout << low << "\n";
  return 0;
}
