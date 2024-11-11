#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)(1e9) + 9;
const int SIZE = 2020;
int d, n;
int a[SIZE];
vector<int> path[SIZE];
long long f[SIZE];
bool vis[SIZE];
void dfs(int x, int root) {
  f[x] = 1;
  for (int i = 0; i < path[x].size(); i++) {
    int son = path[x][i];
    if (vis[son] || !(a[son] >= a[root] && a[son] <= a[root] + d) ||
        (a[son] == a[root] && x < root))
      continue;
    vis[son] = 1;
    dfs(son, root);
    f[x] = (f[x] * (f[son] + 1)) % MOD;
  }
}
int main() {
  int x, y;
  while (cin >> d >> n) {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      path[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
      cin >> x >> y;
      x--, y--;
      path[x].push_back(y);
      path[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        f[j] = 0;
        vis[j] = 0;
      }
      vis[i] = 1;
      dfs(i, i);
      ans = (ans + f[i]) % MOD;
    }
    cout << ans << endl;
  }
}
