#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    long long ans = 0;
    for (int i = 1, j; i <= n; i++) {
      int sum = i;
      for (j = 1; j <= m; j++) {
        if ((sum + j) % 5 == 0) {
          ans += 1;
          break;
        }
      }
      ans += (m - j) / 5;
    }
    cout << ans << endl;
  }
}
