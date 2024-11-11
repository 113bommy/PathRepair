#include <bits/stdc++.h>
using namespace std;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int A[9][9];
string hook, knight;
int x, y;
int main() {
  int cnt;
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++) A[i][j] = 1;
  cin >> hook >> knight;
  x = hook[0] - 'a' + 1;
  y = hook[1] - '0';
  A[x][y] = 1;
  for (int i = 1; i <= 8; i++) {
    A[x][i] = 1;
    A[i][y] = 1;
  }
  for (int i = 0; i < 8; i++)
    if (x + dx[i] > 0 && x + dx[i] <= 8 && y + dy[i] > 0 && y + dy[i] <= 8)
      A[x + dx[i]][y + dy[i]] = 1;
  x = knight[0] - 'a' + 1;
  y = knight[1] - '0';
  A[x][y] = 1;
  for (int i = 0; i < 8; i++)
    if (x + dx[i] > 0 && x + dx[i] <= 8 && y + dy[i] > 0 && y + dy[i] <= 8)
      A[x + dx[i]][y + dy[i]] = 1;
  cnt = 0;
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++)
      if (!A[i][j]) cnt++;
  cout << cnt << endl;
  return 0;
}
