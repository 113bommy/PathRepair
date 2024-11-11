#include <bits/stdc++.h>
using namespace std;
struct atom {
  int x, p;
};
atom a[3];
int b[3];
bool cmpx(const atom &, const atom &);
int main() {
  for (int i = 0; i < 3; ++i) {
    scanf("%d", &a[i].x);
    a[i].p = i;
  }
  sort(a, a + 2, cmpx);
  int s = (a[1].x + a[2].x - a[0].x) / 2;
  if (s > 0) {
    a[1].x -= s;
    a[2].x -= s;
    b[(!min(a[1].p, a[2].p) ? (max(a[1].p, a[2].p) - 1) << 1 : 1)] += s;
  }
  if (a[1].x + a[2].x != a[0].x) {
    printf("Impossible\n");
    return 0;
  }
  b[(!min(a[0].p, a[1].p) ? (max(a[0].p, a[1].p) - 1) << 1 : 1)] += a[1].x;
  b[(!min(a[0].p, a[2].p) ? (max(a[0].p, a[2].p) - 1) << 1 : 1)] += a[2].x;
  printf("%d %d %d\n", b[0], b[1], b[2]);
  return 0;
}
bool cmpx(const atom &a, const atom &b) { return a.x > b.x; }
