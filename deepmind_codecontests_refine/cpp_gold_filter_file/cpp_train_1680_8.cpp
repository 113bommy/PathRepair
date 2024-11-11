#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int _inf = 0xc0c0c0c0;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long _INF = 0xc0c0c0c0c0c0c0c0;
const long long mod = (int)1e9 + 7;
const int N = 550;
struct Node {
  long long a, b, k;
  bool operator<(const Node& x) const { return b > x.b; }
} A[N];
int n;
long long dp[N][N];
void Ac() {
  for (int i = 1; i <= n; ++i)
    scanf("%I64d%I64d%I64d", &A[i].a, &A[i].b, &A[i].k);
  sort(A + 1, A + 1 + n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n + 1; ++j) {
      dp[i][j] = dp[i - 1][j] + max(0ll, A[i].a - A[i].k * A[i].b);
      if (j)
        dp[i][j] = max(dp[i][j],
                       dp[i - 1][j - 1] + max(0ll, A[i].a - (j - 1) * A[i].b));
    }
  }
  long long ans = 0;
  for (int i = 01; i <= n + 1; ++i) ans = max(ans, dp[n][i]);
  printf("%I64d\n", ans);
}
int main() {
  while (~scanf("%d", &n)) {
    Ac();
  }
  return 0;
}
