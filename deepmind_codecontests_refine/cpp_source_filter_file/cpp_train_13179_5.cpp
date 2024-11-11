#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cnt = 0;
      if (a[i][j] != 1) {
        for (int t = 1; t <= n; t++) {
          for (int k = 1; k <= n; k++) {
            if (a[i][t] + a[j][k] == a[i][j]) cnt++;
          }
        }
        if (cnt == 0) {
          cout << "No";
          return 0;
        }
      }
    }
  }
  cout << "Yes";
}
