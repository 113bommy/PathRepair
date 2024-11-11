#include <bits/stdc++.h>
using namespace std;
int n;
bool vis[100100];
long long ans = 0;
vector<long long> g[100100], v;
bool lucky(int x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return false;
    x /= 10;
  }
  return true;
}
int dfs(int x) {
  if (vis[x]) return 0;
  vis[x] = true;
  int t = 1;
  for (auto i : g[x]) {
    t += dfs(i);
  }
  return t;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(vis, 0, sizeof(vis));
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (lucky(c)) continue;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int s = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      int t = dfs(i);
      v.push_back(t);
    }
  }
  for (auto i : v) {
    ans += i * (n - i) * (n - i - 1);
  }
  cout << ans;
}
