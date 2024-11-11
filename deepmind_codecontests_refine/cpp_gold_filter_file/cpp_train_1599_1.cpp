#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1, inf = 1e9;
const int MOD = 1e9 + 7;
int add(int a, int b) { return (a += b) + MOD * (a < 0) - MOD * (a >= MOD); }
int n, dp[N], ps[2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  dp[1] = 1;
  ps[1]++;
  for (int i = 2; i <= n; i++) {
    dp[i] = add(ps[1 - (i % 2)], 1);
    ps[i % 2] = add(ps[i % 2], dp[i]);
  }
  cout << add(ps[0], ps[1]);
  return 0;
}
