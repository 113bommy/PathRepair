#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
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
      c.a[i][j] = 0;
      for (int k = 1; k <= a.sz; k++) {
        (c.a[i][j] += a.a[i][k] * b.a[k][j]) %= mod;
      }
    }
  }
  return c;
}
vector<long long> multiplyVec(Matrix &a, vector<long long> &b) {
  vector<long long> c(b.size());
  for (int i = 1; i <= a.sz; i++) {
    c[i] = 0;
    for (int j = 1; j <= a.sz; j++) {
      (c[i] += a.a[i][j] * b[j]) %= mod;
    }
  }
  return c;
}
Matrix generate(int sz) {
  Matrix c(sz);
  for (int i = 1; i <= sz; i++) {
    for (int j = 1; j <= sz; j++) {
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
  vector<long long> aa(2, 0);
  aa[1] = 1;
  for (int i = 1; i <= n; i++) {
    Matrix B = generate(c[i]);
    B = power(B, b[i] - a[i]);
    aa.resize(B.sz + 1);
    aa = multiplyVec(B, aa);
  }
  cout << aa[1] << endl;
}
