#include <bits/stdc++.h>
using namespace std;
int Gcd(int a, int b) {
  if (b == 0) return a;
  return Gcd(b, a % b);
}
int Lcm(int a, int b) { return a / Gcd(a, b) * b; }
inline long long read() {
  long long f = 1, x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 1e5 + 10;
const long long mod = 1e9 + 7;
struct Graph {
 private:
  int n, m, tot;
  int head[N];
  struct Edge {
    int to, nex, w;
  } ed[N << 1];
  int color[N];

 public:
  void __init__(int n, int m = -1) {
    this->n = n;
    this->m = m;
    tot = 0;
  }
  void addEdge(int u, int v, int w) {
    ed[++tot] = (Edge){v, head[u], w};
    head[u] = tot;
  }

 public:
  bool bfs(int s = 1) {
    queue<int> q;
    q.push(s);
    color[s] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = head[u]; i; i = ed[i].nex) {
        int v = ed[i].to;
        if (color[v] == -1) {
          color[v] = !color[u];
          q.push(v);
        } else if (color[v] == color[u]) {
          return false;
        }
      }
    }
    return true;
  }
  bool isBiGraph() {
    memset(color, -1, sizeof(color));
    for (int i = 1; i <= n; i++) {
      if (color[i] == -1 && bfs(i) == false) {
        return false;
      }
    }
    return true;
  }
} G;
struct Union {
  int tot, n, tag;
  int pre[N], vis[N], id[N];
  void __init__(int n) {
    this->n = n;
    this->tot = 0;
    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
      pre[i] = i;
    }
  }
  int find(int x) {
    if (pre[x] == x) return x;
    return pre[x] = find(pre[x]);
  }
  void join(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
      pre[fx] = fy;
    }
  }
  void map() {
    tag = 1;
    for (int i = 1; i <= n; i++) {
      int fx = find(i);
      if (!vis[fx]) {
        vis[fx] = 1;
        id[fx] = ++tot;
      }
    }
  }
  int totNumber() {
    if (!tag) map();
    return tot;
  }
} S1, S2;
namespace solve {
int n, m;
int u[N], v[N], c[N];
void Read() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    u[i] = read();
    v[i] = read();
    c[i] = read();
  }
}
void initUnion() {
  S1.__init__(n);
  S2.__init__(n);
}
void unionSd() {
  for (int i = 1; i <= m; i++) {
    if (c[i] == 1) {
      S1.join(u[i], v[i]);
    }
  }
  for (int i = 1; i <= m; i++) {
    S2.join(u[i], v[i]);
  }
  S1.map();
  S2.map();
}
void buildGraph() {
  G.__init__(S1.totNumber());
  for (int i = 1; i <= m; i++) {
    if (c[i] == 1) continue;
    int x = S1.find(u[i]), y = S1.find(v[i]);
    x = S1.id[x];
    y = S1.id[y];
    G.addEdge(x, y, 0);
    G.addEdge(y, x, 0);
  }
}
void Init() {
  initUnion();
  unionSd();
  buildGraph();
}
void Work() {
  if (G.isBiGraph() == false) {
    cout << 0 << endl;
    return;
  }
  int tot = S2.totNumber();
  long long ans = 1;
  for (int i = 1; i <= tot - 1; i++) {
    ans = ans * 2 % mod;
  }
  cout << ans << endl;
}
};  // namespace solve
int main() {
  solve::Read();
  solve::Init();
  solve::Work();
  return 0;
}
