#include <bits/stdc++.h>
using namespace std;
int arr[105][105];
pair<int, int> p[10005];
int main() {
  int n, m, ans = INT_MAX, sum = 0, a[105], i, j, k;
  int found = 0;
  cin >> n;
  cin >> m;
  for (i = 1; i <= n; ++i) cin >> a[i];
  for (i = 0; i < m; ++i) {
    cin >> p[i].first;
    cin >> p[i].second;
    arr[p[i].first][p[i].second] = 1;
    arr[p[i].second][p[i].first] = 1;
  }
  for (i = 1; i <= n; ++i) {
    for (j = i + 1; j <= n; ++j) {
      for (k = j + 1; k <= n; ++k) {
        if ((arr[i][j] == 1) && arr[i][k] == 1 && arr[k][j] == 1) {
          sum = a[i] + a[j] + a[k];
          found = 1;
          ans = min(sum, ans);
        }
      }
    }
  }
  if (found == 0) ans = -1;
  cout << ans;
}
