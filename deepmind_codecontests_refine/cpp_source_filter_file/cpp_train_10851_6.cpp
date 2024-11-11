#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline string get() {
  char ch[2000010];
  scanf("%s", ch);
  return ch;
}
inline void read(int *a, int n) {
  for (int i = 0; i < n; i++) a[i] = in();
}
template <class blank>
inline void out(blank x) {
  cout << x << "\n";
  exit(0);
}
template <class blank>
inline void smin(blank &a, blank b) {
  a = min(a, b);
}
template <class blank>
inline void smax(blank &a, blank b) {
  a = max(a, b);
}
const int maxn = 600 + 10;
const int maxm = 1e6 + 10;
const int maxlg = 21;
const int base = 29;
const int mod = 1e9 + 7;
const int inf = 1e9 + 10;
const int SQ = 317;
int a[maxn];
struct edge {
  int v, u, flow, cap, weight;
  edge() {}
  edge(int v, int u, int flow, int cap, int weight)
      : v(v), u(u), flow(flow), cap(cap), weight(weight) {}
} e[maxm];
int cur;
int edgeid[maxn][maxn];
vector<int> g[maxn];
int source, sink;
inline void add_edge(int v, int u, int flow, int cap, int weight) {
  g[v].push_back(cur);
  edgeid[v][u] = cur;
  e[cur++] = {v, u, flow, cap, weight};
  g[u].push_back(cur);
  edgeid[u][v] = cur;
  e[cur++] = {u, v, -flow, 0, -weight};
}
bool used[maxn];
pair<int, int> pre[maxn];
int di[maxn];
int q[(int)1e7];
inline int SPFA() {
  int ret = 0;
  while (true) {
    for (int i = 0; i <= source + 1; i++) di[i] = inf, used[i] = false;
    di[source] = 0, used[source] = true;
    int h = 0, t = 1;
    q[0] = source;
    while (h < t) {
      int v = q[h++];
      used[v] = false;
      for (int i = 0; i < g[v].size(); i++) {
        int u = e[g[v][i]].u;
        int cst = e[g[v][i]].weight + di[v];
        if (e[g[v][i]].cap == e[g[v][i]].flow) continue;
        if (di[u] > cst) {
          di[u] = cst;
          pre[u] = {g[v][i], v};
          if (!used[u]) used[u] = true, q[t++] = u;
        }
      }
    }
    if (di[sink] == inf) return ret;
    int mini = inf;
    int cur = sink;
    while (cur != source) {
      pair<int, int> cc = pre[cur];
      mini = min(mini, e[cc.first].cap - e[cc.first].flow);
      cur = cc.second;
    }
    cur = sink;
    while (cur != source) {
      pair<int, int> cc = pre[cur];
      e[cc.first].flow += mini;
      e[cc.first ^ 1].flow -= mini;
      cur = cc.second;
    }
    ret += mini * di[sink];
  }
  return 0;
}
inline int mcmf() { return SPFA(); }
int what[maxn];
int32_t main() {
  int n = in(), m = in();
  read(a, n);
  memset(edgeid, -1, sizeof edgeid);
  source = 2 * n + m, sink = source + 1;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      add_edge(i, n + m + j, 0, 1,
               __builtin_popcount(a[j]) * bool(a[j] != a[i]));
  for (int i = n; i < n + m; i++)
    for (int j = 0; j < n; j++)
      add_edge(i, n + m + j, 0, 1, __builtin_popcount(a[j]));
  for (int i = 0; i < n + m; i++) add_edge(source, i, 0, 1, 0);
  for (int i = n + m; i < 2 * n + m; i++) add_edge(i, sink, 0, 1, 0);
  int cost = mcmf();
  int lines = 0;
  for (int i = 0; i < n; i++) {
    int node = i + n + m;
    for (int j = 0; j < n + m; j++) {
      if (edgeid[j][node] + 1 && e[edgeid[j][node]].flow) {
        if (j >= n) {
          lines++;
        } else {
          if (a[i] != a[i]) lines++;
        }
      }
    }
    lines++;
  }
  cout << lines << " " << cost << "\n";
  for (int i = 0; i < n; i++) {
    int node = i + n + m;
    for (int j = 0; j < n + m; j++) {
      if (edgeid[j][node] + 1 && e[edgeid[j][node]].flow) {
        if (j >= n) {
          int letter = j - n;
          cout << char(letter + 'a') << "=" << a[i] << "\n";
          what[i] = letter;
        } else {
          if (a[i] != a[j]) cout << char(what[j] + 'a') << "=" << a[i] << "\n";
          what[i] = what[j];
        }
      }
    }
    cout << "print(" << char(what[i] + 'a') << ")\n";
  }
}
