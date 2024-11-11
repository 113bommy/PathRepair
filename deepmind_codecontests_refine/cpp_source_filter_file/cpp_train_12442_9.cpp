#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int ans[100];
int main() {
  int n, m, maxi = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (j == 0) {
        ans[i] = a[i][j];
      } else {
        if (a[i][j] <= ans[i]) {
          ans[i] = a[i][j];
        }
      }
    }
  }
  for (int x = 0; x < m; x++) {
    if (maxi <= ans[x]) {
      maxi = ans[x];
    }
  }
  cout << maxi;
  return 0;
}
