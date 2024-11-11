#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], depth[N];
long long Up[N], Down[N], Total_down[N], sum, sumDown[N];
vector<int> adj[N];
void input() {
  scanf("%d", &n);
  for (int i = (1), _b = (n); i <= _b; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  for (int nhi = 0, _n = (n - 1); nhi < _n; nhi++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}
void dfs1(int u, int par) {
  if (par != -1) depth[u] = depth[par] + 1;
  for (int v : adj[u]) {
    if (v == par) continue;
    dfs1(v, u);
    Down[u] += Down[v] + Total_down[v];
    Total_down[u] += Total_down[v];
    sumDown[u] += Down[v];
  }
  Total_down[u] += a[u];
}
void dfs2(int u, int par) {
  if (par != -1) {
    int tmp = sum - Total_down[par] + a[par];
    Up[u] += Up[par] + tmp;
    Up[u] += (sumDown[par] - Down[u]) + 2 * (sum - Total_down[u] - tmp);
  }
  for (int v : adj[u]) {
    if (v == par) continue;
    dfs2(v, u);
  }
}
void solve() {
  dfs1(1, -1);
  dfs2(1, -1);
  long long res = 0;
  for (int i = (1), _b = (n); i <= _b; i++) res = max(res, Up[i] + Down[i]);
  printf("%I64d\n", res);
}
int main(int argc, char const *argv[]) {
  input();
  solve();
  return 0;
}
