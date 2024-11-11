#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r;
  cin >> l >> r;
  int k = 0;
  for (int i = l; i <= r; i++) {
    int x = i;
    bool b[10];
    for (int g = 0; g < 10; g++) b[g] = 0;
    int ans = 0, g = 0;
    while (x > 0) {
      if (b[x % 10] == 0) {
        b[x % 10] = 1;
        ans += (x % 10) * pow(10, g);
        g++;
      }
      x /= 10;
    }
    if (ans >= l && ans <= r) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
}
