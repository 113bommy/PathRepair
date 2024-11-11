#include <bits/stdc++.h>
const long long md = 1000000007;
using namespace std;
vector<int> v[10005];
int c[10005];
bool vis[10005];
int ans = 0;
void dfs(int s, int p) {
  vis[s] = true;
  if (p != c[s]) ans++;
  for (int i = 0; i < v[s].size(); ++i) {
    if (vis[v[s][i]] == false) dfs(v[s][i], c[s]);
  }
}
int main() {
  int n, x;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x;
    v[i].push_back(x);
    v[x].push_back(i);
  }
  for (int i = 0; i < n; i++) cin >> c[i + 1];
  dfs(1, 0);
  cout << ans + 1;
  return 0;
}
