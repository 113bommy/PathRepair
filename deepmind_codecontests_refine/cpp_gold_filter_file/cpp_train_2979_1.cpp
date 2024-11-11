#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
vector<int> g[maxn];
int a[maxn], egg[maxn];
int n;
map<int, bool> vis[maxn][2];
void checkmax(int &a, int b) {
  if (a < b) a = b;
}
int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
void dfs(int u, int f, bool flag, int mxgcd) {
  if (vis[u][flag][mxgcd]) return;
  vis[u][flag][mxgcd] = 1;
  int tmp = gcd(mxgcd, a[u]);
  checkmax(egg[u], tmp);
  if (!flag) checkmax(egg[u], mxgcd);
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == f) continue;
    dfs(v, u, flag, tmp);
    if (!flag) dfs(v, u, 1, mxgcd);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0, 0, 0);
  for (int i = 1; i <= n; i++) cout << egg[i] << ' ';
  return 0;
}
