#include <bits/stdc++.h>
int n, Ans, u, v, y[7000], nxt[7000], fst[7000], w[7000], tot;
struct hash {
  int s[7000], ans;
  void init() {
    memset(s, 0, sizeof(s));
    ans = 0;
  }
  void add(int x) {
    x += n;
    s[x]++;
    if (!s[x + 1]) ans = x - n;
  }
  void del(int x) {
    x += n;
    s[x]--;
    if (!s[x]) ans = x - n - 1;
  }
} mp;
void add(int u, int v, int c) {
  tot++;
  y[tot] = v;
  nxt[tot] = fst[u];
  fst[u] = tot;
  w[tot] = c;
}
void dfs(int u, int f) {
  for (int j = fst[u]; j; j = nxt[j])
    if (y[j] != f) tot += w[j], dfs(y[j], u);
}
void dfs2(int u, int f, int len) {
  mp.add(len);
  if (tot + len - mp.ans < Ans) Ans = tot + len - mp.ans;
  for (int j = fst[u]; j; j = nxt[j])
    if (y[j] != f) dfs2(y[j], u, len + 1 - 2 * w[j]);
  mp.del(len);
}
int main() {
  scanf("%d", &n);
  Ans = n + 1;
  for (int i = 0; i < n - 1; i++)
    scanf("%d%d", &u, &v), u--, v--, add(u, v, 0), add(v, u, 1);
  for (int i = 0; i < n; i++) {
    tot = 0;
    dfs(i, -1);
    mp.init();
    dfs2(i, -1, 0);
  }
  printf("%d\n", Ans);
}
