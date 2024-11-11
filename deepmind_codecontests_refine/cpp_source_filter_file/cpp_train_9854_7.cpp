#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  cin >> n >> c;
  vector<long long> a(n);
  vector<long long> sum(n, 0);
  vector<long long> mi(n, 1e9 + 10);
  set<long long> se;
  priority_queue<long long> que;
  map<long long, int> ma;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i] = a[i];
    if (i > 0) {
      sum[i] += sum[i - 1];
    }
    if (ma.find(a[i]) == ma.end()) {
      ma.insert(make_pair(a[i], 1));
    } else {
      ma[a[i]]++;
    }
    if (i >= c) {
      ma[a[i - c]]--;
      if (ma[a[i - c]] == 0) {
        ma.erase(a[i - c]);
      }
      auto x = ma.begin();
      mi[i] = x->first;
    } else {
      auto x = ma.begin();
      mi[i] = x->second;
    }
  }
  if (n < c) {
    cout << sum[n - 1] << endl;
    return 0;
  }
  vector<long long> dp(n, 0);
  for (int i = 0; i < c - 1; i++) {
    dp[i] = sum[i];
  }
  for (int i = c - 1; i < n; i++) {
    dp[i] = min((i - 1 >= 0 ? dp[i - 1] : 0) + a[i],
                (i - c >= 0 ? dp[i - c] : 0) + sum[i] -
                    (i - c >= 0 ? sum[i - c] : 0) - mi[i]);
  }
  cout << dp[n - 1] << endl;
}
