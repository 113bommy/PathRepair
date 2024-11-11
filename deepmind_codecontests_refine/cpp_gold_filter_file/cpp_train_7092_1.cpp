#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n;
long long ans;
int a[N];
bool vis[N];
vector<pair<int, bool>> tree[N];
int dfs(int u) {
  vis[u] = 1;
  int cnt = 1;
  for (auto x : tree[u]) {
    int v = x.first;
    bool q = x.second;
    if (vis[v]) continue;
    if (q) continue;
    cnt += dfs(v);
  }
  return cnt;
}
bool isLucky(int x) {
  while (x) {
    int rem = x % 10;
    x /= 10;
    if (rem != 4 && rem != 7) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    bool q = isLucky(z);
    tree[x].push_back({y, q});
    tree[y].push_back({x, q});
  }
  ans = n * (n - 1) * (n - 2);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      long long num = dfs(i);
      long long res = (num - 1) * num * (n - num) * 2;
      ans -= res;
      res = num * (num - 1) * (num - 2);
      ans -= res;
    }
  cout << ans;
}
