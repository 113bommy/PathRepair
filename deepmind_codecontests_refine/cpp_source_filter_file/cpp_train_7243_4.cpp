#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int n, u, v, x, trie[maxn << 1][26], sz[maxn << 1], tot, cnt[maxn], res;
char op[2];
int merge(int a, int b) {
  if (!a || !b) return a + b;
  int rt = ++tot;
  memset(trie[rt], 0, sizeof trie[rt]);
  sz[rt] = 1;
  for (int i = 0; i < 26; ++i) {
    trie[rt][i] = merge(trie[a][i], trie[b][i]);
    sz[rt] += sz[trie[rt][i]];
  }
  return rt;
}
void dfs(int u, int dep) {
  sz[u] = 1;
  for (int i = 0; i < 26; ++i)
    if (trie[u][i]) {
      dfs(trie[u][i], dep + 1);
      sz[u] += sz[trie[u][i]];
    }
  cnt[dep] += sz[u];
  tot = n;
  int rt = 0;
  for (int i = 0; i < 26; ++i) rt = merge(rt, trie[u][i]);
  cnt[dep] -= sz[rt];
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d%d%s", &u, &v, op);
    trie[u][op[0] - 'a'] = v;
  }
  dfs(1, 0);
  res = 0;
  for (int i = 1; i < n; ++i)
    if (cnt[i] > cnt[res]) res = i;
  printf("%d\n%d\n", sz[1] - cnt[res], res + 1);
  return 0;
}
