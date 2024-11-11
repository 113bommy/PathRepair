#include <bits/stdc++.h>
using namespace std;
int constexpr MOD = 1e9 + 7;
int constexpr max_length = 1e5;
long long dp[max_length + 5], ps[max_length + 5];
template <typename T>
T mod(T n) {
  return n % ((T)MOD);
}
void calculate(int k) {
  fill(dp, dp + k, 1);
  for (int i = k; i <= max_length; i++) dp[i] = mod(dp[i - 1] + dp[i - k]);
  for (int i = 1; i <= max_length; i++) ps[i] = (ps[i - 1] + dp[i]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(16);
  if (0) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int t, k;
  cin >> t >> k;
  calculate(k);
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << mod(ps[b] - ps[a - 1]) << endl;
    if (0) cerr << "D" << ps[b] << ", " << ps[a - 1] << endl;
    ;
  }
  return 0;
}
