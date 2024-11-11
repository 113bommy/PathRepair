#include <bits/stdc++.h>
using namespace std;
const int maxn = 3008;
const int maxm = 100086;
const int inf = 0x3f3f3f3f;
const long long Inf = 999999999999999999;
const int mod = 1000000007;
const double eps = 1e-6;
const double pi = acos(-1);
long long a[maxn], b[maxn];
long long dp[maxn][maxn];
long long minn[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    a[i] -= i;
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  int m = unique(b + 1, b + 1 + n) - b - 1;
  minn[0] = Inf;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      minn[j] = min(minn[j - 1], dp[i - 1][j]);
    }
    for (int j = 1; j <= m; j++) {
      dp[i][j] = minn[j] + abs(a[i] - b[j]);
    }
  }
  for (int j = 1; j <= m; j++) {
    minn[j] = min(minn[j - 1], dp[n][j]);
  }
  printf("%lld\n", minn[m]);
  return 0;
}
