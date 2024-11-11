#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
int f[1234][1234];
int main() {
  for (int d = 1; d < 36; d++) {
    f[0][d - 1] = 1;
    for (int k = 1; k < 36; k++)
      for (int i = 0; i < k; i++) f[k][d] += f[i][d - 1] * f[k - i - 1][d - 1];
  }
  int n, h;
  cin >> n >> h;
  cout << f[n][n] - f[n][h - 1] << endl;
  return 0;
}
