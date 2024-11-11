#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int mods = 1e9 + 7;
const int MAXN = 1000005;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int f[MAXN], num[MAXN];
struct enode {
  int u, v, c, id;
} e[MAXN];
int find(int x) { return f[x] == x ? f[x] : f[x] = find(f[x]); }
signed main() {
  int n = read(), m = read(), q = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read(), c = read();
    e[i] = (enode){u, v, c, i};
  }
  sort(e + 1, e + m + 1, [&](enode x, enode y) { return x.c > y.c; });
  while (q--) {
    int l = read(), r = read(), flag = 0;
    for (int i = 1; i <= n << 1; i++) f[i] = i, num[i] = 1;
    for (int i = 1; i <= m; i++)
      if (e[i].id >= l && e[i].id <= r) {
        int x = find(e[i].u), y = find(e[i].v), xx = find(e[i].u + n),
            yy = find(e[i].v + n);
        if (x == y || xx == yy) {
          printf("%d\n", e[i].c);
          flag = 1;
          break;
        }
        if (num[xx] > num[y])
          f[y] = xx, num[xx] += num[y];
        else
          f[xx] = y, num[y] += num[xx];
        if (num[yy] > num[x])
          f[x] = yy, num[yy] += num[x];
        else
          f[yy] = x, num[x] += num[yy];
      }
    if (!flag) puts("-1");
  }
  return 0;
}
