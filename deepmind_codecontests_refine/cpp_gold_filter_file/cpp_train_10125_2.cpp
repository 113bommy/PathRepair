#include <bits/stdc++.h>
using namespace std;
struct compq {
  bool operator()(int i, int j) { return 0; }
};
bool compa(const vector<int> &v1, const vector<int> &v2) {
  return v1[2] < v2[2];
}
struct comph {
  size_t operator()(pair<int, int> p) const { return 3278171; }
};
struct eq {
  bool operator()(int i, int j) { return false; }
};
struct comps {
  bool operator()(const vector<int> &v1, const vector<int> &v2) {
    return v1[2] < v2[2];
  }
};
struct node {
  int s;
  int e;
  int lazy;
  int max;
  node *left;
  node *right;
};
int n;
node *build(int s, int e) {
  if (s == e) return new node{s, e, 0, s - n - 1, 0, 0};
  int m = s + e >> 1;
  node *l = build(s, m);
  node *r = build(m + 1, e);
  return new node{s, e, 0, max(l->max, r->max), l, r};
}
void push_down(node *root) {
  if (root->lazy == 0) return;
  int lazy = root->lazy;
  root->lazy = 0;
  root->left->max += lazy;
  root->right->max += lazy;
  root->left->lazy += lazy;
  root->right->lazy += lazy;
}
int query(node *root, int s, int e) {
  if ((s == root->s) && (e == root->e)) {
    return root->max;
  }
  push_down(root);
  int m = root->s + root->e >> 1;
  int temp = 0;
  if (e <= m) {
    temp = query(root->left, s, e);
  } else if (s >= m + 1) {
    temp = query(root->right, s, e);
  } else {
    temp = max(query(root->left, s, m), query(root->right, m + 1, e));
  }
  return temp;
}
void update(node *root, int s, int e, int v) {
  if ((s == root->s) && (e == root->e)) {
    root->max += v;
    root->lazy += v;
    return;
  }
  push_down(root);
  int m = (root->s + root->e) >> 1;
  if (e <= m) {
    update(root->left, s, e, v);
  } else if (s >= m + 1) {
    update(root->right, s, e, v);
  } else {
    update(root->left, s, m, v);
    update(root->right, m + 1, e, v);
  }
  root->max = max(root->left->max, root->right->max);
}
void func() {
  set<pair<int, int> > sett;
  multiset<int> setpos;
  int k, m;
  cin >> n >> k >> m;
  node *root = build(1, (int)7E5);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    int pos = (x < k) ? (y + k - x) : (y + x - k);
    if (sett.count(pair<int, int>(x, y))) {
      sett.erase(pair<int, int>(x, y));
      setpos.erase(pos);
      update(root, 1, pos, -1);
    } else {
      update(root, 1, pos, 1);
      sett.insert(pair<int, int>(x, y));
      setpos.insert(pos);
    };
    if (setpos.size())
      cout << max(0, query(root, 1, *setpos.rbegin())) << endl;
    else
      cout << 0 << endl;
  }
}
void funcT() {
  int T;
  cin >> T;
  while (T--) {
  }
}
int aux[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
set<pair<int, int> > ex;
int cnt[(int)7E5];
set<int> mx;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int k, m;
  cin >> n >> k >> m;
  node *root = build(1, 2 * n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    int val;
    int tar = y + abs(x - k);
    if (ex.count(pair<int, int>(x, y))) {
      ex.erase(pair<int, int>(x, y));
      cnt[tar]--;
      if (!cnt[tar]) mx.erase(tar);
      update(root, 1, tar, -1);
    } else {
      ex.insert(pair<int, int>(x, y));
      cnt[tar]++;
      mx.insert(tar);
      update(root, 1, tar, 1);
    }
    if (mx.empty())
      cout << 0 << endl;
    else
      cout << max(0, query(root, 1, *mx.rbegin())) << endl;
  }
  return 0;
}
