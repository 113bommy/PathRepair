#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > pos;
vector<pair<int, int> > neg;
vector<int> dp;
bool cmp(pair<int, int> l, pair<int, int> r) {
  return l.first + l.second > r.first + r.second;
}
int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (b < 0)
      neg.push_back({a, b});
    else
      pos.push_back({a, b});
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end(), cmp);
  int ans = 0;
  for (int i = 0; i < pos.size(); i++)
    if (pos[i].first <= r) {
      r += pos[i].second;
      ans++;
    }
  dp = vector<int>(r + 2, -1);
  dp[r] = ans;
  for (int i = 0; i < neg.size(); i++) {
    for (int j = 0; j < r; j++) {
      if (j - neg[i].second >= neg[i].first && dp[j - neg[i].second] != -1)
        dp[i] = max(dp[i], dp[j - neg[i].second] + 1);
      ans = max(ans, dp[i]);
    }
  }
  printf("%d\n", ans);
}
