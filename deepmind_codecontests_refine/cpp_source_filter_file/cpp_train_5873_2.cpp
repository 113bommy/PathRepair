#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const long long INF = 0x3f3f3f3f3f3f;
const int mod = 1000000007;
int n, x, num, po, flag;
int chu[maxn], a[maxn];
struct node {
  int to, next;
} edge[maxn];
int head[maxn], cnt;
int vis[maxn], pre[maxn];
vector<int> vec;
int pos = 0, ans = -1;
void addEdge(int u, int v) {
  edge[cnt].to = v;
  edge[cnt].next = head[u];
  head[u] = cnt++;
}
void dfs(int u, int cen) {
  if (cen > num) {
    ans = cen;
    pos = u;
  }
  int v = pre[u];
  if (vis[v] == 0 && chu[v] == 1 && v) dfs(v, cen + 1);
}
void dfs2(int u) {
  printf("%d ", u);
  int i = head[u];
  if (i == -1) return;
  if (a[u] == 1) {
    return;
  }
  dfs2(edge[i].to);
}
int main() {
  scanf("%d", &n);
  memset(head, -1, sizeof(head));
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1) vis[i] = 1;
  }
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &pre[i]);
    if (pre[i]) {
      addEdge(pre[i], i);
      chu[pre[i]]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      dfs(i, 1);
    }
  }
  printf("%d\n", ans);
  dfs2(pos);
  return 0;
}
