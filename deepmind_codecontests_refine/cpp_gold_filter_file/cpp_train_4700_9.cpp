#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
  if (x < y) x = y;
}
mt19937 rnd(time(0));
int n, k;
const int MAXN = 2e6 + 228;
const int lgg = 20;
int nxt[MAXN];
int root;
int a[MAXN];
vector<int> g[MAXN];
int tin[MAXN];
int tout[MAXN];
int tl = 0;
int t[4 * MAXN];
int add[4 * MAXN];
void push(int v, int l, int r) {
  if (l != r - 1) {
    add[2 * v + 1] += add[v];
    add[2 * v + 2] += add[v];
  }
  t[v] += add[v];
  add[v] = 0;
}
void upd(int v, int l, int r, int ql, int qr, int x) {
  push(v, l, r);
  if (l >= qr || ql >= r) return;
  if (l >= ql && r <= qr) {
    add[v] += x;
    push(v, l, r);
    return;
  }
  upd(2 * v + 1, l, (l + r) / 2, ql, qr, x);
  upd(2 * v + 2, (l + r) / 2, r, ql, qr, x);
  t[v] = max(t[2 * v + 1], t[2 * v + 2]);
}
void dfs(int v, int p) {
  tin[v] = tl++;
  for (int i : g[v]) {
    if (i != p) dfs(i, v);
  }
  tout[v] = tl++;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.precision(20), cout.setf(ios::fixed);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> st;
  root = n;
  fill(nxt, nxt + n, n);
  for (int i = 0; i < n; ++i) {
    while (st.size() && st.back().first < a[i]) {
      nxt[st.back().second] = i;
      st.pop_back();
    }
    st.push_back({a[i], i});
  }
  for (int i = 0; i < n; ++i) {
    g[nxt[i]].push_back(i);
  }
  dfs(root, root);
  for (int i = 0; i < k; ++i) {
    upd(0, 0, MAXN, tin[i], tout[i], 1);
  }
  for (int i = 0; i + k - 1 < n; ++i) {
    cout << t[0] << ' ';
    if (i + k < n) {
      upd(0, 0, MAXN, tin[i + k], tout[i + k], 1);
    }
    upd(0, 0, MAXN, tin[i], tout[i], -2);
  }
}
