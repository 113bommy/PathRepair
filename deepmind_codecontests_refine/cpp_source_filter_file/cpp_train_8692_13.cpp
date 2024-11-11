#include <bits/stdc++.h>
using namespace std;
inline long long in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline string getStr() {
  char ch[1000000];
  scanf("%s", ch);
  return ch;
}
inline char getCh() {
  char ch;
  scanf(" %c", &ch);
  return ch;
}
const long long INF = 1e9;
const long long MAX_N = 1e5 + 10;
const long long MAX_M = MAX_N;
long double pi = 3.1415926535897932384626433832795028841971693993751;
struct edge {
  long long u, w, ind;
  edge() {}
  edge(long long u, long long w, long long ind) : u(u), w(w), ind(ind) {}
};
struct edge2 {
  long long v, u, w, ind;
  edge2() {}
  edge2(long long v, long long u, long long w, long long ind)
      : v(v), u(u), w(w), ind(ind) {}
};
vector<edge> graph[3][MAX_N];
vector<edge2> e;
long long h[MAX_N];
long long last[MAX_N];
long long di[2][MAX_N];
bool vis[MAX_N];
inline void dijkstra(long long node, bool tp) {
  set<pair<long long, long long>> st;
  st.insert({0, node});
  di[tp][node] = 0;
  while (!st.empty()) {
    long long v = st.begin()->second;
    long long dis = st.begin()->first;
    st.erase(st.begin());
    vis[v] = 1;
    for (long long i = 0; i < graph[tp][v].size(); i++) {
      long long u = graph[tp][v][i].u;
      long long cost = graph[tp][v][i].w;
      if (cost + dis < di[tp][u]) {
        st.erase({di[tp][u], u});
        di[tp][u] = cost + dis;
        st.insert({di[tp][u], u});
      }
    }
  }
}
inline void setInf(bool v) {
  for (long long i = 0; i < MAX_N; i++) vis[i] = 0;
  for (long long i = 0; i < MAX_N; i++)
    for (long long j = 0 + v; j < 2; j++) di[j][i] = INF;
}
bool cut[MAX_M];
inline void dfs(long long node, long long ind = -1) {
  vis[node] = true;
  last[node] = h[node];
  for (long long i = 0; i < graph[2][node].size(); i++) {
    long long u = graph[2][node][i].u;
    if (vis[u] == false) {
      h[u] = h[node] + 1;
      dfs(u, graph[2][node][i].ind);
      if (last[u] >= h[u]) cut[graph[2][node][i].ind] = true;
      last[node] = min(last[node], last[u]);
    } else {
      if (graph[2][node][i].ind != ind) {
        last[node] = min(last[node], last[u]);
      }
    }
  }
}
int32_t main() {
  in();
  long long m = in(), s = in(), t = in();
  e.resize(m);
  for (long long i = 0; i < m; i++) {
    e[i].v = in(), e[i].u = in(), e[i].w = in(), e[i].ind = i;
    graph[0][e[i].v].push_back(edge(e[i].u, e[i].w, e[i].ind));
    graph[1][e[i].u].push_back(edge(e[i].v, e[i].w, e[i].ind));
  }
  setInf(0);
  dijkstra(s, 0);
  setInf(1);
  dijkstra(t, 1);
  for (long long i = 0; i < m; i++) {
    long long n1 = e[i].v;
    long long n2 = e[i].u;
    long long cost = e[i].w;
    if (di[0][n1] + cost + di[1][n2] == di[0][t]) {
      graph[2][n1].push_back(edge(n2, cost, e[i].ind));
      graph[2][n2].push_back(edge(n1, cost, e[i].ind));
    }
  }
  for (long long i = 0; i < MAX_N; i++) vis[i] = false;
  dfs(s);
  for (long long i = 0; i < m; i++) {
    if (cut[i])
      printf("YES\n");
    else {
      long long v = e[i].v;
      long long u = e[i].u;
      long long w = e[i].w;
      if (di[0][t] - di[0][v] - di[1][u] - 1 > 0) {
        cout << "CAN " << w - (di[0][t] - di[0][v] - di[1][u] - 1) << endl;
      } else {
        printf("NO\n");
      }
    }
  }
}
