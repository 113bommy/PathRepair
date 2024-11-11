#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int to[N];
vector<int> v;
bool vis[N];
void dfs(int u, int dep) {
  if (vis[u]) {
    v.push_back(dep);
    return;
  }
  vis[u] = 1;
  dfs(to[u], dep + 1);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", to + i);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i, 0);
  }
  sort(v.begin(), v.end());
  int sz = v.size();
  long long ans = 0;
  if (sz == 1)
    ans = 1LL * v[0] * v[0];
  else {
    long long x = v[sz - 1];
    long long y = v[sz - 2];
    ans += (x + y) * (x + y);
    for (int i = 0; i < sz - 2; i++) ans += 1LL * v[i];
  }
  cout << ans << endl;
  return 0;
}
