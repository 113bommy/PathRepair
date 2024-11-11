#include <bits/stdc++.h>
const int N = 300005;
int n;
int a[N], ans[N];
char s[N];
std::vector<int> v[N];
int fa[N], sz[N], hson[N];
void dfs1(int x, int f) {
  fa[x] = f;
  sz[x] = 1;
  for (int i : v[x])
    if (i != f) {
      dfs1(i, x);
      sz[x] += sz[i];
      if (sz[i] > sz[hson[x]]) hson[x] = i;
    }
}
int Now, sum;
int tot = 1, rt = 1;
int ch[N][26], cnt[N];
void update(int x, int& now, int k) {
  if (!now) now = ++tot;
  if (!cnt[now]) ++sum;
  cnt[now] += k;
  if (!cnt[now]) --sum;
  for (int i : v[x])
    if (i != fa[x] && i != Now) update(i, ch[now][s[i] - 'a'], k);
}
void dfs2(int x, int& now, int opt) {
  if (!now) now = ++tot;
  for (int i : v[x])
    if (i != fa[x] && i != hson[x]) dfs2(i, ch[now][s[i] - 'a'], 0);
  if (hson[x]) dfs2(hson[x], ch[now][s[hson[x]] - 'a'], 1), Now = hson[x];
  update(x, now, 1);
  ans[x] = sum + a[x];
  Now = 0;
  if (!opt) update(x, now, -1), tot = 0;
}
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  std::cin >> s + 1;
  for (int i = 1, x, y; i < n; ++i) {
    std::cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs1(1, 0);
  dfs2(1, rt, 0);
  int max = 0;
  for (int i = 1; i <= n; ++i) max = std::max(max, ans[i]);
  std::cout << max << std::endl;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) cnt += ans[i] == max;
  std::cout << cnt << std::endl;
  return 0;
}
