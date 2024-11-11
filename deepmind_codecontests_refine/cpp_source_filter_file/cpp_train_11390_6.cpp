#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int m = 0, n, res = 0, k, ans;
string s2, ch = "", s, t, s1 = "";
vector<pair<string, int> > vm;
vector<pair<pair<int, int>, int> > vvv;
vector<pair<int, int> > vv;
vector<pair<string, int> > vv2;
vector<int> v[500005];
int a[500005], parent[500005], b[500005];
vector<pair<int, int> > vnode;
int used[500005] = {0}, pos[500005], from[500005], to[500005], sz = 0;
void dfs(int node) {
  used[node] = true;
  pos[node] = ++sz;
  from[node] = sz;
  to[node] = sz;
  int i;
  for (i = 0; i < v[node].size(); i++) {
    if (!used[v[node][i]]) {
      parent[v[node][i]] = node;
      dfs(v[node][i]);
      to[node] = max(to[node], to[v[node][i]]);
    }
  }
}
int lazy1[2000005], tree1[2000005];
void build1(int id, int start, int end) {
  if (start == end) {
    tree1[id] = b[start];
  } else {
    int mid = (start + end) / 2;
    build1(2 * id, start, mid);
    build1(2 * id + 1, mid + 1, end);
    tree1[id] = tree1[2 * id] + tree1[2 * id + 1];
  }
}
void upd1(int id, int l, int r, int val) {
  if (val != 1e8) {
    lazy1[id] = val;
    tree1[id] = (r - l + 1) * val;
  }
}
void shift1(int id, int l, int r) {
  int mid = (l + r) / 2;
  upd1(2 * id, l, mid, lazy1[id]);
  upd1(2 * id + 1, mid + 1, r, lazy1[id]);
  lazy1[id] = 1e8;
}
void update1(int l, int r, int v, int id, int start, int end) {
  if (l > end or r < start) return;
  if (l <= start && r >= end) {
    upd1(id, start, end, v);
    return;
  }
  shift1(id, start, end);
  int mid = (start + end) / 2;
  update1(l, r, v, id * 2, start, mid);
  update1(l, r, v, id * 2 + 1, mid + 1, end);
  tree1[id] = tree1[id * 2] + tree1[id * 2 + 1];
}
int query1(int l, int r, int id, int start, int end) {
  if (l > end or r < start) return 0;
  if (l <= start && r >= end) return tree1[id];
  shift1(id, start, end);
  int mid = (start + end) / 2;
  int p1 = query1(l, r, 2 * id, start, mid);
  int p2 = query1(l, r, 2 * id + 1, mid + 1, end);
  return (p1 + p2);
}
int lazy[2000005], tree[2000005];
void build(int id, int start, int end) {
  if (start == end) {
    tree[id] = a[start];
  } else {
    int mid = (start + end) / 2;
    build(2 * id, start, mid);
    build(2 * id + 1, mid + 1, end);
    tree[id] = tree[2 * id] + tree[2 * id + 1];
  }
}
void upd(int id, int l, int r, int val) {
  if (val != 1e8) {
    lazy[id] = 1;
    tree[id] = (r - l + 1);
  }
}
void shift(int id, int l, int r) {
  int mid = (l + r) / 2;
  upd(2 * id, l, mid, lazy[id]);
  upd(2 * id + 1, mid + 1, r, lazy[id]);
  lazy[id] = 1e8;
}
void increase(int l, int r, int v, int id, int start, int end) {
  if (l > end or r < start) return;
  if (l <= start && r >= end) {
    upd(id, start, end, v);
    return;
  }
  shift(id, start, end);
  int mid = (start + end) / 2;
  increase(l, r, v, id * 2, start, mid);
  increase(l, r, v, id * 2 + 1, mid + 1, end);
  tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
int sum(int l, int r, int id, int start, int end) {
  if (l > end or r < start) return 0;
  if (l <= start && r >= end) return tree[id];
  shift(id, start, end);
  int mid = (start + end) / 2;
  int p1 = sum(l, r, 2 * id, start, mid);
  int p2 = sum(l, r, 2 * id + 1, mid + 1, end);
  return (p1 + p2);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int i = 0, x = 0, z = 0, y = 0, j = 0, q, mx = 0, idx = 0, ok = 0, l = 0,
      r = 0, negatif = 0, positif = 0, r1, d, p;
  set<int>::iterator it;
  multiset<int>::iterator its;
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (i = 1; i <= 4 * n; i++) {
    tree[i] = 0;
    tree1[i] = 0;
    lazy[i] = 1e8;
  }
  parent[1] = 0;
  pos[0] = 0;
  dfs(1);
  for (i = 1; i <= n; i++) {
    b[i] = 0;
    a[i] = 0;
  }
  build1(1, 1, n);
  build(1, 1, n);
  cin >> q;
  while (q--) {
    int op;
    cin >> op >> x;
    l = from[x];
    r = to[x];
    int p = parent[x];
    idx = pos[p];
    if (op == 1) {
      int empties = query1(1, 1, n, l, r);
      if (empties && p != 0) {
        update1(idx, idx, 1, 1, 1, n);
        ;
      }
      update1(l, r, 0, 1, 1, n);
      increase(l, r, 1, 1, 1, n);
    } else if (op == 2) {
      update1(pos[x], pos[x], 1, 1, 1, n);
      ;
    } else {
      int empties = query1(l, r, 1, 1, n);
      if (empties) {
        cout << "0\n";
      } else {
        int val = sum(pos[x], pos[x], 1, 1, n);
        if (val > 0) val = 1;
        cout << val << '\n';
      }
    }
  }
  return 0;
}
