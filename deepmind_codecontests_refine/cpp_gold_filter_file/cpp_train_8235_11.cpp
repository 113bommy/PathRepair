#include <bits/stdc++.h>
using namespace std;
int m;
pair<int, int> dp[201][201][4][4];
vector<pair<int, int>> va;
bool o, fi;
int ta, tb;
void print(vector<pair<int, int>>& a) {
  reverse(a.begin(), a.end());
  for (auto& p : a) {
    if (fi)
      fi = 0;
    else
      printf(" ");
    printf("%d:%d", p.first, p.second);
  }
}
void go(int a, int b, int c, int d) {
  printf("%d:%d\n", c, d);
  while (a || b) {
    auto& p = dp[a][b][c][d];
    if (p.first > p.second)
      c--;
    else
      d--;
    va.emplace_back(p);
    a -= p.first;
    b -= p.second;
  }
  fi = 1;
  print(va);
  puts("");
  va.clear();
}
int main() {
  dp[0][0][0][0].first = -1;
  for (int i = 0; i <= 200; i++)
    for (int j = 0; j <= 200; j++)
      for (int k = 0; k < 3; k++)
        for (int l = 0; l < 3; l++) {
          if (dp[i][j][k][l] == make_pair(0, 0)) continue;
          if (k + l == 4)
            ta = 15;
          else
            ta = 25;
          if (i + ta <= 200)
            for (int ii = 0; ii <= ta - 2 && j + ii <= 200; ii++)
              dp[i + ta][j + ii][k + 1][l] = {ta, ii};
          if (j + ta <= 200)
            for (int ii = 0; ii <= ta - 2 && i + ii <= 200; ii++)
              dp[i + ii][j + ta][k][l + 1] = {ii, ta};
          for (int ii = ta + 1; i + ii <= 200 && j + ii - 2 <= 200; ii++)
            dp[i + ii][j + ii - 2][k + 1][l] = {ii, ii - 2};
          for (int ii = ta + 1; j + ii <= 200 && i + ii - 2 <= 200; ii++)
            dp[i + ii - 2][j + ii][k][l + 1] = {ii - 2, ii};
        }
  scanf("%d", &m);
  while (m--) {
    scanf("%d%d", &ta, &tb);
    o = 0;
    for (int i = 3; i >= 1; i--)
      if (dp[ta][tb][3][3 - i] != make_pair(0, 0)) {
        o = 1;
        go(ta, tb, 3, 3 - i);
        break;
      }
    if (o) continue;
    for (int i = 1; i <= 3; i++)
      if (dp[ta][tb][3 - i][3] != make_pair(0, 0)) {
        o = 1;
        go(ta, tb, 3 - i, 3);
        break;
      }
    if (o) continue;
    puts("Impossible");
  }
  return 0;
}
