#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
int N;
int val[1510];
int fa[1510];
int f[1510][1510];
vector<int> vec[1510];
int g[1510];
int a[1510][1510];
void merge(int u, int v, int c) {
  u = fa[u];
  v = fa[v];
  if (u == v) return;
  if (c > val[u]) f[u][1] = 1;
  if (c > val[v]) f[v][1] = 1;
  int s1 = vec[u].size();
  int s2 = vec[v].size();
  memset(g, 0, sizeof(g));
  val[u] = max(val[u], val[v]);
  for (int i = 1; i <= s1; i++)
    for (int j = 1; j <= s2; j++) {
      g[i + j] = (g[i + j] + 1ll * f[u][i] * f[v][j] % Mod);
      val[u] = max(val[u], a[vec[u][i - 1]][vec[v][j - 1]]);
    }
  for (int i = 1; i <= s1 + s2; i++) f[u][i] = g[i];
  for (int i = 0; i < vec[v].size(); i++) {
    fa[vec[v][i]] = u;
    vec[u].push_back(vec[v][i]);
  }
  return;
}
struct Edge {
  int u, v, c;
} e[4000010];
bool cmp(Edge a, Edge b) { return a.c < b.c; }
int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int x;
      scanf("%d", &x);
      a[i][j] = x;
      if (i < j) {
        cnt++;
        e[cnt].u = i;
        e[cnt].v = j;
        e[cnt].c = x;
      }
    }
  sort(e + 1, e + cnt + 1, cmp);
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    val[i] = 0;
    vec[i].push_back(i);
  }
  for (int i = 1; i <= cnt; i++) merge(e[i].u, e[i].v, e[i].c);
  int o = fa[1];
  f[o][1] = 1;
  for (int i = 1; i <= n; i++) printf("%d ", f[o][i]);
  printf("\n");
  return 0;
}
