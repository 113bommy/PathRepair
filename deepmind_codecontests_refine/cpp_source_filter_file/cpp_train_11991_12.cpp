#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    string second, t;
    cin >> second >> t;
    int n = second.size();
    int m = t.size();
    int j = 0;
    vector<int> l, r;
    l.push_back(-1);
    for (int i = 0; i < n; i++) {
      if (second[i] == t[j]) {
        j++;
        l.push_back(i);
        if (j == m) break;
      }
    }
    j = m - 1;
    for (int i = n - 1; i >= 0; i--) {
      if (second[i] == t[j]) {
        j--;
        r.push_back(i);
        if (j == -1) break;
      }
    }
    reverse((r).begin(), (r).end());
    r.push_back(n);
    int ans = 0;
    for (int i = 0; i < m; i++) {
      ans = max(ans, r[i] - l[i] - 1);
    }
    cout << ans << endl;
  }
  return 0;
}
