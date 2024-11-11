#include <bits/stdc++.h>
using namespace std;
int main() {
  char ara[105][105];
  int i, j, n, m;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> ara[i][j];
      if (ara[i][j] == 'C' || ara[i][j] == 'M' || ara[i][j] == 'y') {
        cout << "#Color" << endl;
        return 0;
      }
    }
  }
  cout << "#Black&White" << endl;
  return 0;
}
