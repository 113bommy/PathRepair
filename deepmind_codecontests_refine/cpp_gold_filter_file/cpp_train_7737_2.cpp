#include <bits/stdc++.h>
using namespace std;
int matrix[1010][1010];
long long dp[1010][1010];
int dp2[1010][1010];
int rev[1010][1010];
int main(void) {
  int n, m, a, b;
  scanf("%d %d %d %d", &m, &n, &b, &a);
  memset(dp, 0, sizeof(dp));
  for (int(y) = (0); (y) <= (m - 1); ++(y)) {
    for (int(x) = (0); (x) <= (n - 1); ++(x)) {
      scanf("%d", &matrix[x + 1][y + 1]);
      dp[x + 1][y + 1] =
          matrix[x + 1][y + 1] + dp[x + 1][y] + dp[x][y + 1] - dp[x][y];
      if (x >= a - 1) {
        int mi = 2000000000;
        for (int(i) = (x - a + 1); (i) <= (x); ++(i)) {
          mi = min(mi, matrix[i + 1][y + 1]);
        }
        dp2[(x - a + 1) + 1][y + 1] = mi;
      }
    }
  }
  vector<pair<long long, pair<int, int> > > s;
  for (int(x) = (0); (x) <= (n - a); ++(x)) {
    for (int(y) = (0); (y) <= (m - b); ++(y)) {
      long long cost =
          dp[x + a][y + b] - dp[x + a][y] - dp[x][y + b] + dp[x][y];
      int mi = 2000000000;
      for (int(i) = (y); (i) <= (y + b - 1); ++(i)) {
        mi = min(mi, dp2[x + 1][i + 1]);
      }
      cost -= (long long)(mi)*a * b;
      s.push_back(make_pair(cost, make_pair(y, x)));
    }
  }
  sort(s.begin(), s.end());
  vector<pair<long long, pair<int, int> > > answers;
  int p = 0;
  while (p < s.size()) {
    while (p < s.size() &&
           matrix[s[p].second.second + 1][s[p].second.first + 1] < 0)
      ++p;
    if (p < s.size()) {
      answers.push_back(s[p]);
      for (int(dx) = (-(a - 1)); (dx) <= (a - 1); ++(dx)) {
        for (int(dy) = (-(b - 1)); (dy) <= (b - 1); ++(dy)) {
          int xx = s[p].second.second + dx;
          int yy = s[p].second.first + dy;
          if (xx >= 0 && yy >= 0) matrix[xx + 1][yy + 1] = -1;
        }
      }
      ++p;
    }
  }
  printf("%d\n", answers.size());
  for (int(k) = (0); (k) <= (answers.size() - 1); ++(k)) {
    printf("%d %d %I64d\n", answers[k].second.first + 1,
           answers[k].second.second + 1, answers[k].first);
  }
}
