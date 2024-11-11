#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const double EPS = 1e-8;
const double PI = acos(-1);
int sign(double x) { return x < -EPS ? -1 : x > EPS; }
int dbcmp(double l, double r) { return sign(l - r); }
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int MAXN = 1e6 + 54;
struct SegTree {
  struct SegNode {
    int maxv, minv, l, r, lz;
  } snode[2000150];
  void build(int now, int l, int r) {
    snode[now].lz = snode[now].minv = snode[now].maxv = 0;
    snode[now].l = l;
    snode[now].r = r;
    if (l == r) return;
    build((now << 1), l, ((snode[now].l + snode[now].r) >> 1));
    build((now << 1 | 1), ((snode[now].l + snode[now].r) >> 1) + 1, r);
  }
  void pushdown(int now) {
    if (snode[now].lz == 0) return;
    snode[(now << 1)].lz += snode[now].lz;
    snode[(now << 1 | 1)].lz += snode[now].lz;
    snode[(now << 1)].minv += snode[now].lz;
    snode[(now << 1 | 1)].minv += snode[now].lz;
    snode[(now << 1)].maxv += snode[now].lz;
    snode[(now << 1 | 1)].maxv += snode[now].lz;
    snode[now].lz = 0;
  }
  void update(int now, int L, int R, int val) {
    if (L <= snode[now].l && snode[now].r <= R) {
      snode[now].lz += val;
      snode[now].maxv += val;
      snode[now].minv += val;
      return;
    }
    pushdown(now);
    if (L <= ((snode[now].l + snode[now].r) >> 1))
      update((now << 1), L, R, val);
    if (R > ((snode[now].l + snode[now].r) >> 1))
      update((now << 1 | 1), L, R, val);
    snode[now].maxv = max(snode[(now << 1)].maxv, snode[(now << 1 | 1)].maxv);
    snode[now].minv = min(snode[(now << 1)].minv, snode[(now << 1 | 1)].minv);
  }
  int qm() { return snode[1].minv; }
  int qx() { return snode[1].maxv; }
} ST;
char str[MAXN];
char tmp[MAXN];
void work() {
  const int MAXV = 5e5 + 3;
  ST.build(1, 0, MAXV);
  int n;
  scanf("%d", &n);
  scanf("%s", str);
  int cur = 0;
  int tot = 0;
  for (int i = 0; str[i]; i++) {
    if (str[i] == 'L') {
      if (cur) cur--;
    } else if (str[i] == 'R') {
      cur++;
    } else if (str[i] == '(') {
      if (tmp[cur] == ')') {
        tot += 2;
        ST.update(1, cur, MAXV, 2);
      } else if (tmp[cur] != '(') {
        tot++;
        ST.update(1, cur, MAXV, 1);
      }
      tmp[cur] = str[i];
    } else if (str[i] == ')') {
      if (tmp[cur] == '(') {
        tot -= 2;
        ST.update(1, cur, MAXV, -2);
      } else if (tmp[cur] != ')') {
        tot--;
        ST.update(1, cur, MAXV, -1);
      }
      tmp[cur] = str[i];
    } else {
      if (tmp[cur] == '(') {
        tot++;
        ST.update(1, cur, MAXV, 1);
      } else if (tmp[cur] == ')') {
        tot--;
        ST.update(1, cur, MAXV, -1);
      }
      tmp[cur] = str[i];
    }
    if (tot == 0 && ST.qm() >= 0) {
      printf("%d ", ST.qx());
    } else
      printf("-1 ");
  }
}
int main() {
  { work(); }
}
