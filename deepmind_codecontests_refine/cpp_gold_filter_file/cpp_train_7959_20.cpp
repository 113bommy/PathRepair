#include <bits/stdc++.h>
using namespace std;
using namespace std;
struct D {
  int x, y;
} d1[100005], d2[100005];
bool cmp1(D a, D b) { return (a.x + a.y) < (b.x + b.y); }
bool cmp2(D a, D b) { return (a.x - a.y) < (b.x - b.y); }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int tn;
  scanf("%d", &tn);
  for (int i = 0; i < tn; i++) {
    scanf("%d%d", &d1[i].x, &d1[i].y);
    d2[i] = d1[i];
  }
  sort(d1, d1 + tn, cmp1);
  sort(d2, d2 + tn, cmp2);
  int ans = 2000000009, anid = 1;
  int tm;
  scanf("%d", &tm);
  for (int i = 1; i <= tm; i++) {
    int x, y, tans = 0;
    scanf("%d%d", &x, &y);
    if (abs(x - d1[0].x) + abs(y - d1[0].y) > tans) {
      tans = abs(x - d1[0].x) + abs(y - d1[0].y);
    }
    if (abs(x - d1[tn - 1].x) + abs(y - d1[tn - 1].y) > tans) {
      tans = abs(x - d1[tn - 1].x) + abs(y - d1[tn - 1].y);
    }
    if (abs(x - d2[0].x) + abs(y - d2[0].y) > tans) {
      tans = abs(x - d2[0].x) + abs(y - d2[0].y);
    }
    if (abs(x - d2[tn - 1].x) + abs(y - d2[tn - 1].y) > tans) {
      tans = abs(x - d2[tn - 1].x) + abs(y - d2[tn - 1].y);
    }
    if (tans < ans) {
      ans = tans;
      anid = i;
    }
  }
  printf("%d\n%d\n", ans, anid);
  return 0;
}
