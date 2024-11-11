#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 2e5 + 1;
using ll = long long;
int N, M, K;
string board[55];
bool fill_board(int x, int y) {
  if (x + 1 >= N || x + 2 >= N || x - 1 < 0 || x + 1 >= N) return false;
  if (board[x + 1][y] != '.' || board[x + 2][y] != '.' ||
      board[x + 1][y - 1] != '.' || board[x + 1][y + 1] != '.')
    return false;
  board[x][y] = '#';
  board[x + 1][y] = '#';
  board[x + 2][y] = '#';
  board[x + 1][y - 1] = '#';
  board[x + 1][y + 1] = '#';
  return true;
}
bool Solution() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == '.') {
        if (!fill_board(i, j)) return false;
      }
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> N) {
    for (int i = 0; i < N; ++i) {
      cin >> board[N];
    }
    if (Solution()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
