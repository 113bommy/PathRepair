#include <bits/stdc++.h>
using namespace std;
const int MaxN = 210, MaxM = 1010, inf = 1e9;
int N, M;
int S, T;
int Node[MaxN], Ecnt = 1;
struct Edges {
  int t, next, f;
} e[MaxM * 2];
void Add(int u, int v, int c) {
  e[++Ecnt] = (Edges){v, Node[u], c}, Node[u] = Ecnt;
  e[++Ecnt] = (Edges){u, Node[v], 0}, Node[v] = Ecnt;
}
int q[MaxN], head, tail;
int Dis[MaxN];
bool Bfs() {
  for (register int i = 1; i <= N; i++) Dis[i] = N;
  q[head = tail = 1] = T;
  Dis[T] = 0;
  while (head <= tail) {
    int x = q[head++];
    for (int i = Node[x]; i; i = e[i].next) {
      int t = e[i].t;
      if (Dis[t] > Dis[x] + 1 && e[i ^ 1].f) {
        Dis[t] = Dis[x] + 1;
        q[++tail] = t;
      }
    }
  }
  return Dis[S] < N;
}
int nlast[MaxN];
int Dinic(int x, int f) {
  if (x == T) return f;
  int now = f;
  for (int &i = nlast[x]; i; i = e[i].next) {
    int t = e[i].t;
    if (Dis[x] == Dis[t] + 1 && e[i].f) {
      int aa = Dinic(t, e[i].f < now ? e[i].f : now);
      e[i].f -= aa;
      e[i ^ 1].f += aa;
      now -= aa;
      if (!now) return f;
    }
  }
  return f - now;
}
int MaxFlow() {
  int Ans = 0;
  while (Bfs()) {
    for (register int i = 1; i <= N; i++) nlast[i] = Node[i];
    Ans += Dinic(S, inf);
  }
  return Ans;
}
bool Vis[MaxN];
void Dfs(int x) {
  Vis[x] = 1;
  for (int i = Node[x]; i; i = e[i].next)
    if (e[i].f && !Vis[e[i].t]) Dfs(e[i].t);
}
int Node2[MaxN], Ecnt2 = 1;
struct Edges2 {
  int t, next, c;
} e2[MaxN * 2];
void Add2(int u, int v, int c) {
  e2[++Ecnt2] = (Edges2){v, Node2[u], c}, Node2[u] = Ecnt2;
  e2[++Ecnt2] = (Edges2){u, Node2[v], c}, Node2[v] = Ecnt2;
}
int que[MaxN], Ans;
bool VisE[MaxN * 2];
void Solve(int l, int r) {
  if (l == r) return;
  S = que[l], T = que[r];
  for (int i = 2; i <= Ecnt; i += 2) e[i].f += e[i ^ 1].f, e[i ^ 1].f = 0;
  int Tmp = MaxFlow();
  Add2(que[l], que[l + 1], Tmp);
  Ans += Tmp;
  for (register int i = 1; i <= N; i++) Vis[i] = 0;
  Dfs(S);
  int mid = l - 1;
  for (register int i = l; i <= r; i++)
    if (Vis[que[i]]) {
      int o = que[i];
      que[i] = que[++mid];
      que[mid] = o;
    }
  Solve(l, mid);
  Solve(mid + 1, r);
}
int mn;
void GetMin(int x, int fa) {
  for (int i = Node2[x]; i; i = e2[i].next) {
    if (e2[i].t == fa || VisE[i]) continue;
    if (e2[i].c < e2[mn].c) mn = i;
    GetMin(e2[i].t, x);
  }
}
int GetAns(int x) {
  e2[mn = 0].c = inf;
  GetMin(x, 0);
  if (!mn) return x;
  int Now = mn;
  VisE[Now] = VisE[Now ^ 1] = 1;
  printf("%d ", GetAns(e2[Now].t));
  return GetAns(e2[Now ^ 1].t);
}
int main() {
  scanf("%d %d", &N, &M);
  for (register int i = 1; i <= M; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    Add(u, v, c);
    Add(v, u, c);
  }
  for (register int i = 1; i <= N; i++) que[i] = i;
  Solve(1, N);
  printf("%d\n", Ans);
  printf("%d\n", GetAns(1));
  return 0;
}
