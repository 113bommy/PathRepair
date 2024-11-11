#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  cin >> x;
}
template <typename T, typename T0>
void read(T &x, T0 &y) {
  cin >> x >> y;
}
template <typename T, typename T0, typename T1>
void read(T &x, T0 &y, T1 &z) {
  cin >> x >> y >> z;
}
template <typename T, typename T0, typename T1, typename T2>
void read(T &x, T0 &y, T1 &z, T2 &w) {
  cin >> x >> y >> z >> w;
}
template <typename T, typename T0>
void read(pair<T, T0> &p) {
  cin >> p.first >> p.second;
}
template <typename T>
void read(vector<T> &oneD, int n) {
  for (int(i) = 0; (i) < (n); ++(i)) {
    T x;
    read(x);
    oneD.push_back(x);
  }
}
template <typename T>
void read(T oneD[], int n) {
  for (int i = 0; i < n; i++) {
    read(oneD[i]);
  }
}
template <typename T>
void write(T &x) {
  cout << x << " ";
}
template <typename T>
void wrtline(T &x) {
  cout << x << "\n";
}
template <typename T, typename T0>
void write(T &x, T0 &y) {
  cout << x << " " << y << "\n";
}
template <typename T, typename T0, typename T1>
void write(T &x, T0 &y, T1 &z) {
  cout << x << " " << y << " " << z << "\n";
}
template <typename T, typename T0, typename T1, typename T2>
void write(T &x, T0 &y, T1 &z, T2 &w) {
  cout << x << " " << y << " " << z << " " << w << "\n";
}
template <typename T, typename T0>
void write(pair<T, T0> &p) {
  write(p.first);
  write(p.second);
  cout << "\n";
}
template <typename T>
void write(vector<T> &oneD, int n) {
  for (int i = 0; i < n; i++) {
    cout << oneD[i] << " ";
  }
  cout << "\n";
}
template <typename T>
void write(T oneD[], int &n) {
  for (int i = 0; i < n; i++) {
    write(oneD[i]);
  }
  cout << "\n";
}
template <typename T, typename T0>
void write(map<T, T0> &mpp) {
  for (auto it : mpp) {
    write(it.first);
    cout << ": ";
    write(it.second);
    cout << "\n";
  }
  cout << "\n";
}
template <typename T>
void write(vector<vector<T>> &rc, T &n, T &m) {
  for (int(i) = 0; (i) < (n); ++(i)) {
    for (int(j) = 0; (j) < (m); ++(j)) {
      cout << rc[i][j] << " ";
    }
    cout << "\n";
  }
}
template <typename T>
void _print(T &t) {
  cerr << t;
}
template <class T, class V>
void _print(pair<T, V> &p);
template <class T>
void _print(vector<T> &v);
template <class T>
void _print(set<T> &v);
template <class T, class V>
void _print(map<T, V> &v);
template <class T>
void _print(multiset<T> &v);
template <class T, class V>
void _print(pair<T, V> &p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> &v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> &v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> &v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> &v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
class lazy_seg {
 public:
  vector<int> tree, lazy_tree;
  vector<int> c;
  int N, n;
  lazy_seg(vector<int> c, int n) {
    this->n = n;
    N = 4 * n;
    this->c = c;
    tree = vector<int>(N, 0);
    lazy_tree = vector<int>(N, 0);
  }
  int buildtree(int i, int l, int r) {
    if (l == r) {
      tree[i] = c[l];
      return tree[i];
    }
    int mid = (l + r) / 2;
    int a1 = 0, a2 = 0;
    a1 = buildtree((2 * i) + 1, l, mid);
    a2 = buildtree((2 * i) + 2, mid + 1, r);
    tree[i] = a1 + a2;
    return tree[i];
  }
  int range_update_tree(int val, int l, int r, int lsearch, int rsearch,
                        int i) {
    if (r < lsearch or l > rsearch) return tree[i];
    if (l == r) {
      if (lazy_tree[i] != 0) tree[i] += lazy_tree[i];
      lazy_tree[i] = 0;
      tree[i] += val;
      return tree[i];
    }
    if (lazy_tree[i] != 0) {
      int add = r - l + 1;
      add *= lazy_tree[i];
      lazy_tree[(2 * i) + 1] += lazy_tree[i];
      lazy_tree[(2 * i) + 2] += lazy_tree[i];
      tree[i] += add;
      lazy_tree[i] = 0;
    }
    if (l >= lsearch and r <= rsearch) {
      int add = r - l + 1;
      add *= val;
      lazy_tree[(2 * i) + 1] += val;
      lazy_tree[(2 * i) + 2] += val;
      tree[i] += add;
      return tree[i];
    }
    int mid = (l + r) / 2;
    int a, b;
    a = range_update_tree(val, l, mid, lsearch, rsearch, (2 * i) + 1);
    b = range_update_tree(val, mid + 1, r, lsearch, rsearch, (2 * i) + 2);
    tree[i] = a + b;
    return tree[i];
  }
  void point_update_tree(int val, int i) {
    range_update_tree(val, 0, n - 1, i, i, 0);
  }
  int range_sum_tree(int l, int r, int lsearch, int rsearch, int i) {
    if (r < lsearch or l > rsearch) return 0;
    if (l == r) {
      if (lazy_tree[i] != 0) tree[i] += lazy_tree[i];
      lazy_tree[i] = 0;
      return tree[i];
    }
    if (lazy_tree[i] != 0) {
      int add = r - l + 1;
      add *= lazy_tree[i];
      lazy_tree[(2 * i) + 1] += lazy_tree[i];
      lazy_tree[(2 * i) + 2] += lazy_tree[i];
      tree[i] += add;
      lazy_tree[i] = 0;
    }
    if (l >= lsearch and r <= rsearch) return tree[i];
    int a, b, mid, ct = 0;
    mid = (l + r) / 2;
    a = range_sum_tree(l, mid, lsearch, rsearch, (2 * i) + 1);
    b = range_sum_tree(mid + 1, r, lsearch, rsearch, (2 * i) + 2);
    ct = a + b;
    return ct;
  }
  void show_tree() {
    wrtline(N);
    write(tree, tree.size());
    write(lazy_tree, lazy_tree.size());
  }
};
class seg_tree {
 public:
  vector<vector<int>> tree;
  vector<int> garbage;
  vector<vector<int>> c;
  int n;
  seg_tree(vector<vector<int>> c, int n) {
    this->n = n;
    this->c = c;
    int N = n * 4;
    tree = vector<vector<int>>(N, vector<int>(3, 0));
    garbage = vector<int>(3, -1);
  }
  vector<int> buildtree(int i, int l, int r) {
    if (l == r) {
      tree[i] = c[l];
      return c[l];
    }
    vector<int> a, b;
    int mid = (l + r) / 2;
    a = buildtree((2 * i) + 1, l, mid);
    b = buildtree((2 * i) + 2, mid + 1, r);
    vector<int> mi;
    if (a[0] > b[0])
      mi = a;
    else
      mi = b;
    tree[i] = mi;
    return mi;
  }
  vector<int> range_query(int i, int l, int r, int lsearch, int rsearch) {
    vector<int> mi;
    if (rsearch < l or lsearch > r) return garbage;
    if (lsearch <= l and rsearch >= r)
      return tree[i];
    else {
      vector<int> a, b;
      int mid = (l + r) / 2;
      a = range_query((2 * i) + 1, l, mid, lsearch, rsearch);
      b = range_query((2 * i) + 2, mid + 1, r, lsearch, rsearch);
      if (a[0] > b[0])
        mi = a;
      else
        mi = b;
    }
    return mi;
  }
  vector<int> update_tree(int i, int l, int r, int index, int val) {
    if (l == r) {
      tree[i][0] = val;
      return tree[i];
    }
    vector<int> a, b;
    int mid = (l + r) / 2;
    if (l <= index and index <= mid) {
      a = update_tree((2 * i) + 1, l, mid, index, val);
      if (tree[(2 * i) + 2][0] > a[0])
        tree[i] = tree[(2 * i) + 2];
      else
        tree[i] = a;
    } else {
      b = update_tree((2 * i) + 2, mid + 1, r, index, val);
      if (tree[(2 * i) + 1][0] > b[0])
        tree[i] = tree[(2 * i) + 1];
      else
        tree[i] = b;
    }
    return tree[i];
  }
};
void allVal(lazy_seg &ob) {
  vector<pair<int, int>> c;
  for (int(i) = 1; (i) <= (31); ++(i)) {
    c.push_back({i, ob.range_sum_tree(0, 100001, i, i, 0)});
  }
}
void solve() {
  int n, k;
  read(n, k);
  vector<int> numberLine(200002, 0);
  vector<vector<int>> p(n);
  lazy_seg ob1(numberLine, 200002);
  for (int(i) = 0; (i) < (n); ++(i)) {
    read(p[i], 2);
    p[i].push_back(i + 1);
    ob1.range_update_tree(1, 0, 200001, p[i][0], p[i][1], 0);
  }
  vector<vector<int>> p1 = p;
  sort((p).begin(), (p).end());
  vector<vector<int>> sendVal;
  for (int(i) = 0; (i) < (n); ++(i)) {
    sendVal.push_back({p[i][1], p[i][2], i});
  }
  seg_tree ob2(sendVal, n);
  ob2.buildtree(0, 0, n - 1);
  vector<int> ans;
  int l = 0, r = 0;
  for (int(i) = 1; (i) <= (200000); ++(i)) {
    while (l < r and p[l][1] < i) l++;
    while (r < n and p[r][0] <= i and p[r][1] >= i) r++;
    while (ob1.range_sum_tree(0, 200001, i, i, 0) > k) {
      vector<int> pa = ob2.range_query(0, 0, n - 1, l, r - 1);
      vector<int> ma = p1[pa[1] - 1];
      ob1.range_update_tree(-1, 0, 200001, ma[0], ma[1], 0);
      ans.push_back(ma[2]);
      ob2.update_tree(0, 0, n - 1, pa[2], 0);
    }
  }
  cout << ans.size() << "\n";
  write(ans, ans.size());
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
