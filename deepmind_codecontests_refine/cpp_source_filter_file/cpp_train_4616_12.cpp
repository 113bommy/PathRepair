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
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
long long v, V, s, n, ansa, ansb, ansc, w[10000], c[10000];
inline void dfs1(long long V, long long a, long long b) {
  if ((double)b * b * a - 1e-6 > v) return;
  if (V == n) {
    if (a * b + v / a + v / b < s) {
      s = a * b + v / a + v / b;
      ansa = a;
      ansb = b;
      ansc = v / a / b;
    }
    return;
  }
  long long vv = 1;
  for (long long i = 0; i < c[V]; i++) vv *= w[V];
  for (long long i = c[V]; i >= 1; i--) {
    c[V] -= i;
    dfs1(V + 1, a, b * vv);
    c[V] += i;
    vv /= w[V];
  }
  dfs1(V + 1, a, b);
}
inline void dfs(long long V, long long a) {
  if ((long double)a * a * a - 1e-6 > v) return;
  if (V == n) {
    if (2 * sqrt(v) * sqrt(a) + v / a < s) dfs1(0, a, 1);
    return;
  }
  long long cm = 1;
  for (long long i = 0; i < c[V]; i++) cm *= w[V];
  for (long long i = c[V]; i >= 1; i--) {
    c[V] -= i;
    dfs(V + 1, a * cm);
    c[V] += i;
    cm /= w[V];
  }
  dfs(V + 1, a);
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    v = 1;
    s = 3e18;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      cin >> w[i] >> c[i];
      for (long long j = 0; j < c[i]; j++) v *= w[i];
    }
    dfs(0, 1);
    write(s * 2);
    putchar(' ');
    write(ansa);
    putchar(' ');
    write(ansb);
    putchar(' ');
    writeln(ansc);
  }
  return 0;
}
