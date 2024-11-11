#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1300;
int level[maxn];
int iter[maxn];
int head[maxn], tot;
struct edge {
  int to, cap, Next;
} e[5000];
void init(int n) {
  fill(head, head + n + 1, -1);
  tot = 0;
}
void add(int from, int to, int cap) {
  e[tot].Next = head[from];
  e[tot].to = to;
  e[tot].cap = cap;
  head[from] = tot;
  tot++;
}
void addedge(int from, int to, int cap) {
  add(from, to, cap);
  add(to, from, 0);
}
void bfs(int s) {
  memset(level, -1, sizeof(level));
  queue<int> q;
  level[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = head[v]; ~i; i = e[i].Next) {
      edge &ed = e[i];
      if (ed.cap > 0 && level[ed.to] < 0) {
        level[ed.to] = level[v] + 1;
        q.push(ed.to);
      }
    }
  }
}
int dfs(int v, int t, int f) {
  if (v == t) return f;
  for (int &i = iter[v]; ~i; i = e[i].Next) {
    edge &ed = e[i];
    if (ed.cap > 0 && level[v] < level[ed.to]) {
      int d = dfs(ed.to, t, min(f, ed.cap));
      if (d > 0) {
        ed.cap -= d;
        e[i ^ 1].cap += d;
        return d;
      }
    }
  }
  return 0;
}
int max_flow(int s, int t) {
  int flow = 0;
  while (1) {
    bfs(s);
    if (level[t] < 0) return flow;
    memcpy(iter, head, sizeof(iter));
    int f;
    while ((f = dfs(s, t, inf)) > 0) {
      flow += f;
    }
  }
}
vector<int> cnt[700];
int ans[700];
int deg[700];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    init(n + m + 5);
    fill(ans, ans + m + 1, 0);
    fill(deg, deg + n + 1, 0);
    for (int i = 1; i <= n; i++) cnt[i].clear();
    for (int i = 1; i <= m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      addedge(i, u + m, 1);
      addedge(i, v + m, 1);
      deg[u]++, deg[v]++;
    }
    int S = n + m + 1, T = S + 1;
    for (int i = 1; i <= m; i++) addedge(S, i, 1);
    int num = 0;
    for (int i = 1; i <= n; i++) {
      if (deg[i] > k) {
        addedge(i + m, T, 2 * (deg[i] - k));
        num += deg[i] - k;
      }
    }
    num <<= 1;
    if (num > max_flow(S, T)) {
      for (int i = 1; i <= m; i++) printf("0 ");
      printf("\n");
      continue;
    }
    for (int i = 0; i < 4 * m; i += 4) {
      if (e[i].cap == 0)
        cnt[e[i].to - m].push_back(i / 4 + 1);
      else if (e[i + 2].cap == 0)
        cnt[e[i + 2].to - m].push_back(i / 4 + 1);
    }
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < cnt[i].size(); j += 2) {
        flag++;
        ans[cnt[i][j]] = flag;
        ans[cnt[i][j + 1]] = flag;
      }
    }
    for (int i = 1; i <= m; i++) {
      if (ans[i])
        printf("%d ", ans[i]);
      else
        printf("%d ", ++flag);
    }
    printf("\n");
  }
  return 0;
}
