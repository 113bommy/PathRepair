#include <bits/stdc++.h>
using namespace std;
constexpr long long N = 2e5 + 5;
constexpr long long M = 998244353;
struct IO {
  char buf[(1 << 20)], *p1, *p2;
  char pbuf[(1 << 20)], *pp;
  IO() : p1(buf), p2(buf), pp(pbuf) {}
  ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
  inline char gc() {
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, (1 << 20), stdin);
    return p1 == p2 ? ' ' : *p1++;
  }
  inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }
  template <class T>
  inline void read(T &x) {
    double tmp = 1;
    bool sign = 0;
    x = 0;
    char ch = gc();
    for (; !(ch >= '0' && ch <= '9'); ch = gc())
      if (ch == '-') sign = 1;
    for (; (ch >= '0' && ch <= '9'); ch = gc()) x = x * 10 + (ch - '0');
    if (ch == '.')
      for (ch = gc(); (ch >= '0' && ch <= '9'); ch = gc())
        tmp /= 10.0, x += tmp * (ch - '0');
    if (sign) x = -x;
  }
  inline void read(char *s) {
    char ch = gc();
    for (; blank(ch); ch = gc())
      ;
    for (; !blank(ch); ch = gc()) *s++ = ch;
    *s = 0;
  }
  inline void read(char &c) {
    for (c = gc(); blank(c); c = gc())
      ;
  }
  inline void push(const char &c) {
    if (pp - pbuf == (1 << 20)) fwrite(pbuf, 1, (1 << 20), stdout), pp = pbuf;
    *pp++ = c;
  }
  template <class T>
  inline void write(T x) {
    if (x < 0) x = -x, push('-');
    static T sta[35];
    T top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) push(sta[--top] + '0');
  }
  template <class T>
  inline void write(T x, char lastChar) {
    write(x), push(lastChar);
  }
} io;
long long n, k;
long long h[N];
long long cnt;
long long po[N];
long long fact[N];
long long kpow(long long a, long long b) {
  long long c = 1;
  while (b) {
    if (b & 1) c = c * a % M;
    a = a * a % M;
    b >>= 1;
  }
  return c;
}
inline long long inv(long long x) { return kpow(x, M - 2); }
void init() {
  fact[0] = po[0] = 1;
  for (long long i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % M;
    po[i] = po[i - 1] * k % M;
  }
}
inline long long C(long long n, long long m) {
  return fact[n] * inv(fact[m] * fact[n - m] % M) % M;
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  init();
  io.read(n), io.read(k);
  for (long long i = 1; i <= n; i++) io.read(h[i]);
  long long ans = 1;
  long long sel = 1;
  for (long long i = 1; i <= n; i++) {
    if (h[i] == h[i - 1 >= 1 ? i - 1 : n]) {
      ans = ans * k % M;
    } else {
      cnt++;
      sel = sel * k % M;
    }
  }
  for (long long i = 0; i * 2 <= cnt; i++) {
    sel -= C(cnt, i) * C(cnt - i, i) % M * kpow(k - 2, cnt - i - i) % M;
    if (sel < 0) sel += M;
  }
  sel = sel * inv(2) % M;
  io.write(ans * sel % M, '\n');
  return 0;
}
