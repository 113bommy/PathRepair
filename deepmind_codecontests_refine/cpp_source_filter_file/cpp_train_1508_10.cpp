#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 30;
const int M = 10010;
const int MOD = 1 << 29;
struct Edge {
  int to, next, f;
} E[M];
int head[N], num;
void add(int u, int v, int c) {
  E[num].to = v;
  E[num].f = c;
  E[num].next = head[u];
  head[u] = num++;
  E[num].to = u;
  E[num].f = 0;
  E[num].next = head[v];
  head[v] = num++;
}
int level[N];
int que[N];
bool BFS(int s, int t) {
  int i, iq = 0;
  for (i = 0; i <= t; i++) level[i] = 0;
  que[iq++] = s;
  level[s] = 1;
  for (i = 0; i < iq; i++) {
    int u = que[i];
    if (u == t) return true;
    for (int e = head[u]; e != -1; e = E[e].next) {
      int v = E[e].to;
      if (!level[v] && E[e].f > 0) {
        level[v] = level[u] + 1;
        que[iq++] = v;
      }
    }
  }
  return false;
}
int cur[N];
int dfs(int u, int maxf, int t) {
  if (u == t || maxf == 0) return maxf;
  int ret = 0, f, v;
  for (int& e = cur[u]; e != -1; e = E[e].next) {
    v = E[e].to;
    if (E[e].f > 0 && level[u] + 1 == level[v]) {
      f = dfs(v, min(maxf, E[e].f), t);
      E[e].f -= f;
      E[e ^ 1].f += f;
      maxf -= f;
      ret += f;
      if (maxf == 0) break;
    }
  }
  return ret;
}
void init() {
  memset(head, -1, sizeof(head));
  num = 0;
}
int Dinic(int s, int t) {
  int flow = 0;
  while (BFS(s, t)) {
    for (int i = 0; i <= t; i++) cur[i] = head[i];
    flow += dfs(s, MOD, t);
  }
  return flow;
}
bool vis[M];
int a[N], n, cnt;
vector<int> go[N], ans[N];
bool is[N];
void gao(int u) {
  ans[cnt].push_back(u);
  is[u] = true;
  for (int j = 0; j < go[u].size(); j++) {
    int v = go[u][j];
    if (is[v]) continue;
    gao(v);
  }
}
int main() {
  for (int i = 2; i < M; i++)
    if (!vis[i])
      for (int j = 2 * i; j < M; j += i) vis[j] = true;
  while (scanf("%d", &n) != EOF) {
    init();
    ans[0].clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      go[i].clear();
      ans[i].clear();
    }
    int st = 0, ed = n + 1;
    int cnt_o = 0, cnt_e = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] % 2 == 0) {
        add(st, i, 2);
        cnt_o += 2;
        for (int j = 1; j <= n; j++)
          if (a[j] % 2 == 1 && vis[a[i] + a[j]] == false) add(i, j, 1);
      } else
        add(i, ed, 2), cnt_e += 2;
    int tt = Dinic(st, ed);
    if (cnt_o != cnt_e || cnt_e != tt) {
      printf("Impossible\n");
    } else if (cnt_o == cnt_e && tt == cnt_o) {
      for (int i = 1; i <= n; i++)
        if (a[i] % 2 == 0) {
          for (int j = head[i]; j != -1; j = E[j].next)
            if (E[j].f == 0) {
              int v = E[j].to;
              if (v >= 1 && v <= n && a[v] % 2 == 1) {
                go[i].push_back(v);
                go[v].push_back(i);
              }
            }
        }
      memset(is, 0, sizeof(is));
      cnt = 0;
      for (int i = 1; i <= n; i++)
        if (is[i] == false) {
          gao(i);
          cnt++;
        }
      printf("%d\n", cnt);
      for (int i = 0; i < cnt; i++) {
        int tmp = ans[i].size();
        printf("%d", tmp);
        for (int j = 0; j < ans[i].size(); j++) {
          printf(" %d", ans[i][j]);
        }
        printf("\n");
      }
    } else
      printf("Impossible\n");
  }
  return 0;
}
