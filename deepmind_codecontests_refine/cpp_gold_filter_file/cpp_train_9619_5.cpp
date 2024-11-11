#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100, MX = 12;
long long int dp[N][MX], ch[N][MX];
int mxm(int x) {
  if (x == 0) return 0;
  return max(x % 10, mxm(x / 10));
}
int main() {
  long long int n;
  cin >> n;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 1e6; j++) {
      if (i == 0 && j == 0) continue;
      int mx = mxm(j);
      mx = max(mx, i);
      ch[j][i] = ((j >= mx) ? ch[j - mx][i] : j - mx);
      dp[j][i] = ((j >= mx) ? dp[j - mx][i] + 1 : 1);
    }
  }
  bool added = n == 1e12;
  if (added) n--;
  long long int ans = 0;
  while (n) {
    ans += dp[n % 1000000][mxm(n / 1000000)];
    long long int sub = ch[n % 1000000][mxm(n / 1000000)];
    n = n - (n % 1000000) + sub;
  }
  cout << ans + added;
}
