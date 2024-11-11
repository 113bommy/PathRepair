#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
struct Square {
  int x1, y1, x2, y2;
  Square() {}
  Square(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
} v[N], pref[N], suff[N];
Square gen(Square a, Square b) {
  int nx1 = max(a.x1, b.x1);
  int nx2 = min(a.x2, b.x2);
  int ny1 = max(a.y1, b.y1);
  int ny2 = min(a.y2, b.y2);
  return Square(nx1, ny1, nx2, ny2);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    v[i] = Square(x1, y1, x2, y2);
  }
  pref[0] = v[0];
  for (int i = 1; i < n; ++i) {
    pref[i] = gen(pref[i - 1], v[i]);
  }
  suff[n - 1] = v[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    suff[i] = gen(suff[i + 1], v[i]);
  }
  Square at;
  for (int i = 1; i < n - 1; ++i) {
    at = gen(pref[i - 1], suff[i + 1]);
    if (at.x1 <= at.x2 && at.y1 <= at.y2) {
      printf("%d %d\n", at.x1, at.y1);
      return 0;
    }
  }
  at = pref[n - 2];
  if (at.x1 <= at.x2 && at.y1 <= at.y2) {
    printf("%d %d\n", at.x1, at.y1);
    return 0;
  }
  at = suff[1];
  if (at.x1 <= at.x2 && at.y1 <= at.y2) {
    printf("%d %d\n", at.x1, at.y1);
    return 0;
  }
}
