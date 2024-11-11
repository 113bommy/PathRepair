#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<pair<int, int>>> inMatrix;
char rMatrix[1003][1003];
bool connect(int a, int b, int c, int d, char d1, char d2) {
  if (inMatrix[c][d].first == -1) {
    rMatrix[a][b] = d1;
    if (rMatrix[c][d] == '\0') rMatrix[c][d] = d2;
    return 1;
  } else {
    return 0;
  }
}
void dfs(int a, int b, char d) {
  if (rMatrix[a][b] != '\0') return;
  rMatrix[a][b] = d;
  pair<int, int> cur = inMatrix[a][b];
  if (b - 1 >= 1 && cur.first == inMatrix[a][b - 1].first &&
      cur.second == inMatrix[a][b - 1].second) {
    dfs(a, b - 1, 'R');
  }
  if (b + 1 <= n && cur.first == inMatrix[a][b + 1].first &&
      cur.second == inMatrix[a][b + 1].second) {
    dfs(a, b + 1, 'L');
  }
  if (a - 1 >= 1 && cur.first == inMatrix[a - 1][b].first &&
      cur.second == inMatrix[a - 1][b].second) {
    dfs(a - 1, b, 'D');
  }
  if (a + 1 <= n && cur.first == inMatrix[a + 1][b].first &&
      cur.second == inMatrix[a + 1][b].second) {
    dfs(a + 1, b, 'U');
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  inMatrix.resize(n + 1, vector<pair<int, int>>(n + 1));
  for (int i = 1, thx = n + 1; i < thx; i++) {
    for (int j = 1, thx = n + 1; j < thx; j++) {
      int a, b;
      cin >> a >> b;
      inMatrix[i][j] = {a, b};
    }
  }
  for (int i = 1, thx = n + 1; i < thx; i++) {
    for (int j = 1, thx = n + 1; j < thx; j++) {
      pair<int, int> cur = inMatrix[i][j];
      if (cur.first == -1) {
        bool can = (rMatrix[i][j] != '\0');
        if (can == false && i - 1 >= 1) can = connect(i, j, i - 1, j, 'U', 'D');
        if (can == false && i + 1 <= n) can = connect(i, j, i + 1, j, 'D', 'U');
        if (can == false && j - 1 >= 1) can = connect(i, j, i, j - 1, 'L', 'R');
        if (can == false && j + 1 <= n) can = connect(i, j, i, j + 1, 'R', 'L');
        if (can == false) {
          cout << "INVALID\n";
          return 0;
        }
      } else {
        if (cur.first == i && cur.second == j) dfs(i, j, 'X');
      }
    }
  }
  for (int i = 1, thx = n + 1; i < thx; i++) {
    for (int j = 1, thx = n + 1; j < thx; j++) {
      if (rMatrix[i][j] == '\0') {
        cout << "INVALID\n";
        return 0;
      }
    }
  }
  cout << "VALID\n";
  for (int i = 1, thx = n + 1; i < thx; i++) {
    for (int j = 1, thx = n + 1; j < thx; j++) {
      cout << rMatrix[i][j];
    }
    cout << "\n";
  }
  return 0;
}
