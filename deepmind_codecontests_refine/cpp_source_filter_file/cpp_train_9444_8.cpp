#include <bits/stdc++.h>
using namespace std;
int n, k;
unsigned long long a[55], dp[55][55], Max;
unsigned long long DP(int cur, int cnt) {
  if (cur == n) {
    if (cnt == k)
      return 1;
    else
      return 0;
  }
  unsigned long long &ret = dp[cur][cnt];
  if (ret != -1) return ret;
  unsigned long long sum = 0;
  ret = 0;
  for (int i = cur; i < n; i++) {
    sum += a[i];
    if ((sum & Max) == Max) ret |= DP(i + 1, cnt + 1);
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 10; i >= 0; i--) {
    Max ^= (1LL << i);
    memset(dp, -1, sizeof dp);
    if (!DP(0, 0)) Max ^= (1LL << i);
  }
  cout << Max << endl;
}
