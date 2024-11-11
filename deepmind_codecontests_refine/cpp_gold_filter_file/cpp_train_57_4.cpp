#include <bits/stdc++.h>
using namespace std;
string a[1001][2], b[1001][2];
int main() {
  cin >> a[0][0] >> a[0][1];
  b[0][0] = a[0][0];
  b[0][1] = a[0][1];
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1];
    if (a[i][0] == b[i - 1][0]) {
      b[i][0] = a[i][1];
      b[i][1] = b[i - 1][1];
    } else {
      b[i][0] = b[i - 1][0];
      b[i][1] = a[i][1];
    }
  }
  for (int i = 0; i <= n; i++) cout << b[i][0] << " " << b[i][1] << endl;
  return 0;
}
