#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
int take[100];
struct Edge {
  int to, next;
} edge[10000];
int head[100];
int tot = 0;
long long dir[4][2] = {0, 1, -1, 0, 1, 0, 0, -1};
long long ans[100][2];
int co[100][6];
long long sum = 58;
void add_edge(int u, int v) {
  edge[++tot].to = v;
  edge[tot].next = head[u];
  head[u] = tot;
}
void dfs(int pre, int u) {
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
    if (v == pre) continue;
    for (int j = 0; j < 4; ++j) {
      if (!co[u][j] && !co[v][3 - j]) {
        ans[v][0] += ans[u][0] + dir[j][0] * (1LL << (sum));
        ans[v][1] += ans[u][1] + dir[j][1] * (1LL << (sum--));
        co[u][j] = 1;
        co[v][3 - j] = 1;
        break;
      }
    }
    dfs(u, v);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  memset(take, 0, sizeof take);
  memset(head, -1, sizeof(head));
  bool judge = 1;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    add_edge(v, u);
    take[u]++;
    take[v]++;
    if (take[u] > 4 || take[v] > 4) judge = 0;
  }
  if (judge) {
    cout << "YES\n";
    memset(co, 0, sizeof co);
    ans[1][0] = 0;
    ans[1][0] = 0;
    dfs(-1, 1);
    for (int i = 1; i <= n; ++i) printf("%lld %lld\n", ans[i][0], ans[i][1]);
  } else
    cout << "NO\n";
}
