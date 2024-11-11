#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, cnt = 0, f = 0;
  cin >> n;
  char a[n][n];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'C') cnt++;
    }
    cnt = cnt * (cnt - 1) / 2;
    f += cnt;
    cnt = 0;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[j][i] == 'C') cnt++;
    }
    cnt = cnt * (cnt - 1) / 2;
    f += cnt;
    cnt = 0;
  }
  cout << f << endl;
  return 0;
}
