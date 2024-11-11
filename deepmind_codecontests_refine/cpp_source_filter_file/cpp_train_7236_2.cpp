#include <bits/stdc++.h>
using namespace std;
int main() {
  int ax, ay, bx, by, cx, cy;
  while (cin >> ax >> ay >> bx >> by >> cx >> cy) {
    if (ax == bx && bx == cx) {
      puts("1");
    } else if (ay == by && by == cy) {
      puts("1");
    } else if (ax == bx) {
      if (cy < max(ay, by) && cy > min(ay, by)) {
        puts("3");
      } else
        puts("2");
    } else if (ay == by) {
      if (cx > min(ax, bx) && cx < max(ax, bx)) {
        puts("3");
      } else
        puts("2");
    } else if (ax == cx) {
      if (by < max(ay, cy) && by > min(ay, cy)) {
        puts("3");
      } else
        puts("2");
    } else if (ay == cy) {
      if (bx > min(ax, cx) && bx < max(ax, cx)) {
        puts("3");
      } else
        puts("2");
    } else if (cx == bx) {
      if (ay < max(by, cy) && ay > min(by, cy)) {
        puts("3");
      } else
        puts("2");
    } else if (cy == by) {
      if (ax < max(cx, bx) && ax > min(bx, cx)) {
        puts("3");
      }
      puts("2");
    } else {
      puts("3");
    }
  }
  return 0;
}
