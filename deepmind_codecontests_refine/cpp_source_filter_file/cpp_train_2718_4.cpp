#include <bits/stdc++.h>
using namespace std;
int d, p, f[11][11], c[11][11], x = 1, y = 2, one = 3, idx = 3, z, w[11], I;
inline int add(int a, int b) {
  cout << "+ " << a << ' ' << b << ' ' << ++idx << endl;
  return idx;
}
inline int pw(int a) {
  cout << "^ " << a << ' ' << idx << endl;
  return idx;
}
using ll = long long;
int mul(int a, int n) {
  int b = -1;
  while (n) {
    if (n & 1) b = b < 0 ? a : add(b, a);
    a = add(a, a);
    n >>= 1;
  }
  return b;
}
ll inv(ll a) {
  ll ret = 1;
  int b = p - 2;
  while (b) {
    if (b & 1) ret = ret * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ret;
}
int sqr(int a) {
  for (int i = 0; i <= d - 2; i++) w[i] = i ? add(w[i - 1], one) : a;
  for (int i = 0; i <= d - 2; i++) {
    w[i] = pw(w[i]);
    if ((d - 2 - i) % 2) w[i] = mul(w[i], p - 1);
  }
  for (int i = d - 1; i > 1; --i)
    for (int j = 1; j <= d - 2; j++) w[j] = add(w[j], w[j + 1]);
  return mul(add(w[0], add(mul(a, p - f[d - 2][1] % p), z)), I);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> d >> p;
  for (int i = 0; i <= d; i++)
    for (int j = c[i][0] = 1; j <= i; j++)
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  f[0][d] = 1;
  for (int i = 1; i <= d - 2; i++)
    for (int j = 0; j <= d - i + 1; j++)
      for (int k = 0; k < j; k++) f[i][k] += c[j][k] * f[i - 1][j];
  z = mul(one, p - f[d - 2][0] % p);
  I = inv(f[d - 2][2]);
  cout << "f "
       << mul(add(sqr(add(x, y)), mul(add(sqr(x), sqr(y)), p - 1)),
              (p + 1) / 2);
  return 0;
}
