#include <bits/stdc++.h>
using namespace std;
long double PI = acos(-1);
long double DEL = 1e-10;
int M = 1e9 + 7;
const int N = 3e5 + 10;
template <class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
struct DSU {
  vector<long long> par, size;
  DSU(long long n) {
    par.resize(n + 1);
    size.resize(n + 1);
    for (long long i = 0; i <= n; i++) {
      par[i] = i;
      size[i] = 1;
    }
  }
  long long find(long long x) {
    return par[x] = (x == par[x] ? par[x] : find(par[x]));
  }
  void join(long long x, long long y) {
    long long parx = find(x), pary = find(y);
    if (parx == pary) {
      return;
    }
    if (size[parx] > size[pary]) {
      size[parx] += size[pary];
      par[pary] = parx;
    } else {
      size[pary] += size[parx];
      par[parx] = pary;
    }
  }
};
long long fpow(long long x, long long n) {
  long long res = 1;
  x %= M;
  while (n) {
    if (n & 1) res = res * x % M;
    x = x * x % M;
    n >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long popcount(long long x) { return bitset<65>(x).count(); }
void create_fac(long long n) {
  vector<long long> fac(N), inv(N);
  fac[0] = inv[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % M;
    inv[i] = fpow(fac[i], M - 2);
  }
}
long long ncr(long long n, long long r) {
  vector<long long> fac(N), inv(N);
  return fac[n] * (inv[r] * inv[n - r] % M) % M;
  return fac[n] * (fpow(fac[r], M - 2) * fpow(fac[n - r], M - 2) % M) % M;
}
void sieve(long long n) {
  vector<long long> primes;
  bool iscomp[N];
  for (long long i = 2; i <= n; ++i) {
    if (!iscomp[i]) primes.push_back(i);
    for (long long j = 0; j < primes.size() && i * primes[j] <= n; ++j) {
      iscomp[i * primes[j]] = true;
      if (i % primes[j] == 0) break;
    }
  }
}
long long cnt, sum, mid, mx, mn, ans, a[N], b[N];
long long n, m, d, i, j, k, l, p, q, r, t, w, x, y, z;
string s;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long double sum = 0;
  for (long long i = 1; i <= 2 * n; i++) {
    long double d;
    cin >> d;
    if (d - (long long)d != 0.00) {
      sum += d - (long long)d;
      cnt++;
    }
  }
  long long neut = 2 * n - cnt;
  long double ans = 0;
  if (neut > n) {
    ans = sum;
    while (cnt--) {
      sum -= 1;
      ans = min(ans, abs(sum));
    }
  } else {
    sum -= (cnt - n);
    ans = abs(sum);
    while (neut--) {
      sum -= 1;
      ans = min(ans, abs(sum));
    }
  }
  cout << fixed << setprecision(3) << ans;
}
