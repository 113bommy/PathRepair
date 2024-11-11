#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, d;
  cin >> n >> d;
  vector<long long> delta(n);
  vector<long long> rs(n);
  for (int i = 0; i < n; ++i) cin >> delta[i];
  rs[0] = delta[0];
  for (int i = 1; i < n; ++i) rs[i] = rs[i - 1] + delta[i];
  vector<long long> maxTotDeposit(n);
  long long mxSoFar = LLONG_MIN;
  for (int i = n - 1; i >= 0; --i) {
    mxSoFar = max(mxSoFar, rs[i]);
    maxTotDeposit[i] = d - mxSoFar;
    if (mxSoFar > d) {
      cout << -1;
      return 0;
    }
  }
  long long dep = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!delta[i] && rs[i] + maxTotDeposit[i] < 0) {
      cout << -1;
      return 0;
    }
    if (!delta[i] && rs[i] + dep < 0) {
      ++ans;
      dep = maxTotDeposit[i];
    }
  }
  cout << ans;
  return 0;
}
