#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
  int x, y;
};
node p[222];
int check(node a) {
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (p[i].x > a.x && p[i].y == a.y) res |= 1;
    if (p[i].x > a.x && p[i].y == a.y) res |= 2;
    if (p[i].x == a.x && p[i].y > a.y) res |= 4;
    if (p[i].x == a.x && p[i].y < a.y) res |= 8;
  }
  return res == 15;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y);
  int cnt = 0;
  for (int i = 0; i < n; i++) cnt += check(p[i]);
  printf("%d\n", cnt);
  return 0;
}
