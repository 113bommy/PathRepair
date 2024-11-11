#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long a[100][100], b[100][1], C[50][50];
long long n, k;
void cal() {
  for (int i = 0; i <= k; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
  }
}
void init() {
  cal();
  for (int i = 0; i < 2 * k + 3; ++i) b[i][0] = 1;
  a[2 * k + 2][2 * k + 2] = 1;
  for (int i = 0; i < k + 1; ++i)
    a[2 * k + 2][i] = C[k][i], a[2 * k + 2][i + k + 1] = C[k][i];
  for (int i = 0; i < k + 1; ++i) {
    for (int j = i; j < k + 1; ++j)
      a[i][j] = a[i][j + k + 1] = a[i + k + 1][j] = C[k - i][j - i];
  }
}
void calmatrix1() {
  long long c[100][1] = {0};
  for (int i = 0; i < 2 * k + 3; ++i)
    for (int j = 0; j < 2 * k + 3; ++j)
      c[i][0] = (c[i][0] + a[i][j] * b[j][0]) % MOD;
  memcpy(b, c, sizeof(c));
}
void calmatrix2() {
  long long c[100][100] = {0};
  for (int i = 0; i < 2 * k + 3; ++i)
    for (int j = 0; j < 2 * k + 3; ++j)
      for (int t = 0; t < 2 * k + 3; ++t)
        c[i][t] = (c[i][t] + a[i][j] * a[j][t]) % MOD;
  memcpy(a, c, sizeof(c));
}
long long solve(int x) {
  init();
  x -= 1;
  while (x) {
    if (x & 1) calmatrix1();
    calmatrix2();
    x >>= 1;
  }
  return b[2 * k + 2][0];
}
int main() {
  cin >> n >> k;
  cout << solve(n);
  return 0;
}
