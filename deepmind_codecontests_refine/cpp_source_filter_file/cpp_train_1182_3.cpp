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
using namespace fastIO2;
int n, m, Q, cur, ti[3000010][10], fi[(100010)], se[(100010)], top, tim;
char str[(100010)];
bool vis[(100010)];
void solve(int st) {
  int i = st;
  for (int d = 1, pre = 0; i >= st && i <= n; i += d) {
    vis[i] = 1, tim++;
    if (fi[i] == (0x7f7f7f7f)) fi[i] = tim;
    if (vis[i + 1] && se[i] == (0x7f7f7f7f)) se[i] = tim;
    for (int num = 0; num <= 9; num++) ti[tim][num] = ti[tim - 1][num];
    if (str[i] < '0' || str[i] > '9') {
      if (str[i] != '<' && str[i] != '>') continue;
      if (str[i] == '<')
        d = -1;
      else
        d = 1;
      if (pre) str[pre] = 0;
      pre = i;
    } else
      ti[tim][str[i] - '0']++, str[i]--, pre = 0;
  }
  tim++;
  if (fi[i] == (0x7f7f7f7f)) fi[i] = tim;
  if (vis[i + 1] && se[i] == (0x7f7f7f7f)) se[i] = tim;
  for (int num = 0; num <= 9; num++) ti[tim][num] = ti[tim - 1][num];
}
int main() {
  read(n), read(Q);
  scanf("%s", str + 1);
  memset(se, (0x7f7f7f7f), sizeof(se));
  memset(fi, (0x7f7f7f7f), sizeof(fi));
  for (int st = 1; st <= n; st++)
    if (!vis[st]) solve(st);
  while (Q--) {
    int L, R;
    read(L), read(R);
    int l = fi[L], r = min(fi[R + 1], se[L - 1]);
    for (int i = 0; i < 10; i++) printf("%d ", ti[r - 1][i] - ti[l - 1][i]);
    puts("");
  }
}
