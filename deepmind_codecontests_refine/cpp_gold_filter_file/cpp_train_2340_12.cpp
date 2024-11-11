#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
pair<int, int> tr[4 * N];
int lz[4 * N];
void propagate(int u, int st, int en) {
  tr[u].first += lz[u];
  if (st != en) {
    lz[2 * u] += lz[u];
    lz[2 * u + 1] += lz[u];
  }
  lz[u] = 0;
}
void build(int u, int st, int en) {
  if (st == en) {
    tr[u] = {0, st};
    lz[u] = 0;
  } else {
    int mid = (st + en) / 2;
    build(2 * u, st, mid);
    build(2 * u + 1, mid + 1, en);
    tr[u] = min(tr[2 * u], tr[2 * u + 1]);
    lz[u] = 0;
  }
}
void update(int u, int st, int en, int l, int r, int x) {
  propagate(u, st, en);
  if (r < st || en < l)
    return;
  else if (l <= st && en <= r) {
    lz[u] += x;
    propagate(u, st, en);
  } else {
    int mid = (st + en) / 2;
    update(2 * u, st, mid, l, r, x);
    update(2 * u + 1, mid + 1, en, l, r, x);
    tr[u] = min(tr[2 * u], tr[2 * u + 1]);
  }
}
pair<int, int> query(int u, int st, int en, int l, int r) {
  propagate(u, st, en);
  if (r < st || en < l)
    return {1e9, 1e9};
  else if (l <= st && en <= r)
    return tr[u];
  else {
    int mid = (st + en) / 2;
    return min(query(2 * u, st, mid, l, r),
               query(2 * u + 1, mid + 1, en, l, r));
  }
}
int a[N], b[N];
char type[N];
vector<int> v[N];
int n, q;
vector<int> ans;
bool solve(int l, int r) {
  if (l > r) return true;
  int ll = l, rr = r + 1;
  for (int id : v[l]) {
    update(1, 1, n, a[id], b[id] - 1, -1);
    if (type[id] == 'L')
      ll = max(ll, b[id]);
    else
      rr = min(rr, b[id]);
  }
  if (ll >= rr) return false;
  pair<int, int> nd = query(1, 1, n, ll, rr - 1);
  if (nd.first > 0) return false;
  int mid = nd.second;
  if (!solve(l + 1, mid)) return false;
  ans.push_back(l);
  if (!solve(mid + 1, r)) return false;
  return true;
}
int main() {
  cin >> n >> q;
  build(1, 1, n);
  for (int i = 1; i <= q; i++) {
    cin >> a[i] >> b[i];
    if (a[i] >= b[i]) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    update(1, 1, n, a[i], b[i] - 1, 1);
    v[a[i]].push_back(i);
    string s;
    cin >> s;
    type[i] = s[0];
  }
  if (!solve(1, n)) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for (int x : ans) cout << x << " ";
}
