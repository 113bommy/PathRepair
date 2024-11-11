#include <bits/stdc++.h>
using namespace std;
int n, w, h;
struct node {
  int tag, l, t, id;
} rec[105000];
int x[105000], y[105000];
int id[105000];
int pp[105000];
bool cmp(node a, node b) {
  if (a.l - a.t == b.l - b.t) {
    if (a.tag == b.tag) {
      return a.l < b.l;
    }
    return a.tag < b.tag;
  }
  return a.l - a.t < b.l - b.t;
}
int main() {
  scanf("%d%d%d", &n, &w, &h);
  for (int i = 1; i <= n; i++) {
    int tag, l;
    scanf("%d%d%d", &tag, &l, &rec[i].t);
    rec[i].tag = tag;
    rec[i].l = l;
    rec[i].id = i;
    if (tag == 1) {
      x[i] = l;
      y[i] = h;
    } else {
      x[i] = w;
      y[i] = l;
    }
  }
  sort(rec + 1, rec + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    int as = -1, bs = -1, ac = 0, bc = 0;
    int num = rec[i].l - rec[i].t;
    for (int j = i; j <= n + 1; j++) {
      if (j == n + 1 || rec[j].l - rec[j].t != num) {
        i = j - 1;
        break;
      }
      if (rec[j].tag == 1) {
        if (as == -1) as = j;
        ac++;
      } else {
        if (bs == -1) bs = j;
        bc++;
      }
    }
    for (int j = 1; j <= min(ac, bc); j++) {
      id[rec[as + j - 1].id] = rec[bs + bc - j].id;
      id[rec[bs + j - 1].id] = rec[as + ac - j].id;
    }
    if (ac < bc) {
      for (int j = ac + 1; j <= bc; j++) {
        id[rec[bs + j - 1].id] = rec[bs + j - 1 - ac].id;
      }
    } else {
      for (int j = bc + 1; j <= ac; j++) {
        id[rec[as + j - 1].id] = rec[as + j - 1 - bc].id;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    pp[id[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", x[pp[i]], y[pp[i]]);
  }
}
