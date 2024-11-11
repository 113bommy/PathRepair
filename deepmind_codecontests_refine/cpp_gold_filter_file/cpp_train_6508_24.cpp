#include <bits/stdc++.h>
using namespace std;
inline int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
template <typename T>
inline bool smax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool smin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int X;
const long long mod = 1e9 + 7;
struct matrix {
  long long m[100][100];
  matrix() { memset(m, 0, sizeof(m)); }
};
matrix mul(matrix& a, matrix& b) {
  matrix c;
  for (int i = 0; i < X; i++)
    for (int j = 0; j < X; j++) {
      for (int k = 0; k < X; k++) {
        c.m[i][j] += (a.m[i][k] * b.m[k][j]) % mod;
      }
      c.m[i][j] %= mod;
    }
  return c;
}
matrix pow(matrix a, int b) {
  matrix res;
  for (int i = 0; i < (X); i++) res.m[i][i] = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
int main() {
  matrix t;
  int n, b, k;
  cin >> n >> b >> k >> X;
  for (int i = 0; i < (n); i++) {
    int d;
    cin >> d;
    for (int j = 0; j < X; j++) {
      t.m[j][(j * 10 + d) % X]++;
    }
  }
  matrix res = pow(t, b);
  cout << res.m[0][k] << endl;
  return 0;
}
