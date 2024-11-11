#include <bits/stdc++.h>
using namespace std;
const long long NQ = (long long)8e5 + 10LL;
long long n, nq, s[NQ], f[NQ], cm[NQ], st[4 * NQ], lazy[4 * NQ];
vector<long long> t[NQ], et(0);
void lazy_prop(long long idx) {
  if (lazy[idx] != -1) {
    st[idx] = lazy[idx];
    st[2 * idx] = lazy[2 * idx] = lazy[idx];
    st[(2 * idx) + 1] = lazy[(2 * idx) + 1] = lazy[idx];
    lazy[idx] = -1;
  }
}
void update(long long idx, long long l, long long r, long long x, long long y,
            long long mask) {
  if (r > l) lazy_prop(idx);
  if (x > r or y < l or l > r) return;
  if (x <= l and y >= r) {
    st[idx] = mask;
    lazy[idx] = mask;
    return;
  }
  long long mid = (l + r) / 2;
  update(2 * idx, l, mid, x, y, mask);
  update((2 * idx) + 1, mid + 1, r, x, y, mask);
  st[idx] = st[2 * idx] | st[(2 * idx) + 1];
}
long long query(long long idx, long long l, long long r, long long x,
                long long y) {
  if (r > l) lazy_prop(idx);
  if (x > r or y < l or l > r) return 0LL;
  if (x <= l and y >= r) return st[idx];
  long long mid = (l + r) / 2;
  return query(2 * idx, l, mid, x, y) | query((2 * idx) + 1, mid + 1, r, x, y);
}
void solve() {
  int qt, v, c;
  long long mask, ans;
  for (int i = 0; i < nq; i++) {
    cin >> qt;
    if (qt == 1) {
      cin >> v >> c;
      mask = (1LL << c);
      update(1, 0, (2 * n) - 1, s[v], f[v], mask);
    } else {
      cin >> v;
      mask = query(1, 0, (2 * n) - 1, s[v], f[v]);
      ans = 0;
      for (int i = 1; i <= 60; i++)
        if ((1LL << i) & mask) ans++;
      cout << ans << endl;
    }
  }
}
void euler_walk(int v, int p) {
  et.push_back(cm[v]);
  s[v] = et.size() - 1;
  for (int j = 0; j < t[v].size(); j++)
    if (t[v][j] != p) euler_walk(t[v][j], v);
  et.push_back(cm[v]);
  f[v] = et.size() - 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> nq;
  for (int i = 1; i <= n; i++) {
    cin >> cm[i];
    cm[i] = (1LL << cm[i]);
  }
  int u, v;
  for (int i = 0; i < (n - 1); i++) {
    cin >> u >> v;
    t[v].push_back(u);
    t[u].push_back(v);
  }
  euler_walk(1, -1);
  memset(st, 0, sizeof(st));
  memset(lazy, -1, sizeof(lazy));
  assert(et.size() == (2 * n));
  for (int i = 0; i < et.size(); i++) update(1, 0, (2 * n) - 1, i, i, et[i]);
  solve();
  return 0;
}
