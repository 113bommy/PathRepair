#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, i;
};
bool cmp1(node a, node b) { return a.x < b.x; }
bool cmp2(node a, node b) { return a.x > b.x; }
int main(void) {
  int n, s, i;
  node a[1100], b[1100];
  node ans1[1100], ans2[1100];
  while (scanf("%d%d", &n, &s) == 2) {
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    for (i = 1; i <= n; i++) {
      char t[5];
      int x, y;
      scanf("%s%d%d", t, &x, &y);
      if (t[0] == 'S') {
        a[cnt1].i = i;
        a[cnt1].x = x;
        a[cnt1++].y = y;
      } else {
        b[cnt2].i = i;
        b[cnt2].x = x;
        b[cnt2++].y = y;
      }
    }
    sort(a, a + cnt1, cmp1);
    sort(b, b + cnt2, cmp2);
    int t = 0;
    int ti = 0;
    int c1 = 0;
    for (i = 0; i < cnt1; i++) {
      if (t == 0) ti = a[i].i;
      t += a[i].y;
      if (i == c1 - 1 || a[i].x != a[i + 1].x) {
        ans1[c1].x = a[i].x;
        ans1[c1].y = t;
        ans1[c1].i = ti;
        c1++;
        t = 0;
      }
      if (c1 >= s) break;
    }
    int c2 = 0;
    t = 0;
    for (i = 0; i < cnt2; i++) {
      if (t == 0) ti = b[i].i;
      t += b[i].y;
      if (i == c2 - 1 || b[i].x != b[i + 1].x) {
        ans2[c2].x = b[i].x;
        ans2[c2].y = t;
        ans2[c2].i = ti;
        c2++;
        t = 0;
      }
      if (c2 >= s) break;
    }
    sort(ans1, ans1 + c1, cmp2);
    sort(ans2, ans2 + c2, cmp2);
    for (i = 0; i < c1; i++) printf("S %d %d\n", ans1[i].x, ans1[i].y);
    for (i = 0; i < c2; i++) printf("B %d %d\n", ans2[i].x, ans2[i].y);
  }
  return 0;
}
