#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    ;
  int x = ch - '0';
  for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
    x = x * 10 + ch - '0';
  return x;
}
int query(int u, int v) {
  printf("? %d %d\n", u, v);
  fflush(stdout);
  return read();
}
void answer(int v) {
  printf("! %d\n", v);
  fflush(stdout);
}
const int N = 1e5 + 5;
int n, m, deg[N], q[N];
vector<int> to[N], e[N];
bool vis[N], in[N];
void dfs(int x) {
  vis[x] = in[x] = 1;
  for (int z : to[x]) {
    if (!in[z]) e[x].push_back(z), deg[z]++;
    if (!vis[z]) dfs(z);
  }
  in[x] = 0;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    to[u].push_back(v);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i);
  for (int i = 1; i <= n; i++)
    if (!deg[i]) q[++q[0]] = i;
  for (; q[0] > 1;) {
    int u = q[q[0]--], v = q[q[0]--];
    if (!query(u, v)) swap(u, v);
    q[++q[0]] = u;
    for (int z : e[u])
      if (!(--deg[z])) q[++q[0]] = z;
  }
  answer(q[1]);
  return 0;
}
