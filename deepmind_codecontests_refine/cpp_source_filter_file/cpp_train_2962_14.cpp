#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x *= 10;
    x += ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void read(char *s, int &ts) {
  char x = getchar();
  while (!(x >= 'a' && x <= 'z')) x = getchar();
  while (x >= 'a' && x <= 'z') s[++ts] = x, x = getchar();
}
double d[100010];
int main() {
  int n, m;
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) d[i] = read();
  double ans = -1.0;
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), z = read();
    ans = max(ans, double(d[x] + d[y]) / z);
  }
  printf("%.15f", ans);
  return 0;
}
