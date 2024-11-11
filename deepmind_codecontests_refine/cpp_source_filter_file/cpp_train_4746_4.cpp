#include <bits/stdc++.h>
using namespace std;
map<vector<string>, int> mp;
void init() {
  string a, b, c;
  vector<string> ooxx;
  ooxx.clear();
  a = "...";
  b = "...";
  c = "...";
  ooxx.push_back(a);
  ooxx.push_back(b);
  ooxx.push_back(c);
  mp[ooxx] = 0;
  ooxx.clear();
  a = "...";
  b = ".O.";
  c = "...";
  ooxx.push_back(a);
  ooxx.push_back(b);
  ooxx.push_back(c);
  mp[ooxx] = 0;
  {
    ooxx.clear();
    a = "..O";
    b = "...";
    c = "O..";
    ooxx.push_back(a);
    ooxx.push_back(b);
    ooxx.push_back(c);
    mp[ooxx] = 1;
    ooxx.clear();
    a = "O..";
    b = "...";
    c = "..O";
    ooxx.push_back(a);
    ooxx.push_back(b);
    ooxx.push_back(c);
    mp[ooxx] = 2;
  }
  {
    ooxx.clear();
    a = "..O";
    b = ".O.";
    c = "O..";
    ooxx.push_back(a);
    ooxx.push_back(b);
    ooxx.push_back(c);
    mp[ooxx] = 1;
    ooxx.clear();
    a = "O..";
    b = ".O.";
    c = "..O";
    ooxx.push_back(a);
    ooxx.push_back(b);
    ooxx.push_back(c);
    mp[ooxx] = 2;
  }
  ooxx.clear();
  a = "O.O";
  b = "...";
  c = "O.O";
  ooxx.push_back(a);
  ooxx.push_back(b);
  ooxx.push_back(c);
  mp[ooxx] = 0;
  ooxx.clear();
  a = "O.O";
  b = ".O.";
  c = "O.O";
  ooxx.push_back(a);
  ooxx.push_back(b);
  ooxx.push_back(c);
  mp[ooxx] = 0;
  {
    ooxx.clear();
    a = "O.O";
    b = "O.O";
    c = "O.O";
    ooxx.push_back(a);
    ooxx.push_back(b);
    ooxx.push_back(c);
    mp[ooxx] = 1;
    ooxx.clear();
    a = "OOO";
    b = "...";
    c = "OOO";
    ooxx.push_back(a);
    ooxx.push_back(b);
    ooxx.push_back(c);
    mp[ooxx] = 2;
  }
}
int n, m;
char graph[2010][2010];
int mark[310][310];
void judge(int x, int y, int p, int q) {
  vector<string> ooxx;
  string s;
  for (int i = 0; i < 3; i++) {
    s = "";
    for (int j = 0; j < 3; j++) s += graph[x + i][y + j];
    ooxx.push_back(s);
  }
  mark[p][q] = mp[ooxx];
}
long long one[310];
long long two[310];
int main() {
  init();
  scanf("%d %d", &n, &m);
  for (int i = 0; i < 4 * n + 1; i++) scanf("%s", graph[i]);
  int x, y;
  x = -3;
  for (int i = 0; i < n; i++) {
    x += 4;
    y = -3;
    for (int j = 0; j < m; j++) {
      y += 4;
      judge(x, y, i, j);
    }
  }
  for (int j = 0; j < m; j++) {
    if (n & 1) {
      one[j] = 0;
      continue;
    }
    bool flag = true;
    for (int i = 0; i < n && flag; i++) {
      if (mark[i][j] == 2) flag = false;
    }
    if (flag)
      one[j] = 1;
    else
      one[j] = 0;
  }
  for (int j = 0; j < m - 1; j++) {
    long long dp[310];
    memset(dp, 0, sizeof(dp));
    if (mark[0][j] != 1 && mark[0][j + 1] != 1) dp[0] = 1;
    if (mark[1][j] != 1 && mark[1][j + 1] != 1) dp[1] = dp[0];
    if (mark[2][j] != 2 && mark[2][j + 1] != 2 && mark[1][j] != 2 &&
        mark[1][j + 1] != 2)
      dp[1]++;
    for (int i = 2; i < n; i++) {
      if (mark[i][j] != 1 && mark[i][j + 1] != 1)
        dp[i] = (dp[i] + dp[i - 1]) % 1000000007;
      if (mark[i][j] != 2 && mark[i][j + 1] != 2 && mark[i - 1][j] != 2 &&
          mark[i - 1][j + 1] != 2)
        dp[i] = (dp[i] + dp[i - 2]) % 1000000007;
    }
    two[j] = dp[n - 1];
  }
  long long ddp[310];
  memset(ddp, 0, sizeof(ddp));
  ddp[0] = one[0];
  ddp[1] = two[0];
  for (int i = 2; i < m; i++)
    ddp[i] = (one[i] * ddp[i - 1] + two[i - 1] * ddp[i - 2] -
              one[i] * one[i - 1] * ddp[i - 2]) %
             1000000007;
  printf("%I64d\n", ddp[m - 1]);
  return 0;
}
