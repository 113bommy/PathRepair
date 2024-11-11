#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  int n, m, x, y, moves = 0, ans;
  bool square[1001][1001] = {false}, ok = false;
  cin >> n >> m;
  while (m--) {
    cin >> x >> y;
    square[x][y] = true;
    moves++;
    for (int i = x - 2; i <= x; i++) {
      if (ok) break;
      for (int j = y - 2; j <= y; j++) {
        if (ok) break;
        if (i < 1 || j < 1 || i > 997 || j > 997)
          continue;
        else if (moves >= 9) {
          ok = true;
          for (int u = i; u < i + 3; u++) {
            for (int v = j; v < j + 3; v++) {
              if (!square[u][v]) {
                ok = false;
                break;
              }
            }
            if (!ok) break;
          }
          if (ok) {
            ans = moves;
            break;
          }
        }
      }
    }
  }
  if (ok)
    cout << ans << endl;
  else
    cout << "-1" << endl;
}
