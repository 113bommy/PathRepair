#include <bits/stdc++.h>
using namespace std;
struct _ {
  ios_base::Init i;
  _() {
    cin.sync_with_stdio(0);
    cin.tie(0);
  }
} _;
int main(int argc, char** argv) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = (0); i < (n); ++i) cin >> a[i];
  sort(a.begin(), a.end());
  int num_large = n % k;
  int num_small = k - n % k;
  long long** dp = new long long*[num_large + 1];
  for (int i = (0); i < (num_large + 1); ++i) {
    dp[i] = new long long[num_small + 1];
  }
  dp[0][0] = 0;
  for (int i = (0); i < (num_large + 1); ++i) {
    for (int j = (0); j < (num_small + 1); ++j) {
      if (!i && !j) continue;
      dp[i][j] = 1LL << 60;
      int st, ed;
      long long diff;
      if (i > 0) {
        st = (i - 1) * (n / k + 1) + j * n / k;
        ed = st + (n / k + 1) - 1;
        diff = a[ed] - a[st];
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + diff);
      }
      if (j > 0) {
        st = i * (n / k + 1) + (j - 1) * n / k;
        ed = st + n / k - 1;
        diff = a[ed] - a[st];
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + diff);
      }
    }
  }
  cout << dp[num_large][num_small];
  return 0;
}
