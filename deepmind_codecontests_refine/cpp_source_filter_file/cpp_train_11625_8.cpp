#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  for (x = c - '0'; (c = getchar()) >= '0' && c <= '9';) x = x * 10 + c - '0';
  return x;
}
struct edge {
  int nx, t;
} e[300000 * 2 + 5];
int n, k, h[300000 + 5], en, c[300000 + 5], cc[300000 + 5], d[300000 + 5],
    f[300000 + 5], ff[300000 + 5], l[300000 + 5], cnt, fa[300000 + 5];
vector<int> v[300000 + 5];
long long ans;
inline void ins(int x, int y) {
  e[++en] = (edge){h[x], y};
  h[x] = en;
  e[++en] = (edge){h[y], x};
  h[y] = en;
}
void dfs(int x) {
  l[++cnt] = x;
  for (int i = h[x]; i; i = e[i].nx)
    if (e[i].t != fa[x]) fa[e[i].t] = x, dfs(e[i].t);
}
void dp2(int x, int fa) {
  f[x] = 0;
  v[x].clear();
  for (int i = h[x]; i; i = e[i].nx)
    if (e[i].t != fa) {
      ++c[x];
      dp2(e[i].t, x);
      if (cc[e[i].t] > 67) ++cc[x];
      v[x].push_back(c[e[i].t]);
      f[x] = max(f[x], f[e[i].t]);
      ff[x] = max(ff[x], ff[e[i].t]);
    }
  f[x] = max(f[x], c[x]);
  ans += max(0, f[x] - min(n, 67));
  if (cc[x] > 67) {
    sort(v[x].begin(), v[x].end());
    for (int i = min(n, 67); ++i <= v[x].size();)
      if (v[x][v[x].size() - i] < i)
        break;
      else
        ff[x] = max(ff[x], i);
  }
  ans += max(0, ff[x] - min(n, 67));
}
int main() {
  int* x = new int;
  srand(*x);
  n = read();
  for (int i = 1; i < n; ++i) ins(read(), read());
  dfs(1);
  for (k = 1; k <= 67 && k <= n; ++k)
    for (int i = n; i; --i) {
      int x = l[i];
      f[x] = 0;
      for (int i = h[x], cnt = 0; i; i = e[i].nx)
        if (e[i].t != fa[x]) {
          if (k == 1)
            v[x].push_back(d[e[i].t]);
          else
            v[x][cnt++] = d[e[i].t];
          f[x] = max(f[x], f[e[i].t]);
        }
      if (v[x].size() < k)
        d[x] = 1;
      else
        nth_element(v[x].begin(), v[x].end() - k, v[x].end()),
            d[x] = v[x][v[x].size() - k] + 1;
      ans += f[x] = max(f[x], d[x]);
    }
  ans += 1LL * (n - min(n, 67)) * n;
  dp2(1, 0);
  printf("%I64d", ans);
}
