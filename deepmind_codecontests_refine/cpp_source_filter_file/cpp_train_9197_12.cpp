#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const ll inf = 2e18;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 5;
int n, m, k;
struct Matrix {
  ll a[52][52] = {};
  Matrix operator*(const Matrix &other) {
    Matrix product;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < m; k++) {
          product.a[i][k] = (product.a[i][k] + a[i][j] * other.a[j][k]) % mod;
        }
      }
    }
    return product;
  }
};
Matrix fastpow(Matrix mat, ll n) {
  Matrix res;
  for (int i = 0; i < m; i++) {
    res.a[i][i] = 1;
  }
  while (n) {
    if (n & 1) res = (res * mat);
    n /= 2;
    mat = (mat * mat);
  }
  return res;
}
int get(char c) {
  if (c >= 'a' and c <= 'z') return c - 'a';
  return c - 'A' + 26;
}
void code() {
  cin >> n >> m >> k;
  Matrix mat;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) mat.a[i][j] = 1;
  }
  for (int i = 0; i < k; i++) {
    char c1, c2;
    cin >> c1 >> c2;
    mat.a[get(c1)][get(c2)] = 0;
  }
  Matrix ans = fastpow(mat, n - 1);
  ll sum = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      sum = (sum % mod + ans.a[i][j] % mod) % mod;
    }
  }
  cout << sum << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t-- > 0) {
    code();
  }
}
