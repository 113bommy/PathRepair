#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = n;
    long int ans = 0, cb;
    while (1) {
      while (x % 10 != 0) x--;
      ans += x;
      cb = x / 10;
      x = n - x + cb;
      n = x;
      if (x < 10) break;
    }
    cout << ans + x << endl;
  }
  return 0;
}
