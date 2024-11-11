#include <bits/stdc++.h>
using namespace std;
const int N = 110;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n;
int cnt, head[N], nxt[N << 1], to[N << 1];
void qxx(int x, int y) {
  to[++cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
}
void add(int x, int y) {
  qxx(x, y);
  qxx(y, x);
}
int sz[N], fa[N];
double ru[N], chu[N], sru, schu, ans;
void dfs(int x) {
  sz[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    int k = to[i];
    if (k == fa[x]) continue;
    fa[k] = x;
    dfs(k);
    ru[x] += ru[k];
    sz[x] += sz[k];
  }
}
int main() {
  n = read();
  for (register int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y);
  }
  for (register int i = 1; i <= n; i++) {
    scanf("%lf%lf", &ru[i], &chu[i]);
    sru += ru[i];
    schu += chu[i];
  }
  for (register int i = 1; i <= n; i++) ru[i] /= sru;
  dfs(1);
  for (register int x = 1; x <= n; x++)
    for (register int i = head[x]; i; i = nxt[i]) {
      int k = to[i];
      if (k == fa[x])
        ans += (1 - ru[x]) * (n - sz[x]) * chu[x] / schu;
      else
        ans += ru[k] * sz[k] * chu[x] / schu;
    }
  printf("%.12lf\n", ans);
  return 0;
}
