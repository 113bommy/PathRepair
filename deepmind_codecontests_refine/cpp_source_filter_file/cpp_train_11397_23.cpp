#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const long long LINF = 1LL << 60;
const double inf = 1e15;
long long mod = 1e9 + 7;
char READ_DATA;
int SIGNAL_INPUT;
template <typename Type>
inline Type ru(Type &v) {
  SIGNAL_INPUT = 1;
  while ((READ_DATA = getchar()) < '0' || READ_DATA > '9')
    if (READ_DATA == '-')
      SIGNAL_INPUT = -1;
    else if (READ_DATA == EOF)
      return EOF;
  v = READ_DATA - '0';
  while ((READ_DATA = getchar()) >= '0' && READ_DATA <= '9')
    v = v * 10 + READ_DATA - '0';
  v *= SIGNAL_INPUT;
  return v;
}
inline long long modru(long long &v) {
  long long p = 0;
  SIGNAL_INPUT = 1;
  while ((READ_DATA = getchar()) < '0' || READ_DATA > '9')
    if (READ_DATA == '-')
      SIGNAL_INPUT = -1;
    else if (READ_DATA == EOF)
      return EOF;
  p = v = READ_DATA - '0';
  while ((READ_DATA = getchar()) >= '0' && READ_DATA <= '9') {
    v = (v * 10 + READ_DATA - '0') % mod;
    p = (p * 10 + READ_DATA - '0') % (mod - 1);
  }
  v *= SIGNAL_INPUT;
  return p;
}
template <typename A, typename B>
inline char ru(A &x, B &y) {
  if (ru(x) == EOF) return EOF;
  ru(y);
  return 2;
}
template <typename A, typename B, typename C>
inline char ru(A &x, B &y, C &z) {
  if (ru(x) == EOF) return EOF;
  ru(y);
  ru(z);
  return 3;
}
template <typename A, typename B, typename C, typename D>
inline char ru(A &x, B &y, C &z, D &w) {
  if (ru(x) == EOF) return EOF;
  ru(y);
  ru(z);
  ru(w);
  return 4;
}
struct Edge {
  int u, v, next;
  long long w, cap, flow;
  Edge(int _u = 0, int _v = 0, int nxt = -1, long long _w = 1,
       long long _cap = 0) {
    u = _u;
    v = _v;
    w = _w;
    cap = _cap;
    flow = 0;
    next = nxt;
  }
  int operator<(const Edge &b) const { return w < b.w; }
};
const int maxn = 1e3 + 10, N = 2e6 + 1;
double eps = 1e-7, pi = acos(-1.0);
unsigned long long seed = 131, smod = (1LL << 32) - 267;
long long n, k, m;
long long f[maxn][100][2];
long long power[maxn];
int main() {
  ru(n, k, m);
  power[0] = 1 % k;
  for (register int i = 1; i <= n; ++i) power[i] = power[i - 1] * 10 % k;
  f[0][0][0] = 1;
  for (register int i = 0; i < n; ++i)
    for (register int j = 0; j < k; ++j) {
      for (register int r = (i == n - 1); r < 10; ++r) {
        long long tmp = (r * power[i] + j) % k;
        if (tmp == 0 && r != 0)
          (f[i + 1][tmp][1] += f[i][j][0]) %= m;
        else
          (f[i + 1][tmp][0] += f[i][j][0]) %= m;
        (f[i + 1][tmp][1] += f[i][j][1]);
      }
    }
  long long ans = 0;
  for (register int j = 0; j < k; ++j) (ans += f[n][j][1]) %= m;
  cout << ans;
}
