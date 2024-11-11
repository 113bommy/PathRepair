#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q, s[N];
vector<pair<int, int> > vec[N];
struct node {
  int sum, lazy;
} seg[N << 2];
void shift(int id, int b, int e) {
  if (seg[id].lazy) {
    int mid = (b + e) >> 1, lc = id * 2, rc = lc | 1;
    seg[lc].lazy ^= 1;
    seg[rc].lazy ^= 1;
    seg[lc].sum = mid - b - seg[lc].sum;
    seg[rc].sum = e - mid - seg[rc].sum;
    seg[id].lazy = 0;
  }
}
void modify(int l, int r, int id = 1, int b = 0, int e = n) {
  if (l >= e || b >= r) return;
  if (l <= b && e <= r) {
    seg[id].sum = e - b - seg[id].sum;
    seg[id].lazy ^= 1;
    return;
  }
  shift(id, b, e);
  int mid = (b + e) >> 1, lc = id * 2, rc = lc | 1;
  modify(l, r, lc, b, mid);
  modify(l, r, rc, mid, e);
  seg[id].sum = seg[lc].sum + seg[rc].sum;
  return;
}
long long get(int l, int r, int id = 1, int b = 0, int e = n) {
  if (l >= e || b >= r) return 0;
  if (l <= b && e <= r) return seg[id].sum;
  shift(id, b, e);
  int mid = (b + e) >> 1, lc = id * 2, rc = lc | 1;
  return get(l, r, lc, b, mid) + get(l, r, rc, mid, e);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> s[i];
  sort(s, s + n);
  for (int t = 0; t < q; t++) {
    int x, y;
    cin >> x >> y;
    int l = lower_bound(s, s + n, x) - s, r = lower_bound(s, s + n, y + 1) - s;
    pair<int, int> p = make_pair(l, r);
    vec[l].push_back(p);
    vec[r].push_back(p);
  }
  long long ans = 1LL * n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; i++) {
    while (!vec[i].empty()) {
      pair<int, int> p = vec[i].back();
      vec[i].pop_back();
      int l = p.first, r = p.second;
      modify(l, r);
    }
    long long x = get(i + 1, n) + i - get(0, i);
    x = (x * (x - 1)) / 2;
    ans -= x;
  }
  cout << ans << "\n";
}
