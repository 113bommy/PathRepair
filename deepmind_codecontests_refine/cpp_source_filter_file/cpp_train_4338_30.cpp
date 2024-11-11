#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
const int INF = 1e9;
int n, m, cl, ce, v, q;
int a[maxn + 5], b[maxn + 5];
int main() {
  scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
  for (int i = 1; i <= cl; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= ce; i++) scanf("%d", &a[i]);
  sort(a + 1, a + cl + 1);
  sort(b + 1, b + ce + 1);
  scanf("%d", &q);
  while (q--) {
    int Ax, Ay, Bx, By;
    int Min = INF, t;
    scanf("%d%d%d%d", &Ay, &Ax, &By, &Bx);
    if (Ax > Bx) swap(Ax, Bx);
    if (Ay > By) swap(Ay, By);
    if (Ay == By) Min = min(Min, By - Ay);
    int l = 1, r = ce, ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (a[mid] <= Ax)
        l = mid + 1, ans = mid;
      else
        r = mid - 1;
    }
    if (ans != 0)
      t = (Ax - a[ans]) * 2 + (By - Ay + v - 1) / v + Bx - Ax;
    else
      t = INF;
    Min = min(Min, t);
    l = 1, r = cl, ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (b[mid] <= Ax)
        l = mid + 1, ans = mid;
      else
        r = mid - 1;
    }
    if (ans != 0)
      t = (Ax - b[ans]) * 2 + By - Ay + Bx - Ax;
    else
      t = INF;
    Min = min(Min, t);
    l = 1, r = ce, ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (a[mid] >= Ax)
        r = mid - 1, ans = mid;
      else
        l = mid + 1;
    }
    if (ans != 0 && a[ans] <= Bx)
      t = Bx - Ax + (By - Ay + v - 1) / v;
    else
      t = INF;
    Min = min(Min, t);
    l = 1, r = cl, ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (b[mid] >= Ax)
        r = mid - 1, ans = mid;
      else
        l = mid + 1;
    }
    if (ans != 0 && b[ans] <= Bx)
      t = Bx - Ax + By - Ay;
    else
      t = INF;
    Min = min(Min, t);
    l = 1, r = ce, ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (a[mid] >= Bx)
        r = mid - 1, ans = mid;
      else
        l = mid + 1;
    }
    if (ans != 0)
      t = (a[ans] - Bx) * 2 + Bx - Ax + (By - Ay + v - 1) / v;
    else
      t = INF;
    Min = min(Min, t);
    l = 1, r = cl, ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (b[mid] >= Bx)
        r = mid - 1, ans = mid;
      else
        l = mid + 1;
    }
    if (ans != 0)
      t = (b[ans] - Bx) * 2 + Bx - Ax + By - Ay;
    else
      t = INF;
    Min = min(Min, t);
    printf("%d\n", Min);
  }
  return 0;
}
