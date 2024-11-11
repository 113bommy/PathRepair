#include <bits/stdc++.h>
using namespace std;
template <typename elemType>
inline void Read(elemType &T) {
  elemType X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  T = (w ? -X : X);
}
struct Graph {
  struct edge {
    int Next, to, c;
  };
  edge G[400010];
  int head[20010];
  int cnt;
  Graph() : cnt(2) {}
  void clear(int node_num = 0) {
    cnt = 2;
    if (node_num == 0)
      memset(head, 0, sizeof(head));
    else
      fill(head, head + node_num + 5, 0);
  }
  void add_edge(int u, int v, int c) {
    G[cnt].c = c;
    G[cnt].to = v;
    G[cnt].Next = head[u];
    head[u] = cnt++;
  }
};
Graph G;
vector<tuple<int, int, int> > vec;
const int INF = 1 << 29;
int Deep[20005];
int current[20005];
int Num[20005];
int Pre[20005];
int N, M, S, T, n;
void ISAP_BFS(int t) {
  queue<int> Q;
  for (int i = 1; i <= N; i++) Deep[i] = N;
  Deep[t] = 0;
  Q.push(t);
  while (!Q.empty()) {
    int now = Q.front();
    Q.pop();
    for (int i = G.head[now]; i; i = G.G[i].Next) {
      if (G.G[i ^ 1].c && Deep[G.G[i].to] > Deep[now] + 1) {
        Deep[G.G[i].to] = Deep[now] + 1;
        Q.push(G.G[i].to);
      }
    }
  }
  return;
}
int Add_Flow() {
  int Res = INF, x = T;
  while (x != S) {
    x = Pre[x];
    Res = min(Res, G.G[current[x]].c);
  }
  x = T;
  while (x != S) {
    x = Pre[x];
    G.G[current[x]].c -= Res;
    G.G[current[x] ^ 1].c += Res;
  }
  return Res;
}
int ISAP() {
  memset(Num, 0, sizeof(Num));
  int now = S, MaxFlow = 0;
  ISAP_BFS(T);
  for (int i = 1; i <= N; i++) {
    ++Num[Deep[i]];
    current[i] = G.head[i];
  }
  while (Deep[S] < N) {
    if (now == T) {
      MaxFlow += Add_Flow();
      now = S;
    }
    bool has_find = false;
    for (int i = current[now]; i; i = G.G[i].Next) {
      if (Deep[now] != Deep[G.G[i].to] + 1 || G.G[i].c == 0) continue;
      has_find = true;
      current[now] = i;
      Pre[G.G[i].to] = now;
      now = G.G[i].to;
      break;
    }
    if (!has_find) {
      int minn = N - 1;
      for (int i = G.head[now]; i; i = G.G[i].Next)
        if (G.G[i].c) minn = min(minn, Deep[G.G[i].to]);
      if ((--Num[Deep[now]]) == 0) break;
      Num[Deep[now] = minn + 1]++;
      current[now] = G.head[now];
      if (now != S) now = Pre[now];
    }
  }
  return MaxFlow;
}
bool Judge(int limit) {
  G.clear();
  for (auto e : vec) {
    int u = get<0>(e), v = get<1>(e), w = get<2>(e);
    if (w > limit) continue;
    G.add_edge(u, v, 1);
    G.add_edge(v, u, 0);
  }
  for (int i = 1; i <= n; ++i) {
    G.add_edge(S, i, 1);
    G.add_edge(i, S, 0);
    G.add_edge(i + n, T, 1);
    G.add_edge(T, i + n, 0);
  }
  if (ISAP() == n) return true;
  return false;
}
int Solve(int L, int R) {
  int Res = 0;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (Judge(mid)) {
      Res = mid;
      R = mid - 1;
    } else
      L = mid + 1;
  }
  return Res;
}
int main() {
  Read(n);
  Read(M);
  N = n << 1;
  int Mi = 1 << 30, Mx = 0;
  for (register int i = 1; i <= M; ++i) {
    int u, v, w;
    Read(u);
    Read(v);
    Read(w);
    vec.push_back(make_tuple(u, v + n, w));
    Mi = min(Mi, w);
    Mx = max(Mx, w);
  }
  S = N + 1;
  T = N + 2;
  N += 2;
  if (!Judge(INF)) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", Solve(Mi, Mx));
  return 0;
}
