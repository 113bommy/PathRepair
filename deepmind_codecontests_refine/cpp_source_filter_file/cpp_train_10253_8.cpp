#include <bits/stdc++.h>
using namespace std;
template <class T>
T bigmod(T b, T p, T m) {
  if (!p) return 1;
  T res = (bigmod(b, p / 2, m)) % m;
  res = (res * res) % m;
  if (p & 1) res = (res * b) % m;
  return res % m;
}
template <class T>
T modinv(T b, T m) {
  return bigmod(b, m - 2, m);
}
const long long INF = 1 << 30;
const long long MOD = 1000000007;
const int MAX = 1000005;
const int sz = 200005;
long long dist(long long a, long long b, long long d) {
  double db = (double)ceil((double)abs((double)a - (double)b) / (double)d);
  return (long long)db;
}
int main() {
  long long v1, v2, t, d, i, j, k, l, m, n;
  while (cin >> v1 >> v2 >> t >> d) {
    if (d == 0) {
      cout << v2 * t << endl;
      continue;
    }
    m = v2;
    while (1) {
      if (dist(v1, m + 1, d) + dist(v2, m + 1, d) > t) break;
      m++;
    }
    m--;
    n = 0;
    for (i = v1; i < m; i += d) n += i;
    for (i = v2; i < m; i += d) n += i;
    k = dist(v1, m, d) + dist(v2, m, d);
    n += m * (t - k);
    cout << n << endl;
  }
  return 0;
}
