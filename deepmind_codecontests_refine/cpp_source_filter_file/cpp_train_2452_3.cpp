#include <bits/stdc++.h>
using namespace std;
const int MX = 1e3 + 5;
const int INF = 0x3f3f3f3f;
struct Edge {
  int u, v, nxt, cost;
} E[200005];
int n, m, S, T, dfn, del, ans1, ansid;
int Head[MX], erear;
int DFN[MX], Low[MX];
void edge_init() {
  erear = 0;
  memset(Head, -1, sizeof(Head));
}
void edge_add(int u, int v, int cost) {
  E[erear].u = u;
  E[erear].v = v;
  E[erear].cost = cost;
  E[erear].nxt = Head[u];
  Head[u] = erear++;
}
inline int read() {
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  int x = 0;
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
class Path {
 public:
  bool vis[MX];
  int S[MX], E[MX], fa[MX], sz;
  void solve() {
    sz = 0;
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(::S);
    vis[::S] = 1;
    fa[::S] = -1;
    bool ok = 0;
    int u, v;
    while (!Q.empty()) {
      u = Q.front();
      Q.pop();
      if (u == T) {
        ok = 1;
        break;
      }
      for (int i = Head[u]; ~i; i = ::E[i].nxt) {
        v = ::E[i].v;
        if (vis[v]) continue;
        Q.push(v);
        vis[v] = 1;
        fa[v] = u;
        E[v] = (i + 2) / 2;
      }
    }
    if (!ok) return;
    u = T;
    while (fa[u] != -1) {
      S[++sz] = E[u];
      u = fa[u];
    }
  }
} path;
struct Ans {
  int id[2];
  int num, totcost;
  Ans() {
    num = 0;
    totcost = 2 * INF;
  }
  void print() {
    if (totcost == 2 * INF)
      printf("-1\n");
    else {
      printf("%d\n%d\n", totcost, num);
      for (int i = 0; i < num; i++) printf("%d ", id[i]);
    }
  }
};
int P[MX];
int find(int x) { return P[x] == x ? x : (P[x] = find(P[x])); }
void tarjan(int u, int e) {
  Low[u] = DFN[u] = ++dfn;
  for (int i = Head[u]; ~i; i = E[i].nxt) {
    if ((i + 2) / 2 == del) continue;
    int v = E[i].v;
    if (!DFN[v]) {
      tarjan(v, i | 1);
      Low[u] = min(Low[u], Low[v]);
      if (Low[v] > DFN[u] && DFN[u] < DFN[T] && ans1 > E[i].cost) {
        ansid = (i + 2) / 2;
        ans1 = E[i].cost;
      }
    } else if ((i | 1) != e && DFN[v] < DFN[u]) {
      Low[u] = min(Low[u], DFN[v]);
    }
  }
}
void find_bridge() {
  ans1 = INF;
  dfn = 0;
  memset(DFN, 0, sizeof(DFN));
  tarjan(S, -1);
}
int main() {
  edge_init();
  scanf("%d%d", &n, &m);
  scanf("%d%d", &S, &T);
  for (int i = 1; i <= n; i++) P[i] = i;
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read(), cost = read();
    edge_add(u, v, cost);
    edge_add(v, u, cost);
    int p1 = find(u), p2 = find(v);
    P[p1] = p2;
  }
  if (find(S) != find(T)) {
    printf("0\n0\n");
    return 0;
  }
  Ans ans;
  path.solve();
  find_bridge();
  if (ans1 != INF) {
    ans.num = 1;
    ans.totcost = ans1;
    ans.id[0] = ansid;
  }
  for (int i = 1; i <= path.sz; i++) {
    del = path.S[i];
    find_bridge();
    if (ans1 != INF && ans1 + E[(del - 1) * 2].cost < ans.totcost) {
      ans.num = 2;
      ans.id[0] = ansid;
      ans.id[1] = del;
      ans.totcost = ans1 + E[(del - 1) * 2].cost;
    }
  }
  ans.print();
  return 0;
}
