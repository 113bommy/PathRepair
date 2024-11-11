#include <bits/stdc++.h>
using namespace std;
namespace IO {
int len = 0;
char ibuf[(1 << 20) + 1], *iS, *iT, out[(1 << 25) + 1];
inline void flush() {
  fwrite(out, 1, len, stdout);
  len = 0;
}
inline long long read() {
  register char ch =
      (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin),
       (iS == iT ? EOF : *iS++) : *iS++);
  register long long x = 0;
  register char t = 0;
  while (ch < '0' || ch > '9')
    t |= ch == '-', ch = (iS == iT ? iT = (iS = ibuf) +
                                          fread(ibuf, 1, (1 << 20) + 1, stdin),
                          (iS == iT ? EOF : *iS++) : *iS++);
  while (ch >= '0' && ch <= '9')
    x = x * 10 + (ch ^ 48),
    ch = (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin),
          (iS == iT ? EOF : *iS++) : *iS++);
  return t ? -x : x;
}
inline void putc(char ch) { out[len++] = ch; }
template <class T>
inline void write(T x) {
  if (x < 0) putc('-'), x = -x;
  if (x > 9) write(x / 10);
  out[len++] = x % 10 + 48;
}
}  // namespace IO
using IO::flush;
using IO::putc;
using IO::read;
using IO::write;
const int N = 1e3 + 10;
int n, m;
struct BIT {
  long long t[N][N][2][2];
  inline void add(int x, int y, long long k) {
    for (int i = x; i <= n; i += (i & -i)) {
      for (int j = y; j <= m; j += (j & -j)) {
        t[i][j][x & 1][y & 1] ^= k;
      }
    }
  }
  inline long long query(int x, int y) {
    long long ans = 0;
    for (int i = x; i; i -= (i & -i)) {
      for (int j = y; j; j -= (j & -j)) {
        ans ^= t[i][j][x & 1][y & 1];
      }
    }
    return ans;
  }
} A;
inline void upd(int x, int y, long long v) { A.add(x, y, v); }
inline void add(int a, int b, int c, int d, long long v) {
  upd(a, b, v);
  upd(a, d + 1, v);
  upd(c + 1, b, v);
  upd(c + 1, d + 1, v);
}
inline long long query(int x, int y) { return A.query(x, y); }
inline long long query(int a, int b, int c, int d) {
  return query(c, d) ^ query(a - 1, d) ^ query(c, b - 1) ^ query(a - 1, b - 1);
}
int main() {
  n = read(), m = read();
  while (m--) {
    char opt = read();
    switch (opt) {
      case 1: {
        int a = read(), b = read(), c = read(), d = read();
        write(query(a, b, c, d));
        putc('\n');
        break;
      }
      case 2: {
        long long a = read(), b = read(), c = read(), d = read(), k = read();
        add(a, b, c, d, k);
        break;
      }
    }
  }
  flush();
  return 0;
}
