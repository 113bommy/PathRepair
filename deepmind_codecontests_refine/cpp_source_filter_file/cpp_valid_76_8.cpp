#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LLINF = 1e18;
const int MAXN = 2e5 + 10;
const int mod = 1e9 + 7;
long long dp[MAXN];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  dp[n] = 1;
  long long sum = 0;
  for (int i = n; i >= 1; --i) {
    dp[i] += sum;
    dp[n] %= m;
    sum += dp[i];
    sum %= m;
    int l = 2;
    for (l = 2; l <= i;) {
      int r = i / (i / l);
      dp[i / l] += dp[i] * (r - l + 1) % m;
      dp[i / l] %= m;
      l = r + 1;
    }
  }
  printf("%lld\n", dp[1]);
}
