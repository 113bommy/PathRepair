#include <bits/stdc++.h>
using namespace std;
struct frog {
  long long x, l, xh, eat;
  bool operator<(const frog& aaa) const { return x < aaa.x; }
} a[202020];
int n, m;
long long tr[202020], ans[202020][2];
void gx(int xh, long long vl) {
  xh++;
  while (xh <= n) {
    tr[xh] = max(tr[xh], vl);
    xh += xh & (-xh);
  }
}
long long gt(int xh) {
  long long mx = -1;
  xh++;
  while (xh) {
    mx = max(mx, tr[xh]);
    xh -= xh & (-xh);
  }
  return mx;
}
int main() {
  memset(tr, -1, sizeof(tr));
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].l;
    a[i].xh = i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    gx(i, a[i].x + a[i].l + 1);
  }
  multiset<pair<int, int> > uneat;
  for (int i = 0; i < m; i++) {
    int p, b;
    cin >> p >> b;
    int l = -1, r = n - 1;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (a[mid].x <= p) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    if (r == -1) {
      uneat.insert(make_pair(p, b));
    } else {
      l = 0;
      while (l < r) {
        int mid = (l + r) / 2;
        if (gt(mid) < p) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      if (gt(l) < p) {
        uneat.insert(make_pair(p, b));
      } else {
        a[l].eat++;
        a[l].l += b;
        multiset<pair<int, int> >::iterator it =
            uneat.lower_bound(make_pair(a[l].x, -1));
        while (it != uneat.end() && a[l].x + a[l].l >= it->first) {
          a[l].eat++;
          a[l].l += it->second;
          uneat.erase(it++);
        }
        gx(l, a[l].x + a[l].l);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    ans[a[i].xh][0] = a[i].eat;
    ans[a[i].xh][1] = a[i].l;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i][0] << ' ' << ans[i][1] << endl;
  }
  return 0;
}
