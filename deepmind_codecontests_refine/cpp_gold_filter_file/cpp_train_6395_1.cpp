#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, p;
  cin >> t;
  while (t > 0) {
    cin >> n >> p;
    int e[30][30];
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) e[i][j] = 0;
    for (int i = 1; i <= n; ++i) {
      e[i][(i % n) + 1] = 1;
      e[(i % n) + 1][i] = 1;
      e[i][(i + 1) % n + 1] = 1;
      e[(i + 1) % n + 1][i] = 1;
    }
    while (p > 0) {
      bool a = false;
      for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j)
          if ((e[i][j] == 0) && (e[j][i] == 0)) {
            e[i][j] = 1;
            e[j][i] = 1;
            a = true;
            break;
          }
        if (a) break;
      }
      p--;
    }
    for (int i = 1; i < n; ++i)
      for (int j = i + 1; j <= n; ++j)
        if (e[i][j] == 1) cout << i << " " << j << endl;
    t--;
  }
  return 0;
}
