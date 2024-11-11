#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d = 1, a[150][150], r = 1, c = 1, h = 1, i, j;
  cin >> n;
  while ((d * (d - 1)) / 2 <= n) {
    d++;
  }
  d--;
  cout << d << endl;
  for (i = 1; i <= d; i++)
    for (j = i; j <= d - 1; j++) {
      a[i][j] = h;
      h++;
    }
  h = 1;
  for (j = 1; j <= d - 1; j++)
    for (i = j + 1; i <= d; i++) {
      a[i][j] = h;
      h++;
    }
  for (i = 1; i <= d; i++) {
    for (j = 1; j < d - 1; j++) {
      cout << a[i][j] << " ";
    }
    cout << a[i][d - 1] << endl;
  }
  return 0;
}
