#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
template <typename first, typename second>
ostream& operator<<(ostream& os, const pair<first, second>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ",";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename first, typename second>
ostream& operator<<(ostream& os, const map<first, second>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
void faltu() { cerr << '\n'; }
template <typename T>
void faltu(T a[], int n) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << '\n';
}
template <typename T, typename... hello>
void faltu(T arg, const hello&... rest) {
  cerr << arg << ' ';
  faltu(rest...);
}
const int mx = 5e5 + 5;
int n, k, d;
int a[mx];
bool tree[mx * 4];
void update(int node, int l, int r, int b) {
  if (l == r) {
    tree[node] = 1;
    return;
  }
  int mid = (l + r) / 2;
  if (mid >= b)
    update(2 * node, l, mid, b);
  else
    update(2 * node + 1, mid + 1, r, b);
  tree[node] = tree[2 * node] | tree[2 * node + 1];
}
int query(int node, int l, int r, int b, int e) {
  if (l > e || r < b) return 0;
  if (l >= b && r <= e) return tree[node];
  int mid = (l + r) / 2;
  return query(2 * node, l, mid, b, e) | query(2 * node + 1, mid + 1, r, b, e);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k >> d;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  update(1, 0, n, 0);
  for (int i = 1; i <= n; ++i) {
    int num = a[i] - d;
    int idx = lower_bound(a + 1, a + n + 1, num) - a - 1;
    if (idx > i - k) continue;
    int c = 1;
    if (idx == 0) c = 0;
    if (query(1, 0, n, c, idx)) update(1, 0, n, i);
  }
  if (query(1, 0, n, n, n))
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}
