#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
int dir[8][2] = {-1, 0, 1, 0, 0, -1, 0, 1, -1, -1, -1, 1, 1, -1, 1, 1};
template <typename S, typename T>
ostream &operator<<(ostream &os, const pair<S, T> x) {
  os << "(" << x.first << ", " << x.second << ")";
  return os;
}
template <typename S, typename T>
inline bool Min(S &a, const T &b) {
  return a > b ? a = b, true : false;
}
template <typename S, typename T>
inline bool Max(S &a, const T &b) {
  return a < b ? a = b, true : false;
}
template <typename S, typename T>
inline void Adm(S &a, const T &b) {
  a = (a + b) % MOD;
  if (a < 0) a += MOD;
}
template <typename T>
inline bool IsPri(T x) {
  if (x < 2) return false;
  for (T i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
template <typename T>
inline T _Gcd(T a, T b) {
  while (b) {
    T t = b;
    b = a % b;
    a = t;
  }
  return a;
}
template <typename T>
inline int _BitCnt(T x) {
  int cnt = 0;
  while (x) ++cnt, x &= x - 1;
  return cnt;
}
inline long long Pow(long long a, long long n) {
  long long t = 1;
  a %= MOD;
  while (n > 0) {
    if (n & 1) t = t * a % MOD;
    a = a * a % MOD, n >>= 1;
  }
  return t % MOD;
}
inline int read() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  int x = false;
  char ch =
      p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
          ? EOF
          : *p1++;
  ;
  bool sgn = false;
  while (ch != '-' && (ch < '0' || ch > '9'))
    ch = p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
  ;
  if (ch == '-')
    sgn = true,
    ch = p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
  ;
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48),
    ch = p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
  ;
  return sgn ? -x : x;
}
const int N = 510;
int a[N];
long long f[N][N];
long long DFS(int l, int r) {
  if (l >= r) return 1;
  if (f[l][r] >= 0) return f[l][r];
  int pos = -1, mi = INF;
  for (int i = l; i <= r; ++i)
    if (Min(mi, a[i])) pos = i;
  long long A = 0, B = 0;
  for (int i = l; i <= pos; ++i) Adm(A, DFS(l, i - 1) * DFS(i, pos - 1));
  for (int i = pos; i <= r; ++i) Adm(B, DFS(pos + 1, i) * DFS(i + 1, r));
  return f[l][r] = A * B % MOD;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  memset(f, -1, sizeof(f));
  cout << DFS(1, n) << endl;
  return 0;
}
