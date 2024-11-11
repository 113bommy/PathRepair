#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m;
  cin >> n >> m;
  int a[n][4];
  memset(a, 0, sizeof(a));
  int i, j, p = 1, k = 1;
  int count = 0;
  for (i = n - 1, j = 1; i >= 0 && j <= m / 2; i--, j = j + 2) {
    a[i][0] = j;
    if (p == 1 && j + 2 * n <= m) {
      a[i][1] = j + 2 * n;
    } else
      p = 0;
    a[i][3] = j + 1;
    if (k == 1 && j + 1 + 2 * n <= m) {
      a[i][2] = j + 1 + 2 * n;
    } else
      p = 0;
  }
  for (i = n - 1; i >= 0; i--) {
    if (a[i][1] != 0) {
      cout << a[i][1] << " ";
      count++;
    }
    if (a[i][0] != 0) {
      count++;
      if (count == m) {
        cout << a[i][0] << endl;
        break;
      }
      cout << a[i][0];
    }
    if (a[i][2] != 0) {
      cout << " " << a[i][2];
      count++;
    }
    if (a[i][3] != 0) {
      count++;
      if (count == m) {
        cout << " " << a[i][3] << endl;
        break;
      }
      cout << " " << a[i][3] << " ";
    }
  }
  return 0;
}
