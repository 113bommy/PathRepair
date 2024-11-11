#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int fs = 10001, ls = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        fs = min(fs, i);
        ls = i;
      }
    }
    if (ls == -1) {
      cout << n << "\n";
      continue;
    }
    int ans = max(ls + 1, n - fs);
    if (ls + 1 > n - fs) {
      ans += max(ls + 1, n - ls);
    } else {
      ans += max(fs + 1, n - fs);
    }
    cout << ans << "\n";
  }
  return 0;
}
