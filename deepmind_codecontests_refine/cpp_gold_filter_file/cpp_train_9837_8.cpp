#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
const int INF = 1e9 + 9;
string board[105];
long long color[105][105];
void paint(int x, int y) {
  long long c = -1;
  if (board[x][y] == 'W') c = 1;
  c -= color[x][y];
  for (int i = 0; i <= x; i++)
    for (int j = 0; j <= y; j++) color[i][j] += c;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> board[i];
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if ((board[i][j] == 'W' && color[i][j] != 1) ||
          (board[i][j] == 'B' && color[i][j] != -1)) {
        paint(i, j);
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
