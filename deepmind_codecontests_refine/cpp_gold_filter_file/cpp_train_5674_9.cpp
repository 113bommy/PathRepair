#include <bits/stdc++.h>
using namespace std;
int g[105][105];
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) cin >> g[i][j];
  for (int i = 1; i <= m; i++) {
    int maxid = 1;
    for (int j = 2; j <= n; j++) {
      if (g[i][maxid] < g[i][j]) maxid = j;
    }
    g[i][0] = maxid;
  }
  vector<int> v(n + 1, 0);
  for (int i = 1; i <= n; i++) v[g[i][0]]++;
  int maxid = 1;
  for (int i = 2; i <= n; i++) {
    if (v[maxid] < v[i]) maxid = i;
  }
  cout << maxid;
  return 0;
}
