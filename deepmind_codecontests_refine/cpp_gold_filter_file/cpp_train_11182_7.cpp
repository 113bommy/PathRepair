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
long long parent[300001], size_[300001], tot[300001];
void make_set(long long v) {
  parent[v] = v;
  size_[v] = 1;
}
long long find_set(long long v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(long long a, long long b, long long l) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    parent[b] = a;
    size_[a] += size_[b];
    if (l == 0)
      tot[a] += min((tot[a] + tot[b]) + 1, 1000000000ll) + tot[b];
    else
      tot[a] += l + tot[b];
  } else
    tot[a] += l;
}
void solve() {
  long long n, m, p, q;
  cin >> n >> m >> p >> q;
  pair<long long, long long> f = make_pair(0ll, 0ll);
  for (long long i = 1; i <= n; i++) make_set(i);
  for (long long i = 1; i <= m; i++) {
    long long x, y, l;
    cin >> x >> y >> l;
    union_sets(x, y, l);
    f = make_pair(x, y);
  }
  set<pair<long long, long long> > s;
  for (long long i = 1; i <= n; i++)
    s.insert(make_pair(tot[find_set(i)], find_set(i)));
  vector<pair<long long, long long> > v;
  if (s.size() < q) {
    cout << "NO" << '\n';
    return;
  }
  while (s.size() > q) {
    pair<long long, long long> pp = *s.begin();
    s.erase(s.begin());
    pair<long long, long long> qq = *s.begin();
    s.erase(s.begin());
    v.push_back(make_pair(pp.second, qq.second));
    union_sets(pp.second, qq.second, 0ll);
    f = make_pair(pp.second, qq.second);
    s.insert(make_pair(tot[find_set(pp.second)], find_set(pp.second)));
  }
  if (v.size() > p)
    cout << "NO" << '\n';
  else if (v.size() < p && f.first == 0)
    cout << "NO" << '\n';
  else {
    cout << "YES" << '\n';
    for (auto it : v) {
      cout << it.first << " " << it.second << '\n';
      p--;
    }
    while (p) {
      cout << f.first << " " << f.second << '\n';
      p--;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
}
