#include <bits/stdc++.h>
using namespace std;
int g[50][50], dp[1 << 20];
int cur;
void add(int first, int second, int d) {
  for (int i = 0; i < d; i++) {
    g[first][second + i] = ++cur;
  }
}
int dx[] = {1, 0, 1, 1}, dy[] = {0, 1, 1, -1};
int main(void) {
  add(1, 1, 3);
  add(2, 1, 4);
  add(3, 1, 5);
  add(4, 2, 4);
  add(5, 3, 3);
  vector<int> c;
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j < 20; j++) {
      if (g[i][j]) {
        for (int d = 0; d < 3; d++) {
          int first = 0;
          for (int m = 0; m < 8; m++) {
            int t = g[i + dx[d] * m][j + dy[d] * m];
            if (!t) {
              break;
            }
            first |= 1 << (t - 1);
            c.push_back(first);
          }
        }
      }
    }
  }
  for (int i = 0; i < (1 << 19); i++) {
    for (int j = 0; j < (int)c.size(); j++) {
      int first = c[j];
      if ((i & first) == first && !dp[i ^ first]) {
        dp[i] = 1;
      }
    }
  }
  int first = 0;
  for (int i = 0; i < 19; i++) {
    string s;
    cin >> s;
    if (s != ".") {
      first |= 1 << i;
    }
  }
  puts(dp[first] ? "Karlsson" : "Lillebror");
  return 0;
}
