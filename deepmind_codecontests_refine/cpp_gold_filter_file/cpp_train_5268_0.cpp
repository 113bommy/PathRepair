#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10, MN = 1e5 + 10, MV = 2e6 + 10;
struct node {
  pair<int, int> R[10], L[10];
  int C;
  node() {
    for (int i = 0; i < 10; ++i) L[i] = R[i] = {-1, -1};
    C = 0;
  }
} seg[MN << 2];
unordered_set<long long> M;
int n, k;
int arr[12][MN];
int par[MV], sz[MV];
int root(int a) {
  if (par[a] == a) return a;
  return par[a] = root(par[a]);
}
void Union(int a, int b) {
  a = root(a), b = root(b);
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a;
  sz[a] += sz[b];
}
node mrg(node A, node B) {
  if (A.C == 0) return B;
  if (B.C == 0) return A;
  node ret;
  ret.C = A.C + B.C;
  for (int i = 0; i < k; ++i) {
    if (A.R[i].second == B.L[i].second) {
      Union(2 * A.R[i].first + 1, 2 * B.L[i].first);
      M.insert(1ll * A.R[i].first * INF + 1ll * B.L[i].first);
    }
  }
  ret.C -= ((int)(M).size());
  M.clear();
  for (int i = 0; i < k; ++i) {
    ret.L[i] = {root(2 * A.L[i].first + 1), A.L[i].second};
    ret.R[i] = {root(2 * B.R[i].first), B.R[i].second};
  }
  for (int i = 0; i < k; ++i) {
    int x = 2 * A.R[i].first + 1, y = 2 * B.L[i].first;
    par[x] = x, par[y] = y;
    sz[x] = sz[y] = 1;
  }
  return ret;
}
void build(int id, int b, int e) {
  if (e - b == 1) {
    int tmp = 0;
    for (int i = 0; i < k; ++i) {
      if (i && arr[i][b] != arr[i - 1][b])
        seg[id].L[i] = seg[id].R[i] = {++tmp, arr[i][b]};
      else
        seg[id].R[i] = seg[id].L[i] = {tmp, arr[i][b]};
      seg[id].C = tmp + 1;
    }
    return;
  }
  int mid = b + e >> 1;
  build(id << 1, b, mid), build(id << 1 | 1, mid, e);
  seg[id] = mrg(seg[id << 1], seg[id << 1 | 1]);
}
node get(int id, int b, int e, int l, int r) {
  if (r <= b || e <= l) return node();
  if (l <= b && e <= r) return seg[id];
  int mid = b + e >> 1;
  return mrg(get(id << 1, b, mid, l, r), get(id << 1 | 1, mid, e, l, r));
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  for (int i = 0; i < MV; ++i) par[i] = i, sz[i] = 1;
  int q;
  cin >> k >> n >> q;
  for (int i = 0; i < k; ++i)
    for (int j = 0; j < n; ++j) cin >> arr[i][j];
  build(1, 0, n);
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << get(1, 0, n, l - 1, r).C << '\n';
  }
  return 0;
}
