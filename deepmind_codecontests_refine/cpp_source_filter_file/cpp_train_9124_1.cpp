#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, len;
char str[N];
namespace LeftlistTree {
int root[N], nodeCnt = 0, key[N], lc[N], rc[N], dis[N];
inline int newNode(int val) {
  int p = ++nodeCnt;
  lc[p] = rc[p] = dis[p] = 0;
  key[p] = val;
  return p;
}
int merge(int x, int y) {
  if (!x || !y) return x + y;
  if (key[x] < key[y]) swap(x, y);
  rc[x] = merge(rc[x], y);
  if (dis[lc[x]] < dis[rc[x]]) swap(lc[x], rc[x]);
  dis[x] = dis[rc[x]] + 1;
  return x;
}
int calc(int x) {
  int res = key[x];
  if (lc[x]) res += calc(lc[x]);
  if (rc[x]) res += calc(rc[x]);
  return res;
}
void print(int x) {
  if (lc[x]) print(lc[x]);
  printf("%d ", key[x]);
  if (rc[x]) print(rc[x]);
}
}  // namespace LeftlistTree
using namespace LeftlistTree;
namespace Trie {
int ch[N][26], nodeCnt = 0, dep[N];
bool val[N];
inline void ins() {
  len = strlen(str + 1);
  int u = 0, v;
  for (int i = 1; i <= len; i++) {
    v = str[i] - 'a';
    if (!ch[u][v]) ch[u][v] = ++nodeCnt;
    dep[ch[u][v]] = dep[u] + 1;
    u = ch[u][v];
  }
  val[u] = 1;
}
void dfs(int x) {
  for (int i = 0; i < 26; i++)
    if (ch[x][i]) {
      dfs(ch[x][i]);
      root[x] = merge(root[x], root[ch[x][i]]);
    }
  if (!val[x]) root[x] = merge(lc[root[x]], rc[root[x]]);
  root[x] = merge(root[x], newNode(dep[x]));
}
}  // namespace Trie
using namespace Trie;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str + 1);
    ins();
  }
  int ans = 0;
  for (int i = 0; i < 26; i++)
    if (ch[0][i]) {
      dfs(ch[0][i]);
      ans += calc(root[ch[0][i]]);
    }
  printf("%I64d\n", ans);
  return 0;
}
