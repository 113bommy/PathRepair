#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const int maxm = 1 << 22;
int n;
int a[maxn];
int dp[maxm];
inline void input();
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  input();
}
inline void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[a[i]] = a[i];
  }
  for (int i = 0; i < maxm; i++) {
    for (int j = 0; j < 22; j++) {
      if ((i & (1 << j)) != 0) {
        dp[i] = max(dp[i], dp[i ^ (1 << j)]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (dp[a[i] ^ ((maxm)-1)] == 0) {
      cout << -1 << " ";
    } else {
      cout << dp[a[i] ^ ((maxm)-1)] << " ";
    }
  }
}
