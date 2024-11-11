#include <bits/stdc++.h>
using namespace std;
struct __timestamper {};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
char s[200][200];
char c[200];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    scanf("%s", c);
    vector<int> order(4);
    for (int i = 0; i < 4; i++) {
      order[i] = i;
    }
    int ans = 0;
    do {
      int x, y;
      x = y = -1;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (s[i][j] == 'S') {
            x = i;
            y = j;
            break;
          }
        }
      }
      bool bad = true;
      for (int i = 0; c[i]; i++) {
        x += dx[order[c[i] - '0']];
        y += dy[order[c[i] - '0']];
        if (!(0 <= x && x < n)) {
          break;
        }
        if (!(0 <= y && y < m)) {
          break;
        }
        if (s[x][y] == '#') {
          break;
        }
        if (s[x][y] == 'E') {
          bad = false;
          break;
        }
      }
      if (!bad) {
        ans += 1;
      }
    } while (next_permutation(order.begin(), order.end()));
    printf("%d\n", ans);
  }
  return 0;
}
