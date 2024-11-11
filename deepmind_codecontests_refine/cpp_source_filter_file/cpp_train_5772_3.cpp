#include <bits/stdc++.h>
using namespace std;
int a[200005][15], p[200005], q[200005][15], result[200005];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    p[y]++;
    q[x][y]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        result[i] += (p[j] - q[i][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << result[i] << endl;
  }
  return 0;
}
