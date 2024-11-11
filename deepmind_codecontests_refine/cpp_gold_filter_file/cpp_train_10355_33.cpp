#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[2][3];
  int c[3];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) cin >> a[i][j];
  for (int i = 0; i < 3; i++) cin >> c[i];
  int sol = -1;
  for (int i = 0; i <= 200; i++) {
    int tmp = (a[0][1] + i - a[1][2]);
    if (tmp <= 0) continue;
    int r = a[1][0] / tmp + (a[1][0] % tmp != 0);
    for (int j = 0; j <= 100; j++) {
      int k;
      tmp = (a[1][1] - (a[0][2] + j));
      k = tmp * r - a[0][0];
      if (k < 0)
        k = 0;
      else
        k++;
      if (sol == -1 || sol > k * c[0] + j * c[2] + i * c[1])
        sol = k * c[0] + j * c[2] + i * c[1];
    }
  }
  cout << sol << endl;
  return 0;
}
