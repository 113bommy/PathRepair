#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct point {
  int x, y;
};
point pts[maxn];
int xs[maxn], ys[maxn], ft[maxn], n, xtot;
unordered_map<int, int> xid;
int lowbit(int x) { return x & (-x); }
void update(int x, int d) {
  while (x <= xtot) {
    ft[x] += d;
    x += lowbit(x);
  }
}
int sum(int x) {
  int res = 0;
  while (x) {
    res += ft[x];
    x -= lowbit(x);
  }
  return res;
}
int query(int l, int r) { return sum(r) - sum(l); }
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> pts[i].x >> pts[i].y;
    xs[i] = pts[i].x;
    ys[i] = pts[i].y;
  }
  sort(xs, xs + n);
  xtot = unique(xs, xs + n) - xs;
  for (int i = 0; i < xtot; ++i) xid[xs[i]] = i + 1;
  sort(pts, pts + n, [](point a, point b) -> bool {
    return a.y == b.y ? a.x < b.x : a.y > b.y;
  });
  long long ans = 0;
  for (int i = 0; i < n;) {
    int j;
    for (j = i; pts[j].y == pts[i].y; ++j) {
      if (!query(xid[pts[j].x] - 1, xid[pts[j].x])) update(xid[pts[j].x], 1);
    }
    ans +=
        (long long)query(0, xid[pts[i].x]) * (query(xid[pts[i].x], xtot) + 1);
    for (j = i + 1; pts[j].y == pts[i].y; ++j) {
      ans += (long long)query(xid[pts[j - 1].x], xid[pts[j].x]) *
             (query(xid[pts[j].x], xtot) + 1);
    }
    i = j;
  }
  cout << ans;
  return 0;
}
