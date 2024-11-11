#include <bits/stdc++.h>
using namespace std;
char a[200010], b[200010];
int one[200010];
int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  while (cin >> (a + 1) >> (b + 1)) {
    int n = strlen(a + 1);
    int m = strlen(b + 1);
    for (int i = 1; i <= m; ++i) {
      one[i] = one[i - 1] + (b[i] == '1');
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      int x = one[m - (n - i)] - one[i - 1];
      if (a[i] == '1') {
        x = m - n + 1 - x;
      }
      ans += x;
    }
    cout << ans << '\n';
  }
  return 0;
}
