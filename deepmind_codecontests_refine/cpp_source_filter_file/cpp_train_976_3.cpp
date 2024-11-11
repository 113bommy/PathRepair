#include <bits/stdc++.h>
using namespace std;
const int MOD(1000000007);
const int INF((1 << 30) - 1);
const int MAXN(150);
int a[2][MAXN][MAXN];
int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  int K = 67, now = 1, prev = 0, Move = 1;
  a[prev][K][K] = n;
  int MAX = 0;
  while (Move) {
    Move = 0;
    for (int i = K - 66; i <= K + 66; i++)
      for (int j = K - 66; j <= K + 66; j++) {
        int k = a[prev][i][j] / 4;
        if (k > 0) {
          Move = 1;
          a[now][i + 1][j] += k;
          a[now][i - 1][j] += k;
          a[now][i][j + 1] += k;
          a[now][i][j - 1] += k;
          a[now][i][j] += a[prev][i][j] - 4 * k;
        } else
          a[now][i][j] += a[prev][i][j];
        a[prev][i][j] = 0;
      }
    now ^= 1, prev ^= 1;
  }
  while (t--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x += 67, y += 67;
    if (x < 0 || x > 133 || y < 0 || y > 133)
      printf("-1\n");
    else
      printf("%d\n", a[prev][x][y]);
  }
}
