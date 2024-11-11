#include <bits/stdc++.h>
using namespace std;
const int MN = 88;
const int MOD = 1000000007;
int p2[MN], c[MN][MN];
int mul(int a, int b) { return a * (long long)b % MOD; }
int add(int a, int b) { return (a + b) % MOD; }
void init() {
  p2[0] = 1;
  for (int i = (1), _b = (80); i <= _b; i++) p2[i] = mul(p2[i - 1], 2);
  for (int i = (0), _b = (80); i <= _b; i++) {
    c[i][0] = 1;
    for (int j = (1), _b = (i); j <= _b; j++)
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
}
int power(int x, int k) {
  if (k == 0) return 1;
  if (k == 1) return x % MOD;
  int mid = power(x, k >> 1);
  mid = mul(mid, mid);
  if (k & 1)
    return mul(mid, x);
  else
    return mid;
}
int sz;
struct Matrix {
  int x[88][88];
  void print() {
    for (int i = 0, _a = (sz); i < _a; i++) {
      for (int j = 0, _a = (sz); j < _a; j++) cout << x[i][j] << ' ';
      cout << endl;
    }
  }
} I, p[88];
int start[88];
Matrix operator*(const Matrix &a, const Matrix &b) {
  Matrix c;
  for (int i = 0, _a = (sz); i < _a; i++)
    for (int j = 0, _a = (sz); j < _a; j++) {
      c.x[i][j] = 0;
      for (int k = 0, _a = (sz); k < _a; k++)
        c.x[i][j] = add(c.x[i][j], mul(a.x[i][k], b.x[k][j]));
    }
  return c;
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);
  cout << (fixed) << setprecision(6);
  init();
  long long n;
  int k;
  while (cin >> n >> k) {
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    sz = 2 * k + 3;
    memset(I.x, 0, sizeof I.x);
    for (int i = 0, _a = (sz); i < _a; i++) I.x[i][i] = 1;
    memset(p[0].x, 0, sizeof p[0].x);
    p[0].x[0][0] = 1;
    for (int i = (1), _b = (k + 1); i <= _b; i++) {
      p[0].x[i][i + k + 1] = 1;
    }
    for (int x = (0), _b = (k); x <= _b; x++) {
      for (int y = (0), _b = (x); y <= _b; y++) {
        p[0].x[x + k + 2][y + k + 2] = c[x][y];
        p[0].x[x + k + 2][y + 1] = mul(c[x][y], p2[x - y]);
      }
    }
    for (int j = (1), _b = (2 * k + 2); j <= _b; j++)
      p[0].x[0][j] = p[0].x[sz - 1][j];
    for (int i = (1), _b = (64); i <= _b; i++) p[i] = p[i - 1] * p[i - 1];
    start[0] = add(1, mul(2, power(2, k)));
    start[1] = 1;
    for (int i = (2), _b = (k + 1); i <= _b; i++)
      start[i] = mul(start[i - 1], 1);
    start[k + 2] = 2;
    for (int i = (k + 3), _b = (sz - 1); i <= _b; i++)
      start[i] = mul(start[i - 1], 2);
    Matrix res = I;
    n -= 2;
    for (int bit = (0), _b = (62); bit <= _b; bit++)
      if (n & (1LL << bit)) {
        res = res * p[bit];
      }
    int sum = 0;
    for (int i = 0, _a = (sz); i < _a; i++)
      sum = add(sum, mul(res.x[0][i], start[i]));
    cout << sum << endl;
  }
  return 0;
}
