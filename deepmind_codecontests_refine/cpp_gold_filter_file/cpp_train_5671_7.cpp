#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
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
int resx, resy;
int n, m, dx, dy, ans;
int x[100005], y[100005], d[1000005], q[1000005];
int main() {
  n = read();
  m = read();
  dx = read();
  dy = read();
  for (long long i = 1; i < n; i++)
    if (d[(i * dx) % n] == 0) d[(i * dx) % n] = i;
  for (int i = 1; i <= m; i++) {
    x[i] = read();
    y[i] = read();
    long long t = d[n - x[i] % n];
    t = (t * dy + y[i]) % n;
    q[t]++;
    if (q[t] > ans) ans = q[t], resx = x[i], resy = y[i];
  }
  printf("%d %d\n", resx, resy);
  return 0;
}
