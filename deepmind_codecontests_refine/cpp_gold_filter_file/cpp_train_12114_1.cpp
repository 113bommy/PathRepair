#include <bits/stdc++.h>
using namespace std;
long long int md, l, r, k;
struct matrix {
  long long int m[2][2];
  matrix() {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) m[i][j] = 0;
    }
  }
} mat;
matrix mul(matrix a, matrix b) {
  matrix c;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      c.m[i][j] = 0;
      for (int p = 0; p < 2; ++p) {
        c.m[i][j] = (c.m[i][j] + a.m[i][p] * b.m[p][j]) % md;
      }
    }
  }
  return c;
}
matrix pow(matrix base, long long int exponent) {
  matrix result;
  for (int i = 0; i < 2; ++i) result.m[i][i] = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) result = mul(result, base);
    exponent = exponent >> 1;
    base = mul(base, base);
  }
  return result;
}
long long int check(long long int q) {
  long long int x;
  if (l % q == 0)
    x = l / q;
  else
    x = l / q + 1;
  if (r / q - x + 1 >= k) return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin.tie(0);
  ;
  long long int limit, res = 0, ans = 0, q, i, j;
  cin >> md >> l >> r >> k;
  limit = sqrt(r);
  for (i = 1; i <= limit; i++) {
    if (check(i)) ans = max(ans, i);
  }
  for (i = 1; i <= limit; i++) {
    q = r / i;
    if (check(q)) ans = max(ans, q);
  }
  mat.m[0][0] = 0;
  mat.m[0][1] = 1;
  mat.m[1][0] = 1;
  mat.m[1][1] = 1;
  mat = pow(mat, ans - 1);
  res = (mat.m[0][0] + mat.m[0][1]) % md;
  cout << res;
  return 0;
}
