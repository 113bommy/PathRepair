#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int x, c = 0, ans;
    cin >> x;
    int f = x % 10;
    while (x != 0) {
      x = x / 10;
      c++;
    }
    ans = (f - 1) * 10 + (c * (c + 1) / 2);
    cout << ans << endl;
  }
}
