#include <bits/stdc++.h>
using namespace std;
vector<int> g[300500], tin(300500), tout(300500), ans;
int timer = 1;
void dfs(int x) {
  tin[x] = timer++;
  ans.push_back(x);
  for (int i : g[x]) {
    if (!tin[i]) dfs(i);
  }
  tout[x] = timer++;
}
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(false);
  cout.precision(20);
  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    g[x].push_back(i);
  }
  dfs(1);
  vector<int> tins(n);
  for (int i = 1; i <= n; i++) tins[i - 1] = tin[i];
  sort(tins.begin(), tins.end());
  for (int i = 0; i < q; i++) {
    int u, k;
    cin >> u >> k;
    int x = lower_bound(tins.begin(), tins.end(), tin[u]) - tins.begin();
    k--;
    if (x + k < n && tout[u] >= tin[ans[x + k]])
      cout << ans[x + k] << endl;
    else
      cout << -1 << endl;
  }
}
