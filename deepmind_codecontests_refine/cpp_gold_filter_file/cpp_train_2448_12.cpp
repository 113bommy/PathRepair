#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long INFLL = (1 << 63);
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
int main() {
  fast_io();
  string a, b;
  cin >> a >> b;
  vector<pair<int, int> > dp(b.size(), make_pair(0, 0));
  if (b[0] == '1') {
    dp[0] = make_pair(0, 1);
  } else {
    dp[0] = make_pair(1, 0);
  }
  for (int i = 1; i < b.size(); ++i) {
    dp[i] = dp[i - 1];
    if (b[i] == '1') {
      dp[i].second += 1;
    } else {
      dp[i].first += 1;
    }
  }
  long long answer = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == '1') {
      if (i == 0) {
        answer += dp[i + (b.size() - a.size())].first;
      } else {
        answer += (dp[i + (b.size() - a.size())].first - dp[i - 1].first);
      }
    } else {
      if (i == 0) {
        answer += dp[i + (b.size() - a.size())].second;
      } else {
        answer += (dp[i + (b.size() - a.size())].second - dp[i - 1].second);
      }
    }
  }
  cout << answer;
  return 0;
}
