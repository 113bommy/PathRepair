#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int ara[n], ans = 0, cnt = 0;
  for (long long int i = 0; i < n; i++) cin >> ara[i];
  long long int dp[n];
  vector<long long int> v;
  v.push_back(0);
  for (long long int i = 0; i < n; i++) {
    if (ara[i] > v.back()) {
      dp[i] = v.size();
      v.push_back(ara[i]);
    } else {
      long long int id = lower_bound(v.begin(), v.end(), ara[i]) - v.begin();
      dp[i] = id;
      v[id] = ara[i];
    }
    cnt = max(cnt, dp[i]);
  }
  long long int a[n + 2];
  fill(a, a + n + 2, 0);
  map<long long int, long long int> mark, m;
  for (long long int i = n - 1; i >= 0; i--) {
    if (dp[i] == cnt || ara[i] < a[dp[i] + 1]) {
      mark[i] = 1;
      m[dp[i]]++;
    }
    if (mark[i]) a[dp[i]] = max(ara[i], a[dp[i]]);
  }
  for (long long int i = 0; i < n; i++) {
    if (mark[i] == 0)
      cout << 1;
    else if (m[dp[i]] > 1)
      cout << 2;
    else
      cout << 3;
  }
}
