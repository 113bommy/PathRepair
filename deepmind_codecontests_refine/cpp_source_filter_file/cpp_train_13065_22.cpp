#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, i, j;
  while (cin >> n >> m) {
    int flag = 0, cnt = 0;
    for (i = 1; i <= 2 * m * n; i++) {
      cin >> j;
      if (flag == 0 && j == 1) {
        cnt++;
        flag = 1;
      }
      if (i % m == 0) flag = 0;
    }
    cout << cnt << endl;
  }
}
