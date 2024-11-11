#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 51;
string s[MAXN];
bool val[MAXN][MAXN];
int main() {
  int n;
  while (cin >> n) {
    vector<pair<int, int> > pieces;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      for (int j = 0; j < n; j++) {
        if (s[i][j] == 'o') {
          pieces.push_back(pair<int, int>(i, j));
        }
      }
    }
    set<pair<int, int> > moves;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] == 'x') {
          for (pair<int, int> piece : pieces) {
            moves.insert(pair<int, int>(i - piece.first, j - piece.second));
          }
        }
      }
    }
    vector<pair<int, int> > valid;
    memset(val, 0, sizeof val);
    for (pair<int, int> move : moves) {
      bool all = true;
      for (pair<int, int> piece : pieces) {
        int x = piece.first + move.first;
        int y = piece.second + move.second;
        if (x < 0 || y < 0 || x >= n || y >= n) continue;
        all &= (s[x][y] != '.');
      }
      if (all) {
        valid.push_back(move);
        for (pair<int, int> piece : pieces) {
          int x = piece.first + move.first;
          int y = piece.second + move.second;
          if (x < 0 || y < 0 || x >= n || y >= n) continue;
          val[x][y] = 1;
        }
      }
    }
    bool sw = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] == 'x') {
          sw &= val[i][j];
        }
      }
    }
    if (sw) {
      cout << "YES" << endl;
      vector<string> ans(2 * n - 1, string(2 * n - 1, '.'));
      int x = n - 1, y = n - 1;
      ans[x][y] = 'o';
      for (pair<int, int> p : valid) {
        ans[x + p.first][y + p.second] = 'x';
      }
      for (int i = 0; i < 2 * n - 1; i++) {
        cout << ans[i] << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
