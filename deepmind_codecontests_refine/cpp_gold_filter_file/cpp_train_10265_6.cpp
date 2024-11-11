#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[20];
vector<pair<int, int> > left1, right1;
int main() {
  cin >> n >> m;
  int mark = 0, limit = 0;
  for (int i = 0; i < n; i++) {
    int prev = 0, sum1 = 0, sum2 = 0;
    cin >> s[i];
    for (int j = 0; j < s[i].size(); j++) {
      if (s[i][j] == '1') {
        sum1 += abs(prev - j);
        prev = j;
      }
    }
    int len = m + 2;
    left1.push_back({sum1, abs(prev)});
    prev = len - 1;
    for (int j = len - 1; j >= 0; j--) {
      if (s[i][j] == '1') {
        sum2 += abs(prev - j);
        prev = j;
      }
    }
    right1.push_back({sum2, abs(prev)});
    if (sum1 == 0 && mark == 0)
      limit++;
    else
      mark = 1;
  }
  int ans = 1e17, lim = pow(2, abs(n));
  for (int i = 0; i < lim; i++) {
    int temp = 0;
    for (int j = n - 1; j >= limit; j--) {
      if (i & (1 << j)) {
        if (j == n - 1) {
          temp += m + 1;
        }
        temp += right1[j].first;
        if (j != limit) {
          if (i & (1 << (j - 1)))
            temp += abs(m + 1 - right1[j].second);
          else
            temp += abs(right1[j].second);
        }
      } else {
        temp += left1[j].first;
        if (j != limit) {
          if (i & (1 << (j - 1)))
            temp += abs(m + 1 - left1[j].second);
          else
            temp += abs(left1[j].second);
        }
      }
      if (j != limit) temp++;
    }
    ans = min(ans, temp);
  }
  cout << ans << "\n";
  return 0;
}
