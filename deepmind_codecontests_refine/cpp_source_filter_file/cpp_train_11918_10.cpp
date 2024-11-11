#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 111;
const long long INF = (long long)1e18;
int n, m;
long long d[N], h[N], dist[N];
bool maximize(long long &x, long long y) {
  if (x >= y) return false;
  x = y;
  return true;
}
bool minimize(long long &x, long long y) {
  if (x <= y) return false;
  x = y;
  return true;
}
struct node {
  pair<long long, int> c[2];
};
node MAX, MIN;
void mergeMinValue(node &x, node y, node z) {
  int i = 0, j = 0;
  for (int k = 0; k < 2; ++k) {
    if (y.c[i].first <= z.c[j].first)
      x.c[k] = y.c[i++];
    else
      x.c[k] = z.c[j++];
  }
}
void mergeMaxValue(node &x, node y, node z) {
  int i = 0, j = 0;
  for (int k = 0; k < 2; ++k) {
    if (y.c[i].first >= z.c[j].first)
      x.c[k] = y.c[i++];
    else
      x.c[k] = z.c[j++];
  }
}
struct tree {
  vector<node> maxValue;
  tree() { maxValue.resize(N * 4); }
  void init(int id, int l, int r) {
    for (int i = 0; i < 2; ++i) {
      maxValue[id].c[i].first = -INF;
      maxValue[id].c[i].second = l;
    }
    if (l == r) return;
    int mid = (l + r) / 2;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
  }
  void upd(int id, int l, int r, int k, long long value) {
    if (l == r) {
      maximize(maxValue[id].c[0].first, value);
      return;
    }
    int mid = (l + r) / 2;
    if (k <= mid)
      upd(id * 2, l, mid, k, value);
    else
      upd(id * 2 + 1, mid + 1, r, k, value);
    mergeMaxValue(maxValue[id], maxValue[id * 2], maxValue[id * 2 + 1]);
  }
  node getMax(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return MIN;
    if (u <= l && r <= v) return maxValue[id];
    int mid = (l + r) / 2;
    node tmp1 = getMax(id * 2, l, mid, u, v);
    node tmp2 = getMax(id * 2 + 1, mid + 1, r, u, v);
    node res;
    mergeMaxValue(res, tmp1, tmp2);
    return res;
  }
} it1, it2;
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
    d[i + n] = d[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
    h[i + n] = h[i];
  }
  for (int i = 1; i <= n * 2; ++i) dist[i] = dist[i - 1] + d[i - 1];
  for (int i = 0; i < 2; ++i) MAX.c[i].first = INF, MIN.c[i].first = -INF;
  it1.init(1, 1, n * 2);
  it2.init(1, 1, n * 2);
  for (int i = 1; i <= n * 2; ++i) {
    it1.upd(1, 1, n * 2, i, 2 * h[i] - dist[i]);
    it2.upd(1, 1, n * 2, i, 2 * h[i] + dist[i]);
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    node tmp1, tmp2;
    if (l <= r) {
      tmp1 = it1.getMax(1, 1, n * 2, r + 1, l + n - 1);
      tmp2 = it2.getMax(1, 1, n * 2, r + 1, l + n - 1);
    } else {
      tmp1 = it1.getMax(1, 1, n, r + 1, l - 1);
      tmp2 = it2.getMax(1, 1, n, r + 1, l - 1);
    }
    long long res = 0;
    for (int i = 0; i <= 1; ++i) {
      for (int j = 0; j <= 1; ++j) {
        if (tmp1.c[i].second != tmp2.c[j].second) {
          maximize(res, tmp1.c[i].first + tmp2.c[j].first);
        }
      }
    }
    cout << res << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
