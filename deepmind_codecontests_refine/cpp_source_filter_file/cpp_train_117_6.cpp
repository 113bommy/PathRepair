#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long dp[10] = {};
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    long long item1[3] = {}, item2 = 0, item3 = 0;
    for (int j = 0; j < k; ++j) {
      int c;
      long long d;
      cin >> c >> d;
      if (c == 1) {
        item1[0] = max(item1[0], d);
        sort(item1, item1 + 3);
      } else if (c == 2)
        item2 = max(item2, d);
      else
        item3 = max(item3, d);
    }
    int s1 = 0;
    for (auto it : item1)
      if (it) s1++;
    vector<long long> cards;
    if (s1 >= 1 || item2 || item3)
      cards.push_back(max(item2, max(item3, item1[2])));
    if (s1 >= 2 || (item2 && s1 >= 1))
      cards.push_back(item1[2] + max(item2, item1[1]));
    if (s1 == 3) cards.push_back(item1[0] + item1[1] + item1[2]);
    int c = cards.size();
    long long temp[10];
    copy(dp, dp + 10, temp);
    for (int p = 0; p <= 9; ++p) {
      if (p == 0 || dp[p]) {
        if (p == 9 && c >= 1)
          temp[(p + 1) % 10] = max(temp[(p + 1) % 10], 2 * cards[0] + dp[p]);
        else if (c >= 1)
          temp[(p + 1) % 10] = max(temp[(p + 1) % 10], cards[0] + dp[p]);
        if (p == 8 && c >= 2)
          temp[(p + 2) % 10] =
              max(temp[(p + 2) % 10], max(item2, item1[2]) + cards[1] + dp[p]);
        else if (c >= 2)
          temp[(p + 2) % 10] = max(temp[(p + 2) % 10], cards[1] + dp[p]);
        if (p == 7 && c == 3)
          temp[(p + 3) % 10] =
              max(temp[(p + 3) % 10], item1[2] + cards[2] + dp[p]);
        else if (c == 3)
          temp[(p + 3) % 10] = max(temp[(p + 3) % 10], cards[2] + dp[p]);
      }
    }
    copy(temp, temp + 10, dp);
  }
  long long mV = 0;
  for (auto x : dp) {
    mV = max(mV, x);
  }
  cout << mV;
  return 0;
}
