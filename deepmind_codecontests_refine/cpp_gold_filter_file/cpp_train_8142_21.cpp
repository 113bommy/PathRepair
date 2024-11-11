#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int maxm = 2e5 + 10;
const int mod = 1e9 + 7;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
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
  a = (a + b) % mod;
  if (a < 0) a += mod;
}
template <typename S, typename T>
inline void Mum(S &a, const T &b) {
  a = 1LL * a * b % mod;
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
inline bool IsPri(T x) {
  if (x < 2) return false;
  for (T i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
inline long long qpow(long long a, long long n) {
  long long t = 1;
  while (n) {
    if (n & 1) t = t * a % mod;
    a = a * a % mod, n >>= 1;
  }
  return t % mod;
}
struct Bit {
  inline int lowbit(int x) { return x & (-x); }
  long long Bit[maxn];
  int N;
  bool rev = 0, MOD = 0;
  void init(int x, bool y = 0, bool z = 0) {
    N = x;
    rev = y;
    MOD = z;
    fill(Bit, Bit + N + 5, 0);
  }
  void addBitMax(int x, long long v) {
    if (rev) x = N - x + 1;
    while (x <= N) Bit[x] = max(Bit[x], v), x += lowbit(x);
  }
  void addBitSum(int x, long long v) {
    if (rev) x = N - x + 1;
    while (x <= N) {
      Bit[x] = Bit[x] + v;
      if (MOD) Bit[x] %= mod;
      x += lowbit(x);
    }
  }
  long long qBitMax(int x) {
    if (rev) x = N - x + 1;
    long long res = -linf;
    while (x) res = max(res, Bit[x]), x -= lowbit(x);
    return res;
  }
  long long qBitSum(int x) {
    if (rev) x = N - x + 1;
    long long res = 0;
    while (x) {
      res = res + Bit[x];
      if (MOD) res %= mod;
      x -= lowbit(x);
    }
    if (MOD) return res % mod;
    return res;
  }
};
void p_bit(long long x) { cout << bitset<32>(x) << ':' << x << endl; }
unsigned long long has[maxn], base = 233, pp[maxn];
char s[maxn];
int a[maxn], b[maxn];
int sum[maxn];
unsigned long long get(int l, int r) {
  return has[r] - has[l - 1] * pp[r - l + 1];
}
unsigned long long cmp(int l, int r) {
  unsigned long long res = 0;
  int L = lower_bound(a + 1, a + 1 + a[0], l) - a;
  int R = upper_bound(a + 1, a + 1 + a[0], r) - a - 1;
  if (L > R) return 0;
  res = ((a[L] - l) % 2 + 1) * pp[R - L];
  if (L < R) res += get(L + 1, R);
  return res;
}
int main() {
  int n;
  scanf("%d%s", &n, s + 1);
  pp[0] = 1;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    pp[i] = pp[i - 1] * base;
    sum[i] = sum[i - 1] + (s[i] == '1');
    if (s[i] == '0') {
      a[++a[0]] = i;
      b[a[0]] = cnt % 2;
      cnt = 0;
    } else
      ++cnt;
  }
  for (int i = 1; i <= a[0]; ++i) has[i] = has[i - 1] * base + b[i] + 1;
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r, len;
    scanf("%d%d%d", &l, &r, &len);
    if ((cmp(l, l + len - 1) == cmp(r, r + len - 1)))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
