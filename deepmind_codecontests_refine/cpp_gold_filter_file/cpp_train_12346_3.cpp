#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
vector<pair<int, int> > diamonds;
vector<pair<int, int> > coins;
pair<int, int> dp[MAXN][2];
pair<int, int> arr[MAXN][2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, c, d;
  cin >> n >> c >> d;
  for (int i = 0; i < n; i++) {
    int x, y;
    char type;
    cin >> x >> y >> type;
    if (type == 'C') {
      coins.push_back(make_pair(y, x));
    } else
      diamonds.push_back(make_pair(y, x));
  }
  coins.push_back(make_pair(100001, 100000));
  coins.push_back(make_pair(100001, 100000));
  diamonds.push_back(make_pair(100001, 100000));
  diamonds.push_back(make_pair(100001, 100000));
  sort(coins.begin(), coins.end());
  sort(diamonds.begin(), diamonds.end());
  for (int i = 0; i < MAXN; i++) {
    dp[i][0] = dp[i][1] = arr[i][0] = arr[i][1] = make_pair(-1, -1);
  }
  int idx = 0;
  for (int i = 1; i < MAXN; i++) {
    dp[i][0] = dp[i - 1][0];
    arr[i][0] = arr[i - 1][0];
    while (idx < coins.size() && coins[idx].first <= i) {
      if (coins[idx].second > dp[i][0].first) {
        dp[i][0].second = dp[i][0].first;
        arr[i][0].second = arr[i][0].first;
        dp[i][0].first = coins[idx].second;
        arr[i][0].first = idx;
      } else {
        if (coins[idx].second > dp[i][0].second) {
          dp[i][0].second = coins[idx].second;
          arr[i][0].second = idx;
        }
      }
      idx++;
    }
  }
  idx = 0;
  for (int i = 1; i < MAXN; i++) {
    dp[i][1] = dp[i - 1][1];
    arr[i][1] = arr[i - 1][1];
    while (idx < diamonds.size() && diamonds[idx].first <= i) {
      if (diamonds[idx].second > dp[i][1].first) {
        dp[i][1].second = dp[i][1].first;
        arr[i][1].second = arr[i][1].first;
        dp[i][1].first = diamonds[idx].second;
        arr[i][1].first = idx;
      } else {
        if (diamonds[idx].second > dp[i][1].second) {
          dp[i][1].second = diamonds[idx].second;
          arr[i][1].second = idx;
        }
      }
      idx++;
    }
  }
  int ans = 0;
  int d1 = 0;
  for (int i = 0; i < diamonds.size(); i++) {
    if (diamonds[i].first <= d) d1 = max(d1, diamonds[i].second);
  }
  int c1 = 0;
  for (int i = 0; i < coins.size(); i++) {
    if (coins[i].first <= c) c1 = max(c1, coins[i].second);
  }
  if (c1 != 0 && d1 != 0) ans = c1 + d1;
  for (int i = 0; i < coins.size(); i++) {
    if (coins[i].first >= c) break;
    int temp = 0;
    int left = c - coins[i].first;
    temp = coins[i].second;
    if (dp[left][0].first == -1) continue;
    if (arr[left][0].first != i) {
      temp += dp[left][0].first;
      ans = max(ans, temp);
    } else {
      if (dp[left][0].second != -1) {
        temp += dp[left][0].second;
        ans = max(ans, temp);
      }
    }
  }
  for (int i = 0; i < diamonds.size(); i++) {
    if (diamonds[i].first >= d) break;
    int temp = 0;
    int left = d - diamonds[i].first;
    temp = diamonds[i].second;
    if (dp[left][1].first == -1) continue;
    if (arr[left][1].first != i) {
      temp += dp[left][1].first;
      ans = max(ans, temp);
    } else {
      if (dp[left][1].second != -1) {
        temp += dp[left][1].second;
        ans = max(ans, temp);
      }
    }
  }
  cout << ans;
  return 0;
}
