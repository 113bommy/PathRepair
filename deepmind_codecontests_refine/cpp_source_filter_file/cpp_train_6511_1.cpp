#include <bits/stdc++.h>
using namespace std;
const double PI = acos(0) * 2;
const double EPS = 1e-8;
const long long MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int oo = 1e9;
const double foo = 1e30;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcountll(s);
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
const int N = 105;
long long a[105][105], b[105][105], trans[105][105], w[105];
int n;
void mov(long long a[N][N], long long b[N][N]) {
  int i, j;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j) a[i][j] = b[i][j];
}
void mul(long long a[N][N], long long b[N][N], long long c[N][N]) {
  int i, j, k;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j) a[i][j] = 0;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j)
      for (int k = (0); k < (n); ++k)
        a[i][k] = (a[i][k] + (long long)b[i][j] * c[j][k]) % MOD;
}
int main() {
  long long k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      long long tmp = w[i] ^ w[j];
      if (cntbit(tmp) % 3 == 0) {
        trans[i - 1][j - 1] = 1;
        trans[j - 1][i - 1] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) a[i][i] = 1;
  k--;
  for (int i = 63; i >= 0; i--) {
    mul(b, a, a);
    if (1ll << i & k)
      mul(a, b, trans);
    else
      mov(a, b);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) (ans += a[i][j]) % MOD;
  }
  cout << ans;
}
