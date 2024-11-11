#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int to[N][5];
int to2[N][5];
int head[N], head2[N];
int ans[N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (m); i++) {
    int x;
    int y;
    scanf("%d%d", &x, &y);
    to[x][++head[x]] = y;
    to[y][++head[y]] = x;
  }
  int Up = 210;
  srand(time(0));
  if (n >= 50000) Up = 150;
  for (int T = (1); T <= (Up); T++) {
    for (int i = (1); i <= (n); i++) ans[i] = i;
    random_shuffle(ans + 1, ans + 1 + n);
    ans[n + 1] = ans[1];
    int flag = 1;
    for (int i = (1); i <= (m); i++) {
      int x;
      int y;
      x = ans[i];
      y = ans[i + 1];
      for (int j = (1); j <= (head[x]); j++)
        if (to[x][j] == y) {
          flag = 0;
          break;
        }
    }
    if (flag) {
      for (int i = (1); i <= (m); i++) printf("%d %d\n", ans[i], ans[i + 1]);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
