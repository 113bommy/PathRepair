#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& _p) {
  return os << "(" << _p.first << "," << _p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& _V) {
  bool f = true;
  os << "[";
  for (auto v : _V) {
    os << (f ? "" : ",") << v;
    f = false;
  }
  return os << "]";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& _S) {
  bool f = true;
  os << "(";
  for (auto s : _S) {
    os << (f ? "" : ",") << s;
    f = false;
  }
  return os << ")";
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& _M) {
  return os << set<pair<T, U>>(_M.begin(), _M.end());
}
const signed long long INF = 1000000100;
const long double EPS = 1e-9;
const int MAXN = 10005;
const int MAXM = 100005;
int nodes, nedge, src, dest;
int point[MAXM], nex[MAXM], flow[MAXM], capa[MAXM], cost[MAXM];
int head[MAXN], dist[MAXN], expand[MAXN], pre[MAXN], edge[MAXN];
bool changed[MAXN];
void init(int _nodes, int _src, int _dest) {
  nodes = _nodes;
  src = _src;
  dest = _dest;
  nedge = 0;
  for (int(i) = (0); (i) < (nodes); (i)++) head[i] = -1;
}
void add_edge(int u, int v, int c, int w) {
  point[nedge] = v, capa[nedge] = c, cost[nedge] = w, flow[nedge] = 0,
  nex[nedge] = head[u], head[u] = (nedge++);
  point[nedge] = u, capa[nedge] = 0, cost[nedge] = -w, flow[nedge] = 0,
  nex[nedge] = head[v], head[v] = (nedge++);
}
pair<int, int> ford() {
  int mflow = 0, mcost = 0;
  while (true) {
    for (int(i) = (0); (i) < (nodes); (i)++)
      dist[i] = INF, pre[i] = -1, changed[i] = 0;
    dist[src] = 0;
    changed[src] = 1;
    expand[src] = INF;
    while (true) {
      bool ok = 1;
      for (int(i) = (0); (i) < (nodes); (i)++)
        if (changed[i]) {
          changed[i] = 0;
          for (int k = head[i]; k >= 0; k = nex[k]) {
            if (flow[k] < capa[k] && dist[i] + cost[k] < dist[point[k]]) {
              dist[point[k]] = dist[i] + cost[k];
              changed[point[k]] = 1;
              pre[point[k]] = i;
              edge[point[k]] = k;
              expand[point[k]] = min(expand[i], capa[k] - flow[k]);
              ok = 0;
            }
          }
        }
      if (ok) break;
    }
    if (pre[dest] < 0) break;
    int d = expand[dest];
    mflow += d;
    mcost += d * dist[dest];
    for (int k = dest; k != src; k = pre[k]) {
      flow[edge[k]] += d;
      flow[edge[k] ^ 1] -= d;
    }
  }
  return make_pair(mflow, mcost);
}
const int MAXT = 1010;
int N, M, K;
string A;
string S[MAXT];
int P[MAXT];
char buff[MAXT];
void read_data() {
  scanf("%d", &N);
  scanf("%s", buff);
  A = string(buff);
  scanf("%d", &M);
  for (int(i) = (1); (i) <= (M); (i)++) {
    scanf("%s %d", buff, P + i);
    S[i] = string(buff);
  }
  scanf("%d", &K);
}
void solve() {
  init(N + 1, 0, N);
  for (int(i) = (1); (i) <= (M); (i)++)
    for (int(j) = (0); (j) < (N - int(S[i].size()) + 1); (j)++) {
      if (A.substr(j, int(S[i].size())) == S[i]) {
        add_edge(j, j + int(S[i].size()), 1, -P[i]);
      }
    }
  for (int(i) = (0); (i) < (N); (i)++) add_edge(i, i + 1, K, 0);
  printf("%d\n", -ford().second);
}
int main() {
  read_data();
  solve();
}
