#include <bits/stdc++.h>
using namespace std;
long long n, m, ver[100010], Next[100010], head[100010], tot;
inline long long read() {
  long long tmp = 1, x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') tmp = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return tmp * x;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  long long y = 10, len = 1;
  while (y <= x) {
    y *= 10;
    len++;
  }
  while (len--) {
    y /= 10;
    putchar(x / y + 48);
    x %= y;
  }
}
inline void addEdge(long long x, long long y) {
  ver[++tot] = y;
  Next[tot] = head[x];
  head[x] = tot;
}
inline bool prime(long long m) {
  if (m == 1) return 0;
  long long x = sqrt(m) + 1;
  for (long long i = 2; i <= x; i++) {
    if (m % i == 0) return 0;
  }
  return 1;
}
int main() {
  cin >> n;
  m = n;
  if (n < 4) return printf("-1") & 0;
  while (!prime(m)) m++;
  for (long long i = 1; i < n; i++) addEdge(i, i + 1);
  addEdge(1, n);
  long long now = 1;
  while (m > tot) {
    addEdge(now, n - now);
    now++;
    if (now > n / 2) break;
  }
  write(tot);
  putchar('\n');
  for (long long x = 1; x <= n; x++) {
    for (long long i = head[x]; i; i = Next[i]) {
      write(x);
      putchar(' ');
      write(ver[i]);
      putchar('\n');
    }
  }
  return 0;
}
