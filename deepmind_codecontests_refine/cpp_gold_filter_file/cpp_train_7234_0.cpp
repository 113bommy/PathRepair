#include <bits/stdc++.h>
const long long mod = 1000000007;
const int maxn = 1e5 + 1;
long long inf = 1LL << 60;
using namespace std;
inline void read(int &n) {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = 10 * x + ch - '0';
    ch = getchar();
  }
  n = x * f;
}
inline void read(long long &n) {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = 10ll * x + ch - '0';
    ch = getchar();
  }
  n = x * f;
}
int a[maxn];
int dp[maxn];
int rdp[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  read(n);
  for (int i = 1; i < n + 1; i++) {
    read(a[i]);
  }
  dp[0] = 0;
  for (int i = 1; i < n + 1; i++) {
    dp[i] = min(dp[i - 1] + 1, a[i]);
  }
  rdp[n + 1] = 0;
  for (int i = n; i > 0; i--) {
    rdp[i] = min(rdp[i + 1] + 1, a[i]);
    dp[i] = min(dp[i], rdp[i + 1] + 1);
  }
  int ans = 0;
  for (int i = 1; i < n + 1; i++) {
    ans = max(ans, dp[i]);
  }
  printf("%d ", ans);
  return 0;
}
