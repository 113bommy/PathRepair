#include <bits/stdc++.h>
using namespace std;
int h[100005], ans[100005];
int l[100005], r[100005], w[100005];
vector<int> mid2[100005];
int lo2[100005], hi2[100005];
vector<int> cur[100005];
struct st {
  int le, ri, len, all;
};
st seg[400005];
st update_seg(st a, st b) {
  st res;
  res.len = a.len + b.len;
  res.all = max(max(a.all, b.all), a.ri + b.le);
  if (a.len == a.le)
    res.le = a.len + b.le;
  else
    res.le = a.le;
  if (b.len = b.le)
    res.ri = a.ri + b.len;
  else
    res.ri = b.ri;
  return res;
}
void update(int n, int s, int e, int idx, int v) {
  if (s == e) {
    seg[n].le = max(0, v);
    seg[n].ri = max(0, v);
    seg[n].all = max(0, v);
    seg[n].len = 1;
  } else {
    int mid = (s + e) / 2;
    if (idx <= mid)
      update(n + n, s, mid, idx, v);
    else
      update(n + n + 1, mid + 1, e, idx, v);
    seg[n] = update_seg(seg[n + n], seg[n + n + 1]);
  }
}
st query(int n, int s, int e, int l, int r) {
  if (s > r || l > e) {
    st res;
    res.le = res.ri = res.len = res.all = 0;
    return res;
  }
  if (l <= s && e <= r) return seg[n];
  int mid = (s + e) / 2;
  st q1 = query(n + n, s, mid, l, r);
  st q2 = query(n + n + 1, mid + 1, e, l, r);
  return update_seg(q1, q2);
}
int main() {
  int n, q;
  scanf("%d", &n);
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &h[i]);
    v.push_back(h[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 1; i <= n; i++) {
    int idx = lower_bound(v.begin(), v.end(), h[i]) - v.begin();
    cur[idx].push_back(i);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d", &l[i], &r[i], &w[i]);
    lo2[i] = 0, hi2[i] = v.size() - 1;
  }
  while (1) {
    for (int i = 0; i < v.size(); i++) {
      mid2[i].clear();
      int h = v[i];
      int idx = lower_bound(v.begin(), v.end(), h) - v.begin();
      for (int j = 0; j < cur[idx].size(); j++) {
        int k = cur[idx][j];
        update(1, 1, n, k, 0);
      }
    }
    bool ok = 1;
    for (int i = 1; i <= q; i++) {
      if (lo2[i] <= hi2[i]) {
        int mid = (lo2[i] + hi2[i]) / 2;
        mid2[mid].push_back(i);
        ok = 0;
      }
    }
    if (ok) break;
    for (int i = v.size() - 1; i >= 0; i--) {
      int h = v[i];
      int idx = lower_bound(v.begin(), v.end(), h) - v.begin();
      for (int j = 0; j < cur[idx].size(); j++) {
        int k = cur[idx][j];
        update(1, 1, n, k, 1);
      }
      for (int j = 0; j < mid2[i].size(); j++) {
        int idx = mid2[i][j];
        st q = query(1, 1, n, l[idx], r[idx]);
        if (q.all >= w[idx]) {
          lo2[idx] = i + 1;
          ans[idx] = i;
        } else {
          hi2[idx] = i - 1;
        }
      }
    }
  }
  for (int i = 1; i <= q; i++) printf("%d\n", v[ans[i]]);
}
