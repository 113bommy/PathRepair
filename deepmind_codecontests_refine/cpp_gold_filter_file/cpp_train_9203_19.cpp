#include <bits/stdc++.h>
using namespace std;
int a[4][4];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < 4; i++) cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
  for (int i = 0; i < 4; i++) {
    int f = min(a[i][0], a[i][1]);
    int s = min(a[i][2], a[i][3]);
    if ((f + s) <= n) {
      cout << i + 1 << " ";
      cout << f << " ";
      cout << n - f << " ";
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
