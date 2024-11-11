#include <bits/stdc++.h>
using namespace std;
int board[35][35];
int column[35];
int row[35];
int main() {
  int n;
  cin >> n;
  int num = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> board[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      column[i] += board[i][j];
      row[i] += board[j][i];
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (column[i] > row[j]) num++;
  cout << num << endl;
  return 0;
}
