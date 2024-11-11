#include <bits/stdc++.h>
using namespace std;
char buf[1048576], *p0, *p1;
inline int read() {
  int r = 0;
  char c =
      (p0 == p1 && (p1 = (p0 = buf) + fread(buf, 1, 1048576, stdin), p0 == p1)
           ? EOF
           : *p0++);
  while (c < 48 || c > 57)
    c = (p0 == p1 && (p1 = (p0 = buf) + fread(buf, 1, 1048576, stdin), p0 == p1)
             ? EOF
             : *p0++);
  while (c > 47 && c < 58) {
    r = (r << 3) + (r << 1) + (c ^ 48);
    c = (p0 == p1 && (p1 = (p0 = buf) + fread(buf, 1, 1048576, stdin), p0 == p1)
             ? EOF
             : *p0++);
  }
  return r;
}
int n[2], l[2][1005], s[2], c[2][2], t[2][2][1005], d[2][1005];
bitset<1000005> f[1005];
inline bool check(int u) {
  for (int i = 1; i <= n[u]; ++i) f[i] = f[i - 1] | (f[i - 1] << l[u][i]);
  if (!f[n[u]][s[u]]) return true;
  for (int i = n[u]; i; --i) {
    if (s[u] >= l[u][i] && f[i - 1][s[u] - l[u][i]]) {
      s[u] -= l[u][i];
      t[u][0][++c[u][0]] = l[u][i];
    } else
      t[u][1][++c[u][1]] = l[u][i];
  }
  return false;
}
int main() {
  int q = read(), u, v, w;
  f[0].set(0);
  while (q--) {
    s[0] = s[1] = c[0][0] = c[0][1] = c[1][0] = c[1][1] = 0;
    n[0] = read();
    for (int i = 1; i <= n[0]; ++i) s[0] += l[0][i] = read();
    n[1] = read();
    for (int i = 1; i <= n[1]; ++i) s[1] += l[1][i] = read();
    if (n[0] != n[1] || (s[0] & 1) || (s[1] & 1)) {
      puts("No");
      continue;
    }
    sort(l[0] + 1, l[0] + n[0] + 1);
    sort(l[1] + 1, l[1] + n[1] + 1);
    s[0] >>= 1;
    s[1] >>= 1;
    if (check(0) || check(1)) {
      puts("No");
      continue;
    }
    puts("Yes");
    u = w = c[v = 0][0] > c[1][0];
    for (int i = 1; i <= c[u][0]; ++i) d[0][++v] = t[u][0][i];
    for (int i = 1; i <= c[u][1]; ++i) d[0][++v] = -t[u][1][i];
    u ^= 1;
    v = 0;
    for (int i = c[u][0]; i; --i) d[1][++v] = t[u][0][i];
    for (int i = c[u][1]; i; --i) d[1][++v] = -t[u][1][i];
    u = v = 0;
    for (int i = 1; i <= n[0]; ++i) {
      u += d[0][i];
      w ? printf("%d %d\n", v, u) : printf("%d %d\n", u, v);
      v += d[1][i];
      w ? printf("%d %d\n", v, u) : printf("%d %d\n", u, v);
    }
  }
  return 0;
}
