#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 100000, stdin);
    if (p1 == p2) return EOF;
  }
  return *p1++;
}
inline void read(int &x) {
  char c = nc(), b = 1;
  for (; !(c >= '0' && c <= '9'); c = nc())
    if (c == '-') b = -1;
  for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc())
    ;
  x *= b;
}
inline void read(long long &x) {
  char c = nc(), b = 1;
  for (; !(c >= '0' && c <= '9'); c = nc())
    if (c == '-') b = -1;
  for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc())
    ;
  x *= b;
}
inline int read(char *s) {
  char c = nc();
  int len = 0;
  for (; !((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')); c = nc())
    if (c == EOF) return 0;
  for (; ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
       s[len++] = c, c = nc())
    ;
  s[len++] = '\0';
  return len;
}
inline void read(char &x) {
  for (x = nc(); !((x >= 'a' && x <= 'z')); x = nc())
    ;
}
int wt, ss[19];
inline void print(int x) {
  if (x < 0) x = -x, putchar('-');
  if (!x)
    putchar(48);
  else {
    for (wt = 0; x; ss[++wt] = x % 10, x /= 10)
      ;
    for (; wt; putchar(ss[wt] + 48), wt--)
      ;
  }
}
inline void print(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (!x)
    putchar(48);
  else {
    for (wt = 0; x; ss[++wt] = x % 10, x /= 10)
      ;
    for (; wt; putchar(ss[wt] + 48), wt--)
      ;
  }
}
int n;
long double a[110], q[110];
struct data {
  long double x;
  int id;
  data(long double a = 0, int b = 0) : x(a), id(b){};
};
struct cmp {
  bool operator()(data x, data y) { return x.x < y.x; }
};
int main() {
  read(n);
  int x;
  for (int i = 1; i <= n; i++)
    read(x), a[i] = ((long double)x) / 100.0, q[i] = 1.0;
  int T = 1000000;
  long double f = 0.0, p = 0.0;
  priority_queue<data, vector<data>, cmp> Q;
  for (int i = 1; i <= n; i++)
    Q.push(data((1.0 - (1.0 - a[i]) * q[i]) / (1.0 - q[i]), i));
  long double ans = 0, s = 0.0;
  for (int i = 1; i <= T; i++) {
    x = Q.top().id;
    Q.pop();
    q[x] *= (1.0 - a[x]);
    f = 1.0;
    for (int j = 1; j <= n; j++) f *= 1.0 - q[j];
    Q.push(data((1.0 - (1.0 - a[x]) * q[x]) / (1.0 - q[x]), x));
    s += 1.0;
    ans += s * (f - p);
    p = f;
  }
  printf("%0.10Lf", ans);
  return 0;
}
