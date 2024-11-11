#include <bits/stdc++.h>
using namespace std;
template <int MAXV, class T = int>
struct Dinic {
  const static bool SCALING = true;
  int lim = 1;
  const T INF = numeric_limits<T>::max();
  struct edge {
    int to, rev;
    T cap, flow;
  };
  int s = 0, t = MAXV - 1;
  int level[MAXV], ptr[MAXV];
  vector<edge> adj[MAXV];
  void addEdge(int a, int b, T cap, bool isDirected = true) {
    adj[a].push_back({b, (int)adj[b].size(), cap, 0});
    adj[b].push_back({a, (int)(adj[a].size() - 1), isDirected ? 0 : cap, 0});
  }
  bool bfs() {
    queue<int> q({s});
    fill(level, level + MAXV, -1);
    level[s] = 0;
    while (!q.empty() && level[t] == -1) {
      int v = q.front();
      q.pop();
      for (auto e : adj[v]) {
        if (level[e.to] == -1 && e.flow < e.cap &&
            (!SCALING || e.cap - e.flow >= lim)) {
          q.push(e.to);
          level[e.to] = level[v] + 1;
        }
      }
    }
    return level[t] != -1;
  }
  T dfs(int v, T flow) {
    if (v == t || !flow) return flow;
    for (; ptr[v] < adj[v].size(); ptr[v]++) {
      edge &e = adj[v][ptr[v]];
      if (level[e.to] != level[v] + 1) continue;
      if (T pushed = dfs(e.to, min(flow, e.cap - e.flow))) {
        e.flow += pushed;
        adj[e.to][e.rev].flow -= pushed;
        return pushed;
      }
    }
    return 0;
  }
  long long calc() {
    long long flow = 0;
    for (lim = SCALING ? (1 << 30) : 1; lim > 0; lim >>= 1) {
      while (bfs()) {
        fill(ptr, ptr + MAXV, 0);
        while (T pushed = dfs(s, INF)) {
          flow += pushed;
        }
      }
    }
    return flow;
  }
};
const int N = 1205;
int arr[N], arr2[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    fill(arr, arr + N, 0);
    fill(arr2, arr2 + N, 0);
    Dinic<N, int> d;
    for (int j = n + 1; j <= n + m; j++) {
      int x, y;
      cin >> x >> y;
      arr[x]++;
      arr[y]++;
      d.addEdge(j, N - 1, 1, 1);
      d.addEdge(x, j, 1, 1);
      d.addEdge(y, j, 1, 1);
    }
    int expected_flow = 0;
    for (int i = 1; i <= n; i++) {
      int c = 0;
      if (arr[i] > k) {
        c = 2 * (arr[i] - k);
      } else {
        c = 0;
      }
      expected_flow += c;
      d.addEdge(0, i, min(c, 2 * k), 1);
    }
    int flow = d.calc();
    int z = 1;
    bool bo = 0;
    if (flow == expected_flow) {
      bo = 1;
      for (int i = 1; i <= n; i++) {
        int z2 = 1;
        for (auto e : d.adj[i]) {
          if (e.flow == 1) {
            if (z2 & 1) {
              arr2[e.to] = z + z2++;
            } else {
              arr2[e.to] = z - 1 + z2++;
            }
          }
        }
        z += z2;
      }
    }
    for (int j = n + 1; j <= n + m; j++) {
      if (arr2[j] == 0 && bo) {
        arr2[j] = z++;
      }
      cout << arr2[j] << " ";
    }
    cout << '\n';
  }
}
