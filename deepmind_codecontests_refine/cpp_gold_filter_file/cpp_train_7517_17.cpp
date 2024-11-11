#include <bits/stdc++.h>
using namespace std;
string A[8];
int dx[9] = {-1, -1, -1, 0, 1, 1, 1, 0, 0};
int dy[9] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};
bool dfs(int x, int y, int tour) {
  if (x == 0 && y == 7) return 1;
  if (tour > 8) return true;
  for (int k = 0; k <= 8; k++) {
    int nx = x + dx[k], ny = y + dy[k];
    if (nx < 0 || ny < 0 || nx > 7 || ny > 7) continue;
    if (nx - tour >= 0 && A[nx - tour][ny] == 'S') continue;
    if (nx - tour - 1 >= 0 && A[nx - tour - 1][ny] == 'S') continue;
    if (dfs(nx, ny, tour + 1)) return 1;
  }
  return 0;
}
int main() {
  vector<pair<int, int> > S;
  for (int i = 0; i < 8; i++) {
    cin >> A[i];
  }
  if (dfs(7, 0, 0))
    cout << "WIN" << endl;
  else
    cout << "LOSE" << endl;
  return 0;
}
