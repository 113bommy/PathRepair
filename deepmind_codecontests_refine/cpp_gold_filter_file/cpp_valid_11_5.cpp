#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> x, pair<int, int> y) {
  return abs(x.first - x.second) <= abs(y.first - y.second);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> cnt[5];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      string str;
      cin >> str;
      int ct[5];
      memset(ct, 0, sizeof(ct));
      for (auto it : str) ct[it - 'a']++;
      for (int j = 0; j < 5; j++) cnt[j].push_back(2 * ct[j] - str.size());
    }
    int ans = 0;
    for (int k = 0; k < 5; k++) {
      int sp = 0;
      sort(cnt[k].begin(), cnt[k].end(), greater<int>());
      if (cnt[k][0] <= 0) continue;
      sp = 1;
      int i = 1, p = cnt[k][0];
      while (i < n && p + cnt[k][i] > 0) {
        p += cnt[k][i];
        sp++;
        i++;
      }
      ans = max(ans, sp);
    }
    cout << ans << endl;
  }
  return 0;
}
