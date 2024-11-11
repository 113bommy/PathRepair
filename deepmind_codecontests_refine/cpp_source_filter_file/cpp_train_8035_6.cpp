#include <bits/stdc++.h>
using namespace std;
long long dp[300005];
long long n, a[300005];
vector<long long> v;
long long maxm;
long long lft[300005], rgt[300005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    v.clear();
    maxm = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      v.push_back(a[i]);
      lft[i] = 1e16;
      rgt[i] = -1e16;
    }
    sort(v.begin(), v.end());
    long long sz = unique(v.begin(), v.end()) - v.begin();
    v.resize(sz);
    map<long long, long long> mp;
    for (long long i = 0; i < v.size(); i++) {
      mp[v[i]] = i + 1;
    }
    for (long long i = 1; i <= n; i++) {
      a[i] = mp[a[i]];
      long long el = a[i];
      maxm = max(maxm, a[i]);
      lft[el] = min(lft[el], i);
      rgt[el] = i;
    }
    dp[1] = 1;
    long long ans = 0;
    for (long long i = 2; i <= maxm; i++) {
      if (rgt[i - 1] < lft[i]) {
        dp[i] = dp[i - 1];
      } else
        dp[i] = i;
      ans = max(ans, i - dp[i] + 1);
    }
    cout << maxm - ans << "\n";
  }
  return 0;
}
