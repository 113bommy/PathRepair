#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[100005], b[100005];
int f[100005];
int res;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
  }
  for (int i = 1; i <= m; i++) {
    sort(a[i].begin(), a[i].end(), greater<int>());
    int tg = 0;
    for (int j = 0; j < a[i].size(); j++) {
      int u = a[i][j];
      tg += u;
      if (tg >= 0) {
        f[j + 1] += tg;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    res = max(res, f[i]);
  }
  cout << res;
}
