#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
};
node a[1001];
int n;
int dir(int i) {
  int j = (i + 1) % (n + 1);
  if (a[i].x == a[j].x) {
    if (a[i].y < a[j].y)
      return 0;
    else
      return 1;
  } else {
    if (a[i].x < a[j].x)
      return 2;
    else
      return 3;
  }
  return 0;
}
int init() {
  scanf("%d", &n);
  for (int i = 0; i <= n; i += 1) {
    scanf("%d", &a[i].x);
    scanf("%d", &a[i].y);
  }
  int c = 0;
  int cycle = dir(1) == 2 ? 0 : 1;
  int p = 0;
  if (cycle == 0) {
    for (int i = 1; i <= n - 1; i += 1) {
      int d = dir(i);
      if (d == 0 && p == 2) {
        p = 0;
        c++;
      } else if (d == 1 && p == 3) {
        p = 1;
        c++;
      } else if (d == 2 && p == 1) {
        p = 2;
        c++;
      } else if (d == 3 && p == 0) {
        p = 3;
        c++;
      }
      p = d;
    }
  } else {
    for (int i = 1; i <= n; i += 1) {
      int d = dir(i);
      if (d == 0 && p == 3) {
        p = 0;
        c++;
      } else if (d == 1 && p == 2) {
        p = 1;
        c++;
      } else if (d == 2 && p == 0) {
        p = 2;
        c++;
      } else if (d == 3 && p == 1) {
        p = 3;
        c++;
      }
      p = d;
    }
  }
  cout << c;
  return 0;
}
int main() {
  init();
  return 0;
}
