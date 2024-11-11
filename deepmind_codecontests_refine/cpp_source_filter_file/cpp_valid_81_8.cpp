#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long dp[N];
void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    int val = 1;
    if (c == '-') val *= -1;
    if (i % 2 == 0) val *= -1;
    dp[i] = dp[i - 1] + val;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    long long temp = dp[r] - dp[l - 1];
    if (temp == 0)
      cout << "0\n";
    else if (temp % 2 == 1)
      cout << "1\n";
    else
      cout << "2\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
