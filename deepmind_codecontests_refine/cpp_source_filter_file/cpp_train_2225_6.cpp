#include <bits/stdc++.h>
using namespace std;
long long dp[100005] = {0};
vector<long long> getPrimes(long long n) {
  vector<long long> vect;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      vect.push_back(i);
    }
    while (n % i == 0) n /= i;
  }
  if (n >= 2) vect.push_back(n);
  return vect;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  for (long long i = 0; i < n; i++) {
    long long vv = arr[i];
    vector<long long> v = getPrimes(vv);
    long long ans = -1;
    for (long long j = 0; j < v.size(); j++) {
      long long p = v[j];
      ans = max(ans, dp[p] + 1);
    }
    for (long long j = 0; j < v.size(); j++) {
      long long p = v[j];
      dp[p] = ans;
    }
  }
  long long res = -1;
  for (long long i = 0; i < 100002; i++) {
    res = max(res, dp[i]);
  }
  cout << res;
  return 0;
}
