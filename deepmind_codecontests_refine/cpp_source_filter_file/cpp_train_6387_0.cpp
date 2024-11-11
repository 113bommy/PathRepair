#include <bits/stdc++.h>
using namespace std;
const int N = 100;
bool v[101];
int e[101][2], cnt[101], ans, root;
void dfs(int now, int fa, int c) {
  v[now] = 1;
  int i, j;
  for (i = 0; i < cnt[now]; i++)
    if ((j = e[now][i]) != fa) {
      if (!v[j])
        dfs(j, now, c + 1);
      else if (root == j && (c & 1))
        ans++;
    }
}
int main() {
  int n, m, i, j, fr, to;
  while (scanf("%d%d", &n, &m) == 2) {
    memset(cnt, 0, (n + 1) << 2);
    while (m--) {
      scanf("%d%d", &i, &j);
      e[i][cnt[i]++] = j;
      e[j][cnt[j]++] = i;
    }
    memset(v, 0, n + 1);
    ans = 0;
    for (int i = 1; i <= n; i++)
      if (!v[i]) dfs(root = i, 0, 1);
    printf("%d\n", ans + (n & 1));
  }
  return 0;
}
