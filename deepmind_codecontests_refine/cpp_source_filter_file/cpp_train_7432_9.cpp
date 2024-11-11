#include <bits/stdc++.h>
using namespace std;
struct line {
  int x1, x2, y1, y2;
};
int w, h, n;
bool can[200][200][4];
bool use[200][200];
int bfs(int y, int x) {
  int queue[100 * 100 + 10][2];
  int head = 1, tail = 2, i, j;
  queue[1][0] = y;
  queue[1][1] = x;
  int res = 1;
  while (head < tail) {
    i = queue[head][0];
    j = queue[head][1];
    head++;
    if (can[i][j][0] && !use[i + 1][j]) {
      queue[tail][0] = i + 1;
      queue[tail++][1] = j;
      use[i + 1][j] = true;
      res++;
    }
    if (can[i][j][3] && !use[i - 1][j]) {
      queue[tail][0] = i - 1;
      queue[tail++][1] = j;
      use[i - 1][j] = true;
      res++;
    }
    if (can[i][j][1] && !use[i][j - 1]) {
      queue[tail][0] = i;
      queue[tail++][1] = j - 1;
      use[i][j - 1] = true;
      res++;
    }
    if (can[i][j][2] && !use[i][j + 1]) {
      queue[tail][0] = i;
      queue[tail++][1] = j + 1;
      use[i][j + 1] = true;
      res++;
    }
  }
  return res;
}
int main() {
  int i, j, k;
  vector<int> res;
  line lines[200];
  scanf("%d %d %d", &w, &h, &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d %d %d", &lines[i].x1, &lines[i].y1, &lines[i].x2,
          &lines[i].y2);
  }
  lines[i].x1 = 0;
  lines[i].x2 = w;
  lines[i].y1 = 0;
  lines[i++].y2 = 0;
  lines[i].x1 = 0;
  lines[i].x2 = w;
  lines[i].y1 = h;
  lines[i++].y2 = h;
  lines[i].x1 = 0;
  lines[i].x2 = 0;
  lines[i].y1 = 0;
  lines[i++].y2 = h;
  lines[i].x1 = w;
  lines[i].x2 = w;
  lines[i].y1 = 0;
  lines[i++].y2 = h;
  for (i = 1; i <= h; i++)
    for (j = 1; j <= w; j++) {
      can[i][j][0] = true;
      can[i][j][3] = true;
      can[i][j][1] = true;
      can[i][j][2] = true;
      for (k = 0; k < n + 4; k++) {
        if (i == lines[k].y1 && j <= lines[k].x2 && j >= lines[k].x1 &&
            lines[k].y1 == lines[k].y2)
          can[i][j][0] = false;
        if (i - 1 == lines[k].y1 && j <= lines[k].x2 && j >= lines[k].x1 &&
            lines[k].y1 == lines[k].y2)
          can[i][j][3] = false;
        if (i > lines[k].y1 && i <= lines[k].y2 && j == lines[k].x1 &&
            lines[k].x1 == lines[k].x2)
          can[i][j][2] = false;
        if (i >= lines[k].y1 && i <= lines[k].y2 && j - 1 == lines[k].x1 &&
            lines[k].x1 == lines[k].x2)
          can[i][j][1] = false;
      }
    }
  for (i = 1; i <= h; i++)
    for (j = 1; j <= w; j++) {
      if (!use[i][j]) {
        use[i][j] = true;
        res.push_back(bfs(i, j));
      }
    }
  sort(res.begin(), res.end());
  for (i = 0; i < res.size(); i++) printf("%d ", res[i]);
  return 0;
}
