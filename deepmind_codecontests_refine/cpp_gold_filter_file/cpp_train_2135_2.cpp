#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
  int num;
};
node point[303];
char str[5][105];
int t, n, k;
int flag = 0;
int Flag[5][105];
queue<node> Q;
void bfs() {
  while (!Q.empty()) {
    node D = Q.front(), R;
    Q.pop();
    if (D.x >= n) {
      flag = 1;
    }
    if (D.num == 1 && str[D.y][D.x + 1] == '.') {
      for (int j = D.y - 1; j <= D.y + 1; j++) {
        if (str[j][D.x + 1] == '.' && Flag[j][D.x + 1] == 0) {
          R.num = 2;
          R.x = D.x + 1;
          R.y = j;
          Q.push(R);
          Flag[j][D.x + 1] = 1;
        }
      }
    } else if (D.num == 2 && str[D.y][D.x + 1] == '.' &&
               str[D.y][D.x + 2] == '.') {
      R.num = 1;
      R.x = D.x + 2;
      R.y = D.y;
      Q.push(R);
    }
  }
}
int main() {
  int u, v;
  scanf("%d", &t);
  while (t--) {
    memset(Flag, 0, sizeof(Flag));
    flag = 0;
    scanf("%d%d", &n, &k);
    for (int j = 1; j <= 3; j++) scanf("%s", str[j] + 1);
    for (int i = 1; i <= 3; i++) {
      if (str[i][1] == 's') u = i;
    }
    for (int i = 1; i <= n + 1; i++) {
      str[0][i] = 'A';
      str[4][i] = 'A';
    }
    for (int i = 0; i <= 4; i++) str[i][n + 1] = '.';
    node W;
    W.x = 1;
    W.y = u;
    W.num = 1;
    Q.push(W);
    bfs();
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
