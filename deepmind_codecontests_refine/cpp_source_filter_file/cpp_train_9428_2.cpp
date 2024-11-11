#include <bits/stdc++.h>
using namespace std;
const int mxn = 200010;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int col[mxn];
bool vis[mxn];
vector<int> ve[mxn];
int a[mxn], b[mxn];
void DFS(int u, int d) {
  vis[u] = 1;
  col[u] = d + 1;
  for (int i = 0; i < ve[u].size(); i++) {
    int v = ve[u][i];
    if (!vis[v]) DFS(v, d ^ 1);
  }
  return;
}
int n;
int main() {
  int i, j, u, v;
  n = read();
  for (i = 1; i <= n; i++) {
    u = read();
    v = read();
    a[i] = u;
    b[i] = v;
    ve[u].push_back(v);
    ve[v].push_back(u);
  }
  for (i = 1; i <= n; i++) {
    ve[2 * i].push_back(2 * i - 1);
    ve[2 * i - 1].push_back(2 * i);
  }
  for (i = 1; i <= n; i++)
    if (!vis[i]) DFS(i, 0);
  for (i = 1; i <= n; i++) printf("%d %d\n", col[a[i]], col[b[i]]);
  return 0;
}
