#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    int wins = 0;
    for (int j = 0; j < n; j++) {
      char ch = str[j];
      if (ch == 'W') {
        wins++;
      }
    }
    if (k >= n - wins) {
      cout << 2 * n - 1 << endl;
      continue;
    }
    int streaks = 0;
    bool lastWin = false;
    bool lastLost = false;
    vector<int> streak_gaps;
    for (int j = 0; j < n; j++) {
      char ch = str[j];
      if (ch == 'W') {
        if (!lastWin) {
          streak_gaps.push_back(1);
        } else
          streak_gaps[streak_gaps.size() - 1]++;
        lastWin = true;
        lastLost = false;
      } else {
        if (!lastLost) {
          streak_gaps.push_back(-1);
        } else
          streak_gaps[streak_gaps.size() - 1]--;
        lastLost = true;
        lastWin = false;
      }
    }
    if (streak_gaps.size() > 0 && streak_gaps[streak_gaps.size() - 1] < 0)
      streak_gaps.pop_back();
    if (streak_gaps.size() > 0 && streak_gaps[0] < 0)
      streak_gaps.erase(streak_gaps.begin());
    for (auto it = streak_gaps.begin(); it != streak_gaps.end(); it++) {
      if (*it > 0) {
        it = streak_gaps.erase(it);
        it--;
        streaks++;
      } else
        *it = -*it;
    }
    sort(streak_gaps.begin(), streak_gaps.end());
    int fills = 0;
    int filled_gaps = 0;
    for (auto it = streak_gaps.begin(); it != streak_gaps.end(); it++) {
      int gap = *it;
      if (fills + gap > k) {
        break;
      }
      fills += gap;
      filled_gaps++;
    }
    int ans = 2 * (k + wins) - streaks + filled_gaps;
    if (wins == 0)
      cout << max(0, ans - 1) << "\n";
    else
      cout << ans << "\n";
  }
  return 0;
}
