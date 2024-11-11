#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, en, to[N], nx[N], hd[N], sz[N];
long double S, T, s[N], t[N];
long double ans;
inline void read(int &i) {
  i = 0;
  char c = getchar();
  bool j = 0;
  for (; !isdigit(c); c = getchar())
    if (c == '-') j = 1;
  for (; isdigit(c); c = getchar()) i = (i << 1) + (i << 3) + c - '0';
  i = j ? -i : i;
}
inline void add(int x, int y) { to[++en] = y, nx[en] = hd[x], hd[x] = en; }
void dfs(int x, int fa) {
  sz[x] = 1;
  for (int e = hd[x]; e; e = nx[e])
    if (to[e] != fa) {
      dfs(to[e], x);
      s[x] += s[to[e]];
      sz[x] += sz[to[e]];
      ans += t[x] * s[to[e]] * sz[to[e]];
    }
  ans += t[x] * (1 - s[x]) * (n - sz[x]);
}
int main() {
  read(n);
  for (int i = 1, x, y; i < n; ++i) read(x), read(y), add(x, y), add(y, x);
  for (int i = 1, x, y; i <= n; ++i)
    read(x), read(y), s[i] = x, t[i] = y, S += x, T += y;
  for (int i = 1; i <= n; ++i) s[i] /= S, t[i] /= T;
  dfs(1, 0);
  printf("%.10Lf\n", ans);
  return 0;
}
