#include <bits/stdc++.h>
using namespace std;
namespace fastIO1 {
inline char read() {
  static const int IN_LEN = 1000000;
  static char buf[IN_LEN], *s, *t;
  return (s == t               ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin),
          (s == t ? -1 : *s++) : *s++);
}
template <class T>
inline void read(T &x) {
  static bool iosig;
  static char c;
  for (iosig = false, c = read(); !isdigit(c); c = read()) {
    if (c == '-') iosig = true;
    if (c == -1) return;
  }
  for (x = 0; isdigit(c); c = read()) x = ((x + (x << 2)) << 1) + (c ^ '0');
  if (iosig) x = -x;
}
inline char readc(char &c) {
  for (c = read(); !isalpha(c) && !isdigit(c); c = read())
    if (c == -1) return 0;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh = obuf;
inline void print(char c) {
  if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
  *ooh++ = c;
}
template <class T>
inline void print(T x) {
  static int buf[30], cnt;
  if (x == 0)
    print('0');
  else {
    if (x < 0) print('-'), x = -x;
    for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
    while (cnt) print((char)buf[cnt--]);
  }
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
}  // namespace fastIO1
namespace fastIO2 {
template <class T>
inline void read(T &x) {
  static bool iosig;
  static char c;
  for (iosig = false, c = getchar(); !isdigit(c); c = getchar()) {
    if (c == '-') iosig = true;
    if (c == -1) return;
  }
  for (x = 0; isdigit(c); c = getchar()) x = ((x + (x << 2)) << 1) + (c ^ '0');
  if (iosig) x = -x;
}
}  // namespace fastIO2
using namespace fastIO1;
struct rec {
  int x, y;
} ans[(1000010)];
const int a1[12] = {0, 1, 0, 2, 1, 3, 0, 3, 1, 2, 2, 3};
const int a2[32] = {0, 0, 1, 1, 2, 2, 3, 3, 0, 1, 1, 2, 2, 3, 3, 0,
                    0, 2, 1, 3, 2, 0, 3, 1, 0, 3, 1, 0, 2, 1, 3, 2};
int n, cnt;
int main() {
  read(n);
  if (n % 4 > 1)
    puts("NO"), exit(0);
  else
    puts("YES");
  for (int i = 1; i < n; i += 4)
    for (int j = 0; j < 12; j += 2)
      ans[++cnt] = (rec){i + a1[j], i + a1[j + 1]};
  for (int i = 1; i < n; i += 4)
    for (int j = 1; j < i; j += 4)
      for (int k = 0; k < 32; k += 2)
        ans[++cnt] = (rec){j + a2[k], i + a2[k + 1]};
  for (int i = 1; i <= cnt; i++) {
    if ((ans[i].x & 1) && (n % 4) && (ans[i].y == ans[i].x + 1)) {
      printf("%d %d\n%d %d\n%d %d\n", ans[i].x, n, ans[i].x, ans[i].y, ans[i].y,
             n);
      continue;
    }
    printf("%d %d\n", ans[i].x, ans[i].y);
  }
}
