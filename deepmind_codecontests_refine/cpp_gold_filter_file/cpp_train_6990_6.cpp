#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, i, j, a[502][502], buc[502][12][2] = {0};
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
      int k = 0;
      int temp = a[i][j];
      while (k < 12) {
        if (temp % 2) {
          buc[i][k][1]++;
        } else {
          buc[i][k][0]++;
        }
        temp /= 2;
        k++;
      }
    }
  }
  int flag = 0;
  bool zer = false;
  for (i = 0; i < 12; i++) {
    int one = 0;
    int one_zero = 0;
    int zero = 0;
    for (j = 0; j < n; j++) {
      if (buc[j][i][1] && !buc[j][i][0]) {
        one++;
      } else if (buc[j][i][1] && buc[j][i][0]) {
        one_zero++;
      } else if (buc[j][i][0]) {
        zero++;
      }
    }
    if (one % 2 || one_zero) {
      cout << "TAK" << endl;
      flag = 1;
      if (one % 2 == 0) {
        zer = false;
      } else {
        zer = true;
      }
      break;
    }
  }
  if (!flag) {
    cout << "NIE" << endl;
    return 0;
  }
  int k = i;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      int temp = a[i][j];
      int c = 0;
      while (c < k) {
        temp /= 2;
        c++;
      }
      if (buc[i][k][1] && !buc[i][k][0] && temp % 2) {
        cout << j + 1 << " ";
        break;
      } else if (buc[i][k][1] && buc[i][k][0] && !zer && temp % 2) {
        cout << j + 1 << " ";
        zer = true;
        break;
      } else if (buc[i][k][1] && buc[i][k][0] && temp % 2 == 0 && zer) {
        cout << j + 1 << " ";
        break;
      } else if (!buc[i][k][1] && buc[i][k][0] && temp % 2 == 0) {
        cout << j + 1 << " ";
        break;
      }
    }
  }
  cout << endl;
  return 0;
}
