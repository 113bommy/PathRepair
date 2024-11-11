#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const int N = (int)1e6 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const long long linf = (long long)1e18 + 7;
const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
using namespace std;
long long n, p;
long long a[N];
long long x, y;
long long sum;
long long sm(long long x, long long y) {
  x += y;
  x %= p;
  if (x < 0) x += p;
  return x;
}
long long df(long long x, long long y) { return sm(x, -y); }
long long mult(long long x, long long y) {
  x %= p, y %= p;
  return x * y % p;
}
struct matrix {
  long long m[2][2];
  matrix() { memset(m, 0, sizeof(m)); }
};
matrix operator*(matrix m1, matrix m2) {
  matrix c;
  for (int k = (0); k <= (1); k++) {
    for (int i = (0); i <= (1); i++) {
      for (int j = (0); j <= (1); j++) {
        c.m[i][j] += m1.m[i][k] * m2.m[k][j] % p;
        c.m[i][j] %= p;
      }
    }
  }
  return c;
}
long long calc(long long k) {
  matrix m, to;
  m.m[0][0] = 2;
  m.m[0][1] = -1;
  to.m[0][0] = 3;
  to.m[1][0] = 1;
  to.m[1][1] = 1;
  if (k == 0) return 1;
  if (k == 1) return m.m[0][0];
  k--;
  while (k) {
    if (k & 1) m = m * to;
    to = to * to;
    k >>= 1;
  }
  return m.m[0][0];
}
long long get(long long k) {
  if (k == 0) return a[n];
  matrix m, to;
  m.m[0][0] = a[n - 1];
  m.m[0][1] = a[n];
  to.m[0][1] = to.m[1][1] = to.m[1][0] = 1;
  while (k) {
    if (k & 1) m = m * to;
    to = to * to, k >>= 1;
  }
  return m.m[0][1];
}
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> x >> y >> p;
  for (int i = (1); i <= (n); i++) cin >> a[i], sum += a[i];
  if (n == 1) cout << a[1] % p, exit(0);
  sum %= p;
  long long mx = get(x);
  sum = sm(mult(calc(x), sum), (mult(df(sum, sm(a[1], a[n])), df(calc(x), 1))));
  sum = sm(mult(calc(y), sum), (mult(df(sum, sm(a[1], mx)), df(calc(y), 1))));
  cout << sum;
  exit(0);
}
