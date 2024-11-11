#include <bits/stdc++.h>
using namespace std;
char mp[110][110], l1[2], k, p;
int a, b, c, d, e, l[4][2] = {1, 0, 0, 1, -1, 0, 0, -1}, ans;
void dfs(int x1, int y1) {
  char o = mp[x1][y1];
  mp[x1][y1] = '.';
  for (int x = 0; x < 4; x++) {
    if (mp[x1 + l[x][0]][y1 + l[x][1]] == o) {
      dfs(x1 + l[x][0], y1 + l[x][1]);
    }
  }
}
int main() {
  scanf("%d%d%s", &a, &b, l1);
  for (int x = 0; x < a; x++) {
    scanf("%s", mp[x]);
  }
  for (int x = 0; x < a; x++)
    for (int y = 0; y < b; y++)
      for (int z = 0; z < 4; z++) {
        if (mp[x + l[z][0]][y + l[z][1]] == l1[0] && mp[x][y] != l1[0] &&
            mp[x][y] != '.') {
          ans++;
          dfs(x, y);
        }
      }
  printf("%d", ans);
}
