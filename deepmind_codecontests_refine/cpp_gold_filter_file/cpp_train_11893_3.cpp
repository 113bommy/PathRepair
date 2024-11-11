#include <bits/stdc++.h>
using namespace std;
int a[3][3];
signed main() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  cout.tie(0);
  ;
  int k;
  cin >> k;
  a[0][0] = 262143;
  a[0][1] = 262143;
  a[1][0] = 262143;
  a[0][2] = 131072;
  a[1][2] = 131072;
  a[2][1] = 131072;
  a[2][0] = 131072;
  for (int i = 1; i < 3; i++) a[i][2] += k;
  a[2][1] += k;
  a[1][1] += k;
  cout << "3 3\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) cout << a[i][j] << " ";
    cout << '\n';
  }
  return 0;
}
