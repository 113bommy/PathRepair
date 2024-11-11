#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2010;
const int GO[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int A[MAXN][MAXN], n, circleans, squareans;
bool figure[MAXN][MAXN];
pair<int, int> lefttop, rightdown, topright, downleft;
void dfs(int x, int y) {
  figure[x][y] = true;
  queue<pair<int, int> > Q;
  Q.push(make_pair(x, y));
  while (!Q.empty()) {
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    if (x < lefttop.first || (x == lefttop.first && y < lefttop.second))
      lefttop = make_pair(x, y);
    if (x > rightdown.first || (x == rightdown.first && y > rightdown.second))
      rightdown = make_pair(x, y);
    if (y < topright.second || (y == topright.second && x > topright.first))
      topright = make_pair(x, y);
    if (y > downleft.second || (y == downleft.second && x < downleft.first))
      downleft = make_pair(x, y);
    for (int i = 0; i < 4; ++i)
      if (x + GO[i][0] >= 0 && x + GO[i][0] < n && y + GO[i][1] >= 0 &&
          y + GO[i][1] < n && !figure[x + GO[i][0]][y + GO[i][1]] &&
          A[x + GO[i][0]][y + GO[i][1]]) {
        Q.push(make_pair(x + GO[i][0], y + GO[i][1]));
        figure[x + GO[i][0]][y + GO[i][1]] = true;
      }
  }
}
void recognize() {
  if (lefttop.second == topright.second) {
    squareans++;
    return;
  }
  int x = (lefttop.first + topright.first) / 2,
      y = (lefttop.second + topright.second) / 2;
  if (x - 2 >= 0 && y - 2 >= 0) {
    if (figure[x - 2][y - 2]) {
      circleans++;
      return;
    } else {
      squareans++;
      return;
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) scanf("%d", &A[i][j]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (A[i][j] && !figure[i][j]) {
        lefttop = rightdown = topright = downleft = make_pair(i, j);
        dfs(i, j);
        recognize();
      }
  cout << circleans << " " << squareans << endl;
  return 0;
}
