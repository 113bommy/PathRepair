#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -f;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
int nnu[25];
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (!x) {
    putchar('0');
    return;
  }
  int tp = 0;
  while (x) nnu[++tp] = x % 10, x /= 10;
  while (tp) putchar(nnu[tp--] + '0');
  return;
}
int a[500005], b[500005];
inline void solve1(int n, int _0, int _1) {
  if (_0 >= 3) {
    int tt = 0;
    for (int i = 1; i <= n && tt < 3; i++)
      if (a[i] % 2 == 0) swap(a[i], a[++tt]);
  } else if (n == 3 && _0 == 2 && _1 == 1) {
    puts("NO");
    return;
  } else {
    for (int i = 2; i <= n; i++)
      if (a[i] % 2 == 0) swap(a[i], a[1]);
    int tt = 1;
    for (int i = 3; i <= n && tt < 3; i++)
      if (a[i] % 2 == 1) swap(a[i], a[++tt]);
  }
  b[1] = (a[1] + a[2] + a[3]) / 2 - a[2];
  b[2] = a[1] - b[1];
  b[3] = a[2] - b[2];
  for (int i = 4; i <= n; i++) b[i] = a[i] - b[1];
  puts("YES");
  for (int i = 1; i <= n; i++) write(b[i]), putchar(' ');
  return;
}
unordered_map<int, int> vis;
int id[500005];
inline void solve2(int n) {
  int N = n;
  n = min(n, 27);
  int sta1 = 0, sta2 = 0;
  for (int i = 0; i < (1ll << n); i++)
    if (__builtin_popcount(i) == (n / 2)) {
      int tot = 0;
      for (int j = 1; j <= n; j++)
        if (i & (1ll << (j - 1))) tot += a[j];
      if (vis[tot]) {
        sta1 = vis[tot], sta2 = i;
        break;
      }
      vis[tot] = i;
    }
  if (!sta1) {
    puts("NO");
    return;
  }
  int st = sta1 ^ sta2;
  sta1 &= st, sta2 &= st;
  int tt = -1;
  for (int i = 1; i <= n; i++)
    if (sta1 & (1ll << (i - 1))) tt += 2, id[tt] = i;
  tt = 0;
  for (int i = 1; i <= n; i++)
    if (sta2 & (1ll << (i - 1))) tt += 2, id[tt] = i;
  tt = 2 * __builtin_popcount(sta1);
  b[1] = 1;
  for (int i = 1; i < tt; i++) b[i + 1] = a[id[i]] - b[i];
  sta1 |= sta2;
  for (int i = 1; i <= N; i++)
    if (n > 27 || !(sta1 & (1ll << (i - 1)))) b[++tt] = a[i] - b[1];
  puts("YES");
  for (int i = 1; i <= N; i++) write(b[i]), putchar(' ');
  return;
}
signed main() {
  int n = read();
  int _0 = 0, _1 = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    if (a[i] % 2 == 0)
      _0++;
    else
      _1++;
  }
  if (n == 2) {
    if (a[1] == a[2]) {
      puts("YES");
      write(a[1]), putchar(' '), write(0);
      return 0;
    } else {
      puts("NO");
      return 0;
    }
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    if (a[i] == a[i - 1]) {
      puts("YES");
      for (int j = 1; j < i; j++) write(a[j]), putchar(' ');
      write(0), putchar(' ');
      for (int j = i + 1; j <= n; j++) write(a[j]), putchar(' ');
      return 0;
    }
  if (_0)
    solve1(n, _0, _1);
  else
    solve2(n);
}
