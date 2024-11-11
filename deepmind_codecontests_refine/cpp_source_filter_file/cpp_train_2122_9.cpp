#include <bits/stdc++.h>
using namespace std;
int dsu[110];
int find_set(int v) {
  if (v == 0) return 0;
  return v == dsu[v] ? v : dsu[v] = find_set(dsu[v]);
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> a[110];
  memset(dsu, 0, sizeof(dsu));
  for (int i = 1; i <= n; ++i) dsu[i] = i;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    sum += k;
    int q[110];
    for (int j = 0; j < k; ++j) {
      cin >> q[j];
      a[q[j]].push_back(i + 1);
    }
  }
  if (sum == 0) {
    cout << n << endl;
    return 0;
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 0; i < (int)a[k].size(); ++i)
      for (int j = i + 1; j < (int)a[k].size(); ++j) {
        int v = a[k][i], u = a[k][j];
        int V = find_set(v), U = find_set(u);
        if (V != U) dsu[V] = U;
      }
  set<int> ans;
  for (int i = 1; i <= n; ++i)
    if (ans.find(find_set(i)) == ans.end()) ans.insert(find_set(i));
  cout << ans.size() - 1 << endl;
  return 0;
}
