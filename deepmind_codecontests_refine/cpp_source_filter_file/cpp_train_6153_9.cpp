#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, d = 0, m = 0;
  int MasX[100] = {};
  int MasY[100] = {};
  cin >> n >> d >> m;
  for (int i = 0; i < m; i++) {
    cin >> MasX[i] >> MasY[i];
  }
  for (int i = 0; i < m; i++) {
    int x = 0, y = 0;
    x = MasX[i];
    y = MasY[i];
    int modul = (x > y ? x - y : y - x);
    if (modul > d)
      cout << "NO" << endl;
    else if ((x + y) < 2 || (x + y) > 2 * n - d)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
