#include <bits/stdc++.h>
using namespace std;
int n, m;
char str[2005][2005];
char res[2005][2005];
int deg[2005][2005];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
queue<pair<int, int> > q;
int main() {
  ios::sync_with_stdio(false);
  int i, j, k, x, y, c = INT_MAX, cnt = 0, ans = 0;
  string t, e;
  cin >> n >> m;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      cin >> str[i][j];
      res[i][j] = str[i][j];
    }
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (str[i][j] == '.') {
        cnt++;
        for (int k = 0; k < 4; k++) {
          if (str[i + dx[k]][j + dy[k]] == '.') deg[i][j]++;
        }
        if (deg[i][j] == 1) {
          q.push({i, j});
        }
      }
    }
  }
  while (!q.empty()) {
    pair<int, int> pr = q.front();
    q.pop();
    if (res[pr.first + 1][pr.second] == '.') {
      cnt -= 2;
      res[pr.first][pr.second] = '^';
      res[pr.first + 1][pr.second] = 'v';
      for (int k = 0; k < 4; k++) {
        if (res[pr.first + 1 + dx[k]][pr.second + dy[k]] == '.') {
          deg[pr.first + 1 + dx[k]][pr.second + dy[k]]--;
          if (deg[pr.first + 1 + dx[k]][pr.second + dy[k]] == 1)
            q.push({pr.first + 1 + dx[k], pr.second + dy[k]});
        }
      }
    } else if (res[pr.first - 1][pr.second] == '.') {
      cnt -= 2;
      res[pr.first - 1][pr.second] = '^';
      res[pr.first][pr.second] = 'v';
      for (int k = 0; k < 4; k++) {
        if (res[pr.first - 1 + dx[k]][pr.second + dy[k]] == '.') {
          deg[pr.first - 1 + dx[k]][pr.second + dy[k]]--;
          if (deg[pr.first - 1 + dx[k]][pr.second + dy[k]] == 1)
            q.push({pr.first - 1 + dx[k], pr.second + dy[k]});
        }
      }
    } else if (res[pr.first][pr.second + 1] == '.') {
      cnt -= 2;
      res[pr.first][pr.second] = '<';
      res[pr.first][pr.second + 1] = '>';
      for (int k = 0; k < 4; k++) {
        if (res[pr.first + dx[k]][pr.second + 1 + dy[k]] == '.') {
          deg[pr.first + dx[k]][pr.second + 1 + dy[k]]--;
          if (deg[pr.first + dx[k]][pr.second + 1 + dy[k]] == 1)
            q.push({pr.first + dx[k], pr.second + 1 + dy[k]});
        }
      }
    } else if (res[pr.first][pr.second - 1] == '.') {
      cnt -= 2;
      res[pr.first][pr.second] = '>';
      res[pr.first][pr.second - 1] = '<';
      for (int k = 0; k < 4; k++) {
        if (res[pr.first + dx[k]][pr.second - 1 + dy[k]] == '.') {
          deg[pr.first + dx[k]][pr.second - 1 + dy[k]]--;
          if (deg[pr.first + dx[k]][pr.second - 1 + dy[k]] == 1)
            q.push({pr.first + dx[k], pr.second - 1 + dy[k]});
        }
      }
    }
  }
  if (cnt != 0) {
    cout << "Not unique";
  } else {
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        cout << res[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
