#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  int operator-(point a) { return abs(a.x - x) + abs(a.y - y); }
  int add() { return x + y; }
  int minus() { return x - y; }
} c[100005], h[100005], s;
int min1, max1, min2, max2, ans, MAX[100005];
int main() {
  int m, n, C, H;
  scanf("%d%d", &n, &m);
  scanf("%d", &C);
  for (int i = 0; i < C; i++) {
    scanf("%d%d", &c[i].x, &c[i].y);
    if (c[i].add() > c[max1].add()) max1 = i;
    if (c[i].add() < c[min1].add()) min1 = i;
    if (c[i].minus() > c[max2].minus()) max2 = i;
    if (c[i].minus() < c[min2].minus()) min2 = i;
  }
  scanf("%d", &H);
  for (int i = 0; i < H; i++) {
    scanf("%d%d", &h[i].x, &h[i].y);
    MAX[i] = std::max(
        h[i] - c[max1],
        std::max(h[i] - c[max2], std::max(h[i] - c[min1], h[i] - c[min2])));
    if (MAX[i] < MAX[ans]) ans = i;
  }
  printf("%d\n%d", MAX[ans], ans + 1);
  return 0;
}
