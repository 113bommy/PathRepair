#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
long long POW(long long b, long long p) {
  long long Ans = 1;
  while (p) {
    if (p & 1) Ans = (Ans * b);
    b = (b * b);
    p >>= 1;
  }
  return Ans;
}
long long BigMod(long long b, long long p, long long Mod) {
  long long Ans = 1;
  while (p) {
    if (p & 1) Ans = (Ans * b) % Mod;
    b = (b * b) % Mod;
    p >>= 1;
  }
  return Ans % Mod;
}
long long ModInverse(long long b, long long Mod) {
  return BigMod(b, Mod - 2, Mod);
}
string tostr(int n) {
  stringstream rr;
  rr << n;
  return rr.str();
}
void deb(istream_iterator<string> it) { cout << endl; }
template <typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ",   ";
  deb(++it, args...);
}
long long MOD = 1e9 + 7;
long long DIM = 0;
struct matrix {
  long long a[101][101];
  matrix() { memset(a, 0, sizeof(a)); }
  void init(long long m) {
    a[0][0] = 1, a[0][m - 1] = 1;
    for (long long i = 1; i < m; i++) a[i][i - 1] = 1;
  }
  void print() {
    for (int i = 0; i < DIM; i++)
      for (int j = 0; j < DIM; j++)
        cout << a[i][j] << (j == DIM - 1 ? '\n' : ' ');
  }
  matrix multiply(matrix &B) {
    matrix C;
    for (long long r = 0; r < DIM; r++)
      for (long long c = 0; c < DIM; c++) {
        C.a[r][c] = 0;
        for (long long k = 0; k < DIM; k++)
          C.a[r][c] = (C.a[r][c] + a[r][k] * B.a[k][c]) % MOD;
      }
    return C;
  }
  matrix power(long long n) {
    matrix P;
    if (n == 1) return (*this);
    P = power(n / 2);
    P = P.multiply(P);
    if (n & 1) P = multiply(P);
    return P;
  }
};
int main() {
  long long n;
  long long m;
  cin >> n >> m;
  DIM = m;
  if (n < m) return cout << "1\n", 0;
  matrix mat;
  mat.init(m);
  mat = mat.power(n - m + 1);
  long long ans = 0;
  for (int i = 0; i < m; i++) ans = (ans + mat.a[0][i]) % MOD;
  cout << ans << "\n";
}
