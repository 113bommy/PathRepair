#include <bits/stdc++.h>
using namespace std;
const int MX = 5e5 + 69;
const int inf = 1e9 + 5;
const long long mod = 1e9 + 7;
const long double eps = 1e-10;
int a[MX];
bool b[MX];
vector<int> v[MX];
int n, k;
struct tree {
  int id, mn;
} sgt[4 * MX];
bool operator<(tree a, tree b) { return (a.mn < b.mn); }
void build(int x, int l, int r) {
  if (r < l) {
    return;
  }
  if (l == r) {
    sgt[x].id = l;
    sgt[x].mn = -1000000000;
    return;
  }
  int mid = (l + r) / 2;
  build(2 * x, l, mid);
  build(2 * x + 1, mid + 1, r);
  sgt[x] = max(sgt[2 * x], sgt[2 * x + 1]);
}
void update(int x, int l, int r, int id, int val) {
  if (l > r || r < id || l > id) {
    return;
  }
  if (l == id && r == id) {
    sgt[x].mn = val;
    return;
  }
  int mid = (l + r) / 2;
  update(2 * x, l, mid, id, val);
  update(2 * x + 1, mid + 1, r, id, val);
  sgt[x] = max(sgt[2 * x], sgt[2 * x + 1]);
}
tree query(int x, int l, int r, int st, int en) {
  if (l > r || r < st || l > en) {
    return {-1000000000, -1000000000};
  }
  if (l >= st && r <= en) {
    return sgt[x];
  }
  int mid = (l + r) / 2;
  return max(query(2 * x, l, mid, st, en),
             query(2 * x + 1, mid + 1, r, st, en));
}
int main() {
  int ans = 0, c = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v[a[i]].push_back(i);
  }
  build(1, 1, 400000);
  for (int i = 1; i <= n; i++) {
    if (!b[a[i]]) {
      c++;
      if (c > k) {
        tree q;
        q = query(1, 1, 400000, 1, 400000);
        b[q.id] = 0;
        update(1, 1, 400000, q.id, -1e9);
      }
      b[a[i]] = 1;
      if (v[a[i]].size() < 2) {
        update(1, 1, 400000, a[i], 1e9);
      } else {
        update(1, 1, 400000, a[i], v[a[i]][1]);
      }
      ans++;
    } else {
      if (v[a[i]].size() == 1) {
        update(1, 1, 400000, a[i], 1e9);
      } else {
        update(1, 1, 400000, a[i], v[a[i]][1]);
      }
    }
    v[a[i]].erase(v[a[i]].begin());
  }
  cout << ans;
  return 0;
}
