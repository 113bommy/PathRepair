#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int size = 2;
const long long MOD = 1000000007;
struct Matrix {
  long long X[2][2];
  Matrix() {}
  void init() {
    memset(X, 0, sizeof(X));
    for (int i = 0; i < size; ++i) X[i][i] = 1;
  }
} aux;
Matrix operator*(const Matrix& m1, const Matrix& m2) {
  Matrix m;
  memset(m.X, 0, sizeof(m.X));
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      for (int k = 0; k < size; ++k)
        m.X[i][k] = (m.X[i][k] + m1.X[i][j] * m2.X[j][k]) % MOD;
  return m;
}
Matrix pow(Matrix M0, long long n) {
  Matrix ret;
  ret.init();
  while (n) {
    if (n & 1LL) ret = ret * M0;
    M0 = M0 * M0;
    n >>= 1LL;
  }
  return ret;
}
int main() {
  int k;
  scanf("%d", &k);
  Matrix theOneThatFucks;
  Matrix theOneThatGetsFucked;
  theOneThatFucks.X[0][0] = 2;
  theOneThatFucks.X[0][1] = 1;
  theOneThatFucks.X[1][0] = 0;
  theOneThatFucks.X[1][1] = -1;
  theOneThatGetsFucked.X[1][0] = 0;
  theOneThatGetsFucked.X[0][0] = theOneThatGetsFucked.X[1][1] =
      theOneThatGetsFucked.X[0][1] = 1;
  Matrix ans;
  Matrix tmp = theOneThatFucks;
  long long n = 1;
  bool f = true;
  for (long long i = 0; i < k; i++) {
    long long x;
    scanf("%lld", &x);
    n *= x;
    if (x > 2) f = false;
    if (n > 2) f = false;
    tmp = pow(tmp, x);
  }
  if (f) {
    if (n == 1) printf("%d/%d\n", 0, 1);
    if (n == 2) printf("%d/%d\n", 1, 2);
    return 0;
  }
  tmp = tmp * pow(theOneThatFucks, MOD - 2);
  long long q = tmp.X[0][0];
  tmp = tmp * pow(theOneThatFucks, MOD - 2);
  tmp = tmp * pow(theOneThatFucks, MOD - 2);
  ans = tmp * theOneThatGetsFucked;
  printf("%d/%d\n", int(ans.X[0][1] % MOD), int(q % MOD));
  return 0;
}
