#include <bits/stdc++.h>
using namespace std;
const int oo = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int MAXN = 1e5 + 10;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool lucky(int a) {
  while (a > 0)
    if (a % 10 != 4 && a % 10 != 7)
      return 0;
    else
      a /= 10;
  return 1;
}
int id;
int vis[100002];
vector<int> adj[100002];
void dfs(int node) {
  vis[node] = id;
  for (auto i : adj[node])
    if (vis[i] == 0) dfs(i);
}
int cnt[100002];
int main() {
  std::ios_base::sync_with_stdio(false);
  int n, a, b, c;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    a--, b--;
    if (lucky(c) == 0) adj[a].push_back(b), adj[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    if (vis[i] == 0) id++, dfs(i);
  }
  for (int i = 0; i < n; i++) cnt[vis[i]]++;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long rem = n - cnt[vis[i]];
    ans += rem * (rem - 1);
  }
  cout << ans << endl;
}
