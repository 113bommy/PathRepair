#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int> > que;
pair<int, int> xx;
int fx[] = {+1, -1, +0, +0, +1, -1, -1, +1};
int fy[] = {+0, +0, +1, -1, +1, +1, -1, -1};
bool arr[1005][1005];
int n, ax, ay, bx, by, cx, cy;
void queenmove() {
  int i, j;
  j = 1;
  while (j <= n) {
    arr[ax][j] = true;
    j++;
  }
  i = 1;
  while (i <= n) {
    arr[i][ay] = true;
    i++;
  }
  i = ax;
  j = ay;
  while (i <= n && j <= n) {
    arr[i][j] = true;
    i++;
    j++;
  }
  i = ax;
  j = ay;
  while (i <= n && j >= 1) {
    arr[i][j] = true;
    i++;
    j--;
  }
  i = ax;
  j = ay;
  while (i >= 1 && j <= n) {
    arr[i][j] = true;
    i--;
    j++;
  }
  i = ax;
  j = ay;
  while (i >= 1 && j >= 1) {
    arr[i][j] = true;
    i--;
    j--;
  }
}
void bfs() {
  int i, j, ni, nj, k;
  arr[bx][by] = true;
  que.push(make_pair(bx, by));
  while (!que.empty()) {
    xx = que.front();
    i = xx.first;
    j = xx.second;
    que.pop();
    for (k = 0; k < 8; k++) {
      ni = i + fx[k];
      nj = j + fy[k];
      if (ni >= 1 && ni <= n && nj >= 1 && ni <= n) {
        if (arr[ni][nj] == false) {
          arr[ni][nj] = true;
          que.push(make_pair(ni, nj));
        }
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  scanf("%d%d", &ax, &ay);
  queenmove();
  scanf("%d%d", &bx, &by);
  scanf("%d%d", &cx, &cy);
  bfs();
  if (arr[cx][cy]) {
    printf("YES\n");
  } else
    printf("NO\n");
  return 0;
}
