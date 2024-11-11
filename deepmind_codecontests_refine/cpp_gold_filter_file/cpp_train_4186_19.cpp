#include <bits/stdc++.h>
using namespace std;
char s[1005];
int main() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    scanf("%s", s);
    int l = 1e9, r = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        l = min(l, i);
        r = max(r, i);
      }
    }
    int ans = n;
    if (l <= r) {
      ans = max(ans, (n - l) * 2);
      ans = max(ans, (r + 1) * 2);
    }
    cout << ans << "\n";
  }
  return 0;
}
