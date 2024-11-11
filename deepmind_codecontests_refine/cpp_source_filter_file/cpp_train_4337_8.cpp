#include <bits/stdc++.h>
using namespace std;
long long n, k;
int a[110], ans;
long long dp[100010][110];
int maxN = 100010;
long long get(long long nn, int ind) {
  if (ind == k) {
    return nn;
  }
  if (nn < maxN && dp[nn][ind] >= 0) {
    return dp[nn][ind];
  }
  long long crr = get(nn, ind + 1) - get(nn / a[ind], ind + 1);
  if (nn < maxN) {
    dp[ind][nn] = crr;
  }
  return crr;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  sort(a, a + k);
  reverse(a, a + k);
  memset(dp, -1, sizeof(dp));
  cout << get(n, 0) << endl;
  return 0;
}
