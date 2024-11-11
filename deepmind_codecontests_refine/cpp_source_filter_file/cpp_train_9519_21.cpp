#include <bits/stdc++.h>
using namespace std;
int c, d;
int n, m;
int k;
int dp[10000];
int f(int cont_num) {
  if (cont_num >= (n * m - k)) {
    return dp[cont_num] = 0;
  } else if (dp[cont_num] != -1)
    return dp[cont_num];
  else {
    dp[cont_num] = min(f(cont_num + n) + c, f(cont_num + 1) + d);
    return dp[cont_num];
  }
}
int main() {
  cin >> c >> d;
  cin >> n >> m;
  cin >> k;
  memset(dp, -1, sizeof(dp));
  cout << f(0) << endl;
  return 0;
}
