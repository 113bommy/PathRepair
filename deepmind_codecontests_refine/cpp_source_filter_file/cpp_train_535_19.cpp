#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4;
const long long INFFLUJO = 1e14;
const long long INFCOSTO = 1e14;
struct edge {
  int u, v;
  long long cap, flow;
  long long cost;
  long long rem() { return cap - flow; }
};
int nodes;
vector<int> g[MAXN];
vector<edge> e;
void add_edge(int u, int v, long long cap, long long cost) {
  g[u].push_back(int(e.size()));
  e.push_back((edge){u, v, cap, 0, cost});
  g[v].push_back(int(e.size()));
  e.push_back((edge){v, u, 0, 0, -cost});
}
long long dist[MAXN], mncost;
int pre[MAXN];
long long cap[MAXN], mxflow;
bool in_queue[MAXN];
void flow(int s, int t) {
  memset(in_queue, 0, sizeof(in_queue));
  mxflow = mncost = 0;
  while (1) {
    fill(dist, dist + nodes, INFCOSTO);
    dist[s] = 0;
    memset(pre, -1, sizeof(pre));
    pre[s] = 0;
    memset(cap, 0, sizeof(cap));
    cap[s] = INFFLUJO;
    queue<int> q;
    q.push(s);
    in_queue[s] = 1;
    while (int(q.size())) {
      int u = q.front();
      q.pop();
      in_queue[u] = 0;
      for (int _ = 0, ThxDem = int(g[u].size()); _ < ThxDem; ++_) {
        int i = g[u][_];
        edge &E = e[i];
        if (E.rem() && dist[E.v] > dist[u] + E.cost + 1e-9) {
          dist[E.v] = dist[u] + E.cost;
          pre[E.v] = i;
          cap[E.v] = min(cap[u], E.rem());
          if (!in_queue[E.v]) q.push(E.v), in_queue[E.v] = 1;
        }
      }
    }
    if (pre[t] < 0) break;
    mxflow += cap[t];
    mncost += cap[t] * dist[t];
    for (int v = t; v != s; v = e[pre[v]].u) {
      e[pre[v]].flow += cap[t];
      e[pre[v] ^ 1].flow -= cap[t];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k, c, d;
  cin >> n >> m >> k >> c >> d;
  for (int i = 0, ThxDem = k; i < ThxDem; ++i) {
    int x;
    cin >> x;
    add_edge(0, x, 1, 0);
  }
  int mxlen = k + n + 10, sk = mxlen * k + 1;
  nodes = sk + 1;
  for (int t = 0, ThxDem = mxlen; t < ThxDem; ++t)
    add_edge(n * t + 1, sk, k, 0);
  for (int i = 1, ThxDem = n + 1; i < ThxDem; ++i)
    for (int t = 0, ThxDem = mxlen; t < ThxDem; ++t)
      add_edge(n * t + i, n * (t + 1) + i, k + 1, c);
  for (int i = 0, ThxDem = m; i < ThxDem; ++i) {
    int x, y;
    cin >> x >> y;
    for (int t = 0, ThxDem = mxlen; t < ThxDem; ++t) {
      for (int j = 1, ThxDem = k + 1; j < ThxDem; ++j) {
        add_edge(n * t + x, n * (t + 1) + y, 1, c + d * (2 * j - 1));
        add_edge(n * t + y, n * (t + 1) + x, 1, c + d * (2 * j - 1));
      }
    }
  }
  flow(0, sk);
  cout << mncost << "\n";
}
