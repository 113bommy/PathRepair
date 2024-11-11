#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    if (i % 4 == 2) {
      for (j = 1; j < m; j++) {
        cout << ".";
      }
      cout << "#" << endl;
    } else if (i % 4 == 0) {
      cout << "#";
      for (j = 1; j < m; j++) {
        cout << ".";
      }
      cout << endl;
    } else {
      for (j = 1; j <= m; j++) {
        cout << "#";
      }
      cout << endl;
    }
  }
  return 0;
}
