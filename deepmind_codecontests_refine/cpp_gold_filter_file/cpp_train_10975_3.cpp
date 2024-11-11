#include <bits/stdc++.h>
template <class T>
inline void read(T& x) {
  char c;
  bool f = 0;
  while ((c = getchar()) < '0' || '9' < c) f |= (c == '-');
  for (x = (c ^ 48); '0' <= (c = getchar()) && c <= '9';
       x = (x << 1) + (x << 3) + (c ^ 48))
    ;
  if (f) x = -x;
}
template <class T>
inline T read(const T sample) {
  T x = 0;
  char c;
  bool f = 0;
  while ((c = getchar()) < '0' || '9' < c) f |= (c == '-');
  for (x = (c ^ 48); '0' <= (c = getchar()) && c <= '9';
       x = (x << 1) + (x << 3) + (c ^ 48))
    ;
  return f ? -x : x;
}
template <class T>
void fwrit(const T x) {
  if (x < 0) return (void)(putchar('-'), fwrit(-x));
  if (x > 9) fwrit(x / 10);
  putchar(x % 10 ^ 48);
}
template <class T>
inline T Max(const T x, const T y) {
  return x > y ? x : y;
}
template <class T>
inline T Min(const T x, const T y) {
  return x < y ? x : y;
}
template <class T>
inline T fab(const T x) {
  return x > 0 ? x : -x;
}
inline int gcd(const int a, const int b) { return b ? gcd(b, a % b) : a; }
inline void getInv(int inv[], const int lim, const int MOD) {
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= lim; ++i)
    inv[i] = 1ll * inv[MOD % i] * (MOD - MOD / i) % MOD;
}
inline long long mulMod(const long long a, const long long b,
                        const long long mod) {
  return ((a * b - (long long)((long double)a / mod * b + 1e-8) * mod) % mod +
          mod) %
         mod;
}
const int MAXSIZE = 1e6;
char ch[MAXSIZE + 5];
int opt[MAXSIZE + 5], n;
inline void Init() {
  scanf("%s", ch + 1);
  n = strlen(ch + 1);
  for (signed i = (1), i_end_ = (n); i <= i_end_; ++i)
    if (ch[i] == 'L')
      opt[i] = -1;
    else
      opt[i] = 1;
  if (opt[n] == -1)
    for (signed i = (1), i_end_ = (n); i <= i_end_; ++i) opt[i] = -opt[i];
}
bool vis[MAXSIZE << 1 | 1];
inline bool check(const int x) {
  memset(vis, 0, sizeof vis);
  int pos = 0;
  vis[pos + MAXSIZE] = true;
  for (signed i = (1), i_end_ = (n - 1); i <= i_end_; ++i) {
    pos += opt[i];
    if (pos <= x + 1) pos = x + 1;
    vis[pos + MAXSIZE] = true;
  }
  pos += opt[n];
  if (!vis[pos + MAXSIZE]) return true;
  return false;
}
inline void Bisearch() {
  int l = -1e6, r = 0, mid;
  while (l < r) {
    mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", -1 - l + 1);
}
signed main() {
  Init();
  if (check(-MAXSIZE - 5)) return printf("1\n"), 0;
  Bisearch();
  return 0;
}
