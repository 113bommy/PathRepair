#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int mx = 16;
struct Matrix {
  vector<vector<long long> > a;
  int sz;
  Matrix() {
    sz = 0;
    a.clear();
  }
  Matrix(int isz) {
    sz = isz;
    a.clear();
    a = vector<vector<long long> >(sz + 1, vector<long long>(sz + 1));
  }
  void makeunit() {
    for (int i = 1; i <= sz; i++) {
      for (int j = 1; j <= sz; j++) {
        a[i][j] = (i == j);
      }
    }
  }
};
Matrix multiply(Matrix &a, Matrix &b) {
  Matrix c(a.sz);
  for (int i = 1; i <= a.sz; i++) {
    for (int j = 1; j <= a.sz; j++) {
      for (int k = 1; k <= a.sz; k++) {
        (c.a[i][j] += a.a[i][k] * b.a[k][j]) %= mod;
      }
    }
  }
  return c;
}
Matrix generate(int sz) {
  Matrix c(mx);
  for (int i = 1; i <= mx; i++) {
    for (int j = 1; j <= mx; j++) {
      c.a[i][j] = (abs(i - j) <= 1 && i <= sz && j <= sz);
    }
  }
  return c;
}
Matrix power(Matrix a, long long b) {
  Matrix ans(a.sz);
  ans.makeunit();
  while (b) {
    if (b) ans = multiply(ans, a);
    a = multiply(a, a);
    b >>= 1;
  }
  return ans;
}
long long a[105], b[105];
int c[105];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(30);
  int n;
  long long k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    c[i]++;
  }
  b[n] = k;
  Matrix A(mx);
  A.makeunit();
  for (int i = 1; i <= n; i++) {
    Matrix B = generate(c[i]);
    B = power(B, b[i] - a[i]);
    A = multiply(A, B);
  }
  cout << A.a[1][1] << endl;
}
