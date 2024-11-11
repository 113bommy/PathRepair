#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010, mod = 1e9 + 7;
int n, fa[maxn], size[maxn], zihuan[maxn], huan[maxn], ans = 1;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
inline void write(int a) {
  if (a < 0) {
    char a = '-', b = '1';
    putchar(a);
    putchar(b);
  } else {
    if (a >= 10) write(a / 10);
    putchar(a % 10 + '0');
  }
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int main() {
  n = read();
  for (int i = 1; i <= 2 * n; i++) fa[i] = i, size[i] = 1;
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    if (x == y) zihuan[i] = 1;
    int fx = find(fa[x]), fy = find(fa[y]);
    if (fx != fy) {
      fa[fx] = fy;
      zihuan[fy] |= zihuan[fx];
      size[fy] += size[fx];
      size[fx] = 0;
    } else
      huan[fx] = 1;
  }
  for (int i = 1; i <= 2 * n; i++)
    if (find(i) == i && !zihuan[i]) {
      if (huan[i])
        ans = ans * 2 % mod;
      else
        ans = (long long)ans * size[i] % mod;
    }
  write(ans);
  return 0;
}
