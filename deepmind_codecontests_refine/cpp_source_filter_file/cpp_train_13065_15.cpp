#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int main() {
  int n, m;
  cin >> n >> m;
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * m; j += 2) {
      if (a[i][j] == 1 || a[i][j + 1] == 1) {
        res++;
      }
    }
  }
  cout << res;
  return 0;
}
