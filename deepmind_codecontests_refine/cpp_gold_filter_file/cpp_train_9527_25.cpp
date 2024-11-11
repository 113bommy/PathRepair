#include <bits/stdc++.h>
using namespace std;
vector<vector<string> > board;
int ans = 0;
int visit[11][11][11];
int k, n, m;
void dp(int x, int y, int l) {
  int mv1[4] = {0, -1, 0, 1};
  int mv2[4] = {1, 0, -1, 0};
  for (int i = 0; i < 4; i++) {
    if (mv1[i] + x < n && mv1[i] + x >= 0 && mv2[i] + y < m &&
        mv2[i] + y >= 0 && visit[l][mv1[i] + x][mv2[i] + y] == -1 &&
        board[l][mv1[i] + x][mv2[i] + y] == '.') {
      visit[l][mv1[i] + x][mv2[i] + y] = 1;
      ans++;
      dp(mv1[i] + x, mv2[i] + y, l);
    }
  }
  if (l + 1 < k && visit[l + 1][x][y] == -1 && board[l + 1][x][y] == '.') {
    ans++;
    visit[l + 1][x][y] = 1;
    dp(x, y, l + 1);
  }
  if (l - 1 >= 0 && visit[l - 1][x][y] == -1 && board[l - 1][x][y] == '.') {
    ans++;
    visit[l - 1][x][y] = 1;
    dp(x, y, l - 1);
  }
}
int main() {
  cin >> k >> n >> m;
  memset(visit, -1, sizeof(visit));
  for (int i = 0; i < k; i++) {
    vector<string> temp;
    for (int j = 0; j < n; j++) {
      string yo;
      cin >> yo;
      temp.push_back(yo);
    }
    board.push_back(temp);
  }
  int x, y;
  cin >> x >> y;
  dp(x - 1, y - 1, 0);
  cout << max(ans, 1);
}
