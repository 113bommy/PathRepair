#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void input(T &x) {
  register char c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
inline long long bigmod(long long p, long long e, long long M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
long long dp[N][6], Pr[6][N];
long long a[N];
int n, m;
struct Seg {
  long long T[6];
  long long lazy;
  bool L;
  Seg() {
    for (int i = 0; i < 6; i++) T[i] = 0;
    lazy = L = 0;
  }
} seg[4 * N];
void build(int n, int b, int e) {
  if (b == e) {
    for (int k = 0; k <= 5; k++) seg[n].T[k] = (dp[b][k] * a[b]) % MOD;
    seg[n].L = 0;
    return;
  }
  int mid = (b + e) / 2;
  build(((n) << 1), b, mid);
  build(((n) << 1 | 1), mid + 1, e);
  for (int k = 0; k <= 5; k++)
    seg[n].T[k] = seg[((n) << 1)].T[k] + seg[((n) << 1 | 1)].T[k];
  seg[n].L = 0;
}
long long getSum(int k, int x, int y) {
  return ((Pr[k][y] - Pr[k][x - 1]) % MOD + MOD) % MOD;
}
void update(int n, int b, int e, int i, int j, long long v) {
  if (seg[n].L) {
    for (int k = 0; k < 6; k++)
      seg[n].T[k] = (getSum(k, b, e) * seg[n].lazy) % MOD;
    if (b != e) {
      seg[((n) << 1)].L = 1;
      seg[((n) << 1)].lazy = seg[n].lazy;
      seg[((n) << 1 | 1)].L = 1;
      seg[((n) << 1 | 1)].lazy = seg[n].lazy;
    }
    seg[n].L = 0;
  }
  if (b > j || e < i) return;
  if (b >= i && e <= j) {
    for (int k = 0; k < 6; k++) seg[n].T[k] = (getSum(k, b, e) * v) % MOD;
    if (b != e) {
      seg[((n) << 1)].L = 1, seg[((n) << 1)].lazy = v;
      seg[((n) << 1 | 1)].L = 1, seg[((n) << 1 | 1)].lazy = v;
    }
    return;
  }
  int mid = (b + e) / 2;
  update(((n) << 1), b, mid, i, j, v);
  update(((n) << 1 | 1), mid + 1, e, i, j, v);
  for (int k = 0; k <= 5; k++)
    seg[n].T[k] = seg[((n) << 1)].T[k] + seg[((n) << 1 | 1)].T[k];
}
Seg query(int n, int b, int e, int i, int j) {
  if (seg[n].L) {
    for (int k = 0; k < 6; k++)
      seg[n].T[k] = (getSum(k, b, e) * seg[n].lazy) % MOD;
    if (b != e) {
      seg[((n) << 1)].L = 1;
      seg[((n) << 1)].lazy = seg[n].lazy;
      seg[((n) << 1 | 1)].L = 1;
      seg[((n) << 1 | 1)].lazy = seg[n].lazy;
    }
    seg[n].L = 0;
  }
  if (b > j || e < i) return Seg();
  if (b >= i && e <= j) return seg[n];
  int mid = (b + e) / 2;
  Seg x = query(((n) << 1), b, mid, i, j);
  Seg y = query(((n) << 1 | 1), mid + 1, e, i, j);
  for (int i = 0; i < 6; i++) x.T[i] = (x.T[i] + y.T[i]) % MOD;
  return x;
}
int nCr[6][6];
int main() {
  for (int i = 0; i < 6; i++) {
    nCr[i][0] = 1;
    for (int j = 1; j <= i; j++) nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
  }
  for (int i = 1; i < N; i++) {
    dp[i][0] = 1;
    for (int k = 1; k <= 5; k++) dp[i][k] = (dp[i][k - 1] * i) % MOD;
  }
  for (int k = 0; k <= 5; k++) {
    for (int i = 1; i < N; i++)
      Pr[k][i] = Pr[k][i - 1] + dp[i][k], Pr[k][i] %= MOD;
  }
  input(n), input(m);
  for (int i = 1; i <= n; i++) input(a[i]), a[i] %= MOD;
  build(1, 1, n);
  while (m--) {
    char t;
    int l, r, x;
    scanf(" %c %d %d %d", &t, &l, &r, &x);
    if (t == '?') {
      Seg v = query(1, 1, n, l, r);
      long long Out = 0;
      long long b = l - 1;
      long long temp = 1;
      for (int i = 0; i <= x; i++) {
        Out += (i % 2 == 0 ? 1 : -1) * ((nCr[x][i] * temp) % MOD * v.T[x - i]) %
               MOD;
        Out = ((Out % MOD) + MOD) % MOD;
        temp *= b;
        temp %= MOD;
      }
      cout << Out << endl;
    } else {
      update(1, 1, n, l, r, x % MOD);
    }
  }
  return 0;
}
