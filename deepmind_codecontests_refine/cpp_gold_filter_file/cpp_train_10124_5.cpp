#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.length(), l = 0, r = 0, cnt[4] = {0}, ans = INT_MAX;
    for (; r < n; r++) {
      cnt[s[r] - '0']++;
      while (cnt[s[l] - '0'] > 1) {
        cnt[s[l] - '0']--;
        l++;
      }
      if (cnt[1] > 0 && cnt[2] > 0 && cnt[3] > 0) ans = min(ans, r - l + 1);
    }
    cout << (ans == INT_MAX ? 0 : ans) << endl;
  }
  return 0;
}
