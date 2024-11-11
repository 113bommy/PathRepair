#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (n > m) {
      puts("0");
      continue;
    }
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
      int x = (n >> i) & 1;
      int y = (m >> i) & 1;
      if (x > y) break;
      if (x < y) ans |= (1 << i);
    }
    cout << ans << endl;
  }
}
