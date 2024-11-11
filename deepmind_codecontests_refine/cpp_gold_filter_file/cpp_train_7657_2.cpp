#include <bits/stdc++.h>
using namespace std;
int n, b[400005], maxa, x, y, first[400005], c[400005], go[400005], nxt[400005],
    tot, top, t, from[400005], f[400005];
void addp(int x, int y) {
  nxt[++tot] = first[x];
  from[tot] = x;
  first[x] = tot;
  go[tot] = y;
}
void add(int x, int y) {
  nxt[++t] = first[x];
  first[x] = t;
  go[t] = y;
}
void dfsp(int x) {
  for (int i = first[x]; i; i = nxt[i])
    if (c[x] == c[go[i]] && !b[go[i]]) {
      b[go[i]] = b[x];
      dfsp(go[i]);
    }
}
void dfs(int x, int father) {
  f[x] = f[father] + 1;
  for (int i = first[x]; i; i = nxt[i])
    if (go[i] != father) dfs(go[i], x);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    addp(x, y);
    addp(y, x);
  }
  for (int i = 1; i <= n; i++)
    if (!b[i]) {
      b[i] = ++top;
      dfsp(i);
    }
  memset(first, 0, sizeof(first));
  for (int i = 1; i <= tot; i++)
    if (b[from[i]] != b[go[i]]) add(b[from[i]], b[go[i]]);
  dfs(1, 0);
  maxa = 1;
  for (int i = 1; i <= n; i++)
    if (f[maxa] < f[i]) maxa = i;
  memset(f, 0, sizeof(f));
  dfs(maxa, 0);
  maxa = 0;
  for (int i = 1; i <= top; i++) maxa = max(maxa, f[i]);
  if (maxa == 1) maxa--;
  printf("%d", maxa >> 1);
}
