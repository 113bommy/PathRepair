#include <bits/stdc++.h>
using namespace std;
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int record[5][20][40];
int main() {
  char s[100015];
  vector<int> num[3];
  int len, m, d, y, ans, M, D, Y;
  while (scanf(" %s", s) != EOF) {
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 20; j++)
        for (int k = 0; k < 40; k++) record[i][j][k] = 0;
    len = strlen(s), ans = 0;
    for (int i = 0; i < 3; i++) num[i].clear();
    s[len++] = '-';
    for (int i = 0; i < len; i++) {
      if (s[i] == '-') {
        if (num[0].size() > 0 && num[1].size() == 2 && num[2].size() > 0) {
          if (num[0].size() >= 2)
            d = num[0][num[0].size() - 2] * 10 + num[0][num[0].size() - 1];
          m = num[1][0] * 10 + num[1][1];
          y = 0;
          for (int x = 0; x < 4; x++) y = y * 10 + num[2][x];
          if (2013 <= y && y <= 2015 && 1 <= m && m <= 12 && 1 <= d &&
              d <= day[m]) {
            record[y - 2013][m][d]++;
            if (record[y - 2013][m][d] > ans) {
              ans = record[y - 2013][m][d];
              M = m;
              D = d;
              Y = y;
            }
          }
        }
        num[0] = num[1];
        num[1] = num[2];
        num[2].clear();
      } else {
        num[2].push_back(s[i] - '0');
      }
    }
    printf("%02d-%02d-%d\n", D, M, Y);
  }
  return 0;
}
