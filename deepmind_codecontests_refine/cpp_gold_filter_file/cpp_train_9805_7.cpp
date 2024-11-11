#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  int connect[30][30];
  int a, b;
  memset(connect, 0, sizeof connect);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    connect[a][b] = 1;
    connect[b][a] = 1;
  }
  if (n <= 6)
    printf("%d\n", m);
  else {
    int ans = 999999;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        int sum = 0;
        for (int k = 1; k <= n; k++) {
          if (connect[i][k] && connect[j][k]) sum++;
        }
        ans = min(sum, ans);
      }
    }
    printf("%d\n", m - ans);
  }
  return 0;
}
