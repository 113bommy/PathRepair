#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, inf = 1e9;
char s[N];
int n, cnt, d[N], fa[N], ans[N], w[N], sz[N], son[N], p[1 << 23], h[N],
    to[N << 1], nxt[N << 1];
void add(int u, int v) {
  to[++cnt] = v;
  nxt[cnt] = h[u];
  h[u] = cnt;
}
void dfs(int x) {
  d[x] = d[fa[x]] + 1;
  sz[x] = 1;
  for (int i = h[x], k; i; i = nxt[i]) {
    k = to[i];
    w[k] = w[x] ^ (1 << (s[k] - 'a'));
    dfs(k);
    sz[x] += sz[k];
    if (sz[k] > sz[son[x]]) son[x] = k;
  }
}
void get(int rt, int x) {
  ans[rt] = max(ans[rt], p[w[x]] + d[x] - 2 * d[rt]);
  for (int i = (0); i <= (21); i++)
    ans[rt] = max(ans[rt], p[w[x] ^ (1 << i)] + d[x] - 2 * d[rt]);
  for (int i = h[x], k; i; i = nxt[i]) get(rt, k = to[i]);
}
void get2(int x) {
  p[w[x]] = max(p[w[x]], d[x]);
  for (int i = h[x], k; i; i = nxt[i]) get2(k = to[i]);
}
void del(int x) {
  p[w[x]] = -inf;
  for (int i = h[x], k; i; i = nxt[i]) del(k = to[i]);
}
void work(int x, int op) {
  for (int i = h[x], k; i; i = nxt[i])
    if ((k = to[i]) != son[x]) work(k, 1), ans[x] = max(ans[x], ans[k]);
  if (son[x]) work(son[x], 0), ans[x] = max(ans[x], ans[son[x]]);
  for (int i = h[x], k; i; i = nxt[i])
    if ((k = to[i]) != son[x]) get(x, k), get2(k);
  ans[x] = max(ans[x], p[w[x]] - d[x]);
  for (int i = (0); i <= (21); i++)
    ans[x] = max(ans[x], p[w[x] ^ (1 << i)] - d[x]);
  p[w[x]] = max(p[w[x]], d[x]);
  if (op) del(x);
}
int main() {
  scanf("%d", &n);
  for (int i = (2); i <= (n); i++) scanf("%d %c", &fa[i], &s[i]), add(fa[i], i);
  for (int i = (0); i <= ((1 << 21) - 1); i++) p[i] = -inf;
  dfs(1);
  work(1, 0);
  for (int i = (1); i <= (n); i++) printf("%d ", ans[i]);
  return 0;
}
