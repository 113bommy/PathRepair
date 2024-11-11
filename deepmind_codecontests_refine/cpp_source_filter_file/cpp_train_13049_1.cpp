#include <bits/stdc++.h>
using namespace std;
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <class T>
void read(T &x) {
  x = 0;
  int c = getchar();
  int flag = 0;
  while (c < '0' || c > '9') flag |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
template <class T>
T _max(T a, T b) {
  return b < a ? a : b;
}
template <class T>
T _min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
bool checkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
bool checkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
const int mod = 1000000000 + 7;
void add(int &a, int b) {
  a += b;
  (a >= mod) && (a -= mod);
}
void sub(int &a, int b) {
  a -= b;
  (a < 0) && (a += mod);
}
void mul(int &a, int b) { a = (long long)a * b % mod; }
int Add(int a, int b) {
  a += b;
  return a >= mod ? a - mod : a;
}
int Sub(int a, int b) {
  a -= b;
  return a < 0 ? a + mod : a;
}
int Mul(int a, int b) { return (long long)a * b % mod; }
int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (long long)ans * a % mod;
    a = (long long)a * a % mod;
    b >>= 1;
  }
  return ans;
}
int n, a[10];
int C[105][105];
int f[9][105];
void init() {
  read(n);
  for (int i = 0; i <= 9; ++i) read(a[i]);
  for (int i = 0; i <= 100; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) C[i][j] = Add(C[i - 1][j - 1], C[i - 1][j]);
  }
}
void solve() {
  for (int i = a[1]; i <= n; ++i) f[1][i] = 1;
  for (int i = 2; i <= 9; ++i) {
    for (int j = a[i]; j <= n; ++j) {
      for (int k = a[i]; k <= j; ++k) {
        add(f[i][j], Mul(f[i - 1][j - k], C[j][k]));
      }
    }
  }
  int ans = 0;
  for (int l = 1; l <= n; ++l) {
    for (int i = a[0]; i < l; ++i) {
      add(ans, Mul(C[l - 1][i], f[9][l - i]));
    }
  }
  printf("%d\n", ans);
}
int main() {
  init();
  solve();
  return 0;
}
