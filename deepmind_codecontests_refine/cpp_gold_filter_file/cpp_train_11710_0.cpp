#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& o, pair<A, B>& p) {
  return o << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& v) {
  o << "{";
  for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
    o << *it << ", ";
  return o << "}";
}
struct debugger {
  ostream& out;
  bool first;
  void start() { first = true; }
  debugger(ostream& out) : out(out) { start(); }
  void nl() {
    out << endl;
    start();
  }
  template <class T>
  debugger& operator,(T& v) {
    if (first)
      first = false;
    else
      out << ", ";
    out << v;
    return *this;
  }
  template <class T>
  debugger& operator,(pair<T*, int> arr) {
    out << "{";
    for (typeof((arr.second) - 1) i = (0); i <= ((arr.second) - 1); i++) {
      out << arr.first[i] << ", ";
    }
    out << "}";
    return *this;
  }
} dbg(cerr);
int tree[2000000];
int Insert(int node, int l, int r, int Inode, int Ival) {
  if (l > r || Inode < l || Inode > r) return 0;
  if (l == r) {
    tree[node] = max(tree[node], Ival);
    return tree[node];
  }
  int mid = (l + r) / 2;
  int lval = Insert(node * 2, l, mid, Inode, Ival);
  int rval = Insert(node * 2 + 1, mid + 1, r, Inode, Ival);
  tree[node] = max(lval, tree[node]);
  tree[node] = max(rval, tree[node]);
  return tree[node];
}
int query(int node, int l, int r, int Il, int Ir) {
  if (l > r || Ir < l || Il > r) return 0;
  if (Il <= l && Ir >= r) {
    return tree[node];
  }
  int mid = (l + r) / 2;
  int lval = query(node * 2, l, mid, Il, Ir);
  int rval = query(node * 2 + 1, mid + 1, r, Il, Ir);
  return max(lval, rval);
}
int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  vector<pair<int, int> > v;
  vector<int> preTree;
  for (typeof((n)-1) i = (0); i <= ((n)-1); i++) {
    int x, w;
    cin >> x >> w;
    v.push_back(pair<int, int>(x + w, x - w));
    preTree.push_back(x + w);
    preTree.push_back(x - w);
  }
  sort((v).begin(), (v).end());
  sort((preTree).begin(), (preTree).end());
  int nodecnt = 0;
  for (typeof((2 * n) - 1) i = (0); i <= ((2 * n) - 1); i++) {
    if (mp[preTree[i]] == 0) {
      mp[preTree[i]] = ++nodecnt;
    }
  }
  memset((tree), (0), sizeof(tree));
  int ans = 0;
  for (typeof((n)-1) i = (0); i <= ((n)-1); i++) {
    int r = v[i].first;
    int l = v[i].second;
    int indr = mp[r];
    int indl = mp[l];
    int val = query(1, 1, nodecnt, 1, indl);
    Insert(1, 1, nodecnt, indr, val + 1);
    ans = max(ans, val + 1);
  }
  cout << ans << endl;
  return 0;
}
