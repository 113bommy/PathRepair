#include <bits/stdc++.h>
using namespace std;
long long spf[101];
long long fac[101];
void sieve() {
  spf[1] = 1;
  for (long long i = 2; i < 101; i++) spf[i] = i;
  for (long long i = 4; i < 101; i += 2) spf[i] = 2;
  for (long long i = 3; i * i < 101; i++) {
    if (spf[i] == i) {
      for (long long j = i * i; j < 101; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
map<long long, long long> getfactor(long long a) {
  map<long long, long long> m;
  while (a > 1) {
    m[spf[a]]++;
    a /= spf[a];
  }
  return m;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0 || y < 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long inverse(long long a, long long p) { return power(a, p - 2, p); }
long long ncr(long long n, long long r, long long p) {
  if (r > n) return 0;
  if (r == 0 || r == n) return 1;
  return (fac[n] * inverse(fac[r], p) % p * inverse(fac[n - r], p) % p) % p;
}
long long seg[800009], top[800009], bot[800009];
long long d[400000], h[400000];
void updateseg(long long v, long long l, long long r, long long pos,
               long long val) {
  if (l == r) {
    top[v] = 2 * h[val] + d[val];
    bot[v] = 2 * h[val] - d[val];
    return;
  }
  long long mid = (l + r) / 2;
  if (pos <= mid)
    updateseg(v * 2, l, mid, pos, val);
  else
    updateseg(v * 2 + 1, mid + 1, r, pos, val);
  seg[v] = max(seg[v * 2], seg[v * 2 + 1]);
  seg[v] = max(seg[v], bot[v * 2] + top[v * 2 + 1]);
  bot[v] = max(bot[v * 2], bot[v * 2 + 1]);
  top[v] = max(top[v * 2], top[v * 2 + 1]);
}
pair<long long, pair<long long, long long> > queryseg(long long v, long long l,
                                                      long long r,
                                                      long long posl,
                                                      long long posr) {
  if (l >= posl && r <= posr) {
    return make_pair(seg[v], make_pair(bot[v], top[v]));
  } else if (l > posr || r < posl)
    return make_pair(-1e18, make_pair(-1e18, -1e18));
  long long mid = (l + r) / 2;
  pair<long long, pair<long long, long long> > p1, p2;
  p1 = queryseg(v * 2, l, mid, posl, posr);
  p2 = queryseg(v * 2 + 1, mid + 1, r, posl, posr);
  p1.first = max(p1.first, p2.first);
  p1.first = max(p1.first, p2.second.second + p1.second.first);
  p1.second.first = max(p1.second.first, p2.second.first);
  p1.second.second = max(p1.second.second, p2.second.second);
  return p1;
}
void solve() {
  for (long long i = 0; i <= 800000; i++) {
    seg[i] = top[i] = bot[i] = -1e18;
  }
  long long n, m;
  cin >> n >> m;
  d[1] = 0;
  for (long long i = 2; i <= n + 1; i++) cin >> d[i];
  for (long long i = n + 2; i <= 2 * n; i++) d[i] = d[i - n];
  for (long long i = 2; i <= 2 * n; i++) d[i] += d[i - 1];
  for (long long i = 1; i <= n; i++) cin >> h[i], h[n + i] = h[i];
  for (long long i = 1; i <= 2 * n; i++) {
    updateseg(1, 1, 2 * n, i, i);
  }
  for (long long i = 1; i <= m; i++) {
    long long l, r;
    cin >> l >> r;
    if (l <= r)
      cout << queryseg(1, 1, 2 * n, r + 1, n + l - 1).first << '\n';
    else
      cout << queryseg(1, 1, 2 * n, r + 1, l - 1).first << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test = 1;
  while (test--) {
    solve();
  }
}
