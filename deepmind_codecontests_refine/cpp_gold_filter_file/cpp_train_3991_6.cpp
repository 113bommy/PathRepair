#include <bits/stdc++.h>
using namespace std;
int n, m;
long long dp[105][2550], l;
char s[111];
int mk;
long long find(int x, int y) {
  long long ret = 0;
  if (dp[x][y] != -1) return dp[x][y];
  if (y == 0) return dp[x][y] = 1;
  if (x == 0) return dp[x][y] = 0;
  for (int i = (0); i < (min(y + 1, 26)); i++) {
    ret = (ret + find(x - 1, y - i)) % 1000000007;
  }
  return dp[x][y] = ret;
}
int main() {
  scanf("%d", &n);
  memset(dp, -1, sizeof(dp));
  for (int t = (0); t < (n); t++) {
    mk = 0;
    scanf("%s", s);
    l = strlen(s);
    for (int j = (0); j < (l); j++) mk += s[j] - 'a';
    printf("%d\n", ((int)find(l, mk) - 1 + 1000000007) % 1000000007);
  }
  return 0;
}
