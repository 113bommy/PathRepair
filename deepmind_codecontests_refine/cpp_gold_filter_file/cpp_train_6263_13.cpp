#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int t, f, v, next;
  Edge() {}
  Edge(int a, int b, int c, int d) : t(a), f(b), v(c), next(d) {}
};
Edge e[100000];
int head[10005], vs, vt, tot = -1;
inline void addEdge(int x, int y, int z, int v) {
  e[++tot] = Edge(y, z, v, head[x]);
  head[x] = tot;
  e[++tot] = Edge(x, 0, -v, head[y]);
  head[y] = tot;
}
namespace Flow {
queue<int> q;
int dis[10005], cur[10005];
bool in[10005];
bool spfa() {
  while (!q.empty()) q.pop();
  memset(dis, 0x3f, sizeof(dis));
  memset(in, 0, sizeof(in));
  dis[vs] = 0;
  in[vs] = 1;
  q.push(vs);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    in[x] = 0;
    cur[x] = head[x];
    for (int i = head[x]; i != -1; i = e[i].next)
      if (e[i].f && dis[x] + e[i].v < dis[e[i].t]) {
        int u = e[i].t;
        dis[u] = dis[x] + e[i].v;
        if (!in[u]) {
          in[u] = 1;
          q.push(u);
        }
      }
  }
  return dis[vt] < 0x3f3f3f3f;
}
int vis[10005], cnt;
int dfs(int x, int a) {
  if (x == vt || !a) return a;
  vis[x] = cnt;
  int ans = 0;
  for (int &i = cur[x]; i != -1; i = e[i].next)
    if (e[i].f && vis[e[i].t] < cnt && dis[x] + e[i].v == dis[e[i].t]) {
      int u = e[i].t;
      int f = dfs(u, min(a, e[i].f));
      if (f) {
        e[i].f -= f;
        e[i ^ 1].f += f;
        ans += f;
        a -= f;
        if (!a) break;
      }
    }
  return ans;
}
int msmf(int up) {
  int s = 0, s2 = 0, f;
  while (spfa()) do {
      cnt++;
      f = dfs(vs, 0x3f3f3f3f);
      s += f * dis[vt];
      s2 += f;
    } while (f);
  assert(s2 >= up);
  return s;
}
}  // namespace Flow
pair<long long, int> a[2505], b[2505];
int id1[2505], id2[2505];
bool cmp1(int x, int y) {
  return (a[x].second != a[y].second) ? a[x].second < a[y].second
                                      : a[x].first > a[y].first;
}
bool cmp2(int x, int y) {
  return (b[x].second != b[y].second) ? b[x].second < b[y].second
                                      : b[x].first > b[y].first;
}
bool check(int n, int T) {
  static pair<long long, int> cur[2505];
  static bool vis[2505];
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++)
    cur[i] = pair<long long, int>((long long)b[i].first * T + b[i].second, i);
  sort(cur + 1, cur + n + 1);
  int s = 0, r1 = 1, r2 = 1;
  for (int i = 1; i <= n; i++) {
    int x = id1[i];
    while (r1 <= n && b[id2[r1]].second <= a[x].second) {
      long long v = (long long)b[id2[r1]].first * T + b[id2[r1]].second;
      while (r2 <= n && cur[r2].first <= v) {
        if (!vis[cur[r2].second]) s++;
        vis[cur[r2++].second] = 1;
      }
      if (!vis[id2[r1]]) s++;
      vis[id2[r1++]] = 1;
    }
    long long v = (long long)a[x].first * T + a[x].second;
    while (r2 <= n && cur[r2].first <= v) {
      if (!vis[cur[r2].second]) s++;
      vis[cur[r2++].second] = 1;
    }
    if (i > s) return 0;
  }
  return 1;
}
int solve(int n, int T) {
  static pair<long long, int> cur[2505];
  vs = 0;
  vt = 4 * n + 1;
  for (int i = 1; i <= n; i++)
    cur[i] = pair<long long, int>((long long)b[i].first * T + b[i].second, i);
  sort(cur + 1, cur + n + 1);
  for (int i = 1; i <= n; i++) {
    addEdge(vs, i, 1, 0);
    addEdge(n + i, vt, 1, 0);
    addEdge(2 * n + i, n + i, 1, 0);
    addEdge(3 * n + i, n + i, 1, 0);
  }
  for (int i = 2; i <= n; i++) {
    addEdge(2 * n + id2[i], 2 * n + id2[i - 1], 0x3f3f3f3f, 0);
    addEdge(3 * n + cur[i].second, 3 * n + cur[i - 1].second, 0x3f3f3f3f, 0);
  }
  for (int i = 1; i <= n; i++) {
    int x = id1[i], r = 0;
    long long v = (long long)a[x].first * T + a[x].second;
    while (r < n && cur[r + 1].first <= v) r++;
    if (r) addEdge(x, 3 * n + cur[r].second, 1, 1);
    r = 0;
    long long maxn = 0;
    while (r < n && b[id2[r + 1]].second <= a[x].second) {
      r++;
      maxn = max(maxn, (long long)b[id2[r]].first * T + b[id2[r]].second);
    }
    if (r) addEdge(x, 2 * n + id2[r], 1, 1);
    for (int j = 1; j < i; j++)
      maxn = max(maxn, (long long)a[id1[j]].first * T + a[id1[j]].second);
    r = 0;
    while (r < n && cur[r + 1].first <= maxn) r++;
    if (r) addEdge(x, 3 * n + cur[r].second, 1, 2);
  }
  return Flow::msmf(n);
}
int main() {
  memset(head, 255, sizeof(head));
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i] = pair<long long, int>(x, y);
    id1[i] = i;
  }
  sort(id1 + 1, id1 + n + 1, cmp1);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    b[i] = pair<long long, int>(x, y);
    id2[i] = i;
  }
  sort(id2 + 1, id2 + n + 1, cmp2);
  if (!check(n, 1e9)) {
    puts("-1");
    return 0;
  }
  int l = 0, r = 1e9;
  while (l < r) {
    int m = ((l + r) >> 1);
    if (check(n, m))
      r = m;
    else
      l = m + 1;
  }
  printf("%d %d\n", l, solve(n, l));
  return 0;
}
