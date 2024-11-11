#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long pwr(long long x, long long y, long long mod = MOD) {
  long long res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
inline long long addmod(long long a, long long b) { return ((a + b) % MOD); }
inline long long mulmod(long long a, long long b) { return ((a * b) % MOD); }
bool check_composite(long long n, long long a, long long d, long long s) {
  long long x = pwr(a, d, n);
  if (x == 1 || x == n - 1) return false;
  for (long long r = 1; r < s; r++) {
    x = x * x % n;
    if (x == n - 1) return false;
  }
  return true;
};
const long long first12prime[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool isPrime(long long n) {
  if (n < 2) return false;
  long long r = 0;
  long long d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }
  for (long long i = 0; i < 12; i++) {
    long long a = first12prime[i];
    if (n == a) return true;
    if (check_composite(n, a, d, r)) return false;
  }
  return true;
}
const long long PM = 1e5;
vector<long long> primes;
vector<bool> is_comp;
void sieve() {
  is_comp.resize(PM, false);
  for (long long i = 2; i < PM; i++) {
    if (!is_comp[i]) primes.push_back(i);
    for (long long j = 0; j < primes.size() && primes[j] * i < PM; j++) {
      is_comp[primes[j] * i] = true;
      if (i % primes[j] == 0) break;
    }
  }
}
inline long long sfunc(long long a, long long b) { return a + b; }
long long n;
long long *stree;
void build() {
  for (long long i = n - 1; i > 0; --i)
    stree[i] = sfunc(stree[i << 1], stree[i << 1 | 1]);
}
void modify(long long p, long long value) {
  for (stree[p += n] = value; p > 1; p >>= 1)
    stree[p >> 1] = sfunc(stree[p], stree[p ^ 1]);
}
long long query(long long l, long long r) {
  long long res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = sfunc(res, stree[l++]);
    if (r & 1) res = sfunc(res, stree[--r]);
  }
  return res;
}
long long c, m;
long long par[1001];
long long siz[1001];
long long find(long long u) {
  long long u2 = u;
  while (u ^ par[u]) u = par[u];
  par[u2] = u;
  return u;
}
long long join(long long u, long long v) {
  long long p1 = find(u);
  long long p2 = find(v);
  if (siz[p1] < siz[p2]) {
    par[p1] = p2;
    siz[p2] += siz[p1];
    return p2;
  } else {
    par[p2] = p1;
    siz[p1] += siz[p2];
    return p1;
  }
}
inline long long myceil(long long a, long long b) {
  return (a % b == 0 ? a / b : a / b + 1);
}
map<long long, long long> grundy;
long long calcGrun(long long x) {
  if (grundy.find(x) != grundy.end()) return grundy[x];
  long long k = 1, i = 1;
  set<long long> nums;
  while (i <= x) {
    nums.insert(calcGrun((x & ((1 << (k - 1)) - 1)) | (x >> k)));
    i <<= 1;
    k++;
  }
  i = 0;
  for (long long z : nums) {
    if (z > i) break;
    i++;
  }
  return grundy[x] = i;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  sieve();
  long long n;
  cin >> n;
  long long a, a2;
  long long xr = 0;
  map<long long, long long> pr_vals;
  for (long long i = 0; i < n; i++) {
    cin >> a;
    a2 = a;
    for (long long p : primes) {
      if (p > a) break;
      long long cur = 0;
      while (a % p == 0) {
        a /= p;
        cur++;
      }
      if (cur) {
        pr_vals[p] |= 1LL << (cur - 1);
      }
    }
    if (a > 1) pr_vals[a2] = 1;
  }
  for (pair<long long, long long> x : pr_vals) xr ^= calcGrun(x.second);
  cout << (xr == 0 ? "Arpa\n" : "Mojtaba\n");
}
