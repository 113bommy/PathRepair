#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<long long> > board(n, vector<long long>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> board[i][j];
    }
  }
  map<int, int> diag1, diag2;
  for (int i = 0; i < n; ++i) {
    long long m = i, x = i, y = 0, sum = 0;
    while (x < n && y < n) {
      sum += board[x][y];
      x++, y++;
    }
    diag1[m] = sum;
    m = i - (n - 1), x = i, y = n - 1, sum = 0;
    while (x >= 0 && y >= 0) {
      sum += board[x][y];
      x--, y--;
    }
    diag1[m] = sum;
    m = i, x = i, y = 0, sum = 0;
    while (x >= 0 && y < n) {
      sum += board[x][y];
      x--, y++;
    }
    diag2[m] = sum;
    m = i + (n - 1), x = i, y = n - 1, sum = 0;
    while (x < n && y >= 0) {
      sum += board[x][y];
      x++, y--;
    }
    diag2[m] = sum;
  }
  long long mx1 = 0, mx2 = 0;
  int x1 = 1, y1 = 1, x2 = 1, y2 = 2;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i + j) % 2) {
        long long cur = diag1[i - j] + diag2[i + j] - board[i][j];
        if (cur > mx2) {
          x2 = i + 1, y2 = j + 1, mx2 = cur;
        }
      } else {
        long long cur = diag1[i - j] + diag2[i + j] - board[i][j];
        if (cur > mx1) {
          x1 = i + 1, y1 = j + 1, mx1 = cur;
        }
      }
    }
  }
  cout << mx1 + mx2 << "\n";
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
  return 0;
}
