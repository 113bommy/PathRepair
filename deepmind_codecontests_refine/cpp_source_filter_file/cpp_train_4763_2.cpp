#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 3;
const long long MOD = 998244353;
int board[4][52];
int n;
vector<pair<int, pair<int, int> > > moves;
bool flag;
void make_move(int a, int b, int x, int y) {
  if (board[a][b] == 0 && board[x][y] == 0) return;
  moves.push_back(
      pair<int, pair<int, int> >(board[a][b], pair<int, int>(x, y)));
  board[x][y] = board[a][b];
  board[a][b] = 0;
  flag = true;
}
void enter() {
  for (int i = 0; i < n; i++) {
    if (board[0][i] == board[1][i]) {
      make_move(1, i, 0, i);
    }
    if (board[3][i] == board[2][i]) {
      make_move(2, i, 3, i);
    }
  }
}
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
void print() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      printf("%2d ", board[i][j]);
    }
    puts("");
  }
  puts("");
}
void move() {
  int f = -1, c = -1;
  for (int i = 0; i < n; i++) {
    if (board[1][i] == 0) {
      f = 1;
      c = i;
      break;
    }
    if (board[2][i] == 0) {
      f = 1;
      c = i;
      break;
    }
  }
  if (f == -1) return;
  int d;
  if (f == 1)
    d = 0;
  else
    d = 2;
  for (int t = 0; t < 2 * n - 1; t++) {
    int nf = f + dx[d];
    int nc = c + dy[d];
    if (nf >= 1 && nf <= 2 && nc >= 0 && nc < n) {
      make_move(nf, nc, f, c);
      f = nf;
      c = nc;
    } else {
      t--;
      d = (d + 1) % 4;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> n >> k;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  flag = true;
  while (flag) {
    flag = false;
    enter();
    move();
  }
  if (moves.size()) {
    cout << moves.size() << '\n';
    for (auto x : moves) {
      cout << x.first << " " << x.second.first + 1 << " " << x.second.second + 1
           << '\n';
    }
  } else {
    cout << -1 << '\n';
  }
}
