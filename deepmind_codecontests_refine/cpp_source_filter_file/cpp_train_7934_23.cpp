#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16100100")
using namespace std;
template <typename T>
using min_heap = priority_queue<T, std::vector<T>, std::less<T> >;
template <typename T>
using max_heap = priority_queue<T, std::vector<T>, std::greater<T> >;
void init() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
string board[8];
bool visited[8][8][100];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
bool dfs(int row, int col, int t) {
  if (visited[row][col][t] || t > 100) return false;
  if (row - t >= 0 && board[row - t][col] == 'S') return false;
  visited[row][col][t] = true;
  if (row == 0 && col == 7) return true;
  for (int i = 0; i < (8); i++) {
    int r = row + dy[i];
    int c = col + dx[i];
    if (r < 0 || c < 0 || r >= 8 || c >= 8) continue;
    if (r - t >= 0 && board[r - t][c] == 'S') continue;
    if (dfs(r, c, t + 1)) return true;
  }
  return false;
}
int main() {
  init();
  for (int i = 0; i < (8); i++) cin >> board[i];
  if (dfs(7, 0, 0))
    cout << "WIN";
  else
    cout << "LOSE";
}
