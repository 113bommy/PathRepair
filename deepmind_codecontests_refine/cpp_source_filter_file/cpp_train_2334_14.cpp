#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[4][4], ma = -1, y, r = 0;
  char k;
  bool f = true;
  cin >> n;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      cin >> k;
      ma = max(ma, k - 48);
      if (k != '.')
        a[i][j] = k - 48;
      else
        a[i][j] = 0;
    }
  for (int u = 1; u <= ma; u++) {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        if (a[i][j] == u) r++;
    if (r > n * 2) f = false;
    r = 0;
  }
  if (f)
    cout << "Yes";
  else
    cout << "No";
}
