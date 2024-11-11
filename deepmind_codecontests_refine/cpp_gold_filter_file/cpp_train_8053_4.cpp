#include <bits/stdc++.h>
using namespace std;
const int imax = 100000 + 229;
int n, tot;
double A, B, C, D, ans[imax];
struct Node {
  double x, y;
} p[imax];
void iread() {
  scanf("%d", &n);
  scanf("%lf/%lf%lf/%lf", &A, &B, &C, &D);
  for (int i = 1; i <= n; i++) {
    double nowx, nowy;
    scanf("%lf%lf", &nowx, &nowy);
    ++tot;
    p[tot].y = nowy * B - nowx * A;
    p[tot].x = nowx * C - nowy * D;
    if (p[tot].x <= 0 || p[tot].y <= 0) tot--;
  }
}
bool cmp(const Node t1, const Node t2) {
  return t1.x < t2.x || (t1.x == t2.x && t1.y > t2.y);
}
void iwork() {
  if (tot == 0) {
    puts("0");
    return;
  }
  sort(p + 1, p + tot + 1, cmp);
  int len = 1;
  ans[1] = p[1].y;
  for (int i = 2; i <= tot; i++) {
    if (p[i].y > ans[len])
      ans[++len] = p[i].y;
    else {
      int pos = lower_bound(ans + 1, ans + len + 1, p[i].y) - ans;
      if (pos >= 1 && pos <= n) ans[pos] = p[i].y;
    }
  }
  printf("%d\n", len);
}
int main() {
  iread();
  iwork();
  return 0;
}
