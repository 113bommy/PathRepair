#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int solve() {
  long long n;
  cin >> n;
  if (n == 1) return 1;
  long long curr_len = 1;
  long long curr_sum = 1;
  int ans = 0;
  while (curr_sum <= n) {
    n -= (curr_sum);
    curr_len = (2 * curr_len) + 1;
    curr_sum = (curr_len * (curr_len + 1)) / 2;
    ans++;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}
