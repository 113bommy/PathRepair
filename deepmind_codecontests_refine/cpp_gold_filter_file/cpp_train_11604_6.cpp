#include <bits/stdc++.h>
int const mo = 1000000007;
int const maxn = 100007;
bool black[maxn];
int n;
long long f[maxn][2];
std::vector<std::vector<int> > tree;
void add_edge(int u, int v) {
  tree[u].push_back(v);
  tree[v].push_back(u);
}
void dp(int x, int father) {
  f[x][0] = 1;
  f[x][1] = 0;
  for (int i = 0; i < (int)tree[x].size(); i++) {
    int v = tree[x][i];
    if (father == v) continue;
    dp(v, x);
    f[x][1] = (f[x][1] * f[v][0]) % mo;
    f[x][1] = (f[x][1] + f[x][0] * f[v][1]) % mo;
    f[x][0] = (f[x][0] * f[v][0]) % mo;
  }
  if (black[x])
    f[x][1] = f[x][0];
  else
    f[x][0] = (f[x][0] + f[x][1]) % mo;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  tree.resize(n + 1);
  for (int i = 0, x; i < n - 1; i++) {
    std::cin >> x;
    add_edge(i + 2, x + 1);
  }
  for (int i = 1; i <= n; i++) std::cin >> black[i];
  dp(1, -1);
  std::cout << f[1][1] << "\n";
}
