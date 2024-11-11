#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, a[N][N], b[N][N];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void Change(int i, int j) {
  int x, y;
  for (int k = 0, b_ = 7; k <= b_; ++k) {
    x = i + dx[k];
    y = j + dy[k];
    b[x][y] = 1;
  }
}
bool Check(int i, int j) {
  int x, y;
  for (int k = 0, b_ = 7; k <= b_; ++k) {
    x = i + dx[k];
    y = j + dy[k];
    if (a[i][j] == 0) return false;
  }
  return true;
}
int main() {
  cin >> m >> n;
  char ch;
  for (int i = 1, b_ = m; i <= b_; ++i)
    for (int j = 1, b_ = n; j <= b_; ++j) {
      cin >> ch;
      if (ch == '#') a[i][j] = 1;
    }
  for (int i = 2, b_ = m - 1; i <= b_; ++i)
    for (int j = 2, b_ = n - 1; j <= b_; ++j) {
      if (Check(i, j)) Change(i, j);
    }
  for (int i = 1, b_ = m; i <= b_; ++i)
    for (int j = 1, b_ = n; j <= b_; ++j)
      if (a[i][j] == 1) {
        if (b[i][j] == 0) {
          cout << "NO";
          return 0;
        }
      }
  cout << "YES";
}
