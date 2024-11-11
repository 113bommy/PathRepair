#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007;
const long long linf = 1000000000000000000LL;
const unsigned long long ulinf = (1ULL << 63) - 10ULL;
const double eps = 0.000001;
const double pi = 3.14159265358979323846;
template <class T>
T abs(T a) {
  return a >= 0 ? a : -a;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
T mod(T a, T b) {
  return (a % b + b) % b;
}
template <class T>
T lowbit(T x) {
  return x & -x;
}
long long addmod(long long a, long long b, long long c) {
  return ((a + b) % c + c) % c;
}
long long mulmod(long long a, long long b, long long c) {
  if (b == 0LL) return 0LL;
  long long ret = mulmod(a, b >> 1, c);
  ret = (ret + ret) % c;
  if (b & 1LL) ret = (ret + a) % c;
  return ret;
}
long long powmod(long long a, long long b, long long c) {
  if (b == 0LL) return 1LL;
  long long ret = powmod(a, b >> 1, c);
  ret = ret * ret % c;
  if (b & 1LL) ret = ret * a % c;
  return ret;
}
long long modinv(long long a, long long b) { return powmod(a, b - 2LL, b); }
template <class T>
void maxe(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
void mine(T &a, T b) {
  if (a > b) a = b;
}
int iszero(double a) { return abs(a) <= eps; }
template <class T>
void geti(T &a) {
  a = 0;
  T b = 1;
  char c = getchar();
  if (c == '-')
    b = -1;
  else
    a = c - 48;
  while ((c = getchar()) != ' ' && c != '\n') a = a * 10 + c - 48;
  a *= b;
}
void fileio_in_out() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
void fileio_txt() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
const int N = 3033;
const int M = 600066;
const int K = 33;
const long long md = inf;
int test;
int n, m, k, ans;
int flag[M], f[M], cnt;
int id[N][2 * N];
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1},
          dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int ff(int x) { return f[x] == x ? x : f[x] = ff(f[x]); }
int check(int x, int y, int q) {
  if (m == 1) return 0;
  if (id[x][y]) return 0;
  for (int d = 0; d < 8; d++) {
    int xx = x + dx[d], yy = (y + dy[d] + 2 * m) % (2 * m);
    if (xx < 1 || xx > n) continue;
    if (!id[xx][yy]) continue;
    int t = ff(id[xx][yy]);
    flag[t] = q;
  }
  for (int d = 0; d < 8; d++) {
    int xx = x + dx[d], yy = (y + dy[d] + 3 * m) % (2 * m);
    if (xx < 1 || xx > n) continue;
    if (!id[xx][yy]) continue;
    int t = ff(id[xx][yy]);
    if (flag[t] == q) return 0;
  }
  return 1;
}
void add(int x, int y) {
  id[x][y] = ++cnt;
  f[cnt] = cnt;
  for (int d = 0; d < 8; d++) {
    int xx = x + dx[d], yy = (y + dy[d] + 2 * m) % (2 * m);
    if (xx < 1 || xx > n) continue;
    if (!id[xx][yy]) continue;
    int t = ff(id[xx][yy]);
    f[t] = cnt;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int q = 1; q <= k; q++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (check(x, y, q)) {
      ans++;
      add(x, y);
      add(x, y + m);
    }
  }
  printf("%d\n", ans);
  return 0;
}
