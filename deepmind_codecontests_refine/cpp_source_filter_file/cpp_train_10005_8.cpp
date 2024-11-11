#include <bits/stdc++.h>
using namespace std;
int n, k, i, j, t, l, r, ans, f[200005], astmp, p[200005], u, v, x;
int Find(int x) {
  if (f[x] == 0) {
    astmp = x;
    return 0;
  }
  p[x] ^= Find(f[x]);
  f[x] = astmp;
  return p[x];
}
void uniot(int u, int v, int w) {
  Find(u);
  int x = astmp;
  Find(v);
  int y = astmp;
  if (x != y) {
    f[x] = y;
    p[x] = w ^ p[u];
  }
}
struct str {
  int a, x;
  bool operator<(const str &u) const { return u.a < a; }
};
set<str> q;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d %d", &t, &l, &r);
    l ^= ans;
    r ^= ans;
    if (l > r) l ^= r ^= l ^= r;
    if (t == 1) {
      scanf("%d", &x);
      x ^= ans;
      set<str>::iterator tl = q.find((str){l, 0}), tr = q.find((str){r + 1, 0});
      if (tl == q.end()) {
        q.insert((str){l, ++k});
        u = k;
      } else
        u = (*tl).x;
      if (tr == q.end()) {
        q.insert((str){r + 1, ++k});
        v = k;
      } else
        v = (*tr).x;
      uniot(u, v, x);
      Find(1);
    } else {
      set<str>::iterator tl = q.find((str){l, 0}), tr = q.find((str){r + 1, 0});
      if (tl != q.end() && tr != q.end()) {
        Find(tl->x);
        u = astmp;
        Find(tr->x);
        v = astmp;
        if (u == v) {
          printf("%d\n", p[tl->x] ^ p[tr->x]);
          ans = p[tl->x] ^ p[tr->x];
        } else {
          printf("-1\n");
          ans = 1;
        }
      } else {
        printf("-1\n");
        ans = 1;
      }
    }
  }
}
