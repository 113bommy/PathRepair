#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct TRec {
  int x1, y1, x2, y2, id;
} rec[maxn << 1];
pair<int, int> r[maxn << 1];
int n, m, k, q;
int ans[maxn << 1], st[maxn << 2];
void update(int id, int l, int r, int u, int val) {
  if (l > u || r < u) return;
  if (l == r) {
    st[id] = val;
    return;
  }
  int mid = l + r >> 1;
  update(id << 1, l, mid, u, val);
  update(id << 1 | 1, mid + 1, r, u, val);
  st[id] = min(st[id << 1], st[id << 1 | 1]);
}
int GetMin(int id, int l, int r, int u, int v) {
  if (l > v || r < u) return 1e9;
  if (u <= l && r <= v) return st[id];
  int mid = l + r >> 1;
  return min(GetMin(id << 1, l, mid, u, v),
             GetMin(id << 1 | 1, mid + 1, r, u, v));
}
void Solve() {
  sort(rec + 1, rec + 1 + q,
       [](const TRec &A, const TRec &B) { return A.x2 < B.x2; });
  sort(r + 1, r + 1 + k);
  memset(st, 0, sizeof(st));
  int l = 1;
  for (int i = 1; i <= q; ++i) {
    while (l <= k && r[l].first <= rec[i].x2) {
      update(1, 1, n, r[l].second, r[l].first);
      ++l;
    }
    ans[rec[i].id] |= (GetMin(1, 1, n, rec[i].y1, rec[i].y2) >= rec[i].x1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k >> q;
  n = max(n, m);
  for (int i = 1; i <= k; ++i) {
    cin >> r[i].first >> r[i].second;
  }
  for (int i = 1; i <= q; ++i) {
    cin >> rec[i].x1 >> rec[i].y1 >> rec[i].x2 >> rec[i].y2;
    rec[i].id = i;
  }
  Solve();
  for (int i = 1; i <= k; ++i) swap(r[i].first, r[i].second);
  for (int i = 1; i <= q; ++i)
    swap(rec[i].x1, rec[i].y1), swap(rec[i].x2, rec[i].y2);
  Solve();
  for (int i = 1; i <= q; ++i)
    if (ans[i])
      cout << "YES\n";
    else
      cout << "NO\n";
  return 0;
}
