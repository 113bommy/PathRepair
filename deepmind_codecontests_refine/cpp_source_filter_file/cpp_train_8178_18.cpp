#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const int N = 100100;
long long int dp[N];
int main(void) {
  int n;
  cin >> n;
  vector<long long int> t(n);
  for (int i = (int)(0); i < (int)(n); i++) {
    cin >> t[i];
  }
  dp[0] = 0;
  for (int i = (int)(0); i < (int)(n); i++) {
    long long int mi = dp[i] + 20;
    int idx1 = lower_bound(t.begin(), t.begin() + i, t[i] - 90) - t.begin();
    mi = min(mi, dp[idx1] + 50);
    int idx2 = lower_bound(t.begin(), t.begin() + i, t[i] - 1440) - t.begin();
    mi = min(mi, dp[idx2] + 120);
    dp[i + 1] = mi;
  }
  for (int i = (int)(0); i < (int)(n); i++) {
    cout << dp[i + 1] - dp[i] << endl;
  }
}
