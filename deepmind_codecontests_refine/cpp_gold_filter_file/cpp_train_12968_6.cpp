#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int main() {
  int n, m;
  while (cin >> n >> m) {
    int num = 0;
    char p[n][m];
    int a, b, c, d;
    a = c = inf;
    b = d = -inf;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> p[i][j];
        if (p[i][j] == 'X') {
          a = min(a, i);
          b = max(b, i);
          c = min(c, j);
          d = max(d, j);
          num++;
        }
      }
    }
    if ((b - a + 1) * (d - c + 1) == num)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
