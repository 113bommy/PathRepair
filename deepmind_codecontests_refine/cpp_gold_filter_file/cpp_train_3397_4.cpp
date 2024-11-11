#include <bits/stdc++.h>
using namespace std;
char board[33][33];
int ok[256];
char str[500005];
int main() {
  int n, m, x;
  while (cin >> n >> m >> x) {
    for (int i = 0; i < n; i++) scanf("%s", board[i]);
    memset(ok, -1, sizeof(ok));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (islower(board[i][j])) ok[board[i][j]] = 0;
        if (board[i][j] == 'S') {
          for (int u = 0; u < n; u++) {
            for (int v = 0; v < m; v++) {
              if ((i - u) * (i - u) + (j - v) * (j - v) <= x * x) {
                ok[board[u][v] - 'a' + 'A'] = 0;
              } else {
                if (ok[board[u][v] - 'a' + 'A'] < 0)
                  ok[board[u][v] - 'a' + 'A'] = 1;
              }
            }
          }
        }
      }
    }
    int q;
    scanf("%d", &q);
    scanf("%s", str);
    int res = 0;
    bool p = true;
    for (int i = 0; i < q; i++) {
      if (ok[str[i]] < 0) {
        p = false;
        break;
      }
      res += ok[str[i]];
    }
    printf("%d\n", p ? res : -1);
  }
  return 0;
}
