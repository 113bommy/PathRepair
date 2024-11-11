#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9 + 1000;
int n, m, x, y, ans1;
pair<int, int> a[N], b[N], c[N];
struct item {
  item *l, *r;
  set<int> q;
  item() { l = r = nullptr; }
};
typedef item *pitem;
pitem root = nullptr;
void update(pitem v, int l, int r, int pos, int val) {
  v->q.insert(val);
  if (l == r) {
    return;
  }
  int mid = (r + l) >> 1;
  if (pos <= mid) {
    if (!v->l) {
      v->l = new item();
    }
    update(v->l, l, mid, pos, val);
  } else {
    if (!v->r) {
      v->r = new item();
    }
    update(v->r, mid + 1, r, pos, val);
  }
}
bool exist(pitem v, int l, int r, int tl, int tr, int x, int y) {
  if (!v || l > r || l > tr || tl > r) {
    return false;
  }
  if (tl <= l && r <= tr) {
    auto it = v->q.lower_bound(x);
    if (it != v->q.end() && *it <= y) {
      return true;
    }
    return false;
  }
  int mid = (r + l) >> 1;
  bool yy = exist(v->l, l, mid, tl, tr, x, y);
  return yy ? true : exist(v->r, mid + 1, r, tl, tr, x, y);
}
inline bool check(int x) {
  int mnx = -INT_MAX, mxx = INT_MAX, mny = -INT_MAX, mxy = INT_MAX;
  for (int i = n; i >= 1; i--) {
    int j = c[i].second;
    mnx = max(mnx, a[j].first - x);
    mxx = min(mxx, a[j].first + x);
    mny = max(mny, a[j].second - x);
    mxy = min(mxy, a[j].second + x);
    if (mnx > mxx || mny > mxy) {
      return false;
    }
    if (i == 1) {
      return true;
    }
    if (c[i - 1].first <= x) {
      int left = x - c[i - 1].first;
      if (exist(root, -inf, inf, mnx - left, mxx + left, mny - left,
                mxy + left)) {
        return true;
      }
    }
  }
  assert(false);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    a[i] = make_pair(x + y, x - y);
  }
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    b[i] = make_pair(x + y, x - y);
  }
  int mnx = a[1].first, mxx = a[1].first, mny = a[1].second, mxy = a[1].second;
  for (int i = 2; i <= n; i++) {
    mnx = min(mnx, a[i].first);
    mxx = max(mxx, a[i].first);
    mny = min(mny, a[i].second);
    mxy = max(mxy, a[i].second);
  }
  ans1 = max((mxx - mnx + 1) / 2, (mxy - mny + 1) / 2);
  if (m == 0) {
    return cout << ans1, 0;
  }
  root = new item();
  for (int i = 1; i <= m; i++) {
    update(root, -inf, inf, b[i].first, b[i].second);
  }
  for (int i = 1; i <= n; i++) {
    int l = 0, r = 4e8;
    while (r - l > 1) {
      int mid = (r + l) >> 1;
      if (exist(root, -inf, inf, a[i].first - mid, a[i].first + mid,
                a[i].second - mid, a[i].second + mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    if (exist(root, -inf, inf, a[i].first - l, a[i].first + l, a[i].second - l,
              a[i].second + l)) {
      c[i].first = l;
    } else {
      c[i].first = r;
    }
    c[i].second = i;
  }
  sort(c + 1, c + n + 1);
  int l = 0, r = c[n].first;
  while (r - l > 1) {
    int mid = (r + l) >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  int ans2;
  if (check(l)) {
    ans2 = l;
  } else {
    ans2 = r;
  }
  cout << min(ans1, ans2);
}
