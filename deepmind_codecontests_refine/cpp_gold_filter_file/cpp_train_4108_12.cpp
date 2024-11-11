#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int main() {
  long long n, a, f[maxn], maxnum = 0;
  long long dp[maxn];
  cin >> n;
  memset(f, 0, sizeof(f));
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    f[a] += a;
    maxnum = max(maxnum, a);
  }
  dp[1] = f[1];
  for (int i = 2; i <= maxnum; i++) {
    dp[i] = max(dp[i - 2] + f[i], dp[i - 1]);
  }
  cout << dp[maxnum] << endl;
  return 0;
}
