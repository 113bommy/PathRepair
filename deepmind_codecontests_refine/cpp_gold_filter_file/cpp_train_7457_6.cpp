#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100000 + 5;
namespace fastIO {
inline void init() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const long long MAX_Input = 1000000;
char buf[MAX_Input], *p1, *p2;
inline bool read(long long &x) {
  static std::streambuf *inbuf = cin.rdbuf();
  x = 0;
  register long long f = 0, flag = false;
  register char ch =
      (p1 == p2 && (p2 = (p1 = buf) + inbuf->sgetn(buf, MAX_Input), p1 == p2)
           ? EOF
           : *p1++);
  for (; !isdigit(ch);
       ch = (p1 == p2 &&
                     (p2 = (p1 = buf) + inbuf->sgetn(buf, MAX_Input), p1 == p2)
                 ? EOF
                 : *p1++))
    if (ch == '-') f = 1;
  if (isdigit(ch))
    x = x * 10 + ch - '0',
    ch = (p1 == p2 && (p2 = (p1 = buf) + inbuf->sgetn(buf, MAX_Input), p1 == p2)
              ? EOF
              : *p1++),
    flag = true;
  for (; isdigit(ch);
       ch = (p1 == p2 &&
                     (p2 = (p1 = buf) + inbuf->sgetn(buf, MAX_Input), p1 == p2)
                 ? EOF
                 : *p1++))
    x = x * 10 + ch - 48;
  x = f ? -x : x;
  return flag;
}
template <typename T, typename... Args>
inline bool read(T &a, Args &...args) {
  return read(a) && read(args...);
}
inline void write(long long x) {
  static std::streambuf *outbuf = cout.rdbuf();
  static char stack[21];
  static long long top = 0;
  if (x < 0) {
    outbuf->sputc('-');
    x = -x;
  }
  if (!x) {
    outbuf->sputc('0');
    outbuf->sputc('\n');
    return;
  }
  for (; x; x /= 10) stack[++top] = x % 10 + '0';
  while (top) outbuf->sputc(stack[top--]);
  outbuf->sputc('\n');
}
template <typename T, typename... Args>
inline void write(T a, Args... args) {
  write(a);
  write(args...);
}
}  // namespace fastIO
using namespace fastIO;
long long n, p, a[MAXN], q;
long long fpow(long long x, long long y, long long p) {
  long long sum = 1;
  for (; y; y >>= 1) {
    if (y & 1) {
      sum = sum * x;
      if (sum > p) sum = sum % p + p;
    }
    x = x * x;
    if (x > p) x = x % p + p;
  }
  return sum;
}
long long calc_phi(long long x) {
  long long sum = x, m = sqrt(x) + 1;
  for (long long i = 2; i <= m; i++) {
    if (x % i == 0) {
      sum = sum * (i - 1) / i;
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) sum = sum / x * (x - 1);
  return sum;
}
map<long long, long long> phi;
long long dfs(long long now, long long r, long long p) {
  if (now == r + 1 || p == 1) return 1;
  long long res = dfs(now + 1, r, phi[p]);
  return fpow(a[now], res, p);
}
signed main() {
  read(n, p);
  for (long long i = p; i > 1;) phi[i] = calc_phi(i), i = phi[i];
  phi[1] = 1;
  for (long long i = 1; i <= n; i++) read(a[i]);
  read(q);
  while (q--) {
    long long l, r;
    read(l, r);
    write(dfs(l, r, p) % p);
  }
  return 0;
}
