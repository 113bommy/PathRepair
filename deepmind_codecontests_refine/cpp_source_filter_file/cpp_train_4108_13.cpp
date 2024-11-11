#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 20;
int c[maxn];
long long dp[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int r;
    cin >> r;
    c[r]++;
  }
  dp[1] = c[1];
  for (int i = 2; i < maxn; i++) dp[i] = max(dp[i - 1], dp[i - 2] + c[i] * i);
  cout << *max_element(dp, dp + maxn);
}
