#include <bits/stdc++.h>
using namespace std;
inline long long in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
char ch[4000010];
inline string get() {
  scanf("%s", ch);
  return string(ch);
}
inline void read(long long *a, long long n) {
  for (long long i = 0; i < n; i++) a[i] = in();
}
template <class blank>
inline void out(blank x) {
  cout << x << "\n";
  exit(0);
}
template <class blank, class blank2>
inline void smin(blank &a, blank2 b) {
  a = a <= b ? a : b;
}
template <class blank, class blank2>
inline void smax(blank &a, blank2 b) {
  a = a >= b ? a : b;
}
const long long maxn = 1e7 + 10;
const long long maxm = 4e6 + 10;
const long long maxlg = 20;
const long long base = 29;
const long long mod = 1e9 + 7;
const long long inf = 2e18 + 10;
const double eps = 1e-9;
long long a[maxn], n, x, y, MOD;
struct matrix {
  long long a[3][3];
  matrix(long long v = 0) {
    for (long long i = 0; i < 3; i++)
      for (long long j = 0; j < 3; j++) a[i][j] = i == j ? v : 0;
  }
  inline long long *operator[](const long long x) { return a[x]; }
};
inline matrix operator*(matrix &a, matrix &b) {
  matrix ret;
  for (long long i = 0; i < 3; i++)
    for (long long j = 0; j < 3; j++)
      for (long long k = 0; k < 3; k++)
        ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
  return ret;
}
inline matrix operator^(matrix a, long long tm) {
  matrix ret(1);
  while (tm) {
    if (tm % 2) ret = ret * a;
    a = a * a;
    tm /= 2;
  }
  return ret;
}
inline long long Fibterm(long long x) {
  if (x < 0) return 0;
  x++;
  matrix Z;
  Z[0][0] = 0, Z[0][1] = Z[1][0] = Z[1][1] = 1;
  Z = Z ^ x;
  return Z[0][1];
}
int32_t main() {
  n = in(), x = in(), y = in(), MOD = in();
  read(a, n);
  if (n == 1) out(a[0] % MOD);
  long long sum = 0;
  for (long long i = 0; i < n; i++) sum = (sum + a[i]) % MOD;
  matrix A(1);
  A[0][0] = 3;
  A[1][0] = A[2][0] = MOD - 1;
  A = A ^ x;
  long long mini = a[0] % MOD,
            maxi = (Fibterm(x - 1) * a[n - 2] + Fibterm(x) * a[n - 1]) % MOD;
  matrix B;
  B[0][0] = sum, B[0][1] = a[0], B[0][2] = a[n - 1];
  B = B * A;
  B[0][1] = mini, B[0][2] = maxi;
  A = matrix(1);
  A[0][0] = 3;
  A[1][0] = A[2][0] = MOD - 1;
  A = A ^ y;
  B = B * A;
  cout << B[0][0] << "\n";
}
