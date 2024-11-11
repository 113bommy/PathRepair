#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
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
template <typename S, typename T>
inline void Mum(S &a, const T &b) {
  a = 1LL * a * b % MOD;
}
template <typename T>
inline bool IsPri(T x) {
  if (x < 2) return false;
  for (T i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
template <typename T>
inline T Gcd(T a, T b) {
  while (b) {
    T t = b;
    b = a % b;
    a = t;
  }
  return a;
}
template <typename T>
inline int BitCnt(T x) {
  int cnt = 0;
  while (x) ++cnt, x &= x - 1;
  return cnt;
}
template <typename T>
inline T MDis(T x1, T y1, T x2, T y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}
template <typename T>
inline T MDis(T x1, T y1, T z1, T x2, T y2, T z2) {
  return abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2);
}
inline double EDis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
inline double EDis(double x1, double y1, double z1, double x2, double y2,
                   double z2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) +
              (z1 - z2) * (z1 - z2));
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
  register int x = false;
  register char ch =
      p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
          ? EOF
          : *p1++;
  ;
  register bool sgn = false;
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
const int N = 1e6 + 100;
int n, s;
vector<pair<int, int> > a[2];
int b[N];
bool check(double mid) {
  memset((b), (0), sizeof(b));
  for (auto it : a[0]) {
    int l, r, x = it.first, v = it.second;
    double d = x, z = (mid * (s + v) - d) / s;
    if (d / v <= mid)
      l = 1, r = 1e6 - 1;
    else
      l = x, r = min(x + z * (s - v), 1e6 - 1);
    if (l <= r) ++b[l], --b[r + 1];
  }
  for (int i = 1; i < N; ++i) b[i] += b[i - 1];
  for (int i = 1; i < N; ++i) b[i] += b[i - 1];
  for (auto it : a[1]) {
    int l, r, x = it.first, v = it.second;
    double d = 1e6 - x, z = (mid * (s + v) - d) / s;
    if (d / v <= mid)
      l = 1, r = 1e6 - 1;
    else
      l = max(x - z * (s - v), 1.0), r = x;
    if (l <= r && b[r] - b[l - 1]) return true;
  }
  return false;
}
int main() {
  cin >> n >> s;
  for (int i = 1; i <= n; ++i) {
    int x, v, t;
    scanf("%d%d%d", &x, &v, &t), --t;
    a[t].push_back({x, v});
  }
  double l = 0, r = 1e6, ans = 1e6;
  while (abs(l - r) > 1e-8) {
    double mid = (l + r) / 2;
    if (check(mid))
      r = mid, ans = mid;
    else
      l = mid;
  }
  printf("%.15f\n", ans);
  return 0;
}
