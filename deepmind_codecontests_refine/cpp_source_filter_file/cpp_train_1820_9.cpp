#include <bits/stdc++.h>
using namespace std;
const int size = 101;
const long long mod = 1e9 + 7;
typedef long long** matrix;
matrix new_matrix() {
  matrix res = new long long*[size];
  for (int i = 0; i < size; ++i) {
    res[i] = new long long[size];
    for (int j = 0; j < size; ++j) {
      res[i][j] = 0;
    }
  }
  return res;
}
matrix mult(matrix a, matrix b) {
  matrix res = new_matrix();
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      for (int k = 0; k < size; ++k) {
        res[i][j] += a[i][k] * b[k][j];
        res[i][j] %= mod;
      }
  return res;
}
matrix binpow(matrix a, int n) {
  if (n == 0) {
    matrix res = new_matrix();
    for (int i = 0; i < size; ++i) {
      res[i][i] = 1;
    }
    return res;
  } else if (n % 2 == 1) {
    matrix t = binpow(a, n / 2);
    return mult(a, mult(t, t));
  } else {
    matrix t = binpow(a, n / 2);
    return mult(t, t);
  }
}
int main() {
  int n, x;
  map<int, int> d;
  matrix next = new_matrix();
  matrix init = new_matrix();
  matrix far;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    int di;
    cin >> di;
    d[di] += 1;
  }
  for (int i = 0; i < size - 2; i++) next[i][i + 1] = 1;
  for (int i = 0; i < size - 1; i++) next[size - 2][size - 1 - i] = d[i];
  next[size - 1][size - 2] = 1;
  next[size - 1][size - 1] = 1;
  init[size - 2][0] = 1;
  far = mult(binpow(next, x + 1), init);
  cout << far[size - 1][0] << endl;
  return 0;
}
