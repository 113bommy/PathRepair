#include <bits/stdc++.h>
using namespace std;
int a[100010];
set<int> cuts;
bool can_measure(int len, int n) {
  for (int i = 1; i <= n; i++) {
    if (cuts.count(a[i] + len)) return true;
  }
  return false;
}
int main() {
  int n, l, x, y;
  while (scanf("%d%d%d%d", &n, &l, &x, &y) > 0) {
    cuts.clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      cuts.insert(a[i]);
    }
    if (can_measure(x, n) and can_measure(y, n)) {
      printf("0\n");
      continue;
    }
    if (can_measure(x, n)) {
      printf("1\n%d\n", y);
      continue;
    }
    if (can_measure(y, n)) {
      printf("1\n%d\n", x);
      continue;
    }
    bool test = false;
    for (int i = 1; i <= n and !test; i++) {
      if (a[i] + x < l) {
        if (cuts.count(a[i] + x - y) or cuts.count(a[i] + x + y)) {
          printf("1\n%d\n", a[i] + x);
          test = true;
          break;
        }
      }
      if (a[i] - x > 0) {
        if (cuts.count(a[i] - x - y) or cuts.count(a[i] - x + y)) {
          printf("1\n%d\n", a[i] - x);
          test = true;
          break;
        }
      }
    }
    for (int i = 1; i <= n and !test; i++) {
      if (a[i] + y < l) {
        if (cuts.count(a[i] + y - x) or cuts.count(a[i] + y + x)) {
          printf("1\n%d\n", a[i] + y);
          test = true;
          break;
        }
      }
      if (a[i] - y > 0) {
        if (cuts.count(a[i] - y - x) or cuts.count(a[i] - y + x)) {
          printf("1\n%d\n", a[i] - y);
          test = true;
          break;
        }
      }
    }
    if (!test) {
      printf("2\n%d %d\n", x, y);
    }
  }
}
