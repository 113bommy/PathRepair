#include <bits/stdc++.h>
using namespace std;
int n, i, x, y;
bool fr[1010][1010];
long long int sol = 0;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &x, &y);
    fr[x][y] = true;
  }
  for (int i = 1; i <= 1000; i++) {
    int x = 1, y = i, nr = 0;
    while (x <= 1000 && y <= 1000) {
      if (fr[x][y]) nr++;
      x++;
      y++;
    }
    sol = sol + 1LL * nr * (nr - 1) / 2;
  }
  for (int i = 1000; i >= 1; i--) {
    int x = 1, y = i, nr = 0;
    while (x <= 1000 && y >= 1) {
      if (fr[x][y]) nr++;
      x++;
      y--;
    }
    sol = sol + 1LL * nr * (nr - 1) / 2;
  }
  for (int i = 2; i <= 1000; i++) {
    int x = i, y = 1, nr = 0;
    while (x <= 1000 && y <= 1000) {
      if (fr[x][y]) nr++;
      x++;
      y++;
    }
    sol = sol + 1LL * nr * (nr - 1) / 2;
  }
  for (int i = 2; i <= 1000; i++) {
    int x = i, y = 1000, nr = 0;
    while (x <= 1000 && y >= 1) {
      if (fr[x][y]) nr++;
      x++;
      y--;
    }
    sol = sol + 1LL * nr * (nr - 1) / 2;
  }
  printf("%I64d", sol);
  return 0;
}
