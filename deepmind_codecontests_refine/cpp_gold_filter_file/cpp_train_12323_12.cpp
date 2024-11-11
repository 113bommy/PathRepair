#include <bits/stdc++.h>
using namespace std;
int main() {
  string board[8];
  bool f = 1;
  for (int(i) = 0; (i) < (8); (i)++) {
    cin >> board[i];
    if (board[i][0] == board[i][7]) f = 0;
    for (int(j) = 0; (j) < (7); (j)++) {
      if (board[i][j] == board[i][j + 1]) f = 0;
    }
  }
  if (f)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
