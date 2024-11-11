#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
int res[101][10014];
int one[10014];
int pre[10014];
int idx[10014];
string s;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    cnt = 0;
    int c = -1;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == '1')
        one[cnt++] = c = j;
      else {
        pre[j] = c;
        idx[j] = cnt - 1;
      }
    }
    if (cnt == 0) {
      printf("-1\n");
      return 0;
    }
    for (int j = 0; j < m; ++j) {
      if (s[j] == '1')
        res[i][j] = 0;
      else {
        if (pre[j] == -1)
          res[i][j] = min(one[0] - j, m - one[cnt - 1] + j);
        else if (one[cnt - 1] < j)
          res[i][j] = min(j - pre[j], one[0] + m - j);
        else
          res[i][j] = min(j - pre[j], one[idx[j] + 1] - j);
      }
    }
  }
  int sum;
  int ans = 1000000;
  for (int i = 0; i < m; ++i) {
    sum = 0;
    for (int j = 0; j < n; ++j) sum += res[j][i];
    if (sum < ans) ans = sum;
  }
  printf("%d\n", ans);
  return 0;
}
