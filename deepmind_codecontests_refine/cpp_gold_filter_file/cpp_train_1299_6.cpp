#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
char mp[1010][1010];
int up[1010][1010];
int Left[1010][1010];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%s", mp[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mp[i][j] == '*') {
        up[i][j] = up[i - 1][j] + 1;
        Left[i][j] = Left[i][j - 1] + 1;
      } else {
        up[i][j] = up[i - 1][j];
        Left[i][j] = Left[i][j - 1];
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mp[i][j] == '*') {
        ans += (long long)(Left[i][m] - 1) * (up[n][j] - 1);
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
