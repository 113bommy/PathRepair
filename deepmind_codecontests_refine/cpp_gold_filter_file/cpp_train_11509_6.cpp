#include <bits/stdc++.h>
using namespace std;
int n, k;
int sz[260000];
bool visited[501][501];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int arr[501][501], comp[501][501], inside[260000];
bool onBorder[260000];
int C = 1;
int ans = 0;
deque<int> top, bottom;
int cnt = 0;
void flood(int x, int y) {
  queue<pair<int, int> > q;
  q.push(make_pair(x, y));
  visited[x][y] = true;
  int s = 0;
  while (!q.empty()) {
    int X = q.front().first;
    int Y = q.front().second;
    q.pop();
    comp[X][Y] = C;
    cnt--;
    s++;
    for (int i = 0; i < 4; i++) {
      if (X + dx[i] >= 0 && X + dx[i] < n && Y + dy[i] >= 0 && Y + dy[i] < n &&
          !visited[X + dx[i]][Y + dy[i]] && arr[X + dx[i]][Y + dy[i]] == 0) {
        visited[X + dx[i]][Y + dy[i]] = true;
        q.push(make_pair(X + dx[i], Y + dy[i]));
      }
    }
  }
  sz[C] = s;
  ans = max(ans, s);
  C++;
}
inline void getOnBorder(int x, int y, pair<int, int> dir, vector<int> &a) {
  for (int i = 0; i < k; i++) {
    if (arr[x + dir.first * i][y + dir.second * i] == 0) {
      if (!onBorder[comp[x + dir.first * i][y + dir.second * i]]) {
        a.push_back(comp[x + dir.first * i][y + dir.second * i]);
        onBorder[comp[x + dir.first * i][y + dir.second * i]] = true;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      arr[i][j] = ((s[j] == '.') ? 0 : 1);
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (!visited[i][j] && arr[i][j] == 0) flood(i, j);
    }
  for (int i = 0; i < n - k + 1; i++) {
    for (int r = 0; r < k; r++)
      for (int c = 0; c < k; c++)
        if (!arr[i + r][c]) inside[comp[i + r][c]]++;
    for (int j = 0; j < n - k + 1; j++) {
      vector<int> border;
      if (i - 1 >= 0) {
        getOnBorder(i - 1, j, {0, 1}, border);
      }
      if (i + k < n) {
        getOnBorder(i + k, j, {0, 1}, border);
      }
      if (j - 1 >= 0) {
        getOnBorder(i, j - 1, {1, 0}, border);
      }
      if (j + k < n) {
        getOnBorder(i, j + k, {1, 0}, border);
      }
      int sum = k * k;
      for (int l = 0; l < border.size(); l++) {
        sum += sz[border[l]] - inside[border[l]];
        onBorder[border[l]] = false;
      }
      ans = max(ans, sum);
      for (int l = 0; l < k; l++) {
        inside[comp[i + l][j]]--;
        if (j + k < n) inside[comp[i + l][j + k]]++;
      }
    }
    for (int r = 0; r < 260000; r++) inside[r] = 0, onBorder[r] = false;
    ;
  }
  cout << ans;
  return 0;
}
