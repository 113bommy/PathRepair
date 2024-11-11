#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
constexpr auto MOD = 1000000007LL;
constexpr auto LINF = (1LL << 60);
constexpr auto INF = 2147483647LL;
constexpr auto PI = 3.1415926535897932384626433;
constexpr auto EPS = 1E-9;
template <typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1, T2> p) {
  out << p.first << ' ' << p.second;
  return out;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
auto printVector = []<typename T>(ostream& out, vector<T> v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
};
const int MAXN = 210, MAXM = 15010, DIRECTED = 0, UNDIRECTED = 1;
const int INFTY = 0x3fffffff;
int N, S, T, now;
struct edge {
  int remain;
  int endVertexId, nextEdgeId;
} e[MAXM << 1];
struct vertex {
  int firstEdgeId, level, firstUnsaturEdgeId;
} v[MAXN];
void _addEdge(int begin, int end, int c) {
  e[now].remain = c;
  e[now].endVertexId = end;
  e[now].nextEdgeId = v[begin].firstEdgeId;
  v[begin].firstEdgeId = now++;
}
void addEdge(int begin, int end, int c, int edgeType) {
  _addEdge(begin, end, c);
  _addEdge(end, begin, edgeType * c);
}
void init() {
  now = 0;
  for (int i = 0; i < N; ++i) v[i].firstEdgeId = -1;
}
bool markLevel() {
  for (int i = 0; i < N; ++i)
    v[i].level = -1, v[i].firstUnsaturEdgeId = v[i].firstEdgeId;
  v[S].level = 0;
  queue<int> Q;
  Q.push(S);
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for (int i = v[x].firstEdgeId; i >= 0; i = e[i].nextEdgeId)
      if (e[i].remain && v[e[i].endVertexId].level < 0)
        v[e[i].endVertexId].level = v[x].level + 1, Q.push(e[i].endVertexId);
  }
  return v[T].level > 0;
}
int extendFlow(int x, int flow) {
  if (x == T) return flow;
  int t, total = 0;
  for (int& i = v[x].firstUnsaturEdgeId; i >= 0; i = e[i].nextEdgeId) {
    if (v[e[i].endVertexId].level == v[x].level + 1 && e[i].remain) {
      if (t = extendFlow(e[i].endVertexId, min(flow, e[i].remain)))
        e[i].remain -= t, e[i ^ 1].remain += t, flow -= t, total += t;
      if (0 == flow) break;
    }
  }
  return total;
}
int Dinic() {
  int flow, total = 0;
  while (markLevel())
    while (flow = extendFlow(S, INFTY)) total += flow;
  return total;
}
int n, a[210], f[20010], vis[2010];
vvi res;
void buildGraph() {
  N = n + 2;
  S = 0;
  T = N - 1;
  init();
  int evenCount = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] % 2) {
      addEdge(S, i, 2, DIRECTED);
    } else {
      addEdge(i, T, 2, DIRECTED);
      evenCount++;
    }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (not f[a[i] + a[j]])
        addEdge((a[i] % 2 ? i : j), (a[i] % 2 ? j : i), 1, DIRECTED);
  if (Dinic() != evenCount * 2) {
    cout << "Impossible" << endl;
    return;
  }
  for (int i = 0; i < now; i++) {
    if (e[i].remain == 0 && e[i].endVertexId >= 1 && e[i].endVertexId <= n &&
        a[e[i].endVertexId] % 2 == 0 && not vis[e[i].endVertexId]) {
      res.push_back(vi());
      for (int par = 0, pos = e[i].endVertexId; vis[pos] == 0; par ^= 1) {
        vis[pos] = 1;
        res.back().push_back(pos);
        int canGo = 0;
        for (int i = v[pos].firstEdgeId; i >= 0; i = e[i].nextEdgeId) {
          if (par == 0) {
            if (e[i].remain && not vis[e[i].endVertexId]) {
              pos = e[i].endVertexId;
              canGo = 1;
              break;
            }
          } else {
            if (e[i].remain == 0 && not vis[e[i].endVertexId]) {
              pos = e[i].endVertexId;
              canGo = 1;
              break;
            }
          }
        }
        if (not canGo) break;
      }
    }
  }
  cout << res.size() << endl;
  for (auto v : res) {
    cout << v.size();
    for (auto x : v) cout << ' ' << x;
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  for (int i = 2; i < 20010; i++) {
    if (not f[i]) {
      for (int j = i * i; j < 20010; j += i) f[j] = 1;
    }
  }
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  buildGraph();
  return 0;
}
