#include <bits/stdc++.h>
using namespace std;
namespace acm {
char ch[200][200];
int r, c;
int dp[200][200];
void update(int &a, int b) { a = min(a, b); }
void solve() {
  memset((dp), (0x3f), sizeof(dp));
  dp[0][0] = 0;
  pair<int, int> pos = make_pair(-1, -1);
  for (int i = 0; i < (int)(r); ++i) {
    if (i & 1) {
      for (int j = c - 1; j >= 0; --j)
        if (ch[i][j] == 'W') pos = make_pair(i, j);
    } else {
      for (int j = 0; j < (int)(c); ++j)
        if (ch[i][j] == 'W') pos = make_pair(i, j);
    }
  }
  for (int j = 0; j < (int)(c); ++j) {
    dp[0][j] = j;
    if (pos == make_pair(0, j)) {
      printf("%d\n", j);
      return;
    }
  }
  if (pos == make_pair(0, 0)) {
    printf("0\n");
    return;
  }
  for (int i = 1; i < r; ++i) {
    if (i & 1) {
      for (int j = c - 1; j >= 0; --j) {
        if (j != c - 1) dp[i][j] = dp[i][j + 1] + 1;
        int flag = 1;
        for (int k = j + 1; k < c; ++k) {
          if (ch[i - 1][k] == 'W' || ch[i][k] == 'W') {
            flag = 0;
            break;
          }
        }
        if (flag) update(dp[i][j], dp[i - 1][j] + 1);
        if (make_pair(i, j) == pos) {
          printf("%d\n", dp[i][j]);
          return;
        }
      }
    } else {
      for (int j = 0; j < (int)(c); ++j) {
        if (j) {
          dp[i][j] = dp[i][j - 1] + 1;
        }
        int flag = 1;
        for (int k = 0; k < j; ++k) {
          if (ch[i - 1][k] == 'W' || ch[i][k] == 'W') {
            flag = 0;
            break;
          }
        }
        if (flag) update(dp[i][j], dp[i - 1][j] + 1);
        if (make_pair(i, j) == pos) {
          printf("%d\n", dp[i][j]);
          return;
        }
      }
    }
  }
}
void icpc() {
  while (~scanf("%d%d", &r, &c)) {
    for (int i = 0; i < (int)(r); ++i) scanf("%s", ch[i]);
    solve();
  }
}
};  // namespace acm
int main() {
  acm::icpc();
  return 0;
}
