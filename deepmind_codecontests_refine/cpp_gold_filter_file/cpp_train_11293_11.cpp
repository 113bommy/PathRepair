#include <bits/stdc++.h>
using namespace std;
char a[105][105];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k <= 2; k++) {
      for (int j = 1; j <= m; j++) {
        cout << a[j][i] << a[j][i];
      }
      cout << endl;
    }
  }
  return 0;
}
