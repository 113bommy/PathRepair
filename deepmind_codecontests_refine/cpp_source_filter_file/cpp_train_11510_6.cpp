#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, a[N];
map<int, int> p;
long long sum[N], tree[4 * N], ans[N];
struct data {
  int x, y;
  int k, t;
};
data q[N];
bool cmp(data u, data v) { return (u.y < v.y || (u.y == v.y && u.x < v.x)); }
void Input() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] ^ a[i];
    q[i].x = -1, q[i].y = i, q[i].k = a[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> q[i + n].x >> q[i + n].y;
    q[i + n].t = i;
  }
  m = m + n;
  sort(q + 1, q + m + 1, cmp);
}
void Update(int k, int l, int r, int idx, int val) {
  if (l > idx || r < idx) return;
  if (l == r) {
    tree[k] = val;
    return;
  }
  int mid = (l + r) / 2;
  Update(k * 2, l, mid, idx, val);
  Update(k * 2 + 1, mid + 1, r, idx, val);
  tree[k] = tree[k * 2] ^ tree[k * 2 + 1];
}
long long Get(int k, int l, int r, int L, int R) {
  if (l > R || r < L) return 0;
  if (L <= l && r <= R) return tree[k];
  int mid = (l + r) / 2;
  return (Get(k * 2, l, mid, L, R) ^ Get(k * 2 + 1, mid + 1, r, L, R));
}
void Solve() {
  for (int i = 1; i <= m; i++) {
    if (q[i].x < 0) {
      if (p[q[i].k] != 0) Update(1, 1, n, p[q[i].k], 0);
      Update(1, 1, n, q[i].y, q[i].k);
      p[q[i].k] = q[i].y;
    } else {
      long long t_sum = sum[q[i].y] ^ sum[q[i].x - 1];
      long long d_sum = Get(1, 1, n, q[i].x, q[i].y);
      ans[q[i].t] = d_sum ^ t_sum;
    }
  }
  for (int i = 1; i <= m - n; i++) cout << ans[i] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  Input();
  Solve();
  return 0;
}
