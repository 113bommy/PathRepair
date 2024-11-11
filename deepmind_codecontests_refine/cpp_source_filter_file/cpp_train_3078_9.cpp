#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 7;
pair<pair<int, int>, int> p[N];
int n, na, nb;
bool cmp(const pair<pair<int, int>, int> &a,
         const pair<pair<int, int>, int> &b) {
  return a.first.second - a.first.first < b.first.second - b.first.first;
}
int dp[N][N], pre[N][N];
int main() {
  cin >> n >> na >> nb;
  for (int i = (1); i < (n + 1); i++) scanf("%d", &p[i].first.first);
  for (int i = (1); i < (n + 1); i++) scanf("%d", &p[i].first.second);
  for (int i = (1); i < (n + 1); i++) p[i].second = i;
  sort(p + 1, p + 1 + n, cmp);
  for (int i = (1); i < (n + 1); i++) {
    for (int j = (1); j < (min(i, na + nb) + 1); j++) {
      if (dp[i - 1][j] >
          dp[i - 1][j - 1] + (i <= na ? p[i].first.first : p[i].first.second)) {
        dp[i][j] = dp[i - 1][j];
        pre[i][j] = 1;
      } else {
        dp[i][j] =
            dp[i - 1][j - 1] + (i <= na ? p[i].first.first : p[i].first.second);
        pre[i][j] = 2;
      }
    }
  }
  printf("%d\n", dp[n][na + nb]);
  vector<int> va, vb;
  for (pair<int, int> cur = {n, na + nb}; cur.second;) {
    if (pre[cur.first][cur.second] == 2) {
      if (cur.second <= na) va.push_back(cur.first);
      if (cur.second > nb) vb.push_back(cur.first);
      cur = {cur.first - 1, cur.second - 1};
    } else {
      cur = {cur.first - 1, cur.second};
    }
  }
  for (int i = (0); i < ((int)((va).size())); i++) {
    if (i) printf(" ");
    printf("%d", p[va[i]].second);
  }
  printf("\n");
  for (int i = (0); i < ((int)((vb).size())); i++) {
    if (i) printf(" ");
    printf("%d", p[vb[i]].second);
  }
  return 0;
}
