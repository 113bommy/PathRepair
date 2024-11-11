#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
struct Node {
  int x, y;
  int val;
  int g;
} node[MAXN], res[MAXN];
int p[MAXN];
bool cmp(int a, int b) {
  if (node[a].val == node[b].val) {
    if (node[a].x == node[b].x) return node[a].y > node[b].y;
    return node[a].x < node[b].x;
  }
  return node[a].val < node[b].val;
}
int main() {
  for (int i = 0; i < MAXN; i++) p[i] = i;
  int n, w, h;
  int pos, T, type;
  scanf("%d %d %d", &n, &w, &h);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &type, &pos, &T);
    if (type == 1) {
      node[i].x = pos;
      node[i].y = 0;
      node[i].val = pos - T;
    } else {
      node[i].x = 0;
      node[i].y = pos;
      node[i].val = pos - T;
    }
  }
  sort(p, p + n, cmp);
  node[n].val = -2 * MAXN;
  int first_y = -1, last_y = -1, first_x = -1, last_x = -1;
  int v = node[p[0]].val, goal;
  for (int i = 0; i <= n; i++) {
    if (v != node[p[i]].val) {
      int s = last_y - first_y + 1;
      int t = last_x - first_y + 1;
      int j = first_y;
      if (first_y == -1 && last_y == -1) {
        s = 0;
        j = first_x;
      }
      if (first_x == -1 && last_x == -1) {
        s = 0;
      }
      for (; j <= last_x; j++) {
        goal = j + s;
        if (goal > last_x) goal -= t;
        node[p[j]].g = p[goal];
      }
      v = node[p[i]].val;
      first_y = -1, last_y = -1, first_x = -1, last_x = -1;
    }
    if (node[p[i]].x == 0) {
      if (first_y == -1) first_y = i;
      last_y = i;
    } else {
      if (first_x == -1) first_x = i;
    }
    last_x = i;
  }
  for (int i = 0; i < n; i++) {
    goal = node[p[i]].g;
    if (node[goal].x == 0)
      res[p[i]].x = w;
    else
      res[p[i]].x = node[goal].x;
    if (node[goal].y == 0)
      res[p[i]].y = h;
    else
      res[p[i]].y = node[goal].y;
  }
  for (int i = 0; i < n; i++) printf("%d %d\n", res[i].x, res[i].y);
}
