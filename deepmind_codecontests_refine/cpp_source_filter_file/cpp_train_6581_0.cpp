#include <bits/stdc++.h>
using namespace std;
long long t, n, x, y, l, r;
char a[200000 + 5];
map<long long, long long> Map;
long long read() {
  char c;
  long long x = 0, f = 1;
  c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}
long long Mul(long long a, long long b) { return 1ll * a * b % 1000000007; }
long long Inc(long long a, long long b) {
  return (a += b) >= 1000000007 ? a - 1000000007 : a;
}
long long Dec(long long a, long long b) {
  return (a -= b) < 0 ? a + 1000000007 : a;
}
long long c(long long a, long long b) { return a * 2000000 + b; }
signed main() {
  t = read();
  while (t--) {
    n = read();
    scanf("%s", a + 1);
    x = 0, y = 0;
    l = 0, r = n + 1;
    Map.clear();
    Map[c(0, 0)] = 1;
    for (register long long i = 1; i <= n; ++i) {
      if (a[i] == 'L') x--;
      if (a[i] == 'R') x++;
      if (a[i] == 'U') y++;
      if (a[i] == 'D') y--;
      if (Map[c(x, y)] && i - Map[c(x, y)] + 1 < r - l + 1)
        l = Map[c(x, y)], r = i;
      Map[c(x, y)] = i + 1;
    }
    if (l == 0)
      puts("-1");
    else
      printf("%d %d\n", l, r);
  }
  return 0;
}
