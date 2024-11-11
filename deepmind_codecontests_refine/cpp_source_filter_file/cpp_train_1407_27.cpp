#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int n, m;
int a[MAXN], b[MAXN], l[MAXN];
pair<int, int> q[MAXN];
int idx[MAXN];
int sols[MAXN];
int dad[MAXN], sz[MAXN];
int cnt;
vector<int> undo1, undo3;
vector<pair<int, int>> undo2;
int find(int i) { return dad[i] == dad[dad[i]] ? dad[i] : (find(dad[i])); }
void merge(int id) {
  int x = find(a[id]);
  int y = find(b[id]);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  undo3.push_back(cnt);
  if (sz[x] % 2 && sz[y] % 2) cnt -= 2;
  undo2.push_back({x, sz[x]});
  sz[x] += sz[y];
  undo1.push_back(y);
  dad[y] = x;
}
void rollback() {
  dad[undo1.back()] = undo1.back();
  sz[undo2.back().first] = undo2.back().second;
  cnt = undo3.back();
  undo1.pop_back();
  undo2.pop_back();
  undo3.pop_back();
}
void rek(int l, int r, int ll, int rr) {
  if (l >= r) return;
  int i, prv = undo1.size();
  int mid = (l + r) / 2, mmid = -1;
  for (i = l; i <= mid; ++i)
    if (idx[i] < ll) merge(i);
  for (i = ll; i < rr; ++i)
    if (q[i].second <= mid) {
      merge(q[i].second);
      if (cnt == 0) {
        mmid = i;
        break;
      }
    }
  while (undo1.size() > prv) rollback();
  if (mmid == -1) {
    for (i = l; i <= mid; ++i) sols[i] = -1;
    for (i = l; i <= mid; ++i)
      if (idx[i] < ll) merge(i);
    rek(mid + 1, r, ll, rr);
    while (undo1.size() > prv) rollback();
    return;
  }
  sols[mid] = q[mmid].first;
  for (i = ll; i < mmid; ++i)
    if (q[i].second < l) merge(q[i].second);
  rek(l, mid, mmid, rr);
  while (undo1.size() > prv) rollback();
  for (i = l; i <= mid; ++i)
    if (idx[i] < ll) merge(i);
  rek(mid + 1, r, ll, mmid + 1);
  while (undo1.size() > prv) rollback();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int i;
  cin >> n >> m;
  for (i = 0; i < m; ++i) {
    cin >> a[i] >> b[i] >> l[i];
    q[i] = {l[i], i};
  }
  sort(q, q + m);
  for (i = 0; i < m; ++i) idx[q[i].second] = i;
  for (i = 0; i < n; ++i) {
    dad[i] = i;
    sz[i] = 1;
  }
  cnt = n;
  rek(0, m, 0, m);
  for (i = 0; i < m; ++i) cout << sols[i] << '\n';
}
