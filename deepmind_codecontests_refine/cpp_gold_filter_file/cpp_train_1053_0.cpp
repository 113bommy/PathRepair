#include <bits/stdc++.h>
using namespace std;
namespace io {
const int L = (1 << 20) + 1;
char buf[L], *S, *T, c;
char getchar() {
  if (__builtin_expect(S == T, 0)) {
    T = (S = buf) + fread(buf, 1, L, stdin);
    return (S == T ? EOF : *S++);
  }
  return *S++;
}
int inp() {
  int x = 0, f = 1;
  char ch;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  return x * f;
}
unsigned inpu() {
  unsigned x = 0;
  char ch;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    ;
  for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  return x;
}
long long inp_ll() {
  long long x = 0;
  int f = 1;
  char ch;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  return x * f;
}
char B[25], *outs = B + 20, *outr = B + 20;
template <class T>
inline void print(register T a, register char x = 0) {
  if (x) *--outs = x, x = 0;
  if (!a)
    *--outs = '0';
  else
    while (a) *--outs = (a % 10) + 48, a /= 10;
  if (x) *--outs = x;
  fwrite(outs, outr - outs, 1, stdout);
  outs = outr;
}
};  // namespace io
using io ::inp;
using io ::inp_ll;
using io ::inpu;
using io ::print;
using i32 = int;
using i64 = long long;
using u8 = unsigned char;
using u32 = unsigned;
using u64 = unsigned long long;
using f64 = double;
using f80 = long double;
long long power(long long a, long long b, long long p) {
  if (!b) return 1;
  long long t = power(a, b / 2, p);
  t = t * t % p;
  if (b & 1) t = t * a % p;
  return t;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long px, py;
  long long d = exgcd(b, a % b, px, py);
  x = py;
  y = px - a / b * py;
  return d;
}
template <class T>
inline void freshmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <class T>
inline void freshmax(T &a, const T &b) {
  if (a < b) a = b;
}
const int MAXN = 200010;
const int MAXP = 200000;
const int MAXK = 110;
const int MOD = 1000000009;
const f80 MI = f80(1) / MOD;
const int INF = 1000000000;
template <int MAXN>
struct mybitset {
  const static int LIMIT = (MAXN >> 6) + 1;
  u64 a[LIMIT];
  mybitset() { memset(a, 0, sizeof(a)); }
  void set(int x) { a[x >> 6] |= 1ULL << (x & 63); }
  void reset(int x) { a[x >> 6] &= 0xffffffffffffffff ^ (1ULL << (x & 63)); }
  bool test(int x) { return a[x >> 6] >> (x & 63) & 1; }
  void orshl(const mybitset &v, int shift) {
    if ((shift & 63) == 0) {
      for (int i = 0; i < LIMIT - (shift >> 6); ++i)
        a[(shift >> 6) + i] |= v.a[i];
    } else {
      a[shift >> 6] |= v.a[0] << shift;
      for (int i = 1; i < LIMIT - (shift >> 6); ++i)
        a[(shift >> 6) + i] |= (v.a[i - 1] >> (64 - shift)) | (v.a[i] << shift);
    }
  }
};
int b[MAXN];
mybitset<MAXN> u;
mybitset<MAXN> v[MAXK];
int f[MAXN];
void init(int x) {
  for (int i = 2; i <= MAXP; ++i) {
    if (!b[i]) {
      u.set(i);
      for (int j = i + i; j <= MAXP; j += i) b[j] = i;
    } else if (!b[i / b[i]])
      u.set(i);
  }
  u.reset(x);
  v[0] = u;
  for (int i = 1; i <= MAXP; ++i) {
    for (; v[f[i]].test(i); ++f[i])
      ;
    v[f[i]].orshl(u, i);
  }
}
int main() {
  int n = inp();
  init(inp());
  int ans = 0;
  while (n--) {
    int a = inp();
    int b = inp();
    int c = inp();
    ans ^= f[b - a - 1] ^ f[c - b - 1];
  }
  puts(ans ? "Alice\nBob" : "Bob\nAlice");
  return 0;
}
