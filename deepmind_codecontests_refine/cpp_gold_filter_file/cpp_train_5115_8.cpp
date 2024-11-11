#include <bits/stdc++.h>
using namespace std;
vector<long long int> g[200005];
long long int val[200005];
long long int ans = 0;
bool flag = true;
void dfs(long long int src, long long int par) {
  bool iseven = false;
  long long int k;
  if (par != -1) k = val[par];
  long long int mn = 1e10, cnt = 0, curr = 0;
  if (val[src] == -1) {
    iseven = true;
  }
  for (auto x : g[src]) {
    if (x == par) continue;
    dfs(x, src);
    if (iseven) {
      mn = min(mn, val[x]);
      curr += val[x];
      cnt++;
    }
  }
  if (iseven && cnt > 0) {
    if (mn < k) {
      flag = false;
      return;
    }
    ans += (curr - (cnt - 1) * (mn - k) - k * cnt);
  }
}
signed main() {
  long long int n;
  cin >> n;
  for (long long int i = 2; i <= n; i++) {
    long long int x;
    cin >> x;
    g[x].push_back(i);
    g[i].push_back(x);
  }
  for (long long int i = 1; i <= n; i++) cin >> val[i];
  dfs(1, -1);
  if (flag)
    cout << ans + val[1] << endl;
  else
    cout << -1 << endl;
}
