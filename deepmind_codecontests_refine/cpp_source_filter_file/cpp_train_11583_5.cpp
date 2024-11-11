#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        cnt++;
      else {
        ans += (cnt - k) / k + 1;
        cnt = 0;
      }
    }
    ans += cnt / (k + 1);
    cout << ans << endl;
  }
  return 0;
}
