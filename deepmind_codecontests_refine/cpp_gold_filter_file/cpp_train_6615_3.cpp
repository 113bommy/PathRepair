#include <bits/stdc++.h>
using namespace std;
const double PI = acos(0) * 2;
const double EPS = 1e-8;
const long long MOD = 1e6 + 3;
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
  return __builtin_popcounll(s);
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
struct matrix {
  static const int MAXN = 120;
  long long x[MAXN][MAXN];
  matrix() { memset(x, 0, sizeof(x)); }
  matrix unit() {
    matrix res;
    for (int i = 0; i < MAXN; i++) res.x[i][i] = 1;
    return res;
  }
  matrix operator*(matrix& A) {
    matrix res;
    for (int i = 0; i < MAXN; i++)
      for (int j = 0; j < MAXN; j++) res.x[i][j] = 0;
    for (int i = 0; i < MAXN; i++)
      for (int k = 0; k < MAXN; k++)
        for (int j = 0; j < MAXN; j++) {
          (res.x[i][j] += (long long)x[i][k] * A.x[k][j]) %= MOD;
        }
    return res;
  }
  matrix operator^(long long k) {
    if (!k) return unit();
    matrix res, tmp;
    for (int i = 0; i < MAXN; i++)
      for (int j = 0; j < MAXN; j++) {
        res.x[i][j] = tmp.x[i][j] = x[i][j];
      }
    k--;
    while (k) {
      if (k & 1) res = res * tmp;
      tmp = tmp * tmp;
      k >>= 1;
    }
    return res;
  }
} A, R;
int C, W, H, dp[200], po[200];
int main() {
  cin >> C >> W >> H;
  po[0] = 1;
  for (int i = 1; i <= W; i++) {
    po[i] = mult(po[i - 1], H);
  }
  dp[0] = 1;
  for (int i = 1; i <= W; i++) {
    dp[i] = mult(dp[i - 1], H + 1);
  }
  int npo = min(W, C);
  if (C <= W) {
    cout << dp[npo];
    return 0;
  }
  npo = C - npo;
  int now = 1;
  for (int i = 0; i < W; i++) {
    A.x[i][now] = 1;
    now++;
  }
  now--;
  for (int i = 0; i <= W; i++) {
    A.x[W][i] = po[now];
    now--;
  }
  R = A ^ npo;
  int ans = 0;
  for (int i = 0; i <= W; i++) {
    addmod(ans, mult(R.x[W][i], dp[i]));
  }
  cout << ans << endl;
}
