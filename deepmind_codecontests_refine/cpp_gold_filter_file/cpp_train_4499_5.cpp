#include <bits/stdc++.h>
using namespace std;
long long F[1111];
int a[1111];
int was[1111][3];
long long f[1111][3];
int num, sz;
long long rec(int n, int m) {
  if (n == 0) return m == 0;
  if (was[n][m] == num) return f[n][m];
  was[n][m] = num;
  long long &res = f[n][m];
  res = 0;
  if (m + a[n] > 2) return res;
  if (m + a[n] == 0)
    res = rec(n - 1, 0);
  else {
    if (m + a[n] == 1)
      res = rec(n - 1, 2) + rec(n - 1, 0);
    else {
      if (a[n])
        res = rec(n - 1, m + a[n]);
      else
        res = rec(n - 1, m - 1);
    }
  }
  return res;
}
long long solve(long long n) {
  for (int i = sz - 1; i >= 0; --i) {
    a[i] = n >= F[i] ? 1 : 0;
    if (a[i]) n -= F[i];
  }
  assert(!n);
  num++;
  return rec(sz - 1, 0);
}
int main() {
  memset((F), (0), sizeof(F));
  F[1] = 1;
  F[2] = 2;
  sz = 2;
  while (F[sz] <= (long long)1e+18) {
    sz++;
    F[sz] = F[sz - 1] + F[sz - 2];
  }
  memset((f), (0), sizeof(f));
  memset((was), (0), sizeof(was));
  num = 0;
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    cout << solve(n) << endl;
  }
  return 0;
}
