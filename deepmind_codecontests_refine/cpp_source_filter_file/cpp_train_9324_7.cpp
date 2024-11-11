#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sum = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  if (f) return -sum;
  return sum;
}
const int N = 100005;
int m, a[N];
long double n;
long double c1[N], c2[N], ans;
inline void up(long double *c, int x, int v) {
  for (int i = x; i <= m; i += i & -i) c[i] += v;
}
inline long double ask(long double *c, int x) {
  long double r = 0;
  for (int i = x; i; i -= i & -i) r += c[i];
  return r;
}
int main() {
  int i, j;
  m = n = read();
  for (i = 1; i <= m; i++) a[i] = read();
  for (j = 1; j <= m; j++) ans += (n - j + 1) * j * (j - 1) / 2;
  for (i = m; i >= 1; i--) {
    ans += ask(c1, a[i] - 1) * (n * (n + 1) - (n + 1) * i * 2);
    ans += ask(c2, a[i] - 1) * i * 2;
    up(c1, a[i], 1);
    up(c2, a[i], i);
  }
  printf("%.20Lf", (ans / (n * (n + 1))));
  return 0;
}
