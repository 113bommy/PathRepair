#include <bits/stdc++.h>
using namespace std;
const long long int inf = (long long int)2e18;
const int mod = 1e9 + 7;
bool overflow(long long int a, long long int b) {
  if (a <= (inf + b - 1) / b) return false;
  return true;
}
long long int a[200005];
long long int seg[800005], lazy[800005];
long long int parity[200005];
vector<int> order;
vector<pair<int, int> > range;
vector<vector<int> > v;
long long int querylevel(long long int l, long long int r) {
  return parity[r] - parity[l];
}
void dfs(int i, int parent, int lev) {
  int start = order.size();
  order.push_back(i);
  parity[order.size()] = lev;
  for (int j = 0; j < v[i].size(); j++) {
    if (v[i][j] != parent) {
      dfs(v[i][j], i, lev ^ 1);
    }
  }
  range[i] = {start, order.size() - 1};
}
void build(int i, int l, int r) {
  if (r - l < 2) {
    seg[i] = a[l];
    return;
  }
  long long int mid = (l + r) / 2;
  build(2 * i, l, mid);
  build(2 * i + 1, mid, r);
  seg[i] = seg[2 * i] + seg[2 * i + 1];
}
void shift(int i, long long int l, long long int r) {
  if (lazy[i]) {
    lazy[2 * i] += lazy[i];
    lazy[2 * i + 1] += lazy[i];
    seg[i] +=
        ((querylevel(l, r) * lazy[i]) - ((r - l - querylevel(l, r)) * lazy[i]));
  }
  lazy[i] = 0;
}
void update(int i, long long int l, long long int r, int p, int q,
            long long int val) {
  if (l >= q || r <= p) return;
  if (l >= p && r <= q) {
    lazy[i] += val;
    shift(i, l, r);
    return;
  }
  long long int mid = (l + r) / 2;
  shift(i, l, r);
  update(2 * i, l, mid, p, q, val);
  update(2 * i + 1, mid, r, p, q, val);
  seg[i] = seg[2 * i] +
           ((querylevel(l, mid) * lazy[2 * i]) -
            ((mid - l - querylevel(l, mid)) * lazy[2 * i])) +
           seg[2 * i + 1] +
           ((querylevel(mid, r) * lazy[2 * i + 1]) -
            ((r - mid - querylevel(mid, r)) * lazy[2 * i + 1]));
}
long long int query(int i, long long int l, long long int r, int p) {
  if (r - l < 2) {
    seg[i] +=
        ((querylevel(l, r) * lazy[i]) - ((r - l - querylevel(l, r)) * lazy[i]));
    lazy[i] = 0;
    return seg[i];
  }
  long long int mid = (l + r) / 2;
  shift(i, l, r);
  if (p >= mid)
    return query(2 * i + 1, mid, r, p);
  else
    return query(2 * i, l, mid, p);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, m, i, x, y;
  cin >> n >> m;
  v.resize(n);
  range.resize(n);
  long long int ar[n];
  for (i = 0; i < n; i++) cin >> ar[i];
  for (i = 0; i < n - 1; i++) {
    cin >> x >> y;
    x--, y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(0, -1, 1);
  int index[n];
  for (i = 0; i < n; i++) {
    a[i] = ar[order[i]];
    index[order[i]] = i;
  }
  build(1, 0, n);
  for (i = 1; i < 200005; i++) parity[i] += parity[i - 1];
  while (m--) {
    int type;
    cin >> type;
    if (type - 1 == 0) {
      long long int k, val;
      cin >> k >> val;
      if (!(parity[index[k - 1] + 1] - parity[index[k - 1]])) val = -val;
      update(1, 0, n, range[k - 1].first, range[k - 1].second + 1, val);
    } else {
      long long int k;
      cin >> k;
      cout << query(1, 0, n, index[k - 1]) << "\n";
    }
  }
}
