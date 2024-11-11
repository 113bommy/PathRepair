#include <bits/stdc++.h>
const int INF = 1000 * 1000 * 1000 + 47;
using namespace std;
const int mod = 998244853;
int n, w;
long long sum[1000005];
vector<int> a;
int mx[4000005];
int query(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return -INF;
  }
  if (tl == l && tr == r) return mx[v];
  int tm = (tl + tr) / 2;
  return max(query(v * 2, tl, tm, l, min(r, tm)),
             query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
void upd(int val, int l, int r) {
  sum[l] += val;
  sum[r + 1] -= val;
}
void build(int v, int tl, int tr) {
  if (tl == tr) {
    mx[v] = a[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  build(v * 2, tl, tm);
  build(v * 2 + 1, tm + 1, tr);
  mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> w;
  w += 2;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    a.resize(l + 2);
    a[0] = 0;
    a.back() = 0;
    for (int i = 1; i <= l; i++) cin >> a[i];
    l += 2;
    build(1, 0, l - 1);
    for (int i = 0; i < l; i++) {
      upd(query(1, 0, l - 1, max(0, i - (w - l)), i), i, i);
    }
    if (l <= w - l - 1) upd(mx[1], l, w - l - 1);
    for (int i = max(l, w - l); i < w; i++) {
      upd(query(1, 0, l - 1, i - (w - l), min(l - 1, i)), i, i);
    }
  }
  for (int i = 1; i < w; i++) sum[i] += sum[i - 1];
  w -= 2;
  for (int i = 1; i <= w; i++) cout << sum[i] << " ";
}
