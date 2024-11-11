#include <bits/stdc++.h>
using namespace std;
int ara[100010];
int dp1[100010];
int dp2[100010];
int main() {
  std::ios_base::sync_with_stdio(false);
  ;
  int n;
  cin >> n;
  for (int i = 0; i <= n - 1; i++) {
    cin >> ara[i];
  }
  dp1[0] = 1;
  for (int i = 1; i <= n - 1; i++) {
    int tmp = 0;
    if (ara[i] > ara[i - 1]) {
      tmp = 1 + ara[i - 1];
    } else {
      tmp = ara[i];
    }
    dp1[i] = min(1 + dp1[i - 1], tmp);
  }
  dp2[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    int tmp = 0;
    if (ara[i] > ara[i + 1]) {
      tmp = 1 + ara[i + 1];
    } else {
      tmp = ara[i];
    }
    dp2[i] = min(1 + dp2[i + 1], tmp);
  }
  int ans = 0;
  for (int i = 0; i <= n - 1; i++) {
    ans = max(ans, min(dp1[i], dp2[i]));
  }
  cout << ans << "\n";
  return 0;
}
