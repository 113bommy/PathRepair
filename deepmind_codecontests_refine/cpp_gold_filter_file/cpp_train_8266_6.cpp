#include <bits/stdc++.h>
using namespace std;
const double pi = atan(1) * 4;
const double EXP = 1e-8;
struct node {
  int x, y;
  double a;
} light[30];
double cal(double pos, node l) {
  double len = sqrt((l.x - pos) * (l.x - pos) + l.y * l.y);
  if (pos > l.x) {
    if (l.a < atan(l.y * 1.0 / (pos - l.x))) {
      double ag = atan(l.y * 1.0 / (pos - l.x)) - l.a;
      return sin(l.a) * len / sin(ag);
    } else
      return 1000000.0;
  } else {
    l.x += EXP;
    double ag = atan(l.y * 1.0 / (l.x - pos));
    return sin(l.a) * len / sin(pi - ag - l.a);
  }
}
double dp[1 << 21];
int main() {
  int n, l, r;
  scanf("%d%d%d", &n, &l, &r);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d%d%d", &light[i].x, &light[i].y, &a);
    light[i].x -= l;
    light[i].a = a * pi / 180.0;
  }
  for (int i = 0; i < (1 << n); i++)
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) continue;
      dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + cal(dp[i], light[j]));
    }
  if (dp[(1 << n) - 1] + l >= r)
    printf("%.10f\n", (r - l) * 1.0);
  else
    printf("%.10f\n", dp[(1 << n) - 1]);
  return 0;
}
