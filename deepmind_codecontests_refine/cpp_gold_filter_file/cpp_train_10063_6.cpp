#include <bits/stdc++.h>
using namespace std;
int dfs(int n) {}
int main() {
  int n, k, x, y, a[200200], b[200200];
  cin >> n >> k;
  vector<vector<int> > v(n, vector<int>());
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    v[x - 1].push_back(y - 1);
    v[y - 1].push_back(x - 1);
  }
  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    int x = i, res = lower_bound(b, b + n, a[i]) - b;
    for (int j = 0; j < v[i].size(); j++)
      if (a[v[i][j]] < a[i]) res--;
    cout << res << " ";
  }
  return 0;
}
