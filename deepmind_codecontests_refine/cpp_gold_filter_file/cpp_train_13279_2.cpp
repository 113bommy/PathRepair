#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int inf = 0x3f3f3f3f;
int num[maxn][2];
struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
struct EdmondsKarp {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  int a[maxn];
  int p[maxn];
  void init(int n) {
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }
  void AddEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }
  int Maxflow(int s, int t) {
    int flow = 0;
    for (;;) {
      memset(a, 0, sizeof(a));
      queue<int> Q;
      Q.push(s);
      a[s] = inf;
      while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < (int)G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          if (!a[e.to] && e.cap > e.flow) {
            p[e.to] = G[x][i];
            a[e.to] = min(a[x], e.cap - e.flow);
            Q.push(e.to);
          }
        }
        if (a[t]) break;
      }
      if (!a[t]) break;
      for (int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[t];
        edges[p[u] ^ 1].flow -= a[t];
        if (13 <= u && u <= 17 && 1 <= edges[p[u]].from &&
            edges[p[u]].from <= 6) {
          if (edges[p[u]].from == u - 12) num[u][0] += a[t];
          if (edges[p[u]].from == u - 11) num[u][1] += a[t];
        }
        if (1 <= u && u <= 6 && 13 <= edges[p[u]].from &&
            edges[p[u]].from <= 17) {
          assert(0);
          if (u == edges[p[u]].from - 12) num[edges[p[u]].from][0] -= a[t];
          if (u == edges[p[u]].from - 11) num[edges[p[u]].from][1] -= a[t];
        }
      }
      flow += a[t];
    }
    return flow;
  }
} ED;
int n;
int cnt[maxn];
int ID[maxn];
string s;
int id() {
  cin >> s;
  if (s == "S") return 7;
  if (s == "M") return 8;
  if (s == "L") return 9;
  if (s == "XL") return 10;
  if (s == "XXL") return 11;
  if (s == "XXXL") return 12;
  if (s == "S,M") return 13;
  if (s == "M,L") return 14;
  if (s == "L,XL") return 15;
  if (s == "XL,XXL") return 16;
  if (s == "XXL,XXXL") return 17;
  assert(1);
}
void print(int x) {
  if (x == 7)
    puts("S");
  else if (x == 8)
    puts("M");
  else if (x == 9)
    puts("L");
  else if (x == 10)
    puts("XL");
  else if (x == 11)
    puts("XXL");
  else if (x == 12)
    puts("XXXL");
  else if (num[x][0]) {
    num[x][0]--;
    print(x - 6);
  } else
    print(x - 5);
}
int main() {
  ED.init(19);
  int tp;
  for (int i = 0; i < 6; i++) {
    scanf("%d", &tp);
    ED.AddEdge(0, i + 1, tp);
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) cnt[ID[i] = id()]++;
  for (int i = 7; i <= 17; i++)
    if (cnt[i]) {
      ED.AddEdge(i, 18, cnt[i]);
      if (i >= 13) {
        ED.AddEdge(i - 12, i, n);
        ED.AddEdge(i - 11, i, n);
      } else
        ED.AddEdge(i - 6, i, n);
    }
  int flow = ED.Maxflow(0, 18);
  if (flow != n)
    puts("NO");
  else {
    puts("YES");
    for (int i = 0; i < n; i++) print(ID[i]);
  }
  return 0;
}
