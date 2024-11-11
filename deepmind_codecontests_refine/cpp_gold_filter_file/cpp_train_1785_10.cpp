#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
long long a[1000010], b[1000010], e[1000010], f[1000010];
long long qwer(long long a, long long b) {
  if (a == 0) return 0;
  long long z = 1;
  while (b) {
    if (b % 2) z = (z * a) % p;
    a = (a * a) % p;
    b /= 2;
  }
  return z;
}
long long c(int k, int i) {
  long long x = e[k];
  x = (x * f[i]) % p;
  x = (x * f[k - i]) % p;
  return x;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (m == 1) {
    cout << qwer(k, n) << endl;
    return 0;
  }
  e[0] = 1;
  f[0] = 1;
  for (int i = 1; i <= k + 1; i++) {
    e[i] = (e[i - 1] * i) % p;
    f[i] = qwer(e[i], p - 2);
  }
  a[0] = 0;
  for (int i = 1; i <= min(n, k); i++) {
    long long x, y = 0;
    x = qwer(i, n);
    for (int j = 1; j < i; j++) {
      y = (y + c(i, j) * a[j]) % p;
    }
    a[i] = (x - y) % p;
    if (a[i] < 0) a[i] += p;
  }
  if (m == 2) {
    long long s = 0;
    for (int i = 1; i <= min(n, k); i++) {
      long long x, y;
      x = (a[i] * a[i]) % p;
      y = (c(k, i) * c(k, i)) % p;
      s = (s + x * y) % p;
    }
    cout << s;
    return 0;
  }
  long long s = 0;
  for (int i = 1; i <= min(n, k); i++)
    for (int j = 0; j <= min(i, k - i); j++) {
      long long x;
      x = (c(i, i - j) * c(k - i, j)) % p;
      x = (x * c(k, i)) % p;
      x = (x * a[i]) % p;
      x = (x * a[i]) % p;
      x = (x * qwer(i - j, n * (m - 2))) % p;
      s = (s + x) % p;
    }
  cout << s;
  return 0;
}
