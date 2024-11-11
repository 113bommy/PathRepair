#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<long long> ans[2];
int k;
vector<bool> up, ua;
const long long MD = 1000000007;
void input_data() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < 2; ++i) {
    ans[i].clear();
    for (int j = 0; j < n; ++j) {
      ans[i].push_back(0LL);
    }
  }
  a.resize(n);
  k = 0;
  ua.assign(n, false);
  up.assign(n, false);
  int oldn = n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] != -1) {
      --oldn;
      ua[i] = true;
      up[a[i] - 1] = true;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!ua[i] && !up[i]) {
      ++k;
    }
  }
  n = oldn;
  long long cur_m = 1LL;
  ans[0][0] = 1LL;
  for (int i = 1; i <= n; ++i) {
    cur_m = (cur_m * i) % MD;
    ans[i & 1][0] = cur_m;
    for (int j = 1; j <= min(i, k); ++j) {
      ans[i & 1][j] =
          (ans[i & 1][j - 1] + cur_m - ans[(i - 1) & 1][j - 1] + MD) % MD;
    }
  }
  long long res =
      (k == 0) ? ans[n & 1][0] : (ans[n & 1][k] - ans[n & 1][k - 1] + MD) % MD;
  cout << res << "\n";
}
int main() {
  input_data();
  return 0;
}
