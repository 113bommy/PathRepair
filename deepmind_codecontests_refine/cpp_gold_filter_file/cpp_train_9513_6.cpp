#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m;
  cin >> n >> m;
  if (m == 3 && n > 4) {
    cout << -1 << endl;
    return 0;
  }
  double ang = 2 * 3.1415926 / m;
  double R1 = 10000000;
  double R2 = 100000;
  for (int i = 0; i < m; i++)
    cout << int(cos(ang * i) * R1) << ' ' << int(sin(ang * i) * R1) << endl;
  for (int i = 1; i <= n - m; i++)
    cout << int(cos(ang * i - 2 * 3.1415926 / 180) * R2) << ' '
         << int(sin(ang * i - 2 * 3.1415926 / 180) * R2) << endl;
}
