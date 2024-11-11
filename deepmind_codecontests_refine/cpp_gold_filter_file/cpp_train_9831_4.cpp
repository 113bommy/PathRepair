#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[5002], b[5002];
int _gcd(int a, int b) {
  int r;
  while (a > 0) {
    r = a;
    a = b % a;
    b = r;
  }
  return b;
}
int f(int a) {
  int res1 = 0;
  for (int i = 1; i <= m; i++) {
    if (b[i] > a) break;
    if (a % b[i] == 0) {
      a /= b[i];
      res1++;
      i--;
    }
  }
  int res2 = 0, p = 2;
  while (p * p <= a) {
    if (a % p == 0) {
      a /= p;
      res2++;
    } else
      p++;
  }
  if (a != 1) res2++;
  return (res2 - res1);
}
int main() {
  int gcd[5002];
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i == 1)
      gcd[1] = a[1];
    else
      gcd[i] = _gcd(a[i], gcd[i - 1]);
  }
  for (int i = 1; i <= m; i++) cin >> b[i];
  sort(b + 1, b + m + 1);
  for (int i = n; i >= 1; i--) {
    if (f(gcd[i]) < 0) {
      for (int j = 1; j <= i; j++) {
        a[j] /= gcd[i];
        gcd[j] /= gcd[i];
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res += f(a[i]);
  }
  cout << res;
  return 0;
}
