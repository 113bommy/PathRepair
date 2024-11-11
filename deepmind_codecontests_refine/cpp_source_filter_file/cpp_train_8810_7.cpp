#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MAX_LOG = 19;
class SegmentTree {
 private:
  vector<long long> st, A, lazy;
  int n;
  inline int left(int p) { return (p << 1) + 1; }
  inline int right(int p) { return (p << 1) + 2; }
  inline int mid(int L, int R) { return (L + R) >> 1; }
  void build(int in, int la, int ra) {
    if (la == ra) {
      st[in] = A[la];
      return;
    }
    build(left(in), la, mid(la, ra));
    build(right(in), mid(la, ra) + 1, ra);
    long long p1 = st[left(in)], p2 = st[right(in)];
    st[in] = p1 + p2;
  }
  inline void update_lazy(int in, int la, int ra) {
    st[in] += lazy[in] * (ra - la + 1);
    if (la != ra) {
      lazy[left(in)] += lazy[in];
      lazy[right(in)] += lazy[in];
    } else {
      A[la] = st[in];
    }
    lazy[in] = 0;
  }
  long long rmq(int in, int la, int ra, int l, int r) {
    if (lazy[in]) update_lazy(in, la, ra);
    if (ra < l || r < la) return 0;
    if (l <= la && ra <= r) return st[in];
    long long p1 = rmq(left(in), la, mid(la, ra), l, r);
    long long p2 = rmq(right(in), mid(la, ra) + 1, ra, l, r);
    return p1 + p2;
  }
  void update_range(int in, int la, int ra, int l, int r, int val) {
    if (lazy[in]) update_lazy(in, la, ra);
    if (ra < l || r < la) return;
    if (l <= la && ra <= r) {
      lazy[in] = val;
      update_lazy(in, la, ra);
      return;
    }
    update_range(left(in), la, mid(la, ra), l, r, val);
    update_range(right(in), mid(la, ra) + 1, ra, l, r, val);
    long long p1 = st[left(in)], p2 = st[right(in)];
    st[in] = p1 + p2;
  }

 public:
  SegmentTree(int n) {
    A.assign(n, 0);
    init(n);
  }
  SegmentTree(const vector<long long> &_A) {
    A = _A;
    n = (int)A.size();
    init(n);
  }
  void init(int n) {
    st.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
    build(0, 0, n - 1);
  }
  int rmq(int i, int j) { return rmq(0, 0, n - 1, i, j); }
  void update_point(int idx, int new_value) {
    update_range(0, 0, n - 1, idx, idx, new_value);
  }
  void update_range(int l, int r, int new_value) {
    update_range(0, 0, n - 1, l, r, new_value);
  }
};
long long A[N], sum[N];
int depth[N], par[N][MAX_LOG];
vector<int> adj[N];
int nc = 0;
int euler[N], L[N], R[N];
void dfs(int a, int p) {
  par[a][0] = p;
  sum[a] = A[a];
  euler[++nc] = a;
  L[a] = nc;
  for (int i : adj[a]) {
    if (i == p) continue;
    depth[i] = depth[a] + 1;
    dfs(i, a);
    sum[a] += sum[i];
  }
  R[a] = nc;
}
int GetLCA(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  for (int i = MAX_LOG - 1; i >= 0; i--)
    if (depth[a] - (1 << i) >= depth[b]) a = par[a][i];
  if (a == b) return a;
  for (int i = MAX_LOG - 1; i >= 0; i--)
    if (par[a][i] != 0 && par[a][i] != par[b][i]) {
      a = par[a][i];
      b = par[b][i];
    }
  return par[a][0];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  for (int i = 1; i < MAX_LOG; i++) {
    for (int j = 1; j <= n; j++) {
      if (par[j][i - 1]) par[j][i] = par[par[j][i - 1]][i - 1];
    }
  }
  vector<long long> st_arr(n + 1);
  for (int i = 1; i <= n; i++) {
    st_arr[i] = A[euler[i]];
  }
  SegmentTree st(st_arr);
  int root = 1;
  while (q--) {
    int a;
    cin >> a;
    if (a == 1) {
      int v;
      cin >> v;
      root = v;
    } else if (a == 2) {
      int u, v, val;
      cin >> u >> v >> val;
      int x = 1;
      int uv = GetLCA(u, v);
      if (L[uv] <= L[root] && L[root] <= R[uv]) {
        int __u = GetLCA(u, root);
        int __v = GetLCA(v, root);
        if (__u == uv)
          x = __v;
        else
          x = __u;
      } else {
        x = uv;
      }
      if (root == x) {
        st.update_range(L[1], R[1], val);
        continue;
      }
      int lca = GetLCA(root, x);
      if (lca == x) {
        int delta = depth[root] - depth[x] - 1;
        x = root;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
          if (delta >= (1 << i)) {
            x = par[x][i];
            delta -= (1 << i);
          }
        }
        st.update_range(L[1], R[1], val);
        st.update_range(L[x], R[x], -val);
      } else
        st.update_range(L[x], R[x], val);
    } else {
      int v;
      cin >> v;
      int x = v;
      if (root == x) {
        cout << st.rmq(L[1], R[1]) << "\n";
        continue;
      }
      int lca = GetLCA(root, x);
      if (lca == x) {
        int delta = depth[root] - depth[x] - 1;
        x = root;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
          if (delta >= (1 << i)) {
            x = par[x][i];
            delta -= (1 << i);
          }
        }
        cout << st.rmq(L[1], R[1]) - st.rmq(L[x], R[x]) << "\n";
      } else {
        cout << st.rmq(L[x], R[x]) << "\n";
      }
    }
  }
  return 0;
}
