#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
using ll = long long;
struct Node {
  int x1, x2, y1, y2;
  ll sum;
};
int a[N], lp[N], rp[N], tag[N], lst[N];
vector<Node> v[N];
void del(int x, int y) {
  if (y > tag[x])
    v[x].push_back({tag[x], y - 1, lp[x], rp[x],
                    (v[x].empty() ? 0ll : v[x].back().sum) +
                        (rp[x] - lp[x] + 1ll) * (y - tag[x])});
  tag[x] = 0;
}
void modify(int x, int l, int r, int y) {
  if (tag[x])
    del(x, y);
  else
    lp[x] = l;
  rp[x] = r;
  tag[x] = y;
}
ll query(int kk, int l, int r) {
  ll ret = 0;
  if (!v[kk].empty()) {
    int lt = 0, rt = v[kk].size(), tl, tr;
    while (lt < rt) {
      int mid = (lt + rt) >> 1;
      if (v[kk][mid].x2 >= l && v[kk][mid].y2 >= l)
        rt = mid;
      else
        lt = mid + 1;
    }
    tl = lt;
    lt = -1;
    rt = v[kk].size() - 1;
    while (lt < rt) {
      int mid = (lt + rt + 1) >> 1;
      if (v[kk][mid].x1 <= r && v[kk][mid].y1 <= r)
        lt = mid;
      else
        rt = mid - 1;
    }
    tr = lt;
    if (tl <= tr) {
      ret += v[kk][tr].sum - (tl ? v[kk][tl - 1].sum : 0);
      if (l > v[kk][tl].x1)
        ret -= ll(v[kk][tl].y2 - v[kk][tl].y1 + 1) * (l - v[kk][tl].x1);
      if (r < v[kk][tr].x2)
        ret -= ll(v[kk][tr].y2 - v[kk][tr].y1 + 1) * (v[kk][tr].x2 - r);
      if (v[kk][tl].y1 < l) {
        lt = tl;
        rt = v[kk].size() - 1;
        while (lt < rt) {
          int mid = (lt + rt + 1) >> 1;
          if (v[kk][mid].y1 < l)
            lt = mid;
          else
            rt = mid - 1;
        }
        ret -= ll(l - v[kk][tl].y1) *
               (min(v[kk][lt].x2, r) - min(v[kk][tl].x1, l) + 1);
      }
    }
  }
  if (tag[kk]) {
    int l1 = max(l, tag[kk]), r1 = r, l2 = max(l, lp[kk]), r2 = min(r, rp[kk]);
    if (l1 <= r1 && l2 <= r2) ret += ll(r1 - l1 + 1) * (r2 - l2 + 1);
  }
  return ret;
}
int n;
ll lst_ans;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int l, r, kk;
    cin >> a[i] >> l >> r >> kk;
    a[i] = (a[i] + lst_ans) % (n + 1);
    l = (l + lst_ans) % i + 1;
    r = (r + lst_ans) % i + 1;
    if (l > r) swap(l, r);
    kk = (kk + lst_ans) % (n + 1);
    if (tag[a[i]]) {
      for (int j = a[i] + 1, r = rp[a[i]];; j++) {
        if (lst[j] < lp[a[i]]) {
          modify(j, lp[a[i]], r, i);
          break;
        } else if (lst[j] < r)
          modify(j, lst[j] + 1, r, i), r = lst[j];
      }
      del(a[i], i);
    }
    modify(!a[i], i, i, i);
    lst[a[i]] = i;
    cout << (lst_ans = query(kk, l, r)) << endl;
  }
  return 0;
}
