#include <bits/stdc++.h>
using namespace std;
int main() {
  int u, ans, v, sum, a[110], b[110][110], n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  ans = -1;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    b[u - 1][v - 1] = 1;
    b[v - 1][u - 1] = 1;
  }
  for (int i = 0; i < n - 2; i++)
    for (int j = i + 1; j < n - 1; j++)
      for (int k = j + 1; k < n; k++)
        if (b[i][j] * b[i][k] * b[k][j] == 1) {
          sum = a[i] + a[j] + a[k];
          if (sum < ans || ans == -1) ans = sum;
        }
  cout << ans;
}
