#include <bits/stdc++.h>
using namespace std;
struct bg {
  double x, y;
  bool operator<(const bg& B) const { return x > B.x || x == B.x && y > B.y; }
} a[1000005];
int N;
double g[1000005];
void init() {
  int A, B, C, D;
  scanf("%d%d/%d%d/%d", &N, &A, &B, &C, &D);
  for (int i = 1, x, y; i <= N; i++) {
    scanf("%d%d", &x, &y);
    a[i].x = !D ? -x : y - 1.0 * C / D * x;
    a[i].y = y - 1.0 * A / B * x;
  }
}
void doit() {
  sort(a + 1, a + N + 1);
  int ans = 1;
  memset(g, 127, sizeof(g)), g[1] = 0;
  for (int i = 1, k; i <= N; i++)
    if (a[i].x < 0 && a[i].y > 0)
      k = lower_bound(g + 1, g + N + 1, a[i].y) - g, g[k] = a[i].y,
      ans = max(ans, k);
  printf("%d\n", ans - 1);
}
int main() {
  init();
  doit();
  return 0;
}
