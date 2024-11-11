#include <bits/stdc++.h>
using namespace std;
template <typename Tp>
inline void read(Tp &x) {
  static char c;
  static bool neg;
  x = 0, c = getchar(), neg = false;
  for (; !isdigit(c); c = getchar()) {
    if (c == '-') {
      neg = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (neg) {
    x = -x;
  }
}
const int U = 22;
namespace G {
const int N = 1e3 + 5;
const int M = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int head[N], E = 1;
struct Edge {
  int to, next, flow;
} e[M];
inline void addEdge(int u, int v, int flow) {
  e[++E] = (Edge){v, head[u], flow};
  head[u] = E;
}
inline void addE(int u, int v, int flow) {
  addEdge(u, v, flow);
  addEdge(v, u, 0);
}
int dis[N];
int S, T;
inline bool bfs() {
  memset(dis, 0x3f, sizeof(dis));
  queue<int> q;
  dis[S] = 0;
  q.emplace(S);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u], v, w; v = e[i].to, w = e[i].flow, i; i = e[i].next) {
      if (dis[v] == INF && w != 0) {
        dis[v] = dis[u] + 1;
        q.emplace(v);
      }
    }
  }
  return dis[T] != INF;
}
int dfs(int u, int flow) {
  if (u == T || flow == 0) {
    return flow;
  }
  int res = 0;
  for (int i = head[u], v, w; v = e[i].to, w = e[i].flow, i; i = e[i].next) {
    if (w != 0 && dis[v] == dis[u] + 1) {
      w = dfs(v, std::min(flow, w));
      if (w != 0) {
        flow -= w;
        res += w;
        e[i].flow -= w;
        e[i ^ 1].flow += w;
        if (flow == 0) {
          break;
        }
      }
    }
  }
  if (!res) {
    dis[u] = -1;
  }
  return res;
}
inline int dinic() {
  int res = 0;
  while (bfs()) {
    res += dfs(S, INF);
  }
  return res;
}
}  // namespace G
const int P = U + 5;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int n, m, male, female;
char mp[P][P];
struct Scayger {
  int dis[P][P];
  int x, y, speed;
  inline void calc() {
    memset(dis, 0x3f, sizeof(dis));
    dis[x][y] = 0;
    queue<tuple<int, int, int>> q;
    q.emplace(0, x, y);
    int w, lx, ly, nx, ny;
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      tie(w, lx, ly) = t;
      if (w == dis[lx][ly]) {
        for (int i = 0; i < 4; ++i) {
          nx = lx + dx[i], ny = ly + dy[i];
          if (mp[nx][ny] == '.') {
            if (dis[nx][ny] > w + 1) {
              dis[nx][ny] = w + 1;
              q.emplace(dis[nx][ny], nx, ny);
            }
          }
        }
      }
    }
  }
};
Scayger M[P * P], F[P * P];
inline void buildGraph(long long tim) {
  using G::addE;
  using G::E;
  using G::head;
  using G::S;
  using G::T;
  memset(head, 0, sizeof(head));
  E = 1;
  S = 0, T = male + female + 2 * n * m + 1;
  for (int u = 1; u <= male; ++u) {
    addE(S, (u), 1);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (M[u].dis[i][j] != G::INF &&
            (long long)M[u].dis[i][j] * M[u].speed <= tim) {
          addE((u), (male + female + (i - 1) * n + (j)), 1);
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      addE((male + female + (i - 1) * n + (j)),
           (male + female + n * m + (i - 1) * n + (j)), 1);
    }
  }
  for (int u = 1; u <= female; ++u) {
    addE((male + (u)), T, 1);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (F[u].dis[i][j] != G::INF &&
            (long long)F[u].dis[i][j] * F[u].speed <= tim) {
          addE((male + female + n * m + (i - 1) * n + (j)), (male + (u)), 1);
        }
      }
    }
  }
}
int main() {
  read(n), read(m), read(male), read(female);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", mp[i] + 1);
  }
  if (male - female == -1) {
    ++male;
    for (int i = 1; i <= male; ++i) {
      read(M[i].x), read(M[i].y), read(M[i].speed);
    }
    for (int i = 1; i <= female; ++i) {
      read(F[i].x), read(F[i].y), read(F[i].speed);
    }
  } else if (male - female == 1) {
    ++female;
    read(F[1].x), read(F[1].y), read(F[1].speed);
    for (int i = 1; i <= male; ++i) {
      read(M[i].x), read(M[i].y), read(M[i].speed);
    }
    for (int i = 2; i <= female; ++i) {
      read(F[i].x), read(F[i].y), read(F[i].speed);
    }
  } else {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= male; ++i) {
    M[i].calc();
  }
  for (int i = 1; i <= female; ++i) {
    F[i].calc();
  }
  long long l = 0, r = 1LL << 40, mid, ans = -1;
  while (l <= r) {
    mid = (l + r) >> 1;
    buildGraph(mid);
    if (G::dinic() == male) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%lld\n", ans);
}
