#include <bits/stdc++.h>
using namespace std;
int st[4 * 1000001];
int lazy[4 * 1000001];
void build(int si, int ss, int se) {
  if (ss == se) {
    return;
  }
  int mid = (ss + se) / 2;
  build(2 * si, ss, mid);
  build(2 * si + 1, mid + 1, se);
  st[si] = min(st[2 * si], st[2 * si + 1]);
}
void update(int si, int ss, int se, int qs, int qe, int x) {
  if (lazy[si] > 0) {
    int lz_sum = lazy[si];
    st[si] += lz_sum;
    lazy[si] = 0;
    if (ss != se) {
      lazy[2 * si] += lz_sum;
      lazy[2 * si + 1] += lz_sum;
    }
  }
  if (ss > qe || se < qs) return;
  if (ss >= qs && se <= qe) {
    st[si] += x;
    if (ss != se) {
      lazy[2 * si] += x;
      lazy[2 * si + 1] += x;
    }
    return;
  }
  int mid = (ss + se) / 2;
  update(2 * si, ss, mid, qs, qe, x);
  update(2 * si + 1, mid + 1, se, qs, qe, x);
  st[si] = min(st[2 * si], st[2 * si + 1]);
}
int query(int si, int ss, int se, int qs, int qe) {
  if (lazy[si] > 0) {
    int lz_sum = lazy[si];
    st[si] += lz_sum;
    lazy[si] = 0;
    if (ss != se) {
      lazy[2 * si] += lz_sum;
      lazy[2 * si + 1] += lz_sum;
    }
  }
  if (ss > qe || se < qs) return INT_MAX;
  if (ss >= qs && se <= qe) {
    return st[si];
  }
  int mid = (ss + se) / 2;
  return min(query(2 * si, ss, mid, qs, qe),
             query(2 * si + 1, mid + 1, se, qs, qe));
}
struct seg {
  int l, r, w;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<seg> vec(n + 1);
  for (int i = 1; i <= n; i++) cin >> vec[i].l >> vec[i].r >> vec[i].w;
  sort(vec.begin(), vec.end(), [](seg a, seg b) { return a.w < b.w; });
  int j = 0;
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) {
    while (j < n && query(1, 1, m, 1, m - 1) <= 0) {
      j++;
      update(1, 1, m, vec[j].l, vec[j].r - 1, 1);
    }
    if (query(1, 1, m, 1, m - 1) > 0) ans = min(vec[j].w - vec[i].w, ans);
    update(1, 1, m, vec[i].l, vec[i].r - 1, -1);
  }
  cout << ans << "\n";
  return 0;
}
