#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long MAX = 100005;
const long double PI = 3.14159265359;
const long double G = 9.807;
const long long INF = 1e18;
const long double EPS = 1e-6;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
bool isprime(long long a) {
  if (a == 2) return 1;
  if (!(a & 1)) return 0;
  for (long long i = 3; i * i <= a; i += 2)
    if (a % i == 0) return 0;
  return 1;
}
long long mpow(long long base, long long exponent, long long modulus) {
  if (modulus == 1) return 0;
  long long result = 1;
  base = base % modulus;
  while (exponent) {
    if (exponent % 2 == 1) result = (result * base) % modulus;
    exponent = exponent >> 1;
    base = (base * base) % modulus;
  }
  return result;
}
long long minv(long long a, long long mod) {
  long long _gcd = gcd(a, mod);
  assert(_gcd == 1);
  return mpow(a, mod - 2, mod);
}
long long n;
long long a[105];
long long ans[10001][105];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  long long mi = *min_element(a + 1, a + n + 1);
  long long ok = 0;
  for (long long i = mi; i >= 1; i--) {
    vector<pair<long long, long long> > difs;
    for (long long j = 1; j <= n; ++j) {
      difs.push_back({a[j] - i, j});
    }
    sort(difs.begin(), difs.end());
    long long sum = 0;
    for (long long j = 0; j < n; ++j) {
      sum += difs[j].first;
    }
    if (difs[n - 1].first == 0) {
      ok = 1;
      cout << i << '\n' << 0;
      break;
    }
    long long lo = difs[n - 1].first;
    long long hi = 10000;
    if (sum / lo < 2) continue;
    while (lo < hi) {
      long long mid = (lo + hi) >> 1;
      if ((sum + mid - 1) / mid > 5) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    long long N = lo;
    ok = 1;
    long long cur = 0;
    for (long long j = n - 1; j >= 0; j--) {
      for (long long k = 0; k < difs[j].first; ++k) {
        ans[cur % N][difs[j].second] = 1;
        cur++;
      }
    }
    cout << i << '\n';
    cout << N << '\n';
    for (long long j = 0; j < N; ++j) {
      for (long long k = 1; k <= n; ++k) {
        cout << ans[j][k];
      }
      cout << '\n';
    }
    break;
  }
  if (ok) return 0;
  cout << 0 << '\n';
  cout << (100 * (n - 1)) << '\n';
  for (long long i = 1; i <= 100 * (n - 1); ++i) {
    long long x = (i + 100 - 1) / 100;
    for (long long j = 1; j <= n; ++j) {
      if (j == x or j == n)
        cout << 1;
      else
        cout << 0;
    }
    cout << '\n';
  }
  return 0;
}
