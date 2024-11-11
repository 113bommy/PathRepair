#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(0);
  int n, k;
  string s;
  while (cin >> n) {
    cin >> k;
    cin >> s;
    vector<int> count(n, 0);
    for (int i = 1; i < n; i++) {
      count[i] = count[i - 1] + (s[i] == '0' ? 1 : 0);
    }
    int left = -1;
    int right = 0;
    int ans = n;
    while (right < n) {
      left++;
      while (s[left] != '0') {
        left++;
      }
      while (right < n && count[right] - count[left] < k) {
        right++;
      }
      if (right >= n) {
        break;
      }
      int m = left + (right - left + 1) / 2;
      if (s[m] == '0') {
        ans = min(ans, max(m - left, right - m));
        continue;
      }
      auto range = equal_range(count.begin(), count.end(), count[m]);
      int v1 = range.first - count.begin();
      ans = min(ans, max(v1 - left, right - v1));
      int v2 = range.second - count.begin();
      ans = min(ans, max(v2 - left, right - v2));
    }
    cout << ans << endl;
  }
  return 0;
}
