#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    long long ans = 0;
    for (int i = 0; i <= 8 && i <= n; i++) {
      for (int j = 0; j <= (i == 0 ? 8 : 4) && i + j <= n; j++) {
        ans += n + 1 - i - j;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
