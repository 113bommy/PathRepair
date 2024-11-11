#include <bits/stdc++.h>
using namespace std;
const long long b = 1000000007;
long long kol[101], c[101][101], d[101][10001];
long long min(long long a, long long b) {
  if (a > b) {
    return b;
  }
  return a;
}
long long sqrr(long long a, long long k) {
  if (a == 1) return 1;
  long long res = 1, dega = a;
  while (k) {
    if (k & 1) {
      res = (res * dega) % b;
    }
    dega = (dega * dega) % b;
    k = k >> 1;
  }
  return res;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    kol[i] = (m / n);
    c[i][0] = 1;
    c[i][i] = 1;
  }
  for (int i = 1; i <= m % n; i++) {
    kol[i] = (kol[i] + 1);
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= n - 1; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % b;
    }
  }
  d[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int t = 0; t <= n; t++) {
      long long tmp = sqrr(c[n][t], kol[i + 1]);
      for (int j = 0; j <= min(k - t, n * i); j++) {
        d[i + 1][j + t] = (d[i + 1][j + t] + (d[i][j] * tmp) % b) % b;
      }
    }
  }
  cout << d[n][k];
  return 0;
}
