#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 100;
int n, r;
vector<pair<int, int> > pos;
vector<pair<int, int> > neg;
int ans;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
  return p1.first + p2.second < p2.first + p1.second;
}
int main() {
  cin >> n >> r;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    if (b >= 0)
      pos.push_back(make_pair(a, b));
    else
      neg.push_back(make_pair(a, b));
  }
  sort(pos.begin(), pos.end());
  ans = 0;
  for (int i = 0; i < pos.size(); i++)
    if (pos[i].first <= r) {
      ans++;
      r += pos[i].second;
    }
  sort(neg.begin(), neg.end(), cmp);
  reverse(neg.begin(), neg.end());
  int dp[60100];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < neg.size(); i++)
    for (int j = 0; j <= r; j++) {
      if (j >= neg[i].first && j + neg[i].second >= 0)
        dp[j + neg[i].second] = max(dp[j + neg[i].second], dp[j] + 1);
    }
  for (int i = r - 1; i >= 0; i--) dp[i] = max(dp[i], dp[i + 1]);
  ans += dp[0];
  if (ans == n)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
