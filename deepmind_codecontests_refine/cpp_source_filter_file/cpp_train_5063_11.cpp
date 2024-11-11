#include <bits/stdc++.h>
using namespace std;
int n, s[66];
long long f[66][2][2], k;
long long dp(int x, int rev, int inv) {
  long long& ans = f[x][rev][inv];
  if (~ans) return ans;
  ++ans;
  if (x * 2 >= n) return ans = 1;
  for (int i = 0; i < 2; ++i)
    if (s[x] < 0 or s[x] == i)
      for (int j = 0; j < 2; ++j)
        if (s[n - 1 - x] < 0 or s[n - x - 1] == j)
          if ((x * 2 + 1 != n or i == j) and (rev or i <= j) and
              (inv or i + j <= 1))
            ans += dp(x + 1, rev or i < j, inv or i < j + 1);
  return ans;
}
int main() {
  cin >> n >> k;
  ++k;
  memset(s, -1, sizeof(s));
  memset(f, -1, sizeof(f));
  if (dp(0, 0, 0) < k) return puts("-1") * 0;
  for (int i = 0; i < n; ++i) {
    s[i] = 0, memset(f, -1, sizeof(f));
    if (dp(0, 0, 0) < k) s[i] = 1, k -= dp(0, 0, 0);
  }
  for (int i = 0; i < n; ++i) putchar(s[i] + '0');
}
