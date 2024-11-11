#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x >= 10) write(x / 10);
  putchar('0' + x % 10);
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
inline void writep(long long x) {
  write(x);
  putchar(' ');
}
inline unsigned long long rnd() {
  return ((unsigned long long)rand() << 30 ^ rand()) << 4 | rand() % 4;
}
const int N = 1e6 + 5, M = (1 << 20) + 5;
int L[N], R[N], f[M], g[M], k, a[N], b[N], pos[N][25], c[N];
char s[N], t[N];
int main() {
  int n = read(), m = read();
  k = read();
  scanf("%s%s", s + 1, t + 1);
  for (int i = (int)(1); i <= (int)(n); i++) L[i] = read(), R[i] = read();
  for (int i = (int)(1); i <= (int)(k); i++) pos[n + 1][i] = i;
  for (int o = (int)(n + 1); o >= (int)(1); o--) {
    if (o <= n) {
      for (int i = (int)(1); i <= (int)(k); i++) pos[o][i] = i;
      swap(pos[o][L[o]], pos[o][R[o]]);
      for (int i = (int)(1); i <= (int)(k); i++) c[i] = pos[o][pos[o + 1][i]];
      for (int i = (int)(1); i <= (int)(k); i++) pos[o][i] = c[i];
    }
    for (int i = (int)(1); i <= (int)(k); i++) c[i] = s[pos[o][i]] - '0';
    for (int i = (int)(1); i <= (int)(k); i++) a[o] = a[o] << 1 | c[i];
    for (int i = (int)(1); i <= (int)(k); i++) c[i] = t[pos[o][i]] - '0';
    for (int i = (int)(1); i <= (int)(k); i++) b[o] = b[o] << 1 | c[i];
  }
  for (int i = (int)(0); i <= (int)((1 << k) - 1); i++) f[i] = n + 1;
  for (int i = (int)(1); i <= (int)(n + 1); i++) {
    f[a[i]] = min(f[a[i]], i);
    g[b[i]] = max(g[b[i]], i);
  }
  for (int i = (int)(0); i <= (int)(k - 1); i++) {
    for (int s = (int)((1 << k) - 1); s >= (int)(0); s--)
      if (s >> i & 1) {
        g[s ^ (1 << i)] = max(g[s ^ (1 << i)], g[s]);
        f[s ^ (1 << i)] = min(f[s ^ (1 << i)], f[s]);
      }
  }
  int ans = 0, ansl = 0, ansr = 0;
  for (int s = (int)((1 << k) - 1); s >= (int)(0); s--) {
    if (g[s] - f[s] >= m) {
      int cnt = k;
      for (int i = (int)(0); i <= (int)(k - 1); i++) {
        cnt += 2 * (s >> i & 1);
        cnt -= ::s[i + 1] - '0';
        cnt -= t[i + 1] - '0';
      }
      if (cnt >= ans) ansl = f[s], ansr = g[s] - 1, ans = cnt;
    }
  }
  cout << ans << endl << ansl << " " << ansr;
}
