#include <bits/stdc++.h>
using namespace std;
namespace fastio {
const int bufl = 1 << 15;
char ibuf[bufl], *is = ibuf, *it = ibuf, obuf[bufl], *os = obuf,
                 *ot = obuf + bufl;
inline int getch() {
  if (is == it) {
    it = (is = ibuf) + fread(ibuf, 1, bufl, stdin);
    if (is == it) return EOF;
  }
  return *is++;
}
template <typename Temp>
inline void read(Temp &a) {
  a = 0;
  int b = 0, c = getch();
  while (c < 48 || c > 57) b ^= (c == '-'), c = getch();
  while (c >= 48 && c <= 57) a = (a << 1) + (a << 3) + c - 48, c = getch();
  if (b) a = -a;
}
template <typename Temp1, typename... Temp2>
inline void read(Temp1 &a, Temp2 &...b) {
  read(a);
  read(b...);
}
inline void flush() {
  fwrite(obuf, 1, os - obuf, stdout);
  os = obuf;
}
inline void putch(int a) {
  *os++ = a;
  if (os == ot) flush();
}
inline void putst(char a[]) {
  int b = strlen(a);
  for (int c = 0; c < b; c++) putch(a[c]);
}
template <typename Temp>
inline void write(Temp a) {
  if (a < 0) {
    putch(45);
    a = -a;
  }
  if (a < 10) {
    putch(a + 48);
    return;
  }
  write(a / 10);
  putch(a % 10 + 48);
}
template <typename Temp1, typename... Temp2>
inline void write(Temp1 a, Temp2... b) {
  write(a);
  putch(32);
  write(b...);
}
struct Fline {
  ~Fline() {
    putch(10);
    flush();
  }
} cpp_flusher;
}  // namespace fastio
using fastio::getch;
using fastio::putch;
using fastio::putst;
using fastio::read;
using fastio::write;
const long long mod = 998244353;
int n, b1, w1, b2, w2, mx;
int sum[3][3];
long long fac[100005], el[100005], ans;
inline long long comb(int a, int b) {
  return fac[a] * el[a - b] % mod * el[b] % mod;
}
int main() {
  read(n);
  fac[0] = fac[1] = el[0] = el[1] = 1;
  for (int i = 2; i <= n; i++) {
    fac[i] = i;
    el[i] = (mod - mod / i) * el[mod % i] % mod;
  }
  for (int i = 2; i <= n; i++) {
    fac[i] = fac[i - 1] * fac[i] % mod;
    el[i] = el[i - 1] * el[i] % mod;
  }
  for (int i = 1; i <= n; i++) {
    int c1 = getch();
    while (c1 != 'B' && c1 != 'W' && c1 != '?') c1 = getch();
    int c2 = getch();
    while (c2 != 'B' && c2 != 'W' && c2 != '?') c2 = getch();
    if (c1 == 'B') b1++;
    if (c1 == 'W') w1++;
    if (c2 == 'B') b2++;
    if (c2 == 'W') w2++;
    if (c1 == 'B')
      c1 = 0;
    else if (c1 == 'W')
      c1 = 1;
    else
      c1 = 2;
    if (c2 == 'B')
      c2 = 0;
    else if (c2 == 'W')
      c2 = 1;
    else
      c2 = 2;
    sum[c1][c2]++;
  }
  for (int i = max(b1, w2); i + max(b2, w1) <= n; i++) {
    ans = (ans + comb(n - b1 - w1, i - b1) * comb(n - b2 - w2, i - w2)) % mod;
    if (i && i != n && sum[0][0] == 0 && sum[1][1] == 0 &&
        sum[0][1] + sum[0][2] + sum[2][1] <= i &&
        sum[0][1] + sum[0][2] + sum[2][1] + sum[2][2] >= i)
      ans =
          (ans + mod - comb(sum[2][2], i - sum[0][1] + sum[0][2] + sum[2][1])) %
          mod;
  }
  write(ans);
  return 0;
}
