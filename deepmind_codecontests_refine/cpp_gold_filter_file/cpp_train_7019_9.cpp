#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, m;
int a[200000];
struct GUGAN {
  long long s, e, b;
  GUGAN(long long S, long long E, long long B) { s = S, e = E, b = B; }
  bool operator<(const GUGAN &p) const {
    if (s != p.s)
      return s < p.s;
    else if (e != p.e)
      return e < p.e;
    else
      return b < p.b;
  }
  bool operator==(const GUGAN &p) const { return s == p.s; }
};
set<GUGAN> x[20];
int initial[20][200000];
long long dab = 0;
long long two[20];
long long calc(GUGAN p) { return (p.e - p.s + 1) * (p.e - p.s + 2) / 2; }
int isgood(GUGAN p) { return p.s <= p.e; }
int main() {
  int i, j, k;
  scanf("%d%d", &n, &m);
  two[0] = 1;
  for (i = 1; i < 20; i++) two[i] = two[i - 1] * 2;
  for (i = 0; i < n; i++) {
    int u;
    scanf("%d", &u);
    for (j = 0; j < 20; j++) {
      if (u & (1 << j)) initial[j][i] = 1;
    }
  }
  for (i = 0; i < 20; i++) {
    int now = -1;
    for (j = 0; j <= n; j++) {
      if (j == 0) {
        if (initial[i][j] == 1) {
          x[i].insert(GUGAN(now, j - 1, initial[i][j - 1]));
          now = j;
        }
        continue;
      }
      if (initial[i][j] != initial[i][j - 1]) {
        x[i].insert(GUGAN(now, j - 1, initial[i][j - 1]));
        now = j;
      }
    }
    x[i].insert(GUGAN(now, n, initial[i][n]));
  }
  for (i = 0; i < 20; i++) {
    for (auto g : x[i]) {
      if (g.b == 1) {
        dab += calc(g) * two[i];
      }
    }
  }
  for (i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    for (j = 0; j < 20; j++) {
      int y = v & (1 << j);
      if (y) {
        set<GUGAN>::iterator idx = x[j].upper_bound(GUGAN(u, INT_MAX, INT_MAX));
        idx--;
        if (idx->b == 1) continue;
        if (idx->e == idx->s) {
          GUGAN tmp = *idx;
          GUGAN tmp2 = *(++idx);
          idx--;
          GUGAN tmp3 = *(--idx);
          x[j].erase(tmp), x[j].erase(tmp2), x[j].erase(tmp3);
          dab -= calc(tmp2) * two[j];
          dab -= calc(tmp3) * two[j];
          tmp3.e = tmp2.e;
          dab += calc(tmp3) * two[j];
          x[j].insert(tmp3);
        } else if (idx->s == u) {
          GUGAN tmp = *idx;
          GUGAN tmp2 = *(--idx);
          x[j].erase(tmp), x[j].erase(tmp2);
          dab -= calc(tmp2) * two[j];
          tmp2.e++;
          tmp.s++;
          dab += calc(tmp2) * two[j];
          x[j].insert(tmp2);
          x[j].insert(tmp);
        } else if (idx->e == u) {
          GUGAN tmp = *idx;
          GUGAN tmp2 = *(++idx);
          x[j].erase(tmp), x[j].erase(tmp2);
          dab -= calc(tmp2) * two[j];
          tmp2.s--;
          tmp.e--;
          dab += calc(tmp2) * two[j];
          x[j].insert(tmp2);
          x[j].insert(tmp);
        } else {
          GUGAN tmp = *idx;
          x[j].erase(idx);
          GUGAN tmp1 = GUGAN(tmp.s, u - 1, 0);
          GUGAN tmp2 = GUGAN(u, u, 1);
          GUGAN tmp3 = GUGAN(u + 1, tmp.e, 0);
          dab += 1 * two[j];
          x[j].insert(tmp1);
          x[j].insert(tmp2);
          x[j].insert(tmp3);
        }
      } else {
        set<GUGAN>::iterator idx = x[j].upper_bound(GUGAN(u, INT_MAX, INT_MAX));
        idx--;
        if (idx->b == 0) continue;
        if (idx->e == idx->s) {
          GUGAN tmp = *idx;
          GUGAN tmp2 = *(++idx);
          idx--;
          GUGAN tmp3 = *(--idx);
          x[j].erase(tmp), x[j].erase(tmp2), x[j].erase(tmp3);
          dab -= 1 * two[j];
          tmp3.e = tmp2.e;
          x[j].insert(tmp3);
        } else if (idx->s == u) {
          GUGAN tmp = *idx;
          GUGAN tmp2 = *(--idx);
          x[j].erase(tmp), x[j].erase(tmp2);
          dab -= calc(tmp) * two[j];
          tmp2.e++;
          tmp.s++;
          dab += calc(tmp) * two[j];
          x[j].insert(tmp2);
          x[j].insert(tmp);
        } else if (idx->e == u) {
          GUGAN tmp = *idx;
          GUGAN tmp2 = *(++idx);
          x[j].erase(tmp), x[j].erase(tmp2);
          dab -= calc(tmp) * two[j];
          tmp2.s--;
          tmp.e--;
          dab += calc(tmp) * two[j];
          x[j].insert(tmp2);
          x[j].insert(tmp);
        } else {
          GUGAN tmp = *idx;
          x[j].erase(idx);
          GUGAN tmp1 = GUGAN(tmp.s, u - 1, 1);
          GUGAN tmp2 = GUGAN(u, u, 0);
          GUGAN tmp3 = GUGAN(u + 1, tmp.e, 1);
          dab -= calc(tmp) * two[j];
          dab += calc(tmp1) * two[j];
          dab += calc(tmp3) * two[j];
          x[j].insert(tmp1);
          x[j].insert(tmp2);
          x[j].insert(tmp3);
        }
      }
    }
    printf("%I64d\n", dab);
  }
  return 0;
}
