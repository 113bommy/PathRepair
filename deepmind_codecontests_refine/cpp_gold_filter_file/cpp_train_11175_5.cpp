#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
void print(const T& x) {
  cout << x;
}
template <typename T, typename... R>
void print(const T& x, const R&... r) {
  cout << x;
  print(r...);
}
template <typename T>
void prints(const T& x) {
  cout << x;
}
template <typename T, typename... R>
void prints(const T& x, const R&... r) {
  cout << x << ' ';
  prints(r...);
}
template <typename T>
void read(T& x) {
  cin >> x;
}
template <typename T, typename... R>
void read(T& x, R&... r) {
  cin >> x;
  read(r...);
}
const int N = 2005;
const int ROW[4] = {-1, 0, 1, 0};
const int COL[4] = {0, 1, 0, -1};
const pair<int, int> FOO = make_pair(-1, -1);
bool grid[N][N];
pair<int, int> vis[N][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  read(n, m);
  pair<int, int> start = FOO;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char x;
      read(x);
      grid[i][j] = (x != '#');
      if (x == 'S')
        start = make_pair(i, j), vis[i][j] = start;
      else
        vis[i][j] = FOO;
    }
  }
  queue<pair<int, int> > Q;
  Q.push(start);
  while (Q.size()) {
    int row = Q.front().first, col = Q.front().second;
    Q.pop();
    for (int i = 0; i < 4; i++) {
      int new_row = row + ROW[i], new_col = col + COL[i];
      int mod_row = (new_row + n * N) % n, mod_col = (new_col + m * N) % m;
      if (!grid[mod_row][mod_col]) continue;
      if (vis[mod_row][mod_col] == make_pair(new_row, new_col)) continue;
      if (vis[mod_row][mod_col] == FOO) {
        vis[mod_row][mod_col] = make_pair(new_row, new_col);
        Q.push({new_row, new_col});
      } else {
        print("Yes\n");
        return 0;
      }
    }
  }
  print("No\n");
  return 0;
}
