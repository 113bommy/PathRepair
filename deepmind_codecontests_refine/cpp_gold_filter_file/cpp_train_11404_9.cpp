#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, a[11][11] = {0}, c = 0;
  cin >> n >> t;
  **a = t * 1024;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (a[i][j] >= 1024) {
        c++;
        a[i + 1][j] += a[i][j] - 1024 >> 1;
        a[i + 1][j + 1] += a[i][j] - 1024 >> 1;
      }
    }
  }
  cout << c << endl;
}
