#include <bits/stdc++.h>
using namespace std;
const int sigma_size = 26;
const int N = 200 + 50;
const int MAXN = 40000 + 50;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const int mod = 100000000 + 7;
int n, edge_cnt, top, cnt;
int a[N], head[N], vis[N], que[N], cur[N], s[N], gap[N], dep[N], num[N];
vector<int> mp[N];
struct Edge {
  int u, v, cap, flow, next;
} edge[MAXN];
void init() {
  edge_cnt = top = 0;
  memset(head, -1, sizeof(head));
  for (int i = 1; i <= n; i++) mp[i].clear();
}
void addedge(int u, int v, int cap) {
  edge[edge_cnt].u = u;
  edge[edge_cnt].v = v;
  edge[edge_cnt].cap = cap;
  edge[edge_cnt].flow = 0;
  edge[edge_cnt].next = head[u];
  head[u] = edge_cnt++;
  edge[edge_cnt].u = v;
  edge[edge_cnt].v = u;
  edge[edge_cnt].cap = 0;
  edge[edge_cnt].flow = 0;
  edge[edge_cnt].next = head[v];
  head[v] = edge_cnt++;
}
void bfs(int st, int ed) {
  memset(gap, 0, sizeof(gap));
  memset(dep, -1, sizeof(dep));
  int front = 0, rear = 0;
  gap[0] = 1;
  dep[ed] = 0;
  que[rear++] = ed;
  while (front != rear) {
    int u = que[front++];
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].v;
      if (dep[v] != -1) continue;
      que[rear++] = v;
      dep[v] = dep[u] + 1;
      gap[dep[v]]++;
    }
  }
}
int isap(int st, int ed) {
  bfs(st, ed);
  memcpy(cur, head, sizeof(head));
  int ans = 0, u = st;
  while (dep[st] < n + 2) {
    if (u == ed) {
      int Min = inf, inser;
      for (int i = 0; i < top; i++) {
        if (edge[s[i]].cap - edge[s[i]].flow < Min) {
          Min = edge[s[i]].cap - edge[s[i]].flow;
          inser = i;
        }
      }
      for (int i = 0; i < top; i++)
        edge[s[i]].flow += Min, edge[s[i] ^ 1].flow -= Min;
      ans += Min;
      top = inser;
      u = edge[s[top] ^ 1].v;
      continue;
    }
    int flag = 0, v;
    for (int i = cur[u]; i != -1; i = edge[i].next) {
      v = edge[i].v;
      if (edge[i].cap - edge[i].flow > 0 && dep[v] + 1 == dep[u]) {
        flag = 1;
        cur[u] = i;
        break;
      }
    }
    if (flag) {
      s[top++] = cur[u];
      u = v;
      continue;
    }
    int d = n + 2;
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].v;
      if (edge[i].cap - edge[i].flow > 0 && dep[v] < d) cur[u] = i, d = dep[v];
    }
    gap[dep[u]]--;
    if (!gap[dep[u]]) return ans;
    dep[u] = d + 1;
    gap[dep[u]]++;
    if (u != st) u = edge[s[--top] ^ 1].v;
  }
  return ans;
}
bool ok(int x) {
  int flag = 1;
  for (int i = 2; i * i <= x; i++) {
    if ((x % i) == 0) {
      flag = 0;
      break;
    }
  }
  return flag;
}
void dfs(int u) {
  num[++cnt] = u;
  for (int i = 0; i < mp[u].size(); i++) {
    int v = mp[u][i];
    if (vis[v]) continue;
    vis[v] = 1;
    dfs(v);
  }
}
int main() {
  while (~scanf("%d", &n)) {
    init();
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      if (a[i] & 1)
        addedge(0, i, 2);
      else
        addedge(i, n + 1, 2);
    }
    for (int i = 1; i <= n; i++) {
      if ((a[i] & 1) == 0) continue;
      for (int j = 1; j <= n; j++) {
        if (a[j] & 1) continue;
        if (ok(a[i] + a[j])) addedge(i, j, 1);
      }
    }
    int ans = isap(0, n + 1);
    if (ans != n) {
      printf("Impossible\n");
      continue;
    }
    for (int i = 0; i < edge_cnt; i++) {
      if (edge[i].u > 0 && edge[i].u < n + 1 && edge[i].v > 0 &&
          edge[i].v < n + 1) {
        int u = edge[i].u, v = edge[i].v;
        if ((a[u] & 1) && edge[i].cap - edge[i].flow == 0) {
          mp[u].push_back(v);
          mp[v].push_back(u);
        }
      }
    }
    int count = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
      if (!vis[i]) {
        ++count;
        vis[i] = 1;
        dfs(i);
      }
    printf("%d\n", count);
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        cnt = 0;
        vis[i] = 1;
        dfs(i);
        printf("%d", cnt);
        for (int j = 1; j <= cnt; j++) printf(" %d", num[j]);
        printf("\n");
      }
    }
  }
  return 0;
}
