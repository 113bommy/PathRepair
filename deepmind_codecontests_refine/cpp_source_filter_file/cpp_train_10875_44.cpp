#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > arr(n + 1, vector<int>(m + 1));
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= m; i++) {
      cin >> arr[k][i];
      arr[k][i] += arr[k][i - 1];
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int k = 1; k <= n; k++) {
      arr[k][i] += arr[k - 1][i];
    }
  }
  int a, b;
  cin >> a >> b;
  int res = 1e9;
  for (int k = a; k <= n; k++) {
    for (int i = b; i <= m; i++) {
      res = min(res,
                arr[k][i] - arr[k][i - b] - arr[k - a][i] + arr[k - a][i - b]);
    }
  }
  for (int k = b; k <= n; k++) {
    for (int i = a; i <= n; i++) {
      res = min(res,
                arr[k][i] - arr[k][i - a] - arr[k - b][i] + arr[k - b][i - a]);
    }
  }
  cout << res << '\n';
  return 0;
}
