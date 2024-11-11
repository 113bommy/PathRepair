#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, i, j, r;
  string a[105][105];
  cin >> x >> y;
  r = 0;
  for (i = 1; i <= x; i++)
    for (j = 1; j <= y; j++) {
      cin >> a[i][j];
      if (a[i][j] == "C" || a[i][j] == "M" || a[i][j] == "Y") r++;
    }
  if (r > 0)
    cout << "#Color";
  else
    cout << "#Black&White";
  return 0;
}
