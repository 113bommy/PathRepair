#include <bits/stdc++.h>
using namespace std;
namespace fastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void read(long long &x) {
  char ch;
  long long f = 1;
  while (blank(ch = nc()))
    ;
  while (ch == '-') f = -f, ch = nc();
  if (IOerror) return;
  for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
    ;
  x *= f;
}
inline void read(int &x) {
  char ch;
  int f = 1;
  while (blank(ch = nc()))
    ;
  while (ch == '-') f = -f, ch = nc();
  if (IOerror) return;
  for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
    ;
  x *= f;
}
inline void read(char *s) {
  char ch;
  while (blank(ch = nc()))
    ;
  if (IOerror) return;
  int i = 0;
  for (; !blank(ch); s[i++] = ch, ch = nc())
    ;
  s[i] = '\0';
}
};  // namespace fastIO
using namespace fastIO;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m;
int main() {
  n = read();
  m = read();
  printf("%d ", n == m || m == 0 ? 0 : 1);
  printf("%d\n", m == 0 ? 0 : min(n - m, m + 1));
}
