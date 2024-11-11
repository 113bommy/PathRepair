#include <bits/stdc++.h>
using namespace std;
struct node {
  unsigned long long w;
  int no;
  bool operator<(const node &B) const { return w < B.w; }
};
int n, k;
unsigned long long l;
node A[1000007];
unsigned long long B[1000007] = {0};
unsigned long long dp[2][1000007] = {0};
int main() {
  scanf("%d%llu%d", &n, &l, &k);
  for (int i = 0; i < n; i++) {
    scanf("%llu", &A[i].w);
    A[i].no = i;
    B[i] = A[i].w;
  }
  sort(A, A + n);
  A[n].w = 0;
  unsigned long long c = l / n;
  int k0 = min(c, (unsigned long long)k);
  int m = l % n;
  unsigned long long ans = 0;
  if (!c) goto mark;
  for (int i = 0; i < n; i++) {
    dp[0][i] = i + 1;
    if (A[i].no < m)
      ans = (ans + c + 1) % 1000000007ULL;
    else
      ans = (ans + c) % 1000000007ULL;
  }
  for (unsigned long long i = 1; i < k0; i++) {
    for (int j = n - 1; j >= 0; j--) {
      if (A[j].w == A[j + 1].w)
        dp[1][j] = dp[1][j + 1];
      else
        dp[1][j] = dp[0][j];
      if (A[j].no < m)
        ans = (ans + ((c - i + 1) % 1000000007ULL) * dp[1][j]) % 1000000007ULL;
      else
        ans = (ans + ((c - i) % 1000000007ULL) * dp[1][j]) % 1000000007ULL;
    }
    dp[0][0] = dp[1][0];
    for (int j = 1; j < n; j++)
      dp[0][j] = (dp[0][j - 1] + dp[1][j]) % 1000000007ULL;
  }
  if (c <= (unsigned long long)k) {
    for (int j = n - 1; j >= 0; j--) {
      if (A[j].w == A[j + 1].w)
        dp[1][j] = dp[1][j + 1];
      else
        dp[1][j] = dp[0][j];
      if (A[j].no < m) ans += dp[1][j];
      ans %= 1000000007ULL;
    }
  }
  ans %= 1000000007ULL;
mark:
  if (!c) ans = l;
  printf("%llu\n", ans);
  return 0;
}
