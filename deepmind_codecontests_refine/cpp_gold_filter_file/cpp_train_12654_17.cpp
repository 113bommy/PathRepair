#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, n, temp1 = 0, temp2 = 0, x = 0, y = 0, cnt = 0, bal = 0,
                        kochu = 1, tired1 = 0, tired2 = 0, logic = 0;
  cin >> n;
  long long a[n][n];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
      cnt = cnt + a[i][j];
      if (a[i][j] == 0) {
        bal = 1;
        x = i;
        y = j;
      }
    }
    if (bal == 0) temp1 = cnt;
    if (logic == temp1 && bal == 0) kochu++;
    if (bal == 1) {
      temp2 = cnt;
      bal = 0;
    }
    logic = temp1;
    cnt = 0;
  }
  cnt = 0;
  a[x][y] = temp1 - temp2;
  if (temp2 + a[x][y] == logic) kochu++;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cnt = cnt + a[j][i];
      if (i == j) tired1 += a[i][j];
      if (i + j == n - 1) tired2 += a[j][i];
    }
    if (cnt == temp1) kochu++;
    cnt = 0;
  }
  if (tired1 == logic && tired2 == logic) kochu += 2;
  if (n == 1) {
    if (a[0][0] > 0)
      cout << a[0][0] << endl;
    else {
      cout << 1 << endl;
    }
  } else if (n * 2 + 2 == kochu && a[x][y] > 0)
    cout << a[x][y] << endl;
  else
    cout << -1 << endl;
}
