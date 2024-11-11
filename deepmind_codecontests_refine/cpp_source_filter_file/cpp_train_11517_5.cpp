#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005, inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
const long double pi = acos(-1.0L);
vector<int> t[maxn];
int ans[maxn][3], head[maxn];
bool visit[maxn], use[maxn];
int cnt, num;
struct Edge {
  int from, to, pre;
};
Edge edge[maxn * 2];
void addedge(int from, int to) {
  edge[num] = (Edge){from, to, head[from]};
  head[from] = num++;
  edge[num] = (Edge){to, from, head[to]};
  head[to] = num++;
}
void dfs(int now, int fa, int pre) {
  visit[now] = 1;
  int size;
  for (int i = head[now]; i != -1; i = edge[i].pre) {
    int to = edge[i].to;
    if (to == 0) continue;
    edge[i].to = edge[i ^ 1].to = 0;
    if (!visit[to]) {
      dfs(to, now, 1);
      if (!use[to]) t[now].push_back(to);
    } else
      t[now].push_back(to);
  }
  size = t[now].size() + pre;
  if (size == 0) return;
  if (size % 2 == 0) {
    use[now] = 1;
    for (int i = 0; i + 1 < size - pre; i += 2)
      ans[++cnt][0] = t[now][i], ans[cnt][1] = now, ans[cnt][2] = t[now][i + 1];
    if (pre) ans[++cnt][0] = t[now][size - pre - 1], ans[cnt][1] = now;
    ans[cnt][2] = fa;
  } else
    for (int i = 0; i + 1 < size - pre; i += 2)
      ans[++cnt][0] = t[now][i], ans[cnt][1] = now, ans[cnt][2] = t[now][i + 1];
}
int main() {
  int n, m, i, j, x, y;
  num = 0;
  memset(head, -1, sizeof(head));
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    addedge(x, y);
  }
  memset(visit, 0, sizeof(visit));
  cnt = 0;
  memset(use, 0, sizeof(use));
  for (i = 1; i <= n; i++)
    if (!visit[i]) dfs(i, 0, 0);
  printf("%d\n", cnt);
  for (i = 1; i <= cnt; i++)
    printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
  return 0;
}
