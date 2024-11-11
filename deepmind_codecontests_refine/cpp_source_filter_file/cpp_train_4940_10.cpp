#include <bits/stdc++.h>
using namespace std;
const int maxn = 110000;
const int maxlst = 1 << 17;
const int maxsz = (maxlst << 1) + 100;
struct point {
  int x, y, num;
};
inline bool cmpx(const point& a, const point& b) {
  if (a.x != b.x) return a.x < b.x;
  if (a.y != b.y) return a.y < b.y;
  return a.num < b.num;
}
inline bool cmpy(const point& a, const point& b) {
  if (a.y != b.y) return a.y < b.y;
  if (a.x != b.x) return a.x < b.x;
  return a.num < b.num;
}
inline bool cmpnum(const point& a, const point& b) { return a.num < b.num; }
const int inf = 1 << 30;
int* t[maxsz];
int* t1[maxsz];
int sz[maxsz];
int lst[maxlst];
point a[maxn];
point b[maxn];
int n;
int lsty, szy;
inline bool icmpx(int a, int b) {
  if (a == inf) return false;
  if (b == inf) return true;
  return cmpx(::b[a], ::b[b]);
}
void init() {
  sort(a, a + n, cmpy);
  lsty = 2;
  for (; lsty < n; lsty <<= 1)
    ;
  szy = (lsty << 1) - 1;
  for (int i = 0; i < n; i++) {
    t[i + lsty - 1] = new int[1];
    t1[i + lsty - 1] = new int[1];
    t[i + lsty - 1][0] = a[i].num;
    t1[i + lsty - 1][0] = a[i].num;
    lst[i + lsty - 1] = 1;
    sz[i + lsty - 1] = 1;
  }
  for (int i = n; i < lsty; i++) {
    t[i + lsty - 1] = new int[1];
    t1[i + lsty - 1] = new int[1];
    t[i + lsty - 1][0] = inf;
    t1[i + lsty - 1][0] = inf;
    lst[i + lsty - 1] = 1;
    sz[i + lsty - 1] = 1;
  }
  for (int i = lsty - 2; i >= 0; i--) {
    lst[i] = lst[(((i) << 1) + 1)] + lst[(((i) + 1) << 1)];
    sz[i] = lst[i] * 2 - 1;
    t[i] = new int[sz[i]];
    memcpy(t[i] + lst[i] - 1, t[(((i) << 1) + 1)] + lst[(((i) << 1) + 1)] - 1,
           lst[(((i) << 1) + 1)] * sizeof(int));
    memcpy(t[i] + lst[i] + lst[(((i) << 1) + 1)] - 1,
           t[(((i) + 1) << 1)] + lst[(((i) + 1) << 1)] - 1,
           lst[(((i) + 1) << 1)] * sizeof(int));
    inplace_merge(t[i] + lst[i] - 1, t[i] + lst[i] + lst[(((i) << 1) + 1)] - 1,
                  t[i] + sz[i], icmpx);
    t1[i] = new int[lst[i]];
    memcpy(t1[i], t[i] + lst[i] - 1, lst[i] * sizeof(int));
    for (int j = lst[i] - 2; j >= 0; j--)
      t[i][j] = min(t[i][(((j) << 1) + 1)], t[i][(((j) + 1) << 1)]);
  }
}
int ans[maxn];
void update(int pos, int num) {
  int posx = lower_bound(t1[pos], t1[pos] + lst[pos], num, icmpx) - t1[pos];
  posx += lst[pos] - 1;
  t[pos][posx] = inf;
  if (posx == 0) return;
  for (posx = (((posx)-1) >> 1); posx; posx = (((posx)-1) >> 1))
    t[pos][posx] =
        min(t[pos][(((posx) << 1) + 1)], t[pos][(((posx) + 1) << 1)]);
  t[pos][posx] = min(t[pos][(((posx) << 1) + 1)], t[pos][(((posx) + 1) << 1)]);
}
void update(int num) {
  int pos = lower_bound(a, a + n, b[num], cmpy) - a;
  pos = pos + lsty - 1;
  for (; pos; pos = (((pos)-1) >> 1)) update(pos, num);
  update(0, num);
}
int findx(int v, int v1, int l, int r, int Lx, int Rx) {
  if (r < Lx || l > Rx || Lx > Rx) return inf;
  if (Lx <= l && r <= Rx) return t[v][v1];
  return min(findx(v, (((v1) << 1) + 1), l, (l + r) / 2, Lx, Rx),
             findx(v, (((v1) + 1) << 1), (l + r) / 2 + 1, r, Lx, Rx));
}
int findy(int v, int l, int r, int Lx, int Rx, int Ly, int Ry) {
  if (r < Ly || l > Ry || Ly > Ry) return inf;
  if (Ly <= l && r <= Ry) {
    b[n].x = Lx;
    b[n].y = -inf;
    int lx = lower_bound(t1[v], t1[v] + lst[v], n, icmpx) - t1[v];
    b[n].x = Rx;
    b[n].y = inf;
    int rx = upper_bound(t1[v], t1[v] + lst[v], n, icmpx) - t1[v];
    --rx;
    return findx(v, 0, 0, lst[v] - 1, lx, rx);
  }
  int lv = findy((((v) << 1) + 1), l, (l + r) / 2, Lx, Rx, Ly, Ry);
  int rv = findy((((v) + 1) << 1), (l + r) / 2 + 1, r, Lx, Rx, Ly, Ry);
  return min(lv, rv);
}
struct rect {
  int x1, y1, x2, y2, z, num;
  void read() {
    scanf("%d %d %d %d %d", &x1, &x2, &y1, &y2, &z);
    if (x2 < x1) swap(x1, x2);
    if (y2 < y1) swap(y1, y2);
  };
};
bool cmprect(const rect& a, const rect& b) { return a.z < b.z; }
rect per[maxn];
int main() {
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    per[i].num = i;
    per[i].read();
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    a[i].num = i;
    scanf("%d %d", &a[i].x, &a[i].y);
    b[i] = a[i];
  }
  init();
  sort(per, per + m, cmprect);
  memset(ans, -1, sizeof(ans));
  for (int i = 0; i < m; i++) {
    a[n].x = -inf;
    a[n].y = per[i].y1;
    int ly = lower_bound(a, a + n, a[n], cmpy) - a;
    a[n].x = inf;
    a[n].y = per[i].y2;
    int ry = upper_bound(a, a + n, a[n], cmpy) - a;
    --ry;
    int tmp = findy(0, 0, lsty - 1, per[i].x1, per[i].x2, ly, ry);
    if (tmp == inf) continue;
    ans[tmp] = per[i].num;
    update(tmp);
  }
  for (int i = 0; i < n; i++) printf("%d\n", ans[i] + 1);
  return 0;
}
