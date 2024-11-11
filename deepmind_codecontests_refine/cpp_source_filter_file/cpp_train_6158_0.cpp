#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, LOG = 16;
int n, m, q, pos[N], p[N], a[N], mn[N][LOG], t[4 * N], least[N];
vector<int> v[N];
void update(int node, int start, int end, int id, int val) {
  if (id < start || id > end) return;
  if (start == end) {
    t[node] = val;
    return;
  }
  int mid = (start + end) / 2;
  update(2 * node, start, mid, id, val);
  update(2 * node + 1, mid + 1, end, id, val);
  t[node] = min(t[2 * node], t[2 * node + 1]);
}
int query(int node, int start, int end, int l, int r) {
  if (r < start || l > end) return m + 1;
  if (start >= l && end <= r) return t[node];
  int mid = (start + end) / 2;
  int p1 = query(2 * node, start, mid, l, r);
  int p2 = query(2 * node + 1, mid + 1, end, l, r);
  return min(p1, p2);
}
int binaryLift(int id, int gap) {
  for (int j = LOG - 1; j >= 0; --j)
    if (gap >= (1 << j)) {
      id = mn[id][j];
      gap -= (1 << j);
    }
  return id;
}
int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    pos[p[i]] = i;
  }
  for (int i = 0; i < 4 * N; ++i) t[i] = m;
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    v[a[i]].push_back(i);
  }
  for (int i = 0; i <= n; ++i) v[i].push_back(m);
  if (n != 1) {
    for (int j = 0; j < LOG; ++j) mn[m][j] = m;
    for (int i = 0; i < m; ++i) {
      int id = pos[a[i]];
      int nxt = (id == n - 1) ? p[0] : p[id + 1];
      int nxtId = *lower_bound(v[nxt].begin(), v[nxt].end(), i);
      mn[i][0] = nxtId;
    }
    for (int j = 1; j < 4; ++j)
      for (int i = 0; i < m; ++i) {
        mn[i][j] = mn[mn[i][j - 1]][j - 1];
      }
    for (int i = 0; i < m; ++i) {
      least[i] = binaryLift(i, n - 1);
    }
    for (int i = 0; i < m; ++i) update(1, 0, m - 1, i, least[i]);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    if (query(1, 0, m - 1, l, r) <= r || n == 1)
      cout << "1";
    else
      cout << "0";
  }
  cout << "\n";
  return 0;
}
