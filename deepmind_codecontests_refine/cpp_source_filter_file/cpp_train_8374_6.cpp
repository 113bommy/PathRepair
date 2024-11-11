#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
const long long mod = 1e9 + 7;
long long n, m, ans, fa[N], b[N], c[N];
inline long long read() {
  long long ret = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    ret = ret * 10 + c - 48;
    c = getchar();
  }
  if (f) return -ret;
  return ret;
}
long long find(long long x) {
  if (fa[x] == x) return x;
  fa[x] = find(fa[x]);
  return fa[x];
}
signed main() {
  n = read();
  m = read();
  for (long long i = 0; i <= 2 * n + 2; i++) fa[i] = i;
  for (long long i = 1; i <= m; i++) {
    long long x = read(), y = read(), opt = 0;
    long long xx, yy, xxx, yyy;
    char c;
    scanf("%c", &c);
    if (c == 'x')
      opt = 0;
    else
      opt = 1;
    if (x <= y) {
      xx = 1;
      yy = y - x + 1;
    } else {
      yy = 1;
      xx = x - y + 1;
      yy += xx - 1;
      xx = 1;
    }
    if (x <= n - y + 1) {
      xxx = 1;
      yyy = y + x - 1;
    } else {
      yyy = n;
      xxx = x - (n - y);
      yyy -= xxx - 1;
      xxx = 1;
    }
    yy++;
    yyy++;
    yy -= 2;
    if (opt == 0) {
      fa[find(2 * yy)] = find(2 * yyy);
      fa[find(2 * yy + 1)] = find(2 * yyy + 1);
    } else {
      fa[find(2 * yy)] = find(2 * yyy + 1);
      fa[find(2 * yy + 1)] = find(2 * yyy);
    }
  }
  for (long long i = 0; i <= n + 1; i++)
    if (find(2 * i) == find(2 * i + 1)) {
      puts("0");
      return 0;
    }
  for (long long i = 0; i <= 2 * n + 1; i++)
    if (find(i) == i) ans++;
  ans /= 2;
  ans--;
  long long res = 1;
  for (long long i = 1; i <= ans; i++) res = res * 2 % mod;
  cout << res;
  return 0;
}
