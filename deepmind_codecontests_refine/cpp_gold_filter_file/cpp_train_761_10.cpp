#include <bits/stdc++.h>
using namespace std;
int n;
int x[3001], y[3001];
int board[2001][2001];
int middle(int i, int j) {
  int dx = abs(x[i] - x[j]);
  int dy = abs(y[i] - y[j]);
  if (dx % 2 != 0 || dy % 2 != 0) return 0;
  dx = dx / 2, dy = dy / 2;
  return board[min(x[i], x[j]) + dx][min(y[i], y[j]) + dy];
}
int main() {
  memset(board, 0, sizeof(board));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    x[i] += 1000, y[i] += 1000;
    board[x[i]][y[i]] = 1;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cnt += middle(i, j);
    }
  }
  cout << cnt << endl;
  return 0;
}
