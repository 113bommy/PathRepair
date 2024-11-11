#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e4 + 10, MAXL = 800;
int dp[MAXN][MAXL];
int n, d;
int a[MAXN];
int find(int now, int dis) {
  if (now > 30000 || dis == 0) return 0;
  return dp[now][dis - d + 400];
}
int main() {
  int a1;
  cin >> n >> d;
  for (int i = 1; i <= n; ++i) {
    cin >> a1;
    ++a[a1];
  }
  for (int j = 30000; j >= d; --j)
    for (int i = (d > 400 ? d - 400 : 1); i < d + 400; ++i) {
      dp[j][i - d + 400] =
          a[j] + max(find(j + i - 1, i - 1),
                     max(find(j + i, i), find(j + i + 1, i + 1)));
    }
  cout << dp[d][400];
  return 0;
}
