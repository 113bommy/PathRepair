#include <bits/stdc++.h>
using namespace std;
const int INF32 = 0x3f3f3f3f;
const long long INF64 = 0x3f3f3f3f3f3f3f3f;
struct IO {
  char ibuf[(1 << 21)], *ibs, *ibe, obuf[(1 << 21)], *O;
  int IOerror = 0;
  IO() : ibs(ibuf), ibe(ibuf), O(obuf) {}
  inline char getchar(void) {
    return (ibs == ibe &&
                    (ibe = (ibs = ibuf) + fread(ibuf, 1, (1 << 21), stdin),
                     ibs == ibe)
                ? EOF
                : *ibs++);
  }
  inline void flush(void) {
    fwrite(obuf, 1, O - obuf, stdout);
    O = obuf;
  }
  inline void putchar(char ch) {
    if (O - obuf >= (1 << 21)) flush();
    *O++ = ch;
  }
  ~IO() { flush(); }
  template <typename T>
  inline T getint(void) {
    char ch;
    T ret;
    bool flag = true;
    while (isspace(ch = getchar()) && ch != EOF)
      ;
    if (ch == '-') flag = false, ch = getchar();
    if (ch == EOF || !isdigit(ch)) {
      IOerror = 1;
      return (T)INF64;
    }
    ret = ch - '0';
    while (isdigit(ch = getchar())) ret = ret * 10 + ch - '0';
    return flag ? ret : -ret;
  }
  template <typename T>
  inline void putint(T x) {
    static char numbuf[65];
    int top = 0;
    if (x < 0) putchar('-'), x = -x;
    do numbuf[top++] = x % 10 + '0';
    while (x /= 10);
    while (top--) putchar(numbuf[top]);
  }
  inline void getstr(char *str) {
    do *str = getchar();
    while (*str != EOF && !isspace(*str++));
    *--str = 0;
  }
  inline void getline(char *str) {
    while ((*str = getchar()) != '\n') ++str;
    *str = 0;
  }
  inline void putstr(char *str) {
    while (*str) putchar(*str++);
  }
};
IO io;
int a[55], b[55];
int main() {
  int T = io.getint<int>();
  while (T--) {
    int N = io.getint<int>();
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= N; ++i) {
      char ch;
      while ((ch = io.getchar()) != 'a' && ch != 'b')
        ;
      if (ch == 'a')
        a[i] = a[i - 1] + 1, b[i] = b[i - 1];
      else
        a[i] = a[i - 1], b[i] = b[i - 1] + 1;
    }
    int aa = -1, bb = -1;
    bool flag = true;
    for (int i = 1; i <= N && flag; ++i)
      for (int j = i + 1; j <= N && flag; ++j) {
        if (a[j] - a[i - 1] == b[j] - b[i - 1]) {
          aa = i, bb = j;
          flag = false;
          break;
        }
      }
    io.putint(aa), io.putchar(' '), io.putint(bb), io.putchar('\n');
  }
  return 0;
}
