#include <bits/stdc++.h>
using namespace std;
int k;
int a[517][517];
int main() {
  cin >> k;
  a[1][1] = 1;
  for (int i = 1; i <= k; i++) {
    for (int x = (1 << (i - 1)) + 1; x <= (1 << i); x++)
      for (int y = 1; y <= (1 << (i - 1)); y++)
        a[x][y] = a[x - (1 << (i - 1))][y];
    for (int x = 1; x <= (1 << (i - 1)); x++)
      for (int y = (1 << (i - 1)) + 1; y <= (1 << i); y++)
        a[x][y] = a[x][y - (1 << (i - 1))];
    for (int x = (1 << (i - 1)) + 1; x <= (1 << i); x++)
      for (int y = (1 << (i - 1)) + 1; y <= (1 << i); y++)
        a[x][y] = -a[x - (1 << (i - 1))][y - (1 << (i - 1))];
  }
  for (int i = 1; i <= (1 << k); i++) {
    for (int j = 1; j <= (1 << k); j++)
      if (a[i][j] == 1)
        cout << '+';
      else
        cout << '-';
    cout << endl;
  }
}
