#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int q, n;
  string s, t;
  cin >> q;
  while (q--) {
    int ans = 10000;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
      int k = i;
      for (int j = 0; j < n; j++) {
        if (k < n && s[j] == t[k]) k++;
      }
      ans = min(ans, n - k + i);
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s != t) ans = -1;
    cout << ans << '\n';
  }
  return 0;
}
