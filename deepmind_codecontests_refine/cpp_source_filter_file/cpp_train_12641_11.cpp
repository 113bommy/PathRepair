#include <bits/stdc++.h>
using namespace std;
void FastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long modpow(long long a, long long p, long long mod) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    p /= 2;
  }
  return ret;
}
long long power(long long a, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a);
    a = (a * a);
    p /= 2;
  }
  return ret;
}
long long bn, bm, n, m, x, y, z, p;
pair<long long, long long> clock(long long a, long long b, long long m,
                                 long long n) {
  long long val = x % 4;
  if (val == 0)
    return pair<long long, long long>(a, b);
  else if (val == 1)
    return pair<long long, long long>(b, n + 1 - a);
  else if (val == 2)
    return pair<long long, long long>(n + 1 - a, m + 1 - b);
  else
    return pair<long long, long long>(m + 1 - b, a);
}
pair<long long, long long> hor(long long a, long long b, long long m,
                               long long n) {
  if (y % 2 == 0)
    return pair<long long, long long>(a, b);
  else
    return pair<long long, long long>(a, m + 1 - b);
}
pair<long long, long long> anticlock(long long a, long long b, long long m,
                                     long long n) {
  long long val = z % 4;
  if (val == 0)
    return pair<long long, long long>(a, b);
  else if (val == 1)
    return pair<long long, long long>(m + 1 - b, a);
  else if (val == 2)
    return pair<long long, long long>(n + 1 - a, m + 1 - b);
  else
    return pair<long long, long long>(b, n + 1 - a);
}
int main() {
  FastIO();
  cin >> n >> m >> x >> y >> z >> p;
  bn = n;
  bm = m;
  for (int i = 0; i < p; i++) {
    n = bn;
    m = bm;
    long long a, b, tmp;
    cin >> a >> b;
    pair<long long, long long> p = clock(a, b, n, m);
    if (x % 4) swap(m, n);
    a = p.first;
    b = p.second;
    p = hor(a, b, n, m);
    a = p.first;
    b = p.second;
    p = anticlock(a, b, n, m);
    cout << p.first << " " << p.second << '\n';
  }
  return 0;
}
