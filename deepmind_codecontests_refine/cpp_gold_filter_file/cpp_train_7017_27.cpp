#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long r = 1, z = x;
  while (y) {
    if (y & 1) r *= z;
    z *= z;
    y = y >> 1;
  }
  return r;
}
long long powerm(long long x, long long y, long long p) {
  long long r = 1;
  while (y) {
    if (y & 1) r = (r * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return r % p;
}
long long modinv(long long x, long long m) { return powerm(x, m - 2, m); }
long long logarithm(long long a, long long b) {
  long long x = 0;
  while (a > 1) {
    x++;
    a /= b;
  }
  return x;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long a[n + 1];
  memset(a, 0, sizeof(a));
  for (long long i = 0; i < m; i++) {
    long long p, q, r;
    cin >> p >> q >> r;
    if (a[p]) {
      if (a[p] == 1) {
        a[q] = 2;
        a[r] = 3;
      } else if (a[p] == 2) {
        a[q] = 1;
        a[r] = 3;
      } else {
        a[q] = 2;
        a[r] = 1;
      }
    } else if (a[q]) {
      if (a[q] == 1) {
        a[p] = 2;
        a[r] = 3;
      } else if (a[q] == 2) {
        a[p] = 1;
        a[r] = 3;
      } else {
        a[p] = 2;
        a[r] = 1;
      }
    } else if (a[r]) {
      if (a[r] == 1) {
        a[q] = 2;
        a[p] = 3;
      } else if (a[r] == 2) {
        a[p] = 1;
        a[q] = 3;
      } else {
        a[p] = 2;
        a[q] = 1;
      }
    } else {
      a[p] = 1;
      a[r] = 2;
      a[q] = 3;
    }
  }
  for (long long i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}
