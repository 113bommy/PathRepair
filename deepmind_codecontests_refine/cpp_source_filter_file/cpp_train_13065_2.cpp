#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[105][105];
int main() {
  cin >> n >> m;
  m = 2 * m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j += 2) {
      if (a[i][j] + a[i][j + 1]) {
        k++;
      }
    }
  }
  cout << k;
  return 0;
}
