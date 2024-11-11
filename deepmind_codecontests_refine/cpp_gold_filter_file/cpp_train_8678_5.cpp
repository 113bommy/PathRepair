#include <bits/stdc++.h>
using namespace std;
int n, a[4005], dp[4005][4005], ans, last;
int i = 0, j = 0, k = 0;
;
int main() {
  cin >> n;
  ;
  for ((i) = (1); (i) <= (n); (i++)) cin >> a[i];
  ;
  for ((i) = (1); (i) <= (n); (i++)) {
    last = 0;
    for ((j) = (0); (j) < (i); (j++)) {
      dp[j][i] = dp[last][j] + 1;
      if (a[i] == a[j]) last = j;
      ans = max(ans, dp[j][i]);
    }
  }
  cout << ans << endl;
  ;
}
