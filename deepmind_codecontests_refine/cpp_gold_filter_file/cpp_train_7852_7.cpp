#include <bits/stdc++.h>
using namespace std;
struct Node {
  int t;
  int h;
  int m;
  int f;
} ca[2005], fr[2005];
int Comp(const void *p1, const void *p2) {
  struct Node *c = (Node *)p1;
  struct Node *d = (Node *)p2;
  if (c->m != d->m)
    return d->m - c->m;
  else
    return d->h - c->h;
}
int main() {
  int n, x;
  while (~scanf("%d%d", &n, &x)) {
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
      int type;
      scanf("%d", &type);
      if (!type) {
        ca[c1].t = type;
        scanf("%d%d", &ca[c1].h, &ca[c1].m);
        c1++;
      } else {
        fr[c2].t = type;
        scanf("%d%d", &fr[c2].h, &fr[c2].m);
        c2++;
      }
    }
    qsort(ca, c1, sizeof(ca[0]), Comp);
    qsort(fr, c2, sizeof(fr[0]), Comp);
    for (int i = 0; i < c1; ++i) {
      ca[i].f = 0;
    }
    for (int i = 0; i < c2; ++i) {
      fr[i].f = 0;
    }
    int x2 = x;
    int cnt1 = 0;
    int flag = 0;
    while (1) {
      int f = 0;
      for (int i = 0; i < c1; ++i) {
        if (ca[i].h <= x && ca[i].f == 0) {
          cnt1++;
          x += ca[i].m;
          ca[i].f = 1;
          f = 1;
          break;
        }
      }
      if (!f) break;
      f = 0;
      for (int i = 0; i < c2; ++i) {
        if (fr[i].h <= x && fr[i].f == 0) {
          cnt1++;
          x += fr[i].m;
          fr[i].f = 1;
          f = 1;
          break;
        }
      }
      if (!f) break;
    }
    for (int i = 0; i < c1; ++i) {
      ca[i].f = 0;
    }
    for (int i = 0; i < c2; ++i) {
      fr[i].f = 0;
    }
    int cnt2 = 0;
    int flag2 = 0;
    while (1) {
      int f = 0;
      for (int i = 0; i < c2; ++i) {
        if (fr[i].h <= x2 && fr[i].f == 0) {
          cnt2++;
          x2 += fr[i].m;
          fr[i].f = 1;
          f = 1;
          break;
        }
      }
      if (!f) break;
      f = 0;
      for (int i = 0; i < c1; ++i) {
        if (ca[i].h <= x2 && ca[i].f == 0) {
          cnt2++;
          x2 += ca[i].m;
          ca[i].f = 1;
          f = 1;
          break;
        }
      }
      if (!f) break;
    }
    printf("%d\n", max(cnt1, cnt2));
  }
  return 0;
}
