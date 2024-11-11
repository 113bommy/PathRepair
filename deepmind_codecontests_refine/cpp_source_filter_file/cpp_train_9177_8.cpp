#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, i, count = 0;
  cin >> n;
  vector<pair<long int, long int>> pos, neg, ans;
  for (i = 0; i < n; i++) {
    long int a;
    cin >> a;
    if (a >= 0)
      neg.push_back({-a, i});
    else
      neg.push_back({a, i});
  }
  sort(neg.begin(), neg.end());
  if (neg.size() % 2 != 0) {
    neg[0].first = -(neg[i].first + 1);
  }
  for (i = 0; i < neg.size(); i++) {
    ans.push_back({neg[i].second, neg[i].first});
  }
  sort(ans.begin(), ans.end());
  for (i = 0; i < ans.size(); i++) {
    cout << ans[i].second << " ";
  }
}
