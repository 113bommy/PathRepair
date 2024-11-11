#include <bits/stdc++.h>
using namespace std;
const int inf = 25;
int a[inf][inf]{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int main() {
  int n, m, i, j, k;
  a[1][0] = 0;
  for (i = 0; i <= 5; i++) {
    for (j = 0; j <= 5; j++) {
      a[i + 1][j + 1] = a[i][j + 1] + a[i + 1][j];
    }
  }
  while (cin >> k) {
    cout << a[k - 1][k] << endl;
  }
  return 0;
}
