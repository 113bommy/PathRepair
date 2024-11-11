#include <bits/stdc++.h>
using namespace std;
const int MAX_P = 201;
int dp[MAX_P][MAX_P][3][6];
pair<int, int> score[MAX_P][MAX_P][3][6];
int vis[MAX_P][MAX_P][3][6];
int matchPoint[2] = {25, 15};
int getRes(int a, int b, int lost, int matches) {
  if (matches == 0) {
    vis[a][b][lost][matches] = 1;
    dp[a][b][lost][matches] = a == 0 && b == 0;
    score[a][b][lost][matches] = make_pair(-1, -1);
    return dp[a][b][lost][matches];
  }
  if (a == 0 && b == 0) {
    return dp[a][b][lost][matches] = 0;
  }
  if (vis[a][b][lost][matches]) {
    return dp[a][b][lost][matches];
  }
  int res = 0;
  pair<int, int> validScore;
  if (matches == lost) {
    for (int first = 0; first <= a; ++first) {
      int toWin = matchPoint[matches == 5];
      int second = max(first + 2, toWin);
      if (second <= b && getRes(a - first, b - second, lost - 1, matches - 1)) {
        res = 1;
        validScore = make_pair(first, second);
        break;
      }
    }
  } else {
    for (int second = 0; second <= b; ++second) {
      int toWin = matchPoint[matches == 5];
      int first = max(second + 2, toWin);
      if (first <= a && getRes(a - first, b - second, lost, matches - 1)) {
        res = 1;
        validScore = make_pair(first, second);
        break;
      }
    }
  }
  score[a][b][lost][matches] = validScore;
  vis[a][b][lost][matches] = true;
  return dp[a][b][lost][matches] = res;
}
void solve() {
  int a, b;
  cin >> a >> b;
  for (int won = 3; won >= 0; --won) {
    for (int opp = 0; opp + won <= 5; ++opp) {
      if (won != 3 && opp != 3) {
        continue;
      }
      int first = a;
      int second = b;
      int lost = opp;
      int matches = won + opp;
      if (won < opp) {
        swap(first, second);
        lost = won;
      }
      if (getRes(first, second, lost, matches)) {
        vector<pair<int, int> > scores;
        int lim = matches;
        for (int i = 0; i < lim; ++i) {
          pair<int, int> s = score[first][second][lost][matches];
          scores.push_back(s);
          first -= s.first;
          second -= s.second;
          if (matches == lost) {
            lost--;
          }
          matches--;
        }
        cout << won << ":" << opp << "\n";
        for (int i = scores.size() - 1; i >= 0; --i) {
          auto s = scores[i];
          if (won < opp) {
            swap(s.first, s.second);
          }
          cout << s.first << ":" << s.second << " ";
        }
        cout << "\n";
        return;
      }
    }
  }
  cout << "Impossible\n";
}
int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < MAX_P; ++i) {
    for (int j = 0; j < MAX_P; ++j) {
      for (int k = 0; k < 3; ++k) {
        for (int t = 0; t < 6; ++t) {
          vis[i][j][k][t] = 0;
        }
      }
    }
  }
  int T;
  cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    solve();
  }
  return 0;
}
