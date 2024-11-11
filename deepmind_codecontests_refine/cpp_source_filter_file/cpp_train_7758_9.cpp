#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
template <class T, class X>
inline bool getbit(T a, X i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i) {
  T t = 1;
  return (a & (~(t << i)));
}
inline long long getnum() {
  char c = getchar();
  long long num, sign = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (num = 0; c >= '0' && c <= '9';) {
    c -= '0';
    num = num * 10 + c;
    c = getchar();
  }
  return num * sign;
}
inline long long power(long long a, long long b) {
  long long multiply = 1;
  for (int i = (0); i < (b); i++) {
    multiply *= a;
  }
  return multiply;
}
struct Edge {
  int to, rev;
  long long f, cap;
};
class Dinic {
 public:
  int dist[55], q[55], work[55], src, dest;
  vector<Edge> graph[55];
  void init(int sz) {
    for (int i = (0); i < (sz + 1); i++) graph[i].clear();
  }
  void clearFlow(int sz) {
    for (int i = (0); i < (sz + 1); i++) {
      for (int j = (0); j < (graph[i].size()); j++) graph[i][j].f = 0;
    }
  }
  void addEdge(int s, int t, int cap) {
    Edge a = {t, (int)graph[t].size(), 0, cap};
    Edge b = {s, (int)graph[s].size(), 0, 0};
    graph[s].push_back(a);
    graph[t].push_back(b);
  }
  bool bfs() {
    memset(dist, -1, sizeof(dist));
    dist[src] = 0;
    int qt = 0;
    q[qt++] = src;
    for (int qh = 0; qh < qt; qh++) {
      int u = q[qh];
      for (int j = 0; j < graph[u].size(); j++) {
        Edge &e = graph[u][j];
        int v = e.to;
        if (dist[v] < 0 && e.f < e.cap) {
          dist[v] = dist[u] + 1;
          q[qt++] = v;
        }
      }
    }
    return dist[dest] >= 0;
  }
  long long dfs(int u, long long f) {
    if (u == dest) return f;
    for (int &i = work[u]; i < (int)graph[u].size(); i++) {
      Edge &e = graph[u][i];
      if (e.cap <= e.f) continue;
      int v = e.to;
      if (dist[v] == dist[u] + 1) {
        long long df = dfs(v, min(f, e.cap - e.f));
        if (df > 0) {
          e.f += df;
          graph[v][e.rev].f -= df;
          return df;
        }
      }
    }
    return 0;
  }
  long long maxFlow(int _src, int _dest) {
    src = _src;
    dest = _dest;
    long long result = 0;
    while (bfs()) {
      fill(work, work + 55, 0);
      while (long long delta = dfs(src, 2000000000)) result += delta;
    }
    return result;
  }
} network;
int n, m, x;
int u[505], v[505];
double c[505];
void buildGraph(double val) {
  network.init(n + 2);
  for (int i = (1); i < (m + 1); i++) {
    network.addEdge(u[i] - 1, v[i] - 1, c[i] / val);
  }
}
int main() {
  int test, cases = 1;
  cin >> n >> m >> x;
  for (int i = (1); i < (m + 1); i++) {
    cin >> u[i] >> v[i] >> c[i];
  }
  double low = 0, high = 1e7;
  double ans = 0;
  for (int i = (0); i < (100); i++) {
    double mid = (low + high) / 2.0;
    buildGraph(mid);
    long long bears = network.maxFlow(0, n - 1);
    if (bears < x) {
      high = mid;
    } else {
      low = mid;
      ans = mid;
    }
  }
  printf("%0.10lf\n", ans * x);
  return 0;
}
