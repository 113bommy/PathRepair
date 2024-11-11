#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[]) {
  if (argc == 3) {
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
  }
  int x, y;
  scanf("%d", &x), scanf("%d", &y);
  if (x == 0 && y == 0) {
    puts("0");
    return 0;
  }
  int mx = max(abs(x), abs(y));
  int turn = (mx - 1) * 4;
  if (y == mx) {
    if (x == mx) {
      turn += 1;
    } else {
      turn += 2;
    }
  } else if (y == -mx) {
    if (x == -mx) {
      turn += 3;
    } else {
      turn += 4;
    }
  } else if (x == mx) {
    if (y > -mx + 1) {
      turn += 1;
    }
  } else if (x == -mx) {
    if (y == mx) {
      turn += 2;
    } else {
      turn += 3;
    }
  }
  printf("%d\n", turn);
  return 0;
}
