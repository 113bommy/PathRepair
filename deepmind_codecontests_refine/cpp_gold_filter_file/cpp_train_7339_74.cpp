#include <bits/stdc++.h>
using namespace std;
const int N = 8;
char Matrix[10][10];
int Column[2][10];
int Column2[2][10];
void Read() {
  for (int i = 1; i <= N; i++) Column[0][i] = Column2[1][i] = 10;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      cin >> Matrix[i][j];
      if (Matrix[i][j] == 'W') {
        if (Column[0][j] == 0) Column[0][j] = 10;
        Column[0][j] = min(Column[0][j], i);
        Column2[0][j] = max(Column2[0][j], i);
      }
      if (Matrix[i][j] == 'B') {
        Column[1][j] = max(Column[1][j], i);
        if (Column2[1][j] == 0) Column2[1][j] = 10;
        Column2[1][j] = min(Column2[1][j], i);
      }
    }
}
void Solve() {
  int moveA = 10, moveB = 10;
  for (int i = 1; i <= N; i++) {
    if (Column[0][i] == 10 && Column[1][i] == 0) continue;
    if (Column[0][i] < Column2[1][i]) moveA = min(moveA, Column[0][i] - 1);
    if (Column[1][i] > Column2[0][i]) moveB = min(moveB, N - Column[1][i]);
  }
  if (moveA <= moveB)
    cout << "A\n";
  else
    cout << "B\n";
}
int main() {
  Read();
  Solve();
  return 0;
}
