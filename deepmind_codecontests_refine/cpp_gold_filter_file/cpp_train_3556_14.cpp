#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  int i, j;
  cin >> n >> m;
  vector<string> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  int pig_with_wolves = 0;
  int wolves = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'P')
        wolves++;
      else if (a[i][j] == 'W') {
        if ((i > 0 && a[i - 1][j] == 'P') || (j > 0 && a[i][j - 1] == 'P') ||
            (i < n - 1 && a[i + 1][j] == 'P') ||
            (j < m - 1 && a[i][j + 1] == 'P'))
          pig_with_wolves++;
      }
    }
  }
  cout << min(pig_with_wolves, wolves);
  return 0;
}
