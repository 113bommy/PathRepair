#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
int n, K, d[maxn + 5], MAX[maxn + 5], dep[maxn + 5], ans;
bool vis[maxn + 5];
int E, lnk[maxn + 5], nxt[(maxn << 1) + 5], son[(maxn << 1) + 5];
void Dfs(int x, int pre = 0) {
  dep[x] = dep[pre] + 1;
  for (int j = lnk[x]; j; j = nxt[j])
    if (son[j] != pre) Dfs(son[j], x);
  MAX[x] = dep[x];
  if (d[x] == 1) vis[x] = true;
  for (int j = lnk[x]; j; j = nxt[j])
    if (son[j] != pre && vis[son[j]]) {
      if (MAX[son[j]] - dep[x] + MAX[x] - dep[x] > K) {
        if (MAX[son[j]] <= MAX[x]) MAX[x] = MAX[son[j]], vis[x] = true;
        ans++;
      } else if (MAX[son[j]] >= MAX[x])
        MAX[x] = MAX[son[j]], vis[x] = true;
    }
}
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 1, x, y; i < n; i++)
    scanf("%d%d", &x, &y), (son[++E] = (y), nxt[E] = lnk[x], lnk[x] = E),
        (son[++E] = (x), nxt[E] = lnk[y], lnk[y] = E), d[x]++, d[y]++;
  for (int i = 1; i <= n; i++)
    if (d[i] > 1) {
      Dfs(i);
      ans += vis[i];
      break;
    }
  return printf("%d\n", ans + vis[1]), 0;
}
