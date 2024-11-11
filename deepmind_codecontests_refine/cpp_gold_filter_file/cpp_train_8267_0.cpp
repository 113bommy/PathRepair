#include <bits/stdc++.h>
using namespace std;
struct road {
  int x, next;
  int num;
} r[100005 * 2];
int N, M;
int st[100005], w, deep[100005];
int fa[100005], sum[100005];
int in[100005], vis[100005];
int ans[100005][3], cnt;
vector<int> have[100005];
void add(int x, int y) {
  r[++w].x = y, r[w].next = st[x];
  st[x] = w;
}
void fail() {
  printf("No solution\n");
  exit(0);
}
int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
int Dfs(int x) {
  int i, tmp;
  vis[x] = 1, deep[x] = deep[fa[x]] + 1;
  for (i = st[x]; i; i = r[i].next) {
    if (!vis[tmp = r[i].x]) {
      fa[tmp] = x;
      if (Dfs(tmp)) have[x].push_back(tmp);
    } else if (deep[tmp] < deep[x] && tmp != fa[x])
      have[x].push_back(tmp);
  }
  tmp = have[x].size();
  for (i = 0; i < (int)have[x].size() - 1; i += 2)
    ans[++cnt][0] = have[x][i], ans[cnt][1] = x, ans[cnt][2] = have[x][i + 1];
  if (have[x].size() & 1) {
    if (!fa[x]) x++, x--;
    ans[++cnt][0] = have[x][have[x].size() - 1], ans[cnt][1] = x,
    ans[cnt][2] = fa[x];
    return 0;
  } else
    return 1;
}
int main() {
  int i, j;
  int fr, to;
  scanf("%d %d", &N, &M);
  for (i = 1; i <= N; i++) fa[i] = i;
  for (i = 1; i <= M; i++) {
    scanf("%d %d", &fr, &to);
    add(fr, to), add(to, fr);
    if (find(fr) != find(to)) {
      sum[fa[to]] += sum[fa[fr]];
      fa[fa[fr]] = fa[to];
    }
    sum[find(fr)]++;
  }
  for (i = 1; i <= N; i++)
    if (fa[i] == i && (sum[i] & 1)) fail();
  memset(fa, 0, sizeof(fa));
  for (i = 1; i <= N; i++)
    if (!vis[i]) Dfs(i);
  for (i = 1; i <= cnt; i++)
    printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
  return 0;
}
