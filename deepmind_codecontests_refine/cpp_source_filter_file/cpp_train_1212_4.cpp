#include <bits/stdc++.h>
using namespace std;
struct mat {
  long long m[16][16];
} I, A, BigA;
mat mat_mul(mat a, mat b) {
  int i, j, k;
  mat c;
  for (i = 0; i < 16; i++)
    for (j = 0; j < 16; j++) {
      c.m[i][j] = 0;
      for (k = 0; k < 16; k++)
        c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % 1000000007;
    }
  return c;
}
mat mat_power(mat a, long long n) {
  mat c = I;
  for (; n; n >>= 1) {
    if (n & 1) c = mat_mul(c, a);
    a = mat_mul(a, a);
  }
  return c;
}
void init() {
  for (int i = 0; i < 16; i++)
    for (int j = 0; j < 16; j++) {
      if (i == j)
        I.m[i][j] = 1;
      else
        I.m[i][j] = 0;
      A.m[i][j] = 0;
    }
  A.m[0][4] = 1;
  A.m[0][5] = 1;
  A.m[1][6] = 1;
  A.m[1][7] = 1;
  A.m[2][4] = 1;
  A.m[2][5] = 1;
  A.m[3][6] = 1;
  A.m[3][7] = 1;
  A.m[4][0] = 1;
  A.m[4][1] = 1;
  A.m[5][2] = 1;
  A.m[6][0] = 1;
  A.m[6][1] = 1;
  A.m[7][3] = 1;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) BigA.m[i][j] = I.m[i][j];
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) BigA.m[i + 8][j] = A.m[i][j];
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) BigA.m[i][j + 8] = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) BigA.m[i + 8][j + 8] = A.m[i][j];
}
long long cal(long long m) {
  if (m == 0 || m == -1) return 0;
  if (m == 1) return 4;
  if (m == 2) return 12;
  m -= 2;
  mat B = mat_power(BigA, m);
  long long total = 0;
  for (int i = 8; i < 16; i++)
    for (int j = 0; j < 8; j++) total = (total + B.m[i][j]) % 1000000007;
  return total + 12;
}
int main() {
  init();
  long long l, r;
  cin >> l >> r;
  long long suma = cal(r) - cal(l - 1);
  l = (l + 1) / 2;
  r = (r + 1) / 2;
  long long sumb = cal(r) - cal(l - 1);
  long long ans = (suma - sumb) * 500000004 + sumb;
  ans %= 1000000007;
  if (ans < 0) ans += 1000000007;
  cout << ans << endl;
  return 0;
}
