#include <bits/stdc++.h>
using namespace std;
int read() {
  int ret = 0, sig = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') sig = 1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    ret = (ret << 3) + (ret << 1) + ch - 48;
    ch = getchar();
  }
  if (sig) return -ret;
  return ret;
}
const int maxn = 2000 + 10;
const int inf = 0x3f3f3f3f;
long long dp[maxn], a[maxn], n, k;
bool Check(long long t) {
  dp[1] = 0;
  for (int i = 2; i <= n; ++i) {
    dp[i] = i - 1;
    for (int j = i - 1; j >= 1; --j) {
      if (abs(a[i] - a[j]) <= (i - j) * t) {
        dp[i] = min(dp[i], dp[j] + (i - j - 1));
      }
    }
    if (dp[i] + (n - i) <= k) return true;
  }
  return false;
}
int main() {
  long long l = 0, r = 0, mid, ans;
  n = read();
  k = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    if (i != 1) r = max(a[i] - a[i - 1], r);
  }
  while (l <= r) {
    mid = (l + r) >> 1;
    if (Check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%I64d\n", ans);
  return 0;
}
