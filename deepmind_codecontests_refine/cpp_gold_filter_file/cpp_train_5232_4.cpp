#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int tc;
  scanf("%lld", &tc);
  while (tc--) {
    long long int n;
    scanf("%lld", &n);
    long long int dp[n + 5], arr[n + 5];
    vector<pair<long long int, long long int> > v;
    for (long long int i = 0; i < n; i++) {
      long long int a;
      scanf("%lld", &a);
      v.push_back({a, i});
      dp[i] = 1;
    }
    sort(v.begin(), v.end());
    for (long long int i = 0; i < n; i++) {
      arr[i] = v[i].second;
    }
    long long int mx = 1;
    for (long long int i = n - 2; i >= 0; i--) {
      if (arr[i] < arr[i + 1]) dp[i] = dp[i + 1] + 1;
      mx = max(mx, dp[i]);
    }
    cout << n - mx << endl;
  }
}
