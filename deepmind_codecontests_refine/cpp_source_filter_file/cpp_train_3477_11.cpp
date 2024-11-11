#include <bits/stdc++.h>
using namespace std;
set<int> k;
int sg[105][4];
int r, n;
bool maze[105][2];
int main() {
  scanf("%d%d", &r, &n);
  sg[0][0] = sg[0][1] = sg[0][2] = sg[0][3] = 0;
  sg[1][0] = 0;
  sg[1][1] = 1;
  sg[1][2] = 0;
  sg[1][3] = 1;
  sg[2][0] = 0;
  sg[2][1] = 2;
  sg[2][2] = 1;
  sg[2][3] = 0;
  int i, j;
  for (i = 3; i <= r; ++i) {
    k.clear();
    k.insert(sg[i - 1][1]);
    k.insert(sg[i - 2][1]);
    k.insert(sg[i - 1][2]);
    k.insert(sg[i - 1][3]);
    k.insert(1 ^ sg[i - 2][1]);
    for (j = 3; j < i; ++j) {
      k.insert(sg[j - 1][2] ^ sg[i - j][1]);
      k.insert(sg[j - 1][3] ^ sg[i - j][1]);
    }
    for (j = 0;; ++j)
      if (!k.count(j)) {
        sg[i][1] = j;
        break;
      }
    k.clear();
    k.insert(sg[i - 1][2]);
    k.insert(sg[i - 2][3]);
    k.insert(1 ^ sg[i - 2][2]);
    for (j = 3; j < i - 1; ++j) {
      k.insert(sg[j - 1][2] ^ sg[i - j][3]);
      k.insert(sg[j - 1][3] ^ sg[i - j][2]);
    }
    for (j = 0;; ++j)
      if (!k.count(j)) {
        sg[i][2] = j;
        break;
      }
    k.clear();
    k.insert(sg[i - 1][3]);
    k.insert(sg[i - 2][2]);
    k.insert(1 ^ sg[i - 2][3]);
    for (j = 3; j < i - 1; ++j) {
      k.insert(sg[j - 1][3] ^ sg[i - j][3]);
      k.insert(sg[j - 1][2] ^ sg[i - j][2]);
    }
    for (j = 0;; ++j)
      if (!k.count(j)) {
        sg[i][3] = j;
        break;
      }
    k.clear();
    k.insert(sg[i][1]);
    for (j = 2; j < i; ++j) k.insert(sg[j - 1][1] ^ sg[i - j][1]);
    for (j = 0;; ++j)
      if (!k.count(j)) {
        sg[i][0] = j;
        break;
      }
  }
  while (n--) {
    int x, y;
    scanf("%d%d", &x, &y);
    y--;
    maze[x][y] = 1;
    maze[x][1 - y] = 1;
    if (x - 1 >= 1) maze[x - 1][1 - y] = 1;
    if (x + 1 <= r) maze[x + 1][1 - y] = 1;
  }
  int ans = 0;
  int type = -1, cnt = 0;
  for (i = 1; i <= r; ++i) {
    if (maze[i][0] != maze[i][1]) {
      if (cnt == 0) {
        cnt++;
        if (maze[i][0])
          type = 0;
        else
          type = 1;
      } else {
        cnt++;
        if (type == -1)
          ans ^= sg[cnt][1];
        else if (maze[i][type])
          ans ^= sg[cnt][3];
        else
          ans ^= sg[cnt][2];
        cnt = 0;
        type = -1;
      }
    } else if (maze[i][0]) {
      if (cnt != 0) {
        if (type == -1)
          ans ^= sg[cnt][0];
        else
          ans ^= sg[cnt][1];
        cnt = 0;
        type = -1;
      }
    } else
      cnt++;
  }
  if (cnt != 0) {
    if (type == -1)
      ans ^= sg[cnt][0];
    else
      ans ^= sg[cnt][1];
  }
  if (ans)
    puts("WIN");
  else
    puts("LOSE");
  return 0;
}
