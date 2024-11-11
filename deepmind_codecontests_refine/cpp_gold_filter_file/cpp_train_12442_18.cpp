#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, a[110][110];
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int res = 0, temp;
  for (i = 0; i < n; i++) {
    temp = INT_MAX;
    for (j = 0; j < m; j++) {
      temp = min(temp, a[i][j]);
    }
    res = max(res, temp);
  }
  printf("%d\n", res);
  return 0;
}
