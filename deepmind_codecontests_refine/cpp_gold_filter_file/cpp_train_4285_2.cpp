#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool d = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') d = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return d ? x : -x;
}
inline unsigned long long rnd() {
  return ((unsigned long long)rand() << 30 ^ rand()) << 4 | rand() % 4;
}
const int N = 105, mo = 1e9 + 7, inv2 = (mo + 1) / 2;
int ksm(int x, int p) {
  int res = 1;
  for (; p; p >>= 1, x = (long long)x * x % mo) {
    if (p & 1) res = (long long)res * x % mo;
  }
  return res;
}
struct mat {
  int n, m, a[N][N];
  mat() {}
  mat(int _n, int _m) {
    n = _n;
    m = _m;
    memset(a, 0, sizeof(a));
  }
  int *operator[](int &x) { return a[x]; }
  int *operator[](const int &x) { return a[x]; }
} F, ssw;
mat operator*(mat A, mat B) {
  mat C(A.n, B.m);
  for (int i = (int)(0); i <= (int)(A.n); i++)
    for (int k = (int)(0); k <= (int)(A.m); k++) {
      for (int j = (int)(0); j <= (int)(B.m); j++)
        C[i][j] = (C[i][j] + (long long)A[i][k] * B[k][j]) % mo;
    }
  return C;
}
int n, a[N];
mat power(mat x, int p) {
  mat res = x;
  p--;
  if (p == 0) return res;
  for (; p; p >>= 1, x = x * x) {
    if (p & 1) res = res * x;
  }
  return res;
}
int f[N][N];
int main() {
  n = read();
  int k = read(), m = 0, tot = 0;
  for (int i = (int)(1); i <= (int)(n); i++) {
    a[i] = read();
    if (a[i] == 0)
      tot++;
    else
      m++;
  }
  F.n = F.m = m;
  for (int i = (int)(0); i <= (int)(m); i++) {
    int zl = tot - m + i, zy = n - tot - i, yl = m - i, yy = i;
    F[i][i] = (long long)m * (m - 1) % mo * inv2 % mo;
    F[i][i] = (F[i][i] + (long long)(n - m) * (n - m - 1) % mo * inv2) % mo;
    F[i][i] = (F[i][i] + (long long)zl * yl) % mo;
    F[i][i] = (F[i][i] + (long long)zy * yy) % mo;
    if (i) F[i][i - 1] = (long long)zl * yy % mo;
    if (i <= m) F[i][i + 1] = (long long)zy * yl % mo;
  }
  ssw.n = 1;
  ssw.m = m;
  int cnt = 0;
  for (int i = (int)(n); i >= (int)(n - m + 1); i--)
    if (a[i] == 1) cnt++;
  ssw[1][cnt] = 1;
  if (k != 0) ssw = ssw * power(F, k);
  int p = ksm(n * (n - 1) / 2, mo - 2);
  cout << (long long)ssw[1][m] * ksm(p, k) % mo;
}
