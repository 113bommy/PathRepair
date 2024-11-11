#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, count = 1;
  cin >> n >> m >> i >> j;
  bool a[n + 1][m + 1];
  memset(a, true, sizeof(a));
  for (; i > 0; i--) {
    cout << i << " " << j << "\n";
    a[i][j] = false;
  }
  i = 1;
  for (j -= 1; j > 0; j--) {
    cout << i << " " << j << "\n";
    a[i][j] = false;
  }
  while (count <= n) {
    if (count % 2) {
      for (int i = 1; i <= m; i++) {
        if (a[count][i]) cout << count << " " << i << "\n";
      }
      count++;
    } else {
      for (int i = m; i > 0; i--) {
        if (a[count][i]) cout << count << " " << i << "\n";
      }
      count++;
    }
  }
}
