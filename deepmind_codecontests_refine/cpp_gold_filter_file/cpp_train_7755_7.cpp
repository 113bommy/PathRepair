#include <bits/stdc++.h>
using namespace std;
const int SIZE = 51;
const int INF = 100000000;
string s, solution;
int n;
int val[25][3];
int highscore = -1000000000;
map<pair<int, int>, pair<string, int> > dp;
void dfs(int depth, int dif1, int dif2, int L) {
  if (depth == n / 2) {
    if (dp.find({dif1, dif2}) == dp.end()) {
      dp[{dif1, dif2}] = {s, L};
    } else if (dp[{dif1, dif2}].second < L) {
      dp[{dif1, dif2}] = {s, L};
    }
    return;
  }
  s += '1';
  dfs(depth + 1, dif1 - val[depth][1], dif2 + val[depth][1] - val[depth][2], L);
  s = s.substr(0, s.length() - 1);
  s += '2';
  dfs(depth + 1, dif1 + val[depth][0], dif2 - val[depth][2], L + val[depth][0]);
  s = s.substr(0, s.length() - 1);
  s += '3';
  dfs(depth + 1, dif1 + val[depth][0] - val[depth][1], dif2 + val[depth][1],
      L + val[depth][0]);
  s = s.substr(0, s.length() - 1);
}
void dfs2(int depth, int dif1, int dif2, int L) {
  if (depth == n) {
    if (dp.count({-dif1, -dif2}) == 1) {
      if (dp[{-dif1, -dif2}].second + L > highscore) {
        solution = dp[{-dif1, -dif2}].first + s;
        highscore = dp[{-dif1, -dif2}].second + L;
      }
    }
    return;
  }
  s += '1';
  dfs2(depth + 1, dif1 - val[depth][1], dif2 + val[depth][1] - val[depth][2],
       L);
  s = s.substr(0, s.length() - 1);
  s += '2';
  dfs2(depth + 1, dif1 + val[depth][0], dif2 - val[depth][2],
       L + val[depth][0]);
  s = s.substr(0, s.length() - 1);
  s += '3';
  dfs2(depth + 1, dif1 + val[depth][0] - val[depth][1], dif2 + val[depth][1],
       L + val[depth][0]);
  s = s.substr(0, s.length() - 1);
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> val[i][j];
    }
  }
  dfs(0, 0, 0, 0);
  dfs2(n / 2, 0, 0, 0);
  if (highscore == -1000000000) {
    cout << "Impossible";
  } else {
    for (int i = 0; i < n; i++) {
      switch (solution[i]) {
        case '1':
          cout << "MW\n";
          break;
        case '2':
          cout << "LW\n";
          break;
        default:
          cout << "LM\n";
          break;
      }
    }
  }
  return 0;
}
