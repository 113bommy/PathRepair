#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, flag = 0;
  cin >> n >> m;
  char s[n][m];
  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      for (j = 0; j < m; j++) {
        cout << "#";
      }
    } else if (flag == 0) {
      for (j = 0; j < m - 1; j++) {
        cout << ".";
      }
      cout << "#";
      flag = 1;
    } else {
      cout << "#";
      for (j = 1; j < m - 1; j++) {
        cout << ".";
      }
      flag = 0;
    }
    cout << endl;
  }
  return 0;
}
