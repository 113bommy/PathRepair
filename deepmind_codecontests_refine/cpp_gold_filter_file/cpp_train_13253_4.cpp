#include <bits/stdc++.h>
using namespace std;
long long Q = 1e9 + 7;
long long poww(long long a, long long b) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y);
      if (x > Q) x %= Q;
    }
    y = (y * y);
    if (y > Q) y %= Q;
    b /= 2;
  }
  return x;
}
long long C[52][52];
void binomialCoeff() {
  long long i, j;
  for (i = 0; i <= 50; i++) {
    for (j = 0; j <= 50; j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long ans = 0;
  if (m == 1) {
    ans = 1;
  } else if (k == 1 || k > n) {
    ans = poww(m, n);
  } else if (n == k) {
    ans = poww(m, (k + 1) / 2);
    ans %= Q;
  } else if (k % 2 != 0) {
    ans = m * m;
    ans %= Q;
  } else {
    ans = m;
    ans %= Q;
  }
  ans %= Q;
  cout << ans << "\n";
  return 0;
}
