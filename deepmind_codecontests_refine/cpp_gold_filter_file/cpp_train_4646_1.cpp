#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int N = 4e5 + 5;
template <typename T>
vector<T> CoordinateCompression(const vector<T> &x, int offset = 0) {
  int n = x.size();
  vector<T> y = x, ret(n);
  sort(y.begin(), y.end());
  y.erase(unique(y.begin(), y.end()), y.end());
  for (int i = 0; i < n; i++) {
    ret[i] = lower_bound(y.begin(), y.end(), x[i]) - y.begin() + offset;
  }
  return ret;
}
int tree[8 * N];
void build(int node, int start, int end, vector<int> &a) {
  if (start == end) {
    tree[node] = a[start];
  } else {
    int mid = (start + end) / 2;
    build(2 * node, start, mid, a);
    build(2 * node + 1, mid + 1, end, a);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
  }
}
int query(int node, int start, int end, int l, int r) {
  if (r < start or end < l) {
    return 1e9;
  }
  if (l <= start and end <= r) {
    return tree[node];
  }
  int mid = (start + end) / 2;
  int p1 = query(2 * node, start, mid, l, r);
  int p2 = query(2 * node + 1, mid + 1, end, l, r);
  return min(p1, p2);
}
signed main() {
  4;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_cases = 1;
  while (test_cases--) {
    int n;
    cin >> n;
    vector<int> l(n), r(n), v;
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
      v.push_back(l[i]);
      v.push_back(r[i]);
      v.push_back(l[i] - 1);
      v.push_back(r[i] + 1);
    }
    auto c = CoordinateCompression(v);
    map<int, int> f, rev;
    for (int i = 0; i < 4 * n; i++) {
      f[v[i]] = c[i];
      rev[c[i]] = v[i];
    }
    vector<int> pref(N * 2);
    for (int i = 0; i < n; i++) {
      int x = f[l[i]];
      int y = f[r[i]];
      pref[x]++;
      pref[y + 1]--;
    }
    for (int i = 1; i < pref.size(); i++) pref[i] += pref[i - 1];
    build(1, 0, pref.size() - 1, pref);
    for (int i = 0; i < n; i++) {
      int x = f[l[i]];
      int y = f[r[i]];
      if (query(1, 0, pref.size() - 1, x, y) > 1) {
        cout << i + 1;
        return 0;
      }
    }
    cout << "-1";
  }
}
