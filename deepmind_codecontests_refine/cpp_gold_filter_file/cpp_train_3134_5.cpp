#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, q;
int best[15][N], dp[9][5100005];
vector<int> pr[N];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    for (int j = 2; j * j <= x; ++j) {
      if (x % j == 0) {
        int c = 0;
        while (x % j == 0) x /= j, ++c;
        if (c & 1) pr[i].push_back(j);
      }
    }
    if (x > 1) pr[i].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 15; ++j) best[j][i] = best[j][i - 1];
    int ST = 1 << pr[i].size();
    for (int s = 0; s < ST; ++s) {
      int val = 1, c = pr[i].size();
      for (int j = 0; j < pr[i].size(); ++j) {
        if ((s >> j) & 1) val *= pr[i][j], --c;
      }
      for (int j = 0; j < 8; ++j) {
        best[j + c][i] = max(best[j + c][i], dp[j][val]);
      }
      dp[c][val] = max(dp[c][val], i);
    }
  }
  for (int l, r; q; --q) {
    scanf("%d%d", &l, &r);
    for (int i = 0; i < 15; ++i) {
      if (best[i][r] >= l) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}
