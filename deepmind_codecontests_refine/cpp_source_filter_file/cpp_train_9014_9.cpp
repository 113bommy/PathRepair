#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
struct Graph {
  int to, next;
} e[MAX_N << 1];
int fir[MAX_N], e_cnt;
void clearGraph() {
  memset(fir, -1, sizeof(fir));
  e_cnt = 0;
}
void Add_Edge(int u, int v) { e[e_cnt] = (Graph){v, fir[u]}, fir[u] = e_cnt++; }
int N, M, fa[MAX_N], deg[MAX_N], dis[MAX_N];
int a[MAX_N];
vector<int> cir;
bool vis[MAX_N];
void YES() {
  puts("YES");
  for (int i = 1; i <= N; i++) printf("%d ", a[i]);
  putchar('\n');
}
void dfs(int x) {
  if (cir.size()) return;
  if (vis[x]) {
    int o = fa[x];
    cir.push_back(x);
    while (o != x) cir.push_back(o), o = fa[o];
    return;
  }
  vis[x] = 1;
  for (int i = fir[x]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa[x]) continue;
    fa[v] = x, dfs(v);
  }
}
void solve() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= M; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    Add_Edge(u, v), Add_Edge(v, u);
    ++deg[u], ++deg[v];
  }
  cir.clear();
  for (int i = 1; i <= N; i++)
    if (!vis[i]) {
      dfs(i);
      if (cir.size()) break;
    }
  if (cir.size()) {
    for (int it : cir) a[it] = 1;
    return YES();
  }
  for (int x = 1; x <= N; x++)
    if (deg[x] > 3) {
      a[x] = 2;
      for (int i = fir[x]; ~i; i = e[i].next) a[e[i].to] = 1;
      return YES();
    }
  for (int i = 1; i <= N; i++) vis[i] = 0;
  for (int rt = 1; rt <= N; rt++) {
    if (deg[rt] != 3) continue;
    static int Q[MAX_N];
    int head, tail;
    Q[head = tail = 1] = rt;
    dis[rt] = 1, vis[rt] = 1, fa[rt] = 0;
    while (head <= tail) {
      int x = Q[head++];
      for (int i = fir[x]; ~i; i = e[i].next) {
        int v = e[i].to;
        if (vis[v]) continue;
        fa[v] = x, dis[v] = dis[x] + 1, vis[v] = 1, Q[++tail] = v;
      }
    }
    for (int j = 2; j <= N; j++) {
      int x = Q[j];
      if (deg[x] == 3) {
        for (int i = fir[rt]; ~i; i = e[i].next) a[e[i].to] = 1;
        for (int i = fir[x]; ~i; i = e[i].next) a[e[i].to] = 1;
        for (int i = x; i; i = fa[i]) a[i] = 2;
        return YES();
      }
    }
    int p = 0, q = 0, r = 0;
    for (int i = 1; i <= tail; i++) {
      int x = Q[i];
      if (deg[x] == 1) {
        if (!p)
          p = x;
        else if (!q)
          q = x;
        else if (!r)
          r = x;
      }
    }
    if (1ll * dis[p] * dis[q] * dis[r] <
        1ll * dis[p] * dis[q] + 1ll * dis[p] * dis[r] + 1ll * dis[q] * dis[r])
      continue;
    vector<int> vec[3];
    for (int i = p; i != rt; i = fa[i]) vec[0].push_back(i);
    for (int i = q; i != rt; i = fa[i]) vec[1].push_back(i);
    for (int i = r; i != rt; i = fa[i]) vec[2].push_back(i);
    for (int i = 0; i < 3; i++) reverse(vec[i].begin(), vec[i].end());
    if (vec[0].size() > vec[1].size()) swap(vec[0], vec[1]);
    if (vec[0].size() > vec[2].size()) swap(vec[0], vec[2]);
    if (vec[1].size() > vec[2].size()) swap(vec[1], vec[2]);
    if (vec[2].size() >= 5) {
      a[rt] = 6, a[vec[0][0]] = 3, a[vec[1][0]] = 4, a[vec[1][1]] = 2;
      for (int i = 0; i < 5; i++) a[vec[2][i]] = 5 - i;
    } else {
      a[rt] = (vec[0].size() + 1) * (vec[1].size() + 1) * (vec[2].size() + 1);
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < (int)vec[i].size(); j++)
          a[vec[i][j]] = a[rt] / (vec[i].size() + 1) * (vec[i].size() - j);
    }
    return YES();
  }
  puts("NO");
}
int main() {
  clearGraph();
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    solve();
    for (int i = 1; i <= N; i++)
      fir[i] = -1, a[i] = deg[i] = fa[i] = vis[i] = 0;
    e_cnt = 0;
  }
  return 0;
}
