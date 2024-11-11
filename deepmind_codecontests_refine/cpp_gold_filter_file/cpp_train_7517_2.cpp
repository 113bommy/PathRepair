#include <bits/stdc++.h>
using namespace std;
bool valid(int r, int c) { return min(r, c) >= 0 && max(r, c) < 8; }
int main() {
  ios::sync_with_stdio(0);
  vector<string> A(8);
  for (auto& s : A) cin >> s;
  vector<vector<string>> G(9);
  G[0] = A;
  for (int i = 1; i < 9; i++) {
    G[i] = G[i - 1];
    for (int r = 7; r >= 0; r--)
      for (int c = 0; c < 8; c++)
        if (G[i][r][c] == 'S') {
          G[i][r][c] = '.';
          if (r + 1 < 8) G[i][r + 1][c] = 'S';
        }
  }
  int R[11][11][11] = {};
  int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
  int dc[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
  queue<vector<int>> q;
  q.push({0, 7, 0});
  while (!q.empty()) {
    int g = q.front()[0];
    int r = q.front()[1];
    int c = q.front()[2];
    q.pop();
    if (g == 8) return cout << "WIN\n", 0;
    for (int k = 0; k < 9; k++)
      if (valid(r + dr[k], c + dc[k]) &&
          G[g + 1][r + dr[k]][c + dc[k]] != 'S' &&
          G[g][r + dr[k]][c + dc[k]] != 'S' && !R[g + 1][r + dr[k]][c + dc[k]])
        R[g + 1][r + dr[k]][c + dc[k]] = 1,
                                q.push({g + 1, r + dr[k], c + dc[k]});
  }
  cout << "LOSE\n";
}
