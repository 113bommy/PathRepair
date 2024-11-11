#include <bits/stdc++.h>
using namespace std;
long long dp[1010][1010];
int n, m;
long long k;
int d[1010][1010];
int cnt;
long long s[1010][1010];
char st[1010];
pair<int, int> a[1000010];
inline int cmp(pair<int, int> x, pair<int, int> y) {
  int dt = d[x.first][y.first];
  if (dt >= x.second || dt >= y.second) return x.second > y.second;
  return st[x.first + dt] > st[y.first + dt];
}
int check(int num) {
  memset(dp, 0, sizeof(dp));
  int len = a[num].second, pos = a[num].first;
  s[n + 1][0] = 1;
  for (int i = n; i; i--) {
    int t = min(len, d[pos][i]);
    if (t == len || st[i + t] > st[pos + t]) {
      for (int j = 1; j <= m; j++) dp[i][j] = s[i + t + 1][j - 1];
    }
    for (int j = 0; j <= m; j++) s[i][j] = min(s[i + 1][j] + dp[i][j], k);
  }
  return dp[1][m] >= k;
}
int main() {
  scanf("%d%d%lld", &n, &m, &k);
  scanf("%s", st + 1);
  for (int i = n; i; i--)
    for (int j = n; j; j--)
      d[i][j] = (st[i] == st[j] ? d[i + 1][j + 1] + 1 : 0);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) a[++cnt] = make_pair(i, j - i + 1);
  sort(a + 1, a + cnt + 1, cmp);
  int l = 1, r = cnt;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  r--;
  for (int i = a[r].first; i < a[r].first + a[r].second; i++) putchar(st[i]);
  putchar('\n');
}
