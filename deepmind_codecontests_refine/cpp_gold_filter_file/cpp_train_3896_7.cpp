#include <bits/stdc++.h>
using namespace std;
int d[8][8];
int diferencias[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                         {1, 0},  {1, -1}, {0, -1}, {-1, -1}};
int main() {
  int x1, y1, x2, y2;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  x1--;
  x2--;
  y1--;
  y2--;
  if (x1 == x2 && y1 == y2) {
    printf("0 0 0\n");
    return 0;
  }
  if (x1 == x2 || y1 == y2) {
    printf("1 ");
  } else {
    printf("2 ");
  }
  if (abs(x1 - x2) == abs(y1 - y2)) {
    printf("1 ");
  } else {
    bool p1 = x1 % 2 == y1 % 2;
    bool p2 = x2 % 2 == y2 % 2;
    if (p1 == p2) {
      printf("2 ");
    } else {
      printf("0 ");
    }
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      d[i][j] = 100;
    }
  }
  d[x1][y1] = 0;
  deque<pair<int, int>> q;
  q.push_front(make_pair(x1, y1));
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop_front();
    for (int i = 0; i < 8; i++) {
      int newy = y + diferencias[i][0];
      int newx = x + diferencias[i][1];
      if (newx >= 0 && newy >= 0 && newx < 8 && newy < 8) {
        if (d[x][y] + 1 < d[newx][newy]) {
          d[newx][newy] = d[x][y] + 1;
          q.push_back(make_pair(newx, newy));
        }
      }
    }
  }
  printf("%d\n", d[x2][y2]);
  return 0;
}
