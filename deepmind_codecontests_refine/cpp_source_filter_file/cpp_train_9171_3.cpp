#include <bits/stdc++.h>
using namespace std;
const int mx = 1000000000;
int n, k, idx;
struct segment_tree {
  int l, r, val;
} seg[5000005];
int rt[100005];
struct robot {
  int x, r, q;
} arr[100005];
vector<int> v;
void add(int &id, int l, int r, int p) {
  if (!id) id = ++idx;
  seg[id].val++;
  if (l == r) return;
  int m = (l + r) >> 1;
  if (p <= m)
    add(seg[id].l, l, m, p);
  else
    add(seg[id].r, m + 1, r, p);
}
long long query(int id, int l, int r, int ql, int qr) {
  if (!id) return 0;
  if (ql <= l && qr >= r) return seg[id].val;
  long long m = (l + r) >> 1, ans = 0;
  if (ql <= m) ans += query(seg[id].l, l, m, ql, qr);
  if (qr > m) ans += query(seg[id].r, m + 1, r, ql, qr);
  return ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  ;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].x >> arr[i].r >> arr[i].q;
    v.push_back(arr[i].q);
  }
  sort((v).begin(), (v).end());
  v.resize(unique((v).begin(), (v).end()) - v.begin());
  sort(arr + 1, arr + 1 + n, [](robot &a, robot &b) { return a.r > b.r; });
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int idx = lower_bound((v).begin(), (v).end(), arr[i].q - k) - v.begin();
    for (; idx < v.size() && v[idx] < arr[i].q + k; idx++) {
      ans += query(rt[idx], 0, mx, max(arr[i].x - arr[i].r, 0),
                   min(arr[i].x + arr[i].r, mx));
    }
    idx = lower_bound((v).begin(), (v).end(), arr[i].q) - v.begin();
    add(rt[idx], 0, mx, arr[i].x);
  }
  cout << ans << '\n';
}
