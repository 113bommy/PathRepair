#include <bits/stdc++.h>
using namespace std;
int q;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> q;
  while (q--) {
    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;
    string tmp_s = s, tmp_t = t;
    sort(tmp_s.begin(), tmp_s.end());
    sort(tmp_t.begin(), tmp_t.end());
    if (tmp_s != tmp_t) {
      cout << "-1\n";
      continue;
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
      int j = 0;
      int k;
      for (k = i; k < n; ++k) {
        while (j < n && s[j] != t[k]) ++j;
        if (j == n) break;
      }
      ans = min(ans, n - (k - i));
    }
    cout << ans << '\n';
  }
}
