#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar(), w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * w;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
const int N = 210;
int n, m;
long long b;
struct T {
  long long x, k;
  int t;
} a[N];
bool cmp(T _x, T _y) { return _x.k < _y.k; }
long long f[1 << 20];
int main() {
  n = read(), m = read(), b = read();
  for (int i = 1; i <= n; ++i) {
    a[i].x = read(), a[i].k = read();
    int ct = read();
    for (int j = 1; j <= ct; ++j) a[i].t |= (1 << (read() - 1));
  }
  sort(a + 1, a + 1 + n, cmp);
  long long sum = 0;
  int B = (1 << m);
  memset(f, 0x3f, sizeof f);
  long long ans = 1e18;
  f[0] = 0;
  for (int i = 1; i <= n; ++i) {
    sum += (a[i].k - a[i - 1].k) * b;
    for (int S = 0; S < B; ++S)
      f[S | a[i].t] = min(f[S | a[i].t], f[S] + a[i].x);
    ans = min(ans, f[B - 1] + sum);
  }
  if (ans = 1e18) {
    puts("-1");
    return 0;
  }
  writeln(ans);
  return 0;
}
