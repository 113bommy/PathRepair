#include <bits/stdc++.h>
using namespace std;
const int N6 = 10000 * 1000 + 20;
const int N = 700 * 1000 + 50;
const int N3 = 5000 + 20;
const long long mod = 1000 * 1000 * 1000 + 9;
const long long inf = LLONG_MAX / 10;
long long dp[N6], a[N];
vector<int> vec[30];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  fill(dp, dp + N6, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[(1 << 22) - a[i] - 1] = a[i];
  }
  for (int i = 0; i < (1 << 22); i++) {
    vec[__builtin_popcount(i)].push_back(i);
  }
  for (int i = 22; i > -1; i--) {
    for (auto x : vec[i]) {
      for (int j = 0; j < 22; j++) {
        if (!((x >> j) & 1)) {
          dp[x] = max(dp[x], dp[x + (1 << j)]);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << dp[a[i]] << " ";
  }
  cout << "\n";
}
