#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const long long INF = 1e15;
const int N = 3e5 + 2;
const int mod = 998244353;
const double Pi = acos(-1);
void Fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n, timer = 0;
int p[200005], d[200005], color[200005];
int Euler[400005], ST[400005][20], tin[200005], tout[200005], L[400005],
    H[200005];
pair<int, int> SegTree[800005];
vector<int> Adj[200005];
int MinHeight(int x, int y) { return H[x] > H[y] ? y : x; }
void DFS(int node) {
  tin[node] = ++timer;
  ST[timer][0] = node;
  Euler[timer] = node;
  for (auto x : Adj[node]) {
    H[x] = H[node] + 1;
    DFS(x);
    Euler[++timer] = node;
    ST[timer][0] = node;
  }
  tout[node] = timer;
}
int LCA(int x, int y) {
  if (tin[x] > tin[y]) {
    swap(x, y);
  }
  int temp = L[tin[y] - tin[x] + 1];
  int tmp = tin[y] + 1 - (1 << temp);
  return MinHeight(ST[tin[x]][temp], ST[tin[y] + 1 - (1 << temp)][temp]);
}
bool Isparent(int u, int v) { return tin[u] <= tin[v] and tout[u] >= tout[v]; }
pair<int, int> Merge(pair<int, int> A, pair<int, int> B) {
  if (A.first == 0) {
    return B;
  }
  if (B.first == 0) {
    return A;
  }
  if (A.first == -1 or B.first == -1) {
    return make_pair(-1, -1);
  }
  int temp;
  temp = LCA(A.first, B.first);
  if (Isparent(temp, A.second) and Isparent(temp, B.second) and
      (Isparent(A.second, A.first) or Isparent(A.second, B.first)) and
      (Isparent(B.second, B.first) or Isparent(A.second, A.first))) {
    return make_pair(A.first, B.first);
  }
  temp = LCA(A.first, B.second);
  if (Isparent(temp, A.second) and Isparent(temp, B.first) and
      (Isparent(A.second, A.first) or Isparent(A.second, B.second)) and
      (Isparent(B.first, B.second) or Isparent(B.first, A.first))) {
    return make_pair(A.first, B.second);
  }
  temp = LCA(A.second, B.first);
  if (Isparent(temp, A.first) and Isparent(temp, B.second) and
      (Isparent(A.first, A.second) or Isparent(A.first, B.first)) and
      (Isparent(B.second, B.first) or Isparent(B.second, A.second))) {
    return make_pair(A.second, B.first);
  }
  temp = LCA(A.second, B.second);
  if (Isparent(temp, A.first) and Isparent(temp, B.first) and
      (Isparent(A.first, A.second) or Isparent(A.first, B.second)) and
      (Isparent(B.first, B.second) or Isparent(B.first, A.second))) {
    return make_pair(A.second, B.second);
  }
  temp = LCA(A.first, A.second);
  if (Isparent(temp, B.first) and Isparent(temp, B.second) and
      (Isparent(B.first, A.first) or Isparent(B.first, A.second)) and
      (Isparent(B.second, A.first) or Isparent(B.second, A.second))) {
    return A;
  }
  swap(A, B);
  temp = LCA(A.first, A.second);
  if (Isparent(temp, B.first) and Isparent(temp, B.second) and
      (Isparent(B.first, A.first) or Isparent(B.first, A.second)) and
      (Isparent(B.second, A.first) or Isparent(B.second, A.second))) {
    return A;
  }
  return make_pair(-1, -1);
}
void Build(int node, int l, int r) {
  if (l == r) {
    SegTree[node] = make_pair(p[l], p[l]);
    return;
  }
  int mid = (l + r) >> 1;
  Build(node << 1, l, mid);
  Build(node << 1 | 1, mid + 1, r);
  SegTree[node] = Merge(SegTree[node << 1], SegTree[node << 1 | 1]);
}
void PointUpdate(int node, int l, int r, int id) {
  if (l > id or r < id) {
    return;
  }
  if (l == r) {
    SegTree[node] = make_pair(p[l], p[l]);
    return;
  }
  int mid = (l + r) >> 1;
  PointUpdate(node << 1, l, mid, id);
  PointUpdate(node << 1 | 1, mid + 1, r, id);
  SegTree[node] = Merge(SegTree[node << 1], SegTree[node << 1 | 1]);
}
pair<int, int> Query(int node, int l, int r, int L, int R) {
  if (l > R or r < L) {
    return make_pair(0, 0);
  }
  if (L <= l and r <= R) {
    return SegTree[node];
  }
  int mid = (l + r) >> 1;
  return Merge(Query(node << 1, l, mid, L, R),
               Query(node << 1 | 1, mid + 1, r, L, R));
}
signed main() {
  Fastio();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> color[i];
    p[++color[i]] = i;
  }
  for (int i = 2; i <= n; i++) {
    int par;
    cin >> par;
    Adj[par].emplace_back(i);
  }
  L[0] = -1;
  for (int i = 1; i <= 400000; i++) {
    L[i] = L[i >> 1] + 1;
  }
  DFS(1);
  for (int i = 1; i <= 19; i++) {
    for (int j = 1; j + (1 << i) <= timer + 1; j++) {
      ST[j][i] = MinHeight(ST[j][i - 1], ST[j + (1 << (i - 1))][i - 1]);
    }
  }
  Build(1, 1, n);
  int q;
  int l, r;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int u, v;
      cin >> u >> v;
      swap(color[u], color[v]);
      p[color[u]] = u;
      p[color[v]] = v;
      PointUpdate(1, 1, n, color[u]);
      PointUpdate(1, 1, n, color[v]);
    } else {
      assert(type == 2);
      int l = 1, r = n;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (Query(1, 1, n, 1, mid).first != -1) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      cout << l << '\n';
    }
  }
}
