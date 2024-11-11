#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000009;
int n, m, a[251][251];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int k = 0; k < 3; k++) {
      for (int j = 1; j <= m; j++) {
        char ch = '#';
        while (ch != 'O' && ch != '.') ch = getchar();
        if (ch == 'O') a[i][j] |= 1 << k * 3;
        if (getchar() == 'O') a[i][j] |= 1 << k * 3 + 1;
        if (getchar() == 'O') a[i][j] |= 1 << k * 3 + 2;
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int tmp = a[i][j];
      if (tmp == 0104 || tmp == 0124 || tmp == 0555) a[i][j] = 1;
      if (tmp == 0401 || tmp == 0421 || tmp == 0707) a[i][j] = 2;
      if (tmp == 0000 || tmp == 0020 || tmp == 0505 || tmp == 0525) a[i][j] = 3;
    }
  long long dp[251] = {1};
  for (int j = 1; j <= m; j++) {
    long long tag = (n + 1) % 2;
    for (int i = 1; i <= n && tag; i++) tag = a[i][j] & 1;
    dp[j] = dp[j - 1] * tag;
    if (j == 1) continue;
    long long cnt[251] = {1};
    for (int i = 1; i <= n; i++) {
      cnt[i] = cnt[i - 1] * (a[i][j] & a[i][j - 1] & 2) / 2;
      if (i == 1) continue;
      bool v = a[i][j] & a[i][j - 1] & a[i - 1][j] & a[i - 1][j - 1] & 1;
      if (!v) tag = 0;
      cnt[i] = (cnt[i] + cnt[i - 2] * v) % mod;
    }
    dp[j] = (dp[j] + dp[j - 2] * (cnt[n] - tag)) % mod;
  }
  printf("%I64d\n", dp[m]);
}
