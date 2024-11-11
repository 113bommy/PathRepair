#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6 + 5;
long long int maxlvl[N], deg[N];
vector<long long int> g[N];
long long int n, k, d, node;
void construct(long long int u, long long int lvl) {
  if (lvl <= 0) return;
  if (node >= n + 1) return;
  for (long long int i = deg[u] + 1; i <= k; i++) {
    if (node == n + 1) return;
    g[u].push_back(node);
    g[node].push_back(u);
    deg[node]++;
    long long int store = node;
    node++;
    construct(store, lvl - 1);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    cin >> n >> d >> k;
    if (d >= n) {
      cout << "NO" << endl;
      return 0;
    }
    for (long long int i = 1; i <= d; i++) {
      g[i].push_back(i + 1);
      g[i + 1].push_back(i);
      deg[i]++;
      deg[i + 1]++;
      maxlvl[i] = min(d - i + 1, i - 1);
    }
    node = d + 2;
    for (long long int i = 2; i <= d; i++) construct(i, maxlvl[i]);
    if (node < n + 1 || node > n + 1) {
      cout << "NO" << endl;
      return 0;
    }
    for (long long int i = 1; i <= n; i++) {
      if (deg[i] > k) {
        cout << "NO" << endl;
        return 0;
      }
    }
    cout << "YES" << endl;
    for (long long int i = 1; i <= n; i++) {
      for (auto itr : g[i]) {
        if (itr > i) cout << i << " " << itr << endl;
      }
    }
  }
  return 0;
}
