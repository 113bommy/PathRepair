#include <bits/stdc++.h>
using namespace std;
int main() {
  int m;
  cin >> m;
  int c[m];
  for (int i = 0; i < m; i++) cin >> c[i];
  int x, y;
  cin >> x >> y;
  int tot = accumulate(c, c + m, 0);
  int par;
  for (int i = 0; i < m; i++) {
    par = accumulate(c, c + i, 0);
    if (x <= par && par <= y && x <= (tot - par) && (tot - par) <= y) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << "0" << endl;
  return 0;
}
