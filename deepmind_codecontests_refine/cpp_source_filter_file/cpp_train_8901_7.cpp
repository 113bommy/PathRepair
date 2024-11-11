#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
  a[0] = 6;
  a[1] = 2;
  a[2] = 5;
  a[3] = 5;
  a[4] = 4;
  a[5] = 5;
  a[6] = 6;
  a[7] = 3;
  a[8] = 8;
  a[9] = 7;
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int i = n; i <= m; i++) {
    int t = i;
    while (t != 0) {
      ans += a[t % 10];
      t /= 10;
    }
  }
  cout << ans;
  return 0;
}
