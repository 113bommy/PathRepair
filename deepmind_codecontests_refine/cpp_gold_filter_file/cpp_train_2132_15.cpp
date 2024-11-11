#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int data = 0, w = 1;
  char ch = 0;
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (isdigit(ch)) data = 10 * data + ch - '0', ch = getchar();
  return w * data;
}
const int INF = 1e9;
const int MAX_N = 1e5 + 5;
struct Graph {
  int to, cap, next;
} e[MAX_N << 1];
int fir[MAX_N], e_cnt;
void clearGraph() {
  memset(fir, -1, sizeof(fir));
  e_cnt = 0;
}
void Add_Edge(int u, int v, int c) {
  e[e_cnt] = (Graph){v, c, fir[u]};
  fir[u] = e_cnt++;
  e[e_cnt] = (Graph){u, 0, fir[v]};
  fir[v] = e_cnt++;
}
int level[MAX_N];
bool bfs(int s, int t) {
  queue<int> que;
  for (int i = 1; i <= t; i++) level[i] = -1;
  que.push(s), level[s] = 0;
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    for (int i = fir[x]; ~i; i = e[i].next) {
      int v = e[i].to;
      if (!e[i].cap || ~level[v]) continue;
      level[v] = level[x] + 1, que.push(v);
    }
  }
  return level[t] != -1;
}
int iter[MAX_N];
int dfs(int x, int t, int f) {
  if (x == t) return f;
  for (int &i = iter[x]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (level[v] > level[x] && e[i].cap) {
      int d = dfs(v, t, min(f, e[i].cap));
      if (d) {
        e[i].cap -= d;
        e[i ^ 1].cap += d;
        return d;
      }
    }
  }
  level[x] = -1;
  return 0;
}
int dinic(int s, int t) {
  int res = 0;
  while (bfs(s, t)) {
    for (int i = 1; i <= t; i++) iter[i] = fir[i];
    int f;
    while ((f = dfs(s, t, INF))) res += f;
  }
  return res;
}
int N, a[MAX_N], prime[MAX_N], cnt;
bool nprime[MAX_N];
void sieve() {
  for (int i = 2; i <= 100000; i++) {
    if (!nprime[i]) prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] <= 100000; j++) {
      nprime[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int S, T;
int Num1[MAX_N], Num2[MAX_N], c1, c2;
bool vis[MAX_N];
int siz = 0;
vector<int> vec[MAX_N];
void Dfs(int x) {
  vis[x] = 1;
  vec[siz].push_back(x);
  for (int i = fir[x]; ~i; i = e[i].next)
    if (!vis[e[i].to] && e[i | 1].cap == 1) Dfs(e[i].to);
}
int main() {
  clearGraph();
  N = gi();
  for (int i = 1; i <= N; i++) a[i] = gi();
  sieve();
  for (int i = 1; i <= N; i++)
    if (a[i] & 1)
      Num1[++c1] = i;
    else
      Num2[++c2] = i;
  if (c1 != c2) return puts("Impossible") & 0;
  S = N + 1, T = S + 1;
  for (int i = 1; i <= c1; i++)
    for (int j = 1; j <= c2; j++)
      if (!nprime[a[Num1[i]] + a[Num2[j]]]) Add_Edge(Num1[i], Num2[j], 1);
  for (int i = 1; i <= c1; i++) Add_Edge(S, Num1[i], 2);
  for (int i = 1; i <= c2; i++) Add_Edge(Num2[i], T, 2);
  if (dinic(S, T) != c1 * 2) return puts("Impossible") & 0;
  for (int i = 1; i <= N; i++)
    if (!vis[i]) Dfs(i), ++siz;
  printf("%d\n", siz);
  for (int i = 0; i < siz; i++, putchar('\n')) {
    printf("%lu ", vec[i].size());
    for (auto it : vec[i]) printf("%d ", it);
  }
  return 0;
}
