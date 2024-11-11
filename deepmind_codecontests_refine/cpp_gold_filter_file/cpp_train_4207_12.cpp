#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n == 4) {
    cout << "-1\n";
    return 0;
  }
  if (n % 2) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i % 2) {
          if (j < i && j % 2)
            a[i][j] = 1;
          else if (j > i && !(j % 2))
            a[i][j] = 1;
        } else {
          if (j < i && !(j % 2))
            a[i][j] = 1;
          else if (j > i && (j % 2))
            a[i][j] = 1;
        }
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if (i != n)
        a[i][(i + 1)] = 1;
      else
        a[i][1] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if ((j - i) % 2 == 0 && j != i && a[j][i] == 0)
          a[i][j] = 1;
        else if ((j - i) % 2 != 0 && j != i && a[i][j] == 0)
          a[j][i] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
