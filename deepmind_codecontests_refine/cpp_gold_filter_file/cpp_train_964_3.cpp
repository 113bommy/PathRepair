#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cntl = 0;
    for (int i = 0; i < n; i++) {
      cntl += (s[i] == 'L');
    }
    if (k >= cntl) {
      cout << 2 * n - 1 << "\n";
      continue;
    }
    if (cntl == n) {
      cout << max(2 * k - 1, 0) << "\n";
      continue;
    }
    int basic = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W') {
        basic++;
        if (i > 0 && s[i - 1] == 'W') basic++;
      }
    }
    int cnt = -1;
    vector<int> segs;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W') {
        if (cnt > 0) segs.push_back(cnt);
        cnt = 0;
      } else {
        if (cnt != -1) cnt++;
      }
    }
    sort(segs.begin(), segs.end());
    for (int l : segs) {
      if (k >= l) {
        basic += 2 * l + 1;
        k -= l;
      }
    }
    basic += 2 * k;
    cout << basic << "\n";
  }
  return 0;
}
