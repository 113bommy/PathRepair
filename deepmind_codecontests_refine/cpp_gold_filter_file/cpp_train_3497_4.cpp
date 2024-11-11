#include <bits/stdc++.h>
using namespace std;
const int N = 300;
int h[N], ne[N], e[N], idx;
int g[N][N];
void add(int a, int b) {
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx++;
}
int smax;
int c[N], cnt;
bool vis[N];
void dfs(int u, int sum) {
  vis[u] = true;
  smax = max(sum, smax);
  for (int i = h[u]; i != -1; i = ne[i]) {
    int j = e[i];
    if (!vis[j]) {
      vis[j] = true;
      dfs(j, sum + g[u][j]);
    }
  }
}
int main() {
  int n;
  cin >> n;
  memset(h, -1, sizeof h);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b);
    add(b, a);
    g[a][b] = c;
    g[b][a] = c;
  }
  dfs(0, 0);
  cout << smax << endl;
  return 0;
}
