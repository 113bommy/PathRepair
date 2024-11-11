#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  x = 0;
  char c = getchar();
  int flag = 0;
  while (c < '0' || c > '9') flag |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
template <class T>
inline T _max(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline T _min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline bool checkmax(T &a, T b) {
  return b > a ? a = b, 1 : 0;
}
template <class T>
inline bool checkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
const int N = 200005, M = 3005, mod = 998244353;
int Add(int a, int b) {
  a += b;
  return a >= mod ? a - mod : a;
}
int Sub(int a, int b) {
  a -= b;
  return a < 0 ? a + mod : a;
}
int Mul(int a, int b) { return (long long)a * b % mod; }
void add(int &a, int b) {
  a += b;
  (a >= mod ? a -= mod : a);
}
void sub(int &a, int b) {
  a -= b;
  (a < 0 ? a += mod : a);
}
void mul(int &a, int b) { a = (long long)a * b % mod; }
int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) mul(ans, a);
    mul(a, a);
    b >>= 1;
  }
  return ans;
}
int get_inv(int x) { return qpow(x, mod - 2); }
int n, m, A = 0, B = 0, like = 0, dislike = 0;
int sum1 = 0, sum2 = 0, tmp1 = 0, tmp2 = 0, tmp3 = 0;
int typ[N], w[N], g[M];
int f[M][M];
void init() {
  read(n);
  read(m);
  for (int i = 1; i <= n; ++i) {
    read(typ[i]);
  }
  for (int i = 1; i <= n; ++i) {
    read(w[i]);
    if (typ[i])
      A += w[i], ++like;
    else
      B += w[i], ++dislike;
  }
  tmp1 = get_inv(A);
  tmp2 = get_inv(B);
  tmp3 = Mul(tmp2, B - m);
}
int calc_like(int x) {
  int ans = 0;
  ans = Add(sum1, Mul(tmp1, sum2));
  mul(ans, w[x]);
  return ans;
}
int calc_dislike(int x) {
  int ans = 0;
  ans = Add(Mul(tmp3, sum1), Mul(tmp2, sum2));
  mul(ans, w[x]);
  return ans;
}
void solve() {
  f[0][0] = 1;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j <= i; ++j) {
      int tmp = qpow(A + B - (i - j) + j, mod - 2);
      add(f[i + 1][j], Mul(f[i][j], Mul(B - (i - j), tmp)));
      add(f[i + 1][j + 1], Mul(f[i][j], Mul(A + j, tmp)));
    }
  }
  for (int i = 0; i <= m; ++i) {
    add(sum1, f[m][i]);
    add(sum2, Mul(f[m][i], i));
  }
  for (int i = 1; i <= n; ++i) {
    if (typ[i] == 1)
      printf("%d\n", calc_like(i));
    else
      printf("%d\n", calc_dislike(i));
  }
}
int main() {
  init();
  solve();
  return 0;
}
