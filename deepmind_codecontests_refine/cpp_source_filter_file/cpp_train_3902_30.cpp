#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n;
  cin >> m >> n;
  char a[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i % 2 == 0)
        a[i][j] = '#';
      else
        a[i][j] = '.';
    }
  }
  bool last = true;
  for (int i = 1; i < m; i += 2) {
    if (last)
      a[i][n - 1] = '#';
    else
      a[i][0] = '#';
    last = !last;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}
