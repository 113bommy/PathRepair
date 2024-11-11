#include <bits/stdc++.h>
using namespace std;
struct Point {
  Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
  int x, y;
};
Point ps[10];
bool cmp(const Point& a, const Point& b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
void solvex(int a, int b, int c) {
  if (ps[c].y == ps[a].y)
    puts("2");
  else if (ps[c].y == ps[b].y)
    puts("2");
  else if (ps[a].y > ps[b].y) {
    if (ps[c].y > ps[a].y || ps[c].y < ps[b].y)
      puts("2");
    else
      puts("3");
  } else {
    if (ps[c].y > ps[b].y || ps[c].y < ps[a].y)
      puts("2");
    else
      puts("3");
  }
}
void solvey(int a, int b, int c) {
  if (ps[c].x == ps[a].x)
    puts("2");
  else if (ps[c].x == ps[b].x)
    puts("2");
  else if (ps[a].x > ps[b].x) {
    if (ps[c].x > ps[a].x || ps[c].x < ps[b].x)
      puts("2");
    else
      puts("3");
  } else {
    if (ps[c].x > ps[b].x || ps[c].x < ps[a].x)
      puts("2");
    else
      puts("3");
  }
}
int main() {
  scanf("%d %d", &ps[0].x, &ps[0].y);
  scanf("%d %d", &ps[1].x, &ps[1].y);
  scanf("%d %d", &ps[2].x, &ps[2].y);
  if (ps[0].x == ps[1].x && ps[1].x == ps[2].x) {
    puts("1");
    return 0;
  }
  if (ps[0].y == ps[1].y && ps[1].y == ps[2].y) {
    puts("1");
    return 0;
  }
  if (ps[0].x == ps[1].x) {
    solvex(0, 1, 2);
  } else if (ps[1].x == ps[2].x) {
    solvex(1, 2, 0);
  } else if (ps[0].x == ps[2].x) {
    solvex(0, 2, 1);
  } else if (ps[0].y == ps[1].y) {
    solvey(0, 1, 2);
  } else if (ps[1].y == ps[2].y) {
    solvey(1, 2, 0);
  } else if (ps[0].y == ps[2].y) {
    solvey(0, 2, 1);
  } else
    puts("3");
  return 0;
}
