#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long LL_INF = LLONG_MAX;
void print_vector(vector<int>& v) {
  for (int i : v) cout << i << " ";
  cout << '\n';
}
void print_array(int a[], int s, int e) {
  for (int i = s; i < e; ++i) cout << a[i] << " ";
  cout << '\n';
}
int lc(int n) { return n << 1; }
int rc(int n) { return (n << 1) + 1; }
int avg(int a, int b) { return (a + b) / 2; }
const int MAXN = 400005;
set<int> Uset[MAXN];
set<int> Dset[MAXN];
int TU[MAXN << 2];
int TD[MAXN << 2];
int n, m, q;
void build(int node, int s, int e) {
  if (s == e) {
    TU[node] = 0;
    TD[node] = n + 1;
    return;
  }
  int mid = avg(s, e);
  build(lc(node), s, mid);
  build(rc(node), mid + 1, e);
  TU[node] = max(TU[lc(node)], TU[rc(node)]);
  TD[node] = min(TD[lc(node)], TD[rc(node)]);
  return;
}
int getval(int node, int s, int e, int ql, int qr, int type) {
  if (qr < s || ql > e) {
    if (type)
      return n + 1;
    else
      return 0;
  }
  if (s == ql && e == qr) {
    if (type)
      return TD[node];
    else
      return TU[node];
  }
  int mid = avg(s, e);
  if (type)
    return min(getval(lc(node), s, mid, ql, min(qr, mid), type),
               getval(rc(node), mid + 1, e, max(ql, mid + 1), qr, type));
  else
    return max(getval(lc(node), s, mid, ql, min(qr, mid), type),
               getval(rc(node), mid + 1, e, max(ql, mid + 1), qr, type));
}
void update(int node, int s, int e, int x, int y, int type) {
  if (s == e) {
    if (type)
      TD[node] = y;
    else
      TU[node] = y;
    return;
  }
  int mid = avg(s, e);
  if (x <= mid)
    update(lc(node), s, mid, x, y, type);
  else
    update(rc(node), mid + 1, e, x, y, type);
  TD[node] = min(TD[lc(node)], TD[rc(node)]);
  TU[node] = max(TU[lc(node)], TU[rc(node)]);
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  T = 1;
  while (T--) {
    cin >> n >> m >> q;
    n *= 2;
    m *= 2;
    build(1, 1, n);
    string prev = "";
    for (int i = 0; i < q; ++i) {
      int x, y;
      cin >> y >> x;
      if (prev == "NO") {
        cout << "NO\n";
        continue;
      }
      if (y & 1) {
        if (Dset[x].find(y) == Dset[x].end()) {
          Dset[x].insert(y);
        } else {
          Dset[x].erase(Dset[x].find(y));
        }
        int val;
        if (!Dset[x].empty()) {
          val = *(Dset[x].begin());
        } else
          val = m + 1;
        update(1, 1, n, x, val, 1);
        int no = getval(1, 1, n, x, m, 0);
        if (no >= y) {
          cout << "NO\n";
          prev = "NO";
        } else
          cout << "YES\n";
      } else {
        if (Uset[x].find(y) == Uset[x].end()) {
          Uset[x].insert(y);
        } else {
          Uset[x].erase(Uset[x].find(y));
        }
        int val;
        if (!Uset[x].empty()) {
          val = *(Uset[x].rbegin());
        } else
          val = 0;
        update(1, 1, n, x, val, 0);
        int no = getval(1, 1, n, 1, x, 1);
        if (no <= y) {
          cout << "NO\n";
          prev = "NO";
        } else
          cout << "YES\n";
      }
    }
  }
}
