#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return ans * f;
}
const int MAXN = 200001;
struct node {
  int u, v, nex;
} x[MAXN << 2];
int head[MAXN], cnt, N, M, A[MAXN], dfn[MAXN], low[MAXN], col[MAXN], sta[MAXN],
    tot;
vector<int> vec[MAXN];
int Q(int u, int opt) { return u * 2 - (opt ^ 1); }
void add(int u, int v) {
  x[cnt].u = u, x[cnt].v = v, x[cnt].nex = head[u], head[u] = cnt++;
}
void tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  sta[++sta[0]] = u;
  for (int i = head[u]; i != -1; i = x[i].nex) {
    int v = x[i].v;
    if (!dfn[v])
      tarjan(v), low[u] = min(low[u], low[v]);
    else if (!col[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (low[u] == dfn[u]) {
    col[u] = ++col[0];
    while (sta[sta[0]] != u) {
      col[sta[sta[0]]] = col[0];
      sta[0]--;
    }
    sta[0]--;
  }
  return;
}
int main() {
  memset(head, -1, sizeof(head));
  N = read(), M = read();
  for (int i = 1; i <= N; i++) A[i] = read();
  for (int i = 1; i <= M; i++) {
    int c = read();
    for (int j = 1; j <= c; j++) vec[read()].push_back(i);
  }
  for (int i = 1; i <= N; i++) {
    if (A[i] == 1) {
      int x = vec[i][0], y = vec[i][1];
      add(Q(x, 1), Q(y, 1)), add(Q(y, 1), Q(x, 1));
      add(Q(x, 0), Q(y, 0)), add(Q(y, 0), Q(x, 0));
    }
    if (A[i] == 0) {
      int x = vec[i][0], y = vec[i][1];
      add(Q(x, 1), Q(y, 0)), add(Q(y, 0), Q(x, 1));
      add(Q(x, 0), Q(y, 1)), add(Q(y, 1), Q(x, 0));
    }
  }
  for (int i = 1; i <= 2 * M; i++)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= M; i++)
    if (col[Q(i, 0)] == col[Q(i, 1)]) {
      printf("NO\n");
      return 0;
    }
  printf("YES\n");
  return 0;
}
