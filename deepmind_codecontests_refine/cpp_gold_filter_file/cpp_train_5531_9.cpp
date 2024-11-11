#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1);
  vector<int> b(n + 1);
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  if (n * (n - 1) / 2 == m)
    cout << "NO\n";
  else {
    for (int i = 1; i <= n; ++i)
      a[i].push_back(i), sort(a[i].begin(), a[i].end());
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i == j) continue;
        if ((int)a[i].size() == j) continue;
        if ((int)a[i].size() > j && a[i][j - 1] == j) continue;
        b[i] = 1;
        b[j] = 2;
        int now = 3;
        for (int j = 1; j <= n; ++j) {
          if (b[j]) continue;
          b[j] = now++;
        }
        for (int j = 1; j <= n; ++j) {
          cout << b[j] << " ";
        }
        cout << '\n';
        b[j] = 1;
        for (int j = 1; j <= n; ++j) {
          cout << b[j] << " ";
        }
        cout << "\n";
        return 0;
      }
    }
  }
  return 0;
}
