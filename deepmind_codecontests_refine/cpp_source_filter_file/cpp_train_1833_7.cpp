#include <bits/stdc++.h>
using namespace std;
struct node {
  int x1, x2, y1, y2;
} a[100005];
int cl[100005];
int ct[100005];
int cr[100005];
int cb[100005];
int main() {
  int d, n, m;
  cin >> d >> n >> m;
  for (int i = 1; i <= d; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a[i].x1 = x1;
    a[i].x2 = x2;
    a[i].y1 = y1;
    a[i].y2 = y2;
    cl[min(x1, x2)]++;
    ct[min(y1, y2)]++;
    cr[max(x1, x2)]++;
    cb[max(y1, y2)]++;
  }
  int cntl, cntr, cntt, cntb;
  int ans = 0;
  cin >> cntl >> cntr >> cntt >> cntb;
  for (int i = 1; i <= 1e5 + 10; i++) {
    cl[i] = cl[i] + cl[i - 1];
  }
  for (int i = 1; i <= 1e5 + 10; i++) {
    ct[i] = ct[i] + ct[i - 1];
  }
  for (int i = 1e5 + 10; i >= 0; i--) {
    cr[i] = cr[i] + cr[i + 1];
  }
  for (int i = 1e5 + 10; i >= 0; i--) {
    cb[i] = cb[i] + cb[i + 1];
  }
  for (int i = 1; i <= d; i++) {
    int tmpl = cl[max(a[i].x1, a[i].x2) - 1];
    if (a[i].x1 != a[i].x2) tmpl--;
    int tmpr = cr[min(a[i].x1, a[i].x2) + 1];
    if (a[i].x1 != a[i].x2) tmpr--;
    int tmpt = ct[max(a[i].y1, a[i].y2) - 1];
    if (a[i].y1 != a[i].y2) tmpt--;
    int tmpb = cb[min(a[i].y1, a[i].y2) + 1];
    if (a[i].y1 != a[i].y2) tmpb--;
    if (tmpl == cntl && tmpr == cntr && tmpb == cntb && tmpt == cntt) {
      ans = i;
      break;
    }
  }
  if (ans)
    printf("%d\n", ans);
  else
    printf("-1\n");
}
