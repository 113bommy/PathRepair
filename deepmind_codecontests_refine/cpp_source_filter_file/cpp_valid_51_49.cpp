#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
int w[maxn][maxn], d[maxn];
struct edge {
  int u, v, w;
  bool operator<(const edge& a) const { return w < a.w; }
};
struct node {
  int to, w, nex;
} buf[maxn * 2];
int h[maxn], buf_tot;
void add_edge(int u, int v, int w) {
  buf[++buf_tot] = (node){v, w, h[u]};
  h[u] = buf_tot;
}
struct node2 {
  int to, nex;
} buf2[maxn * maxn * 6];
int h2[maxn * 6], buf2_tot;
void add_edge2(int u, int v) {
  buf2[++buf2_tot] = (node2){v, h2[u]};
  h2[u] = buf2_tot;
}
int I[maxn * 6];
int pre[maxn], pre_id[maxn], rt[maxn], dep[maxn], deg[maxn];
void dfs(int u, int p, int r) {
  rt[u] = r;
  for (int i = h[u]; i; i = buf[i].nex) {
    int v = buf[i].to;
    if (v == p) continue;
    pre[v] = u;
    pre_id[v] = buf[i].w;
    dep[v] = dep[u] + 1;
    dfs(v, u, r);
  }
}
int pa[maxn];
int fnd(int u) { return u == pa[u] ? u : (pa[u] = fnd(pa[u])); }
int X2[maxn * 6], dis_w[maxn * 6], dis_num[maxn * 6], dis_pre[maxn * 6];
int vis[maxn * 6], cnt[maxn * 6];
int main(void) {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) scanf("%d", &d[i]);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) scanf("%d", &w[i][j]);
  }
  for (int i = k + 1; i <= n; i++) d[i] = n;
  for (int i = k + 1; i <= n; i++) pa[i] = i;
  vector<edge> e;
  for (int i = k + 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) e.push_back((edge){i, j, w[i][j]});
  sort(e.begin(), e.end());
  vector<edge> U;
  for (int i = 0; i < (int)e.size(); i++) {
    int u = fnd(e[i].u), v = fnd(e[i].v);
    if (u == v) continue;
    U.push_back(e[i]);
    pa[u] = v;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = k + 1; j <= n; j++) U.push_back((edge){i, j, w[i][j]});
  }
  vector<edge> V;
  for (int i = 1; i <= k; i++) {
    for (int j = i + 1; j <= k; j++) V.push_back((edge){i, j, w[i][j]});
  }
  int ans = (int)1e9;
  for (int sv = 0, sz = (1 << V.size()); sv < sz; sv++) {
    for (int i = 1; i <= k; i++) pa[i] = i;
    for (int i = 1; i <= n; i++) deg[i] = 0;
    int ok = 1;
    for (int j = 0; j < (int)V.size(); j++)
      if ((sv >> j) & 1) {
        int u = fnd(V[j].u), v = fnd(V[j].v);
        if (u == v) {
          ok = 0;
          break;
        }
        pa[u] = v;
        deg[V[j].u]++, deg[V[j].v]++;
      }
    for (int i = 1; i <= k; i++)
      if (deg[i] > d[i]) ok = 0;
    if (!ok) continue;
    for (int i = 0; i < U.size(); i++) I[i] = 0;
    while (1) {
      buf_tot = 0;
      for (int i = 1; i <= n; i++)
        h[i] = pre[i] = pre_id[i] = dep[i] = rt[i] = 0;
      for (int j = 0; j < (int)V.size(); j++)
        if ((sv >> j) & 1) {
          int u = V[j].u, v = V[j].v;
          add_edge(u, v, -1);
          add_edge(v, u, -1);
        }
      for (int j = 0; j < (int)U.size(); j++)
        if (I[j]) {
          int u = U[j].u, v = U[j].v;
          add_edge(u, v, j);
          add_edge(v, u, j);
        }
      for (int i = 1; i <= n; i++)
        if (pre[i] == 0) dfs(i, 0, i);
      buf2_tot = 0;
      for (int i = 0; i < (int)U.size(); i++) h2[i] = 0;
      vector<int> IP;
      for (int a = 0; a < (int)U.size(); a++)
        if (I[a]) {
          IP.push_back(a);
          for (int b = 0; b < (int)U.size(); b++)
            if (!I[b]) {
              deg[U[a].u]--, deg[U[a].v]--;
              deg[U[b].u]++, deg[U[b].v]++;
              if (deg[U[b].u] <= d[U[b].u] && deg[U[b].v] <= d[U[b].u]) {
                add_edge2(a, b);
              }
              deg[U[a].u]++, deg[U[a].v]++;
              deg[U[b].u]--, deg[U[b].v]--;
            }
        }
      for (int b = 0; b < (int)U.size(); b++)
        if (!I[b]) {
          int u = U[b].u, v = U[b].v;
          if (rt[u] != rt[v]) {
            for (auto a : IP) {
              add_edge2(b, a);
            }
          } else {
            while (u != v) {
              if (dep[u] > dep[v]) {
                if (~pre_id[u]) add_edge2(b, pre_id[u]);
                u = pre[u];
              } else {
                if (~pre_id[v]) add_edge2(b, pre_id[v]);
                v = pre[v];
              }
            }
          }
        }
      for (int e = 0; e < U.size(); e++) {
        dis_w[e] = (int)1e9;
        dis_num[e] = 0;
        dis_pre[e] = -1;
        vis[e] = 0;
        cnt[e] = 0;
      }
      queue<int> Q;
      for (int i = 0; i < U.size(); i++) X2[i] = 0;
      for (int e = 0; e < U.size(); e++)
        if (!I[e]) {
          if (deg[U[e].u] + 1 <= d[U[e].u] && deg[U[e].v] + 1 <= d[U[e].v]) {
            Q.push(e);
            cnt[e]++;
            dis_w[e] = U[e].w, dis_num[e] = 0;
          }
          if (rt[U[e].u] != rt[U[e].v]) X2[e] = 1;
        }
      while (!Q.empty()) {
        int e = Q.front();
        Q.pop();
        vis[e] = false;
        for (int i = h2[e]; i; i = buf2[i].nex) {
          int v = buf2[i].to;
          int w = I[v] ? -U[v].w : U[v].w;
          if (dis_w[v] > dis_w[e] + w ||
              (dis_w[v] == dis_w[e] + w && dis_num[v] > dis_num[e] + 1)) {
            dis_w[v] = dis_w[e] + w;
            dis_num[v] = dis_num[e] + 1;
            dis_pre[v] = e;
            if (!vis[v]) {
              vis[v] = true;
              Q.push(v);
              if (++cnt[v] > U.size()) {
                assert(0);
              }
            }
          }
        }
      }
      int e = -1, min_dis = (int)1e9, min_num = 0;
      for (int i = 0; i < U.size(); i++)
        if (X2[i]) {
          if (dis_w[i] < min_dis ||
              (dis_w[i] == min_dis && dis_num[i] < min_num)) {
            e = i;
            min_dis = dis_w[i], min_num = dis_num[i];
          }
        }
      if (min_dis == (int)1e9) break;
      while (~e) {
        if (I[e])
          deg[U[e].u]--, deg[U[e].v]--;
        else
          deg[U[e].u]++, deg[U[e].v]++;
        I[e] ^= 1;
        e = dis_pre[e];
      }
    }
    for (int i = 1; i <= n; i++) pa[i] = i, deg[i] = 0;
    int cnt = 0, tmp = 0;
    for (int j = 0; j < V.size(); j++)
      if ((sv >> j) & 1) {
        int u = fnd(V[j].u), v = fnd(V[j].v);
        assert(u != v);
        pa[u] = v;
        deg[V[j].u]++, deg[V[j].v]++;
        tmp += V[j].w;
        cnt++;
      }
    for (int j = 0; j < U.size(); j++)
      if (I[j]) {
        int u = fnd(U[j].u), v = fnd(U[j].v);
        assert(u != v);
        pa[u] = v;
        deg[U[j].u]++, deg[U[j].v]++;
        tmp += U[j].w;
        cnt++;
      }
    if (cnt < n - 1) continue;
    for (int i = 1; i <= n; i++) assert(fnd(i) == fnd(1));
    for (int i = 1; i <= n; i++) assert(deg[i] <= d[i]);
    ans = min(ans, tmp);
  }
  printf("%d\n", ans);
  return 0;
}
