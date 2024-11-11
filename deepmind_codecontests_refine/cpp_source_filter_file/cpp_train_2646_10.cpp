#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger &operator,(const T &v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
inline long long gcd(long long a, long long b) {
  a = ((a) < 0 ? -(a) : (a));
  b = ((b) < 0 ? -(b) : (b));
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
long long ext_gcd(long long A, long long B, long long *X, long long *Y) {
  long long x2, y2, x1, y1, x, y, r2, r1, q, r;
  x2 = 1;
  y2 = 0;
  x1 = 0;
  y1 = 1;
  for (r2 = A, r1 = B; r1 != 0;
       r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y) {
    q = r2 / r1;
    r = r2 % r1;
    x = x2 - (q * x1);
    y = y2 - (q * y1);
  }
  *X = x2;
  *Y = y2;
  return r2;
}
inline long long modInv(long long a, long long m) {
  long long x, y;
  ext_gcd(a, m, &x, &y);
  x %= m;
  if (x < 0) x += m;
  return x;
}
inline long long power(long long a, long long p) {
  long long res = 1, x = a;
  while (p) {
    if (p & 1) res = (res * x);
    x = (x * x);
    p >>= 1;
  }
  return res;
}
inline long long bigmod(long long a, long long p, long long m) {
  long long res = 1 % m, x = a % m;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
inline int STRLEN(char *s) {
  int p = 0;
  while (s[p]) p++;
  return p;
}
int dir8[8][2] = {{-1, 0},  {0, 1}, {1, 0},  {0, -1},
                  {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
const long long inf = 2147383647;
const long long mod = 1e9 + 7;
const double pi = 2 * acos(0.0);
const double eps = 1e-9;
const int Size = 1000055;
int N, M, X;
int DP[10000000];
long long call(int pos, int opn, int tot) {
  if (opn < 0) return 0;
  if (tot > M) return 0;
  if (pos == N) {
    if (opn == 0 && tot == M) return 1;
    return 0;
  }
  int state = (M + 1) * (M + 1) * pos + (M + 1) * tot + opn;
  state %= 10000000;
  if (DP[state] != -1) return DP[state];
  long long res = 0;
  if (pos == X - 1) {
    res += call(pos + 1, opn + 1, tot + 1);
    if (opn > 0) res += call(pos + 1, opn, tot + 1);
    if (opn == 0) res += call(pos + 1, opn, tot + 1);
  } else {
    res += call(pos + 1, opn + 1, tot + 1);
    if (opn > 0) res += call(pos + 1, opn, tot + 1);
    if (opn == 0) res += call(pos + 1, opn, tot + 1);
    res += call(pos + 1, opn - 1, tot);
    res += call(pos + 1, opn, tot);
  }
  return DP[state] = res % mod;
}
int main() {
  scanf("%d %d %d", &M, &N, &X);
  memset(DP, -1, sizeof(DP));
  long long res = 0;
  if (N >= M) {
    res = call(0, 0, 0);
  }
  for (int i = 1; i <= M; i++) res = (res * i) % mod;
  cout << res << endl;
  return 0;
}
