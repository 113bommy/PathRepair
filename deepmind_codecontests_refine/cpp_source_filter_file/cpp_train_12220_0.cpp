#include <bits/stdc++.h>
using namespace std;
struct st {
  int x, y;
} p[1001];
int x, y;
void inti() {
  p[0].x = 0;
  p[0].y = 0;
  p[1].x = 1;
  p[1].y = 0;
  p[2].x = 1;
  p[2].y = 1;
  int k = 3;
  int flag = 0, len = 2;
  while (k <= 1000) {
    if (!flag) {
      p[k].x = p[k - 1].x - len;
      p[k].y = p[k - 1].y;
      k++;
      p[k].x = p[k - 1].x;
      p[k].y = p[k - 1].y - len;
      k++;
      flag = 1;
      len++;
    } else {
      p[k].x = p[k - 1].x + len;
      p[k].y = p[k - 1].y;
      k++;
      p[k].x = p[k - 1].x;
      p[k].y = p[k - 1].y + len;
      k++;
      flag = 0;
      len++;
    }
  }
}
int f1(int i) {
  int px = x - p[i - 1].x, py = y - p[i - 1].y;
  int qx = p[i].x - p[i - 1].x, qy = p[i].y - p[i - 1].y;
  if (px * qy - qx * py == 0) return 1;
  return 0;
}
int f2(int i) {
  int px = p[i - 1].x - x, py = p[i - 1].y - y;
  int qx = p[i].x - x, qy = p[i].y - y;
  if (px * qy - qx * py <= 0) return 1;
  return 0;
}
int main() {
  inti();
  while (~scanf("%d %d", &x, &y)) {
    for (int i = 1; i < 40005; i++) {
      if (f1(i) && f2(i)) {
        printf("%d\n", i - 1);
        break;
      }
    }
  }
  return 0;
}
