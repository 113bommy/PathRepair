#include <bits/stdc++.h>
using namespace std;
int n, k, p, a[500005], now, tmp;
int tr1[205], tr2[205], f[3][500005];
int lowbit(int x) { return x & -x; }
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int _read() {
  char ch = nc();
  int sum = 0;
  while (!(ch >= '0' && ch <= '9')) ch = nc();
  while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - 48, ch = nc();
  return sum;
}
int get1(int x) {
  int tmp = 1e9;
  for (; x; x -= lowbit(x)) tmp = min(tmp, tr1[x]);
  return tmp;
}
void add1(int x, int u) {
  for (; x <= p; x += lowbit(x)) tr1[x] = min(tr1[x], u);
}
int get2(int x) {
  int tmp = 1e9;
  for (; x; x -= lowbit(x)) tmp = min(tmp, tr2[x]);
  return tmp;
}
void add2(int x, int u) {
  for (; x <= p; x += lowbit(x)) tr2[x] = min(tr2[x], u);
}
void add(int x, int u) {
  x++;
  add2(x, u);
  add1(p - x + 1, u);
}
int get() {
  int x = now + 1;
  return min(get1(p - x + 1) - now, get2(x - 1) + (p - now));
}
int main() {
  n = _read();
  k = _read();
  p = _read();
  for (int i = 1; i <= n; i++) a[i] = _read(), a[i] %= p;
  for (int i = 1; i <= n; i++) f[1][i] = (f[1][i - 1] + a[i]) % p;
  tmp = 1;
  for (int j = 2; j <= k; j++) {
    for (int i = 1; i <= p; i++) tr1[i] = tr2[i] = 1e9;
    now = 0;
    add(now, f[tmp][j - 1] + now);
    for (int i = j; i <= n; i++) {
      now = (now - a[i] + p) % p;
      f[tmp ^ 1][i] = get();
      add(now, f[tmp][i] + now);
    }
    tmp ^= 1;
  }
  printf("%I64d\n", f[tmp][n]);
}
