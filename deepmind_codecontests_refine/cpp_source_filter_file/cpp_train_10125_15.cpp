#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int N = 4e5 + 10;
const int inf = 1e9;
int n, k, m;
map<pair<int, int>, int> vis;
int mx[N << 2], tag[N << 2];
int a[N];
void pd(int p, int k) {
  mx[p << 1] += k;
  tag[p << 1] += k;
  mx[p << 1 | 1] += k;
  tag[p << 1 | 1] += k;
  tag[p] = 0;
}
void up(int dl, int dr, int l, int r, int p, int k) {
  if (l == dl && r == dr) {
    mx[p] += k;
    tag[p] += k;
    return;
  }
  int mid = l + r >> 1;
  pd(p, tag[p]);
  if (dr <= mid)
    up(dl, dr, l, mid, p << 1, k);
  else if (dl > mid)
    up(dl, dr, mid + 1, r, p << 1 | 1, k);
  else
    up(dl, mid, l, mid, p << 1, k), up(mid + 1, dr, mid + 1, r, p << 1 | 1, k);
  mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    int p = abs(x - k) + y;
    if (vis.count(make_pair(x, y))) {
      up(1, p, 1, 2 * n, 1, -1);
      a[p]--;
      if (a[p] == 0) up(p, p, 1, 2 * n, 1, -p + 1);
      vis[make_pair(x, y)] = 0;
    } else {
      up(1, p, 1, 2 * n, 1, 1);
      if (a[p] == 0) up(p, p, 1, 2 * n, 1, p - 1);
      ++a[p];
      vis[make_pair(x, y)] = 1;
    }
    cout << max(0, mx[1] - n) << '\n';
  }
  return 0;
}
