#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (a * n != b * m) {
      cout << "NO" << endl;
      continue;
    }
    int ar[n][m];
    int x = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (j < a)
          ar[i][(x + j) % m] = 1;
        else
          ar[i][(x + j) % m] = 0;
      }
      x = x + a;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << ar[i][j] << " ";
      }
      cout << endl;
    }
  }
}
