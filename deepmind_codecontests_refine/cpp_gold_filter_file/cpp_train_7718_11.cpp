#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;
int n, m;
int read() {
  int x = 0, y = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') y = (ch == '-') ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * y;
}
int tot = 0, first[M];
struct Edge {
  int nxt, to;
} e[M << 1];
void add(int x, int y) {
  e[++tot] = (Edge){first[x], y};
  first[x] = tot;
}
int in[M];
bool vis[M], ins[M];
vector<int> G[M];
void tarjan(int u) {
  vis[u] = ins[u] = 1;
  for (int i = first[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (!ins[v]) G[u].push_back(v), in[v]++;
    if (!vis[v]) tarjan(v);
  }
  ins[u] = 0;
}
int top = 0, sta[M];
void solve() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    add(x, y);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) tarjan(i);
  for (int i = 1; i <= n; i++)
    if (!in[i]) sta[++top] = i;
  while (top > 1) {
    int x = sta[top--], y = sta[top--];
    printf("? %d %d\n", x, y), fflush(stdout);
    int flag = read();
    if (!flag) swap(x, y);
    sta[++top] = x;
    for (int v : G[y]) {
      in[v]--;
      if (!in[v]) sta[++top] = v;
    }
  }
  printf("! %d\n", sta[1]);
}
signed main() { solve(); }
