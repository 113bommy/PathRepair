#include <bits/stdc++.h>
using namespace std;
int mr[100005][2];
int mc[100005][2];
int md1[200005][2];
int md2[200005][2];
struct node {
  int x;
  int y;
} q[100005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= 100005; i++) {
    mr[i][0] = 0, mc[i][0] = 0;
    mr[i][1] = 100010, mc[i][1] = 100010;
  }
  for (int i = 1; i <= 200005; i++) {
    md1[i][0] = 0, md2[i][0] = 0;
    md1[i][1] = 100010, md2[i][1] = 100010;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    q[i].x = x;
    q[i].y = y;
    mr[x][0] = mr[x][0] < y ? y : mr[x][0];
    mr[x][1] = mr[x][1] > y ? y : mr[x][1];
    mc[y][0] = mc[y][0] < x ? x : mc[y][0];
    mc[y][1] = mc[y][1] > x ? x : mc[y][1];
    md1[x + y - 1][0] = md1[x + y - 1][0] < x ? x : md1[x + y - 1][0];
    md1[x + y - 1][1] = md1[x + y - 1][1] > x ? x : md1[x + y - 1][1];
    md2[n - x + y][0] = md2[n - x + y][0] < x ? x : md2[n - x + y][0];
    md2[n - x + y][1] = md2[n - x + y][1] > x ? x : md2[n - x + y][1];
  }
  map<int, int> mmap;
  for (int i = 1; i <= m; i++) {
    int c = 0;
    int x = q[i].x;
    int y = q[i].y;
    if (mr[x][0] != mr[x][1]) {
      if (y < mr[x][0] && y > mr[x][1])
        c = c + 2;
      else
        c++;
    }
    if (mc[y][0] != mc[y][1]) {
      if (x < mc[y][0] && x > mc[y][1])
        c = c + 2;
      else
        c++;
    }
    if (md1[x + y - 1][0] != md1[x + y - 1][1]) {
      if (x < md1[x + y - 1][0] && x > md1[x + y - 1][1])
        c = c + 2;
      else
        c++;
    }
    if (md2[n - x + y][0] != md2[n - x + y][1]) {
      if (x < md2[n - x + y][0] && x > md2[n - x + y][1])
        c = c + 2;
      else
        c++;
    }
    mmap[c]++;
  }
  for (int i = 0; i <= 8; i++) printf("%d ", mmap[i]);
  return 0;
}
