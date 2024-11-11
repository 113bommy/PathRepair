#include <bits/stdc++.h>
using namespace std;
const int N = 100 * 1000 + 10;
int a[N], l[N], r[N], seg[N * 4], lazy[N * 4];
void f(int v, int s, int e) {
  seg[v] = e - s - seg[v];
  lazy[v] ^= 1;
}
void shift(int v, int s, int e) {
  if (lazy[v] == 0) return;
  int mid = (s + e) / 2;
  lazy[v] = 0;
  f(2 * v, s, mid);
  f(2 * v + 1, mid, e);
}
void upd(int l, int r, int v, int s, int e) {
  if (l <= s && e <= r) {
    f(v, s, e);
    return;
  }
  if (l >= e || r <= s) return;
  int mid = (s + e) / 2;
  shift(v, s, mid);
  upd(l, r, 2 * v, s, mid);
  upd(l, r, 2 * v + 1, mid, e);
  seg[v] = seg[2 * v] + seg[2 * v + 1];
}
int get(int p, int v, int s, int e) {
  if (e - s < 2) return seg[v];
  int mid = (s + e) / 2;
  shift(v, s, e);
  if (p < mid) return get(p, 2 * v, s, mid);
  return get(p, 2 * v + 1, mid, e);
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n - 1; i++) cin >> a[i];
  sort(a, a + n);
  a[n] = (1000 * 1000 * 1000) + 10;
  vector<pair<int, int> > vec;
  for (int i = 0; i <= m - 1; i++) {
    int x, y;
    cin >> x >> y;
    y++;
    l[i] = lower_bound(a, a + n, x) - a;
    r[i] = lower_bound(a, a + n, y) - a;
    vec.push_back(make_pair(a[l[i]], i));
    vec.push_back(make_pair(a[r[i]], i));
  }
  sort((vec).begin(), (vec).end());
  long long ans = 1LL * n * (n - 1) * (n - 2) / 6;
  int ind = 0;
  for (int i = 0; i <= n - 1; i++) {
    while (ind < ((int)(vec).size()) && vec[ind].first == a[i])
      upd(l[vec[ind].second], r[vec[ind].second], 1, 0, n), ind++;
    long long d = seg[1] - get(i, 1, 0, n);
    ans -= d * (d - 1) / 2;
    upd(i, i + 1, 1, 0, n);
  }
  cout << ans << endl;
  return 0;
}
