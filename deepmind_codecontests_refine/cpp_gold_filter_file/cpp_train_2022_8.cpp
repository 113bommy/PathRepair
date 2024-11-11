#include <bits/stdc++.h>
using namespace std;
void in(int &x) {
  register int c = getchar();
  x = 0;
  for (; (c < 48 || c > 57); c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
}
const int N = 1 << 24;
long long dp[N];
string s[10004];
int main() {
  int n, i, j, mask, full = N - 1;
  in(n);
  for (i = 0; i < n; i++) {
    cin >> s[i];
    mask = 0;
    for (j = 0; j < 3; j++) mask |= 1 << (s[i][j] - 'a');
    mask ^= full;
    dp[mask]++;
  }
  for (i = 0; i < 24; i++) {
    for (mask = 0; mask < N; mask++)
      if (!(mask & (1 << i))) {
        dp[mask] += dp[mask ^ (1 << i)];
      }
  }
  long long ret = 0;
  for (i = 0; i < N; i++) ret ^= 1ll * (n - dp[i]) * (n - dp[i]);
  printf("%lld\n", ret);
  return 0;
}
