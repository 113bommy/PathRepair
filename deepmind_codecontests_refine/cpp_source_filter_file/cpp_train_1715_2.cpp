#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} debug1;
template <typename T1, typename T2>
inline ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
const int NN = (1 << 18);
const int inf = numeric_limits<int>::max();
int seg[NN << 1], lazy[NN << 1];
int cnt[NN << 1];
int bit[NN];
vector<pair<int, int>> adj[NN];
int out[NN], x[NN], len[NN];
void update(int i, int v) {
  for (i += 5; i < NN; i += i & -i) bit[i] += v;
}
int query(int i) {
  int ans = 0;
  for (i += 5; i > 0; i -= i & -i) ans += bit[i];
  return ans;
}
void pushdown(int node, int st, int en) {
  if (!lazy[node]) return;
  seg[node] = max(seg[node], lazy[node]);
  if (st != en) {
    lazy[2 * node] = max(lazy[2 * node], lazy[node]);
    lazy[2 * node + 1] = max(lazy[2 * node + 1], lazy[node]);
  }
  lazy[node] = 0;
}
void update(int node, int st, int en, int L, int R, int vv) {
  pushdown(node, st, en);
  if (st > en or st > R or en < L) return;
  if (st >= L and en <= R) {
    lazy[node] = max(lazy[node], vv);
    pushdown(node, st, en);
    return;
  }
  int mid = (st + en) / 2;
  update(2 * node, st, mid, L, R, vv);
  update(2 * node + 1, mid + 1, en, L, R, vv);
}
int query(int node, int st, int en, int pos) {
  pushdown(node, st, en);
  if (st == en) return seg[node];
  int mid = (st + en) / 2;
  if (mid >= pos) return query(2 * node, st, mid, pos);
  return query(2 * node + 1, mid + 1, en, pos);
}
void solve() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i] >> len[i];
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[b].push_back({a, i});
  }
  update(1, 0, n - 1, 0, 0, x[0] + len[0]);
  for (int i = 1; i < n; ++i) {
    int st = 0, en = i - 1;
    int res = NN;
    while (st <= en) {
      int mid = (st + en) / 2;
      if (query(1, 0, n - 1, mid) < x[i]) {
        res = mid;
        en = mid - 1;
      } else
        st = mid + 1;
    }
    while (res < i) {
      int vv = query(1, 0, n - 1, res);
      st = res, en = i - 1;
      int tmp = NN;
      while (st <= en) {
        int mid = (st + en) / 2;
        if (query(1, 0, n - 1, mid) < vv) {
          tmp = mid;
          en = mid - 1;
        } else
          st = mid + 1;
      }
      int add = x[i] - vv;
      update(res, add);
      update(tmp, -add);
      res = tmp;
    }
    update(1, 0, n - 1, 0, i, x[i] + len[i]);
    for (auto tmp : adj[i]) {
      int bg = tmp.first;
      int k = tmp.second;
      out[k] = query(bg);
    }
  }
  for (int i = 0; i < m; ++i) cout << out[i] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
