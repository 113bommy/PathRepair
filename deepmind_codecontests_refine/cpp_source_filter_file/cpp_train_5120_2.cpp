#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 2e5 + 5;
long long gcd(long long n, long long m) {
  if (n == 0)
    return m;
  else
    return gcd(m % n, n);
}
long long a[105], b[105];
vector<pair<long long, long long> > v1, v2;
long long dp[103][60000];
long long go(long long pos, long long r) {
  if (r < 0) return -MOD;
  if (pos == v2.size()) {
    return 0;
  }
  long long &ans = dp[pos][r];
  if (ans != -1) return ans;
  ans = go(pos + 1, r);
  if (r >= a[v2[pos].second]) {
    ans = max(ans, go(pos + 1, r + b[v2[pos].second]) + 1);
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, r;
  cin >> n >> r;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    if (b[i] >= 0) {
      v1.push_back({a[i], b[i]});
    } else {
      v2.push_back({-(a[i] + b[i]), i});
    }
  }
  memset(dp, -1, sizeof(dp));
  if (v1.size() > 0) {
    sort(v1.begin(), v1.end());
    long long ans = 0;
    for (long long i = 0; i < v1.size(); i++) {
      if (r >= v1[i].first) {
        r += v1[i].second;
        ans++;
      }
    }
    if (v2.size() == 0) {
      cout << "YES" << endl;
      return 0;
    }
    sort(v2.begin(), v2.end());
    long long k = go(0, r);
    cout << ans + k << endl;
  } else {
    sort(v2.begin(), v2.end());
    cout << go(0, r) << endl;
  }
}
