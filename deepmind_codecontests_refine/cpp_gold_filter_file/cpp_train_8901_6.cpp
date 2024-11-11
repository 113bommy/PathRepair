#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[10];
  a[0] = 6;
  a[1] = 2;
  a[2] = 5;
  a[3] = 5;
  a[4] = 4;
  a[5] = 5;
  a[6] = 6;
  a[7] = 3;
  a[8] = 7;
  a[9] = 6;
  int k, c, x;
  cin >> k >> c;
  long long ans = 0;
  for (int i = k; i <= c; i++) {
    x = i;
    while (x > 0) {
      ans += a[x % 10];
      x = x / 10;
    }
  }
  cout << ans;
  return 0;
}
