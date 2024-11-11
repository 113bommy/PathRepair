#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger &operator,(const T &v) {
    cerr << v << "\t";
    return *this;
  }
} dbg;
template <class T>
void setmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
void setmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
T Abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T Mod(T n, T m) {
  return (n % m + m) % m;
}
template <class T>
string toString(T n) {
  ostringstream oss;
  oss << n;
  oss.flush();
  return oss.str();
}
int toInt(string s) {
  int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
bool isVowel(char ch) {
  ch = tolower(ch);
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return true;
  return false;
}
bool isUpper(char c) { return c >= 'A' && c <= 'Z'; }
bool isLower(char c) { return c >= 'a' && c <= 'z'; }
long long Pow(long long B, long long P) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) R = (R * B);
    P /= 2;
    B = (B * B);
  }
  return R;
}
int BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return (int)R;
}
void binprint(long long mask, long long n) {
  long long i;
  string s = "";
  do {
    s += (mask % 2 + '0');
    mask /= 2;
  } while (mask);
  reverse(s.begin(), s.end());
  s = string(max(n - (int)s.size(), 0LL), '0') + s;
  for (i = (int)s.size() - n; i < (int)s.size(); i++) printf("%c", s[i]);
  printf("\n");
}
void ASCII_Chart() {
  int i, j, k;
  printf("ASCII Chart:(30-129)\n");
  for (i = 30; i < 50; i++) {
    for (j = 0; j < 5; j++) {
      k = i + j * 20;
      printf("%3d---> '%c'   ", k, k);
    }
    printf("\n");
  }
}
struct pq {
  int node, cost;
  pq(int node = 0, int cost = 0) {
    this->node = node;
    this->cost = cost;
  }
  bool operator<(const pq &b) const { return cost > b.cost; }
};
char node[105][105];
string str;
int tmp[105], len[105], arr[30];
vector<int> adj[150];
int cost[150][150], capacity[150][150], flow;
int DIST[150], par[150];
void addedge(int u, int v, int cst, int cap) {
  adj[u].push_back(v);
  adj[v].push_back(u);
  cost[u][v] = cst;
  cost[v][u] = -cst;
  capacity[u][v] = cap;
  capacity[v][u] = 0;
}
bool Dijkstra(int source, int sink) {
  priority_queue<pq> Q;
  int i, u, v, c;
  for (i = 0; i <= sink; i++) DIST[i] = (1 << 28);
  DIST[source] = 0;
  Q.push(pq(source, 0));
  while (!Q.empty()) {
    u = Q.top().node;
    c = Q.top().cost;
    Q.pop();
    if (u == sink) return true;
    if (c > DIST[u]) continue;
    for (i = 0; i < adj[u].size(); i++) {
      v = adj[u][i];
      if (capacity[u][v] <= 0) continue;
      if (DIST[u] + cost[u][v] >= DIST[v]) continue;
      DIST[v] = DIST[u] + cost[u][v];
      par[v] = u;
      Q.push(pq(v, DIST[v]));
    }
  }
  return false;
}
void Update_graph(int v) {
  flow = min(flow, capacity[par[v]][v]);
  if (par[v]) Update_graph(par[v]);
  capacity[par[v]][v] -= flow;
  capacity[v][par[v]] += flow;
}
int MinCostMaxFlow(int source, int sink) {
  int res = 0, totalFlow = 0;
  while (Dijkstra(source, sink)) {
    flow = (1 << 28);
    Update_graph(sink);
    totalFlow += flow;
    res += (flow * DIST[sink]);
  }
  if (totalFlow == str.size()) return res;
  return -1;
}
int main() {
  int i, j, test, Case = 1;
  int source, sink, N;
  test = 5;
  while (test--) {
    cin >> str;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
      scanf("%s %d", node[i], &tmp[i]);
      len[i] = strlen(node[i]);
    }
    source = 0;
    sink = N + 26 + 1;
    for (i = 0; i <= sink; i++) adj[i].clear();
    for (i = 1; i <= N; i++) addedge(source, i, 0, min(tmp[i], len[i]));
    memset(arr, 0, sizeof(arr));
    for (i = 0; i < str.size(); i++) arr[str[i] - 'a']++;
    for (i = 0; i < 26; i++)
      if (arr[i]) addedge(N + i + 1, sink, 0, arr[i]);
    for (i = 1; i <= N; i++) {
      memset(arr, 0, sizeof(arr));
      for (j = 0; j < len[i]; j++) {
        arr[node[i][j] - 'a']++;
      }
      for (j = 0; j < 26; j++)
        if (arr[j]) addedge(i, N + j + 1, i, arr[j]);
    }
    int res = MinCostMaxFlow(source, sink);
    printf("%d\n", res);
  }
  return 0;
}
