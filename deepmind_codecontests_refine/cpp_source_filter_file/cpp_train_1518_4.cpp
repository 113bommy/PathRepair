#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
int n, t, k, a[MAXN], pai[MAXN], aux = 1, leaves;
vector<int> v[MAXN];
int main() {
  cin >> n >> t >> k;
  v[0].push_back(1);
  for (int i = 1; i <= t; i++) {
    cin >> a[i];
    for (int j = 1; j <= a[i]; j++) v[i].push_back(++aux);
    leaves += a[i] - (i != t);
  }
  for (int i = 1; i <= n; i++) pai[i] = 0;
  for (int i = t; i >= 1; i--) pai[v[i][0]] = v[i - 1][0];
  int nivat = t;
  while (leaves > k && t > 0) {
    for (int i = 1; i < (int)min(v[t - 1].size(), v[t].size()); i++) {
      if (leaves <= k) break;
      pai[v[t][i]] = v[t - 1][i];
      leaves--;
    }
    for (int i = v[t - 1].size(); i < (int)v[t].size(); i++) {
      if (leaves <= k) break;
      pai[v[t][i]] = v[t - 1][0];
    }
    t--;
  }
  t = nivat;
  if (leaves > k) cout << "-1", exit(0);
  for (int i = t; i >= 1; i--)
    for (auto u : v[i])
      if (pai[u] == 0) pai[u] = v[i - 1][0];
  cout << n << "\n";
  for (int i = 2; i <= n; i++) cout << i << " " << pai[i] << "\n";
}
