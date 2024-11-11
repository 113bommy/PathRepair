#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  register int data = 0, w = 1;
  register char ch = 0;
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (isdigit(ch)) data = 10 * data + ch - '0', ch = getchar();
  return w * data;
}
const int MAX_N = 2e6 + 5;
struct Graph {
  int to, next;
} e[MAX_N << 1];
int fir[MAX_N], e_cnt;
void clearGraph() {
  memset(fir, -1, sizeof(fir));
  e_cnt = 0;
}
void Add_Edge(int u, int v) { e[e_cnt] = (Graph){v, fir[u]}, fir[u] = e_cnt++; }
int P, N, M, Q;
int dfn[MAX_N], low[MAX_N], tim;
int stk[MAX_N], top, col[MAX_N], scc;
void tarjan(int x) {
  low[x] = dfn[x] = ++tim, stk[++top] = x;
  for (int i = fir[x]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (!dfn[v])
      tarjan(v), low[x] = min(low[x], low[v]);
    else if (!col[v])
      low[x] = min(low[x], dfn[v]);
  }
  if (dfn[x] == low[x]) {
    col[x] = ++scc;
    while (stk[top] != x) col[stk[top--]] = scc;
    --top;
  }
}
int main() {
  clearGraph();
  P = gi(), N = gi(), M = gi(), Q = gi();
  for (int i = 1; i <= P; i++) {
    int u = gi() - 1, v = gi() - 1;
    Add_Edge(((u) << 1 | 1), ((v) << 1)), Add_Edge(((v) << 1 | 1), ((u) << 1));
  }
  for (int i = 0; i < M; i++) {
    Add_Edge(((N + i) << 1), ((N + i + 1) << 1));
    Add_Edge(((N + i + 1) << 1 | 1), ((N + i) << 1 | 1));
  }
  Add_Edge(((N) << 1), ((N) << 1 | 1));
  for (int i = 0; i < N; i++) {
    int l = gi(), r = gi();
    Add_Edge(((i) << 1), ((N + l - 1) << 1 | 1));
    Add_Edge(((N + l - 1) << 1), ((i) << 1 | 1));
    Add_Edge(((i) << 1), ((N + r) << 1));
    Add_Edge(((N + r) << 1 | 1), ((i) << 1 | 1));
  }
  for (int i = 1; i <= Q; i++) {
    int u = gi() - 1, v = gi() - 1;
    Add_Edge(((u) << 1), ((v) << 1 | 1)), Add_Edge(((v) << 1), ((u) << 1 | 1));
  }
  for (int i = 0; i <= ((N + M) << 1 | 1); i++)
    if (!dfn[i]) tarjan(i);
  for (int i = 0; i <= N + M; i++)
    if (col[((i) << 1)] == col[((i) << 1 | 1)]) return puts("-1") & 0;
  int cnt = 0;
  for (int i = 0; i < N; i++)
    if (col[((i) << 1)] < col[((i) << 1 | 1)]) ++cnt;
  for (int i = 1; i <= M; i++)
    if (col[((N + i) << 1)] < col[((i) << 1 | 1)]) {
      printf("%d %d\n", cnt, i);
      break;
    }
  for (int i = 0; i < N; i++)
    if (col[((i) << 1)] < col[((i) << 1 | 1)]) printf("%d ", i + 1);
  putchar('\n');
  return 0;
}
