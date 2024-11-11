#include <bits/stdc++.h>
using namespace std;
namespace NetFlow {
const int MAXN = 100000, MAXM = 500000, inf = 1e9;
struct Edge {
  int v, c, f, nx;
  Edge() {}
  Edge(int v, int c, int f, int nx) : v(v), c(c), f(f), nx(nx) {}
} E[MAXM];
int G[MAXN], cur[MAXN], pre[MAXN], dis[MAXN], gap[MAXN], N, sz;
void init(int _n) {
  N = _n, sz = 0;
  memset(G, -1, sizeof(G[0]) * N);
}
void link(int u, int v, int c) {
  E[sz] = Edge(v, c, 0, G[u]);
  G[u] = sz++;
  E[sz] = Edge(u, 0, 0, G[v]);
  G[v] = sz++;
}
int ISAP(int S, int T) {
  int maxflow = 0, aug = inf, flag = false, u, v;
  for (int i = 0; i < N; ++i) cur[i] = G[i], gap[i] = dis[i] = 0;
  for (gap[S] = N, u = pre[S] = S; dis[S] < N; flag = false) {
    for (int &it = cur[u]; ~it; it = E[it].nx) {
      if (E[it].c > E[it].f && dis[u] == dis[v = E[it].v] + 1) {
        if (aug > E[it].c - E[it].f) aug = E[it].c - E[it].f;
        pre[v] = u, u = v;
        flag = true;
        if (u == T) {
          for (maxflow += aug; u != S;) {
            E[cur[u = pre[u]]].f += aug;
            E[cur[u] ^ 1].f -= aug;
          }
          aug = inf;
        }
        break;
      }
    }
    if (flag) continue;
    int mx = N;
    for (int it = G[u]; ~it; it = E[it].nx) {
      if (E[it].c > E[it].f && dis[E[it].v] < mx) {
        mx = dis[E[it].v];
        cur[u] = it;
      }
    }
    if ((--gap[dis[u]]) == 0) break;
    ++gap[dis[u] = mx + 1];
    u = pre[u];
  }
  return maxflow;
}
bool bfs(int S, int T) {
  static int Q[MAXN];
  memset(dis, -1, sizeof(dis[0]) * N);
  dis[S] = 0;
  Q[0] = S;
  for (int h = 0, t = 1, u, v, it; h < t; ++h) {
    for (u = Q[h], it = G[u]; ~it; it = E[it].nx) {
      if (dis[v = E[it].v] == -1 && E[it].c > E[it].f) {
        dis[v] = dis[u] + 1;
        Q[t++] = v;
      }
    }
  }
  return dis[T] != -1;
}
int dfs(int u, int T, int low) {
  if (u == T) return low;
  int ret = 0, tmp, v;
  for (int &it = cur[u]; ~it && ret < low; it = E[it].nx) {
    if (dis[v = E[it].v] == dis[u] + 1 && E[it].c > E[it].f) {
      if (tmp = dfs(v, T, min(low - ret, E[it].c - E[it].f))) {
        ret += tmp;
        E[it].f += tmp;
        E[it ^ 1].f -= tmp;
      }
    }
  }
  if (!ret) dis[u] = -1;
  return ret;
}
int dinic(int S, int T) {
  int maxflow = 0, tmp;
  while (bfs(S, T)) {
    memcpy(cur, G, sizeof(G[0]) * N);
    while (tmp = dfs(S, T, inf)) maxflow += tmp;
  }
  return maxflow;
}
}  // namespace NetFlow
using namespace NetFlow;
struct Seg {
  int x, y;
  friend bool operator<(const Seg &a, const Seg &b) { return a.x < b.x; }
  Seg(int x, int y) : x(x), y(y) {}
};
int cal(int l, int r, int mod) {
  if (mod == 0)
    return r / 5 - (l - 1) / 5;
  else
    return (r - mod + 5) / 5 - (l - mod + 4) / 5;
}
vector<Seg> vi;
int n, b, q;
int main(int argc, char *argv[]) {
  scanf("%d%d%d", &n, &b, &q);
  vi.push_back(Seg(b, n));
  for (int i = 1; i <= q; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    vi.push_back(Seg(x, y));
  }
  sort(vi.begin(), vi.end());
  int End = vi.size() + 6;
  init(q + 10);
  for (int i = 1; i <= 5; ++i) link(0, i, n / 5);
  int sum = 0;
  for (int i = 0; i < vi.size(); ++i) {
    int x = vi[i].x, y = vi[i].y;
    int num = vi[i].y - sum;
    if (num < 0) {
      cout << "unfair" << endl;
      return 0;
    }
    link(i + 6, End, num);
    for (int j = 1; j <= 5; ++j) {
      int l = i ? vi[i - 1].x + 1 : 1;
      int r = vi[i].x;
      link(j, i + 6, cal(l, r, j - 1));
    }
    sum += num;
  }
  if (dinic(0, End) == n)
    printf("fair\n");
  else
    printf("unfair\n");
  return 0;
}
