#include <bits/stdc++.h>
using namespace std;
int num[10];
int dx[5] = {0, -1, 1, 1, -1};
int dy[5] = {0, -1, -1, 1, 1};
int dir;
int x[2000], y[2000];
int k, a, b;
bool done;
bool vis[2000][2000];
void scan() {
  scanf("%d %d %d", &k, &a, &b);
  if (k == -1 || k == 0) {
    exit(0);
  } else {
    vis[x[k]][y[k]] = 0;
    x[k] = a;
    y[k] = b;
    vis[x[k]][y[k]] = 1;
  }
}
void check() {
  done = 1;
  for (int i = 1; i <= 6; i++) {
    if (x[i] > x[0] && y[i] > y[0]) num[1]++;
    if (x[i] < x[0] && y[i] > y[0]) num[2]++;
    if (x[i] < x[0] && y[i] < y[0]) num[3]++;
    if (x[i] > x[0] && y[i] < y[0]) num[4]++;
  }
  num[0] = 1000;
  for (int i = 1; i <= 4; i++) {
    if (num[i] < num[0]) {
      num[0] = num[i];
      dir = i;
    }
  }
}
void move() {
  if (done) {
    if (vis[x[0] + dx[dir]][y[0] + dy[dir]])
      x[0] += dx[dir];
    else
      x[0] += dx[dir], y[0] += dy[dir];
    printf("%d %d\n", x[0], y[0]);
    fflush(stdout);
    scan();
  } else {
    if (x[0] < 500) {
      if (y[0] < 500) {
        if (vis[x[0] + 1][y[0] + 1] == 1)
          x[0] = x[0] + 1, y[0] = y[0];
        else
          x[0] = x[0] + 1, y[0] = y[0] + 1;
      } else if (y[0] > 500) {
        if (vis[x[0] + 1][y[0] - 1] == 1)
          x[0] = x[0] + 1, y[0] = y[0];
        else
          x[0] = x[0] + 1, y[0] = y[0] - 1;
      } else
        x[0] = x[0] + 1, y[0] = y[0];
    } else if (x[0] > 500) {
      if (y[0] < 500) {
        if (vis[x[0] - 1][y[0] + 1] == 1)
          x[0] = x[0] - 1, y[0] = y[0];
        else
          x[0] = x[0] - 1, y[0] = y[0] + 1;
      } else if (y[0] > 500) {
        if (vis[x[0] - 1][y[0] - 1] == 1)
          x[0] = x[0] - 1, y[0] = y[0];
        else
          x[0] = x[0] - 1, y[0] = y[0] - 1;
      } else
        x[0] = x[0] - 1, y[0] = y[0];
    } else {
      if (y[0] < 500)
        x[0] = x[0], y[0] = y[0] + 1;
      else if (y[0] > 500)
        x[0] = x[0], y[0] = y[0] - 1;
      else
        x[0] = x[0], y[0] = y[0];
    }
    printf("%d %d\n", x[0], y[0]);
    fflush(stdout);
    scan();
    if (x[0] == 500 && y[0] == 500) {
      check();
    }
  }
}
int main() {
  scanf("%d%d", &x[0], &y[0]);
  for (int i = 1; i <= 6; i++) {
    scanf("%d%d", &x[i], &y[i]);
    vis[x[i]][y[i]] = 1;
  }
  if (x[0] == 500 && y[0] == 500) {
    check();
  }
  while (1) {
    move();
  }
  return 0;
}
