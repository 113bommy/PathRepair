#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 9;
int l, r, n, k, seg[MAX * 4], lz[MAX * 4], a[MAX];
long long ans, t;
vector<pair<int, int> > o[MAX];
void shift(int s, int e, int m, int id) {
  if (lz[id]) {
    lz[id * 2 + 1] ^= 1, lz[id * 2 + 2] ^= 1;
    seg[id * 2 + 1] = m - s - seg[id * 2 + 1];
    seg[id * 2 + 2] = e - m - seg[id * 2 + 2];
    lz[id] ^= 1;
  }
}
void upd(int l, int r, int s = 0, int e = n, int id = 0) {
  if (r <= s || e <= l) return;
  if (l <= s && e <= r) {
    seg[id] = e - s - seg[id], lz[id] ^= 1;
    return;
  }
  int mid = s + e >> 1;
  shift(s, e, mid, id);
  upd(l, r, s, mid, id * 2 + 1), upd(l, r, mid, e, id * 2 + 2);
  seg[id] = seg[id * 2 + 1] + seg[id * 2 + 2];
}
int get(int l, int r, int s = 0, int e = n, int id = 0) {
  if (r <= s || e <= l) return 0;
  if (l <= s && e <= r) return seg[id];
  int mid = s + e >> 1;
  shift(s, e, mid, id);
  return get(l, r, s, mid, id * 2 + 1) + get(l, r, mid, e, id * 2 + 2);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k, ans = -n * (n - 2) * (n - 1) / 6;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < k; i++)
    cin >> l >> r, l = lower_bound(a, a + n, l) - a,
                   r = upper_bound(a, a + n, r) - a, o[l].push_back({l, r}),
                   o[r].push_back({l, r});
  for (int i = 0; i < n; i++) {
    for (auto j : o[i]) upd(j.first, j.second);
    if (i) upd(i - 1, i);
    t = get(0, n);
    if (get(i, i + 1)) t--;
    ans += t * (n - t - 1);
  }
  cout << ans / 2;
  return 0;
}
