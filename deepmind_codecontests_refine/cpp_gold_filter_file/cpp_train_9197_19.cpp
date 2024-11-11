#include <bits/stdc++.h>
using namespace std;
const long long maxM = 60, delta = 1e9 + 7;
long long N, M, K;
struct Matrix {
  long long n = maxM, m = maxM;
  long long a[maxM][maxM];
  Matrix(long long n_ = maxM, long long m_ = maxM) {
    n = n_;
    m = m_;
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j < m; j++) a[i][j] = 0;
  }
  Matrix operator*(const Matrix& oth) {
    assert(m == oth.n);
    Matrix ret = Matrix(n, oth.m);
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j < oth.m; j++)
        for (long long k = 0; k < m; k++)
          ret.a[i][j] =
              (ret.a[i][j] + 1ll * this->a[i][k] * oth.a[k][j]) % delta;
    return ret;
  }
};
Matrix MAT;
Matrix po(Matrix A, long long b) {
  if (b == 1) return A;
  Matrix tmp = A;
  A = po(tmp, b / 2);
  A = A * A;
  if (b & 1) A = A * tmp;
  return A;
}
int por(int A, long long b) {
  if (b == 1) return A;
  int tmp = por(A, b / 2);
  tmp = tmp * tmp;
  if (b & 1) tmp = A * tmp;
  return tmp;
}
void elim(char c1, char c2) {
  long long a1 = c1 - 'a';
  long long a2 = c2 - 'a';
  if (a1 < 0) a1 += 58;
  if (a2 < 0) a2 += 58;
  MAT.a[a1][a2] = 1;
}
void input() {
  cin >> N >> M >> K;
  while (K--) {
    string s;
    cin >> s;
    elim(s[0], s[1]);
  }
}
void calc() {
  for (long long i = 0; i < M; i++)
    for (long long j = 0; j < M; j++) MAT.a[i][j] = !MAT.a[i][j];
  if (N > 1)
    MAT = po(MAT, N - 1);
  else {
    cout << M << endl;
    return;
  }
  long long ans = 0;
  for (long long i = 0; i < M; i++) {
    for (long long j = 0; j < M; j++) {
      ans = (ans + MAT.a[i][j]) % delta;
    }
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int FF = 2;
  while (00) {
    int g;
    cin >> g;
    cout << por(FF, 2) << endl;
  }
  input();
  calc();
}
