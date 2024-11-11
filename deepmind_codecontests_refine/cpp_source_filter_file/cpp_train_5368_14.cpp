#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, a, R = 1000000007;
  cin >> n >> m >> k;
  int u[m], v[m], l[m];
  bool vis[n];
  for (int i = 0; i < m; i++) cin >> u[i] >> v[i] >> l[i];
  for (int i = 0; i < n; i++) vis[i] = 0;
  for (int i = 0; i < k; i++) {
    cin >> a;
    vis[a] = 1;
  }
  for (int i = 0; i < m; i++)
    if (vis[u[i]] && !vis[v[i]] || !vis[u[i]] && vis[v[i]]) R = min(R, l[i]);
  if (R == 1000000007)
    cout << "-1" << endl;
  else
    cout << R << endl;
  return 0;
}
