#include <bits/stdc++.h>
using namespace std;
int n, a[100001], dp[100001] = {0};
int go(int k) {
  if (k > n - 1)
    return 0;
  else {
    if (a[k] < a[k + 1]) {
      dp[k] = 1;
      return 1 + go(k + 1);
    } else
      return 0;
  }
}
int main() {
  a[100000] = INT_MAX;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    if (!dp[i]) ans = max(ans, go(i));
  cout << ans + 1 << endl;
}
