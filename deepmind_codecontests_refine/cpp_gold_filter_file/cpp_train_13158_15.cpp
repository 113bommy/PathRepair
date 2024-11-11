#include <bits/stdc++.h>
using namespace std;
long long int get_sum(vector<long long int> &sum, int l, int r) {
  return (l == 0) ? sum[r] : (sum[r] - sum[l - 1]);
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<long long int> val(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }
  vector<pair<long long int, int>> memo(n, {-1, -1});
  long long int currsum = accumulate(end(val) - k, end(val), 0);
  memo[n - k] = {currsum, n - k};
  for (int i = n - k - 1; i >= 0; i--) {
    currsum -= val[i + k];
    currsum += val[i];
    memo[i] = max(memo[i + 1], {currsum, i});
    if (memo[i + 1].first == currsum) memo[i].second = i;
  }
  currsum = accumulate(begin(val), begin(val) + k, 0);
  pair<int, int> ans(0, memo[k].second);
  long long int maxsum = currsum + memo[k].first;
  for (int i = 1; i <= n - 2 * k; i++) {
    currsum -= val[i - 1];
    currsum += val[i + k - 1];
    if (maxsum < currsum + memo[i + k].first) {
      ans = {i, memo[i + k].second};
      maxsum = currsum + memo[i + k].first;
    }
  }
  cout << ans.first + 1 << " " << ans.second + 1;
  return 0;
}
