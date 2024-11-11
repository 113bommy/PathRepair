#include <bits/stdc++.h>
using namespace std;
const long long fix = (long long)1e9 + 7;
long long po2(long long a) {
  double temp = a;
  if (log2(temp) == (long long)log2(temp)) return log2(temp);
  return -1;
}
void tc(long long i) { cout << "Case #" << i + 1 << ": "; }
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }
void impb() { cout << "IMPOSSIBLE" << '\n'; }
long long ct() {
  long long t;
  scanf("%lld", &t);
  return t;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long modinv(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
const long long N = 5e5 + 5;
list<long long> adj[N];
queue<long long> q;
long long comanc(long long u, long long v, long long parent[]) {
  while (u ^ v) {
    if (u == 1 || v == 1) return 1;
    u = parent[u];
    v = parent[v];
  }
  return u;
}
long long x;
long long bser(long long lo, long long hi, long long arr[]) {
  while (lo < hi) {
    long long mid = lo + (hi - lo + 1) / 2;
    if (arr[mid] >= x) {
      hi = mid - 1;
    } else {
      lo = mid;
    }
  }
  return lo;
}
long long n, m;
long long arr[(long long)1e5 + 5][2];
long long rec() {}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
int32_t main() {
  long long t = ct();
  for (long long ii = (0); ii < (t); ii++) {
    long long n = ct();
    map<long long, long long> mp;
    long long a;
    for (long long j = (0); j < (n); j++) {
      a = ct();
      a += j;
      if (a < 0) {
        mp.insert(pair<long long, long long>((n - abs(a) % n) % n, 1));
      } else {
        mp.insert(pair<long long, long long>(abs(a) % n, 1));
      }
    }
    if (mp.size() == n) {
      yes();
    } else {
      no();
    }
  }
  return 0;
}
