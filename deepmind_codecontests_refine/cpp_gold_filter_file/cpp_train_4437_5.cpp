#include <bits/stdc++.h>
using namespace std;
long long binpow(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long binpowmod(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long mod_inverse(long long n, long long p) {
  return binpowmod(n, p - 2, p);
}
int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
bool comp(long long x, long long y) { return x > y; }
bool isPowerOfTwo(long long x) { return x && (!(x & (x - 1))); }
bool comp2(pair<long long, long long> &x, pair<long long, long long> &y) {
  return x.second < y.second;
}
void solve() {
  int m, i;
  cin >> m;
  vector<long long> a(m);
  vector<pair<long long, long long> > b(m);
  for (i = 0; i < m; i++) cin >> a[i];
  for (i = 0; i < m; i++) cin >> b[i].second, b[i].first = i;
  sort(b.begin(), b.end(), comp2);
  sort(a.begin(), a.end(), comp);
  for (i = 0; i < m; i++) b[i].second = a[i];
  sort(b.begin(), b.end());
  for (i = 0; i < m; i++) cout << b[i].second << ' ';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
