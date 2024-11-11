#include <bits/stdc++.h>
using namespace std;
int k, n, d, a[500005], psum[500005], dp[500005];
vector<int> vec;
int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> k >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vec.push_back(a[i]);
  }
  vec.push_back(-1);
  sort(a + 1, a + 1 + n);
  sort(vec.begin(), vec.end());
  dp[0] = 1;
  psum[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (abs(a[i] - a[1]) <= d && i >= k) dp[i] = 1;
    if (i < k) dp[i] = 0;
    int it = lower_bound(vec.begin(), vec.end(), -d + a[i]) - vec.begin();
    if (abs(i - it + 1) >= k && i >= k && it >= 1 && it != vec.size()) {
      dp[i] = ((psum[i - k] - psum[0]) | dp[i]);
    }
    psum[i] += psum[i - 1] + min(dp[i], 1);
  }
  if (dp[n])
    cout << "YES";
  else
    cout << "NO";
}
