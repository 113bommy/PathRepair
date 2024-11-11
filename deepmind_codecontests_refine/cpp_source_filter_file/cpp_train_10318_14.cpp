#include <bits/stdc++.h>
namespace IO {
const int SIZE = (1 << 20) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = obuf + SIZE - 1;
char _st[55];
int _qr = 0;
inline char gc() {
  return (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
          (iS == iT ? EOF : *iS++) : *iS++);
}
inline void qread() {}
template <class T1, class... T2>
inline void qread(T1 &IEE, T2 &...ls) {
  register T1 __ = 0, ___ = 1;
  register char ch;
  while (!isdigit(ch = gc())) ___ = (ch == '-') ? -___ : ___;
  do {
    __ = (__ << 1) + (__ << 3) + (ch ^ 48);
  } while (isdigit(ch = gc()));
  __ *= ___;
  IEE = __;
  qread(ls...);
  return;
}
template <class T>
inline void QreadArr(T Begin, T End) {
  while (Begin != End) {
    qread(*Begin);
    ++Begin;
  }
}
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
  return;
}
inline void putc_(char _x) {
  *oS++ = _x;
  if (oS == oT) flush();
}
inline void qwrite() {}
template <class T1, class... T2>
inline void qwrite(T1 IEE, T2... ls) {
  if (!IEE) putc_('0');
  if (IEE < 0) putc_('-'), IEE = -IEE;
  while (IEE) _st[++_qr] = IEE % 10 + '0', IEE /= 10;
  while (_qr) putc_(_st[_qr--]);
  qwrite(ls...);
  return;
}
template <class T>
inline void WriteArr(T Begin, T End) {
  const char Kg = ' ', Edl = '\n';
  while (Begin != End) {
    qwrite(*Begin);
    ++Begin;
    putc_(Kg);
  }
  putc_(Edl);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher;
}  // namespace IO
using namespace IO;
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long My_Rand(long long Mod) { return (unsigned long long)(rnd()) % Mod; }
template <class T1, class T2>
T1 Min(const T1 x, const T2 y) {
  return x > y ? y : x;
}
template <class T1, class T2>
T1 Max(const T1 x, const T2 y) {
  return x > y ? x : y;
}
template <class T1, class T2>
void To_max(T1 &x, const T2 y) {
  x < y ? x = y : x = x;
}
template <class T1, class T2>
void To_min(T1 &x, const T2 y) {
  x > y ? x = y : x = x;
}
inline long long qmul(long long x, long long y, long long p) {
  long long l = x * (y >> 25) % p * (1 << 25) % p;
  long long r = x * (y & ((1 << 25) - 1)) % p;
  return (l + r) % p;
}
inline long long qpow(long long n, long long base, long long mod = 1e18) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = ret * base % mod;
    base = base * base % mod;
    n >>= 1;
  }
  return ret % mod;
}
inline long long gcd(long long x, long long y) {
  return !y ? x : gcd(y, x % y);
}
inline long long lcm(long long x, long long y) { return x / gcd(x, y) * y; }
void InitHash(unsigned long long &base, int &prime, unsigned long long &mod) {
  base = 131, prime = 233317, mod = 212370440130137957ll;
}
int n;
int a[105], cnt[105];
bool vis[105];
int main() {
  qread(n);
  for (int i = (1); i <= (n); ++i) qread(a[i]), ++cnt[a[i]];
  int c1 = 0, c2 = 0;
  for (int i = (1); i <= (100); ++i) {
    if (cnt[i] == 1)
      ++c1;
    else if (cnt[i] > 2)
      ++c2;
  }
  if ((c1 & 1) && !c2)
    puts("NO");
  else {
    puts("YES");
    if (c1 & 1) {
      int now = 0, ff = 0;
      for (int i = (1); i <= (n); ++i) {
        if (cnt[a[i]] == 1) {
          if (!now)
            putchar('A');
          else
            putchar('B');
          now ^= 1;
        } else if (cnt[a[i]] == 2) {
          if (vis[a[i]])
            putchar('B');
          else
            putchar('A'), vis[a[i]] = true;
        } else {
          if (!ff) {
            ff = 1;
            putchar('A');
          } else {
            putchar('B');
          }
        }
      }
    } else {
      int now = 0;
      for (int i = (1); i <= (n); ++i) {
        if (cnt[a[i]] == 1) {
          if (!now)
            putchar('A');
          else
            putchar('B');
          now ^= 1;
        } else if (cnt[a[i]] == 2) {
          if (vis[a[i]])
            putchar('B');
          else
            putchar('A'), vis[a[i]] = true;
        } else
          putchar('A');
      }
    }
  }
  return 0;
}
