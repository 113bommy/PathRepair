#include <bits/stdc++.h>
using namespace std;
int n, dp[500500];
unsigned long long pw[500500], hs[500500];
char s[500500];
const int base = 317;
map<unsigned long long, bool> mp;
inline unsigned long long Hash(int l, int r) {
  return hs[r] - hs[l - 1] * pw[r - l + 1];
}
int main() {
  pw[0] = 1;
  for (int i = 1; i < 500500; i++) pw[i] = pw[i - 1] * base;
  scanf("%d %s", &n, s + 1);
  for (int i = 1; i <= n; i++) {
    hs[i] = hs[i - 1] * base + s[i];
  }
  int ans = dp[n + 1] = 0;
  mp[0] = 1;
  for (int i = n, j = n + 1, k; i; i--) {
    for (k = dp[i + 1] + 1; k >= 1; k--) {
      while (j > i + k) {
        j--;
        int r = j + dp[j] - 1, l = j;
        while (r >= l) {
          unsigned long long x = Hash(l, r);
          bool &y = mp[x];
          if (!y)
            y = 1;
          else
            break;
          l++;
        }
      }
      if (mp[Hash(i, i + k - 2)] || mp[Hash(i + 1, i + k - 1)]) break;
    }
    dp[i] = k;
    ans = max(ans, k);
  }
  printf("%d\n", ans);
  return 0;
}
