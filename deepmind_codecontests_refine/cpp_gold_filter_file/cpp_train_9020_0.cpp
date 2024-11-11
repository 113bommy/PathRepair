#include <bits/stdc++.h>
using namespace std;
int a[200002];
map<int, int> dp, pos, nxt;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  dp[a[n]] = 1;
  pos[a[n]] = n;
  int ans = 1, start = n;
  for (int i = n - 1; i >= 1; i--) {
    dp[a[i]] = dp[a[i] + 1] + 1;
    nxt[i] = pos[a[i] + 1];
    if (dp[a[i]] > ans) {
      ans = dp[a[i]];
      start = i;
    }
    pos[a[i]] = i;
  }
  cout << ans << endl;
  while (start != 0) {
    cout << start << " ";
    start = nxt[start];
  }
  return 0;
}
