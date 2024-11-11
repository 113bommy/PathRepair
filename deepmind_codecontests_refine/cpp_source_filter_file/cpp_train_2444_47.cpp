#include <bits/stdc++.h>
using namespace std;
const int dx[10] = {0, 0, 0, 1, -1};
const int dy[10] = {0, 1, 1, 0, 0};
char ch[1000][1000];
bool visit[1000];
int n, m, father[1000 * 10];
int find(int x) {
  if (father[x] == x) return x;
  return father[x] = find(father[x]);
}
int dfs(char col) {
  for (int i = 1; i <= 10000; i++) father[i] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (ch[i][j] == col) {
        for (int k = 2; k <= 3; k++) {
          int x = i + dx[k], y = j + dy[k], xx = find(x * m + y),
              yy = find(i * m + j);
          if (ch[x][y] != col) continue;
          if (xx == yy)
            return 1;
          else
            father[xx] = yy;
        }
      }
    }
  }
  return 0;
}
int main() {
  int ans = 0, finish = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!visit[(int)ch[i][j]]) {
        if (dfs(ch[i][j])) ans = 1, finish = 1;
        visit[(int)ch[i][j]] = 1;
      }
    }
    if (finish == 1) break;
  }
  if (ans)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
