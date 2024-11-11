#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v1;
vector<pair<int, int> > v2;
int tree[2000001];
int lazy[2000001];
void makeTree(int node, int l, int r) {
  if (l == r) {
    tree[node] = 1;
    return;
  }
  int mid = (l + r) / 2;
  makeTree(2 * node + 1, l, mid);
  makeTree(2 * node + 2, mid + 1, r);
  tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
}
int query(int node, int l, int r, int a, int b) {
  if (lazy[node] != -1) {
    tree[node] = max(tree[node], lazy[node]);
    if (l != r) {
      lazy[2 * node + 1] = max(lazy[2 * node + 1], lazy[node]);
      lazy[2 * node + 2] = max(lazy[2 * node + 2], lazy[node]);
    }
    lazy[node] = -1;
  }
  if (l > b || r < a) return 0;
  if (l >= a && r <= b) {
    return tree[node];
  }
  int mid = (l + r) / 2;
  int t1 = query(2 * node + 1, l, mid, a, b);
  int t2 = query(2 * node + 2, mid + 1, r, a, b);
  return max(t1, t2);
}
void update(int node, int l, int r, int a, int b, int val) {
  if (lazy[node] != -1) {
    tree[node] = max(tree[node], lazy[node]);
    if (l != r) {
      lazy[2 * node + 1] = max(lazy[2 * node + 1], lazy[node]);
      lazy[2 * node + 2] = max(lazy[2 * node + 2], lazy[node]);
    }
    lazy[node] = -1;
  }
  if (l > b || r < a) return;
  if (l >= a && r <= b) {
    tree[node] = max(val, tree[node]);
    if (l != r) {
      lazy[2 * node + 1] = tree[node];
      lazy[2 * node + 2] = tree[node];
    }
    return;
  }
  int mid = (l + r) / 2;
  update(2 * node + 1, l, mid, a, b, val);
  update(2 * node + 2, mid + 1, r, a, b, val);
}
void print(int n) {
  for (int i = 0; i < n; i++) {
    cout << query(0, 0, n - 1, i, i) << " ";
  }
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, w;
    cin >> x >> w;
    pair<int, int> p1(x, w);
    v1.push_back(p1);
    pair<int, int> p2(x + w, i);
    v2.push_back(p2);
  }
  sort(v2.begin(), v2.end());
  makeTree(0, 0, n - 1);
  for (int i = n - 1; i >= 0; i--) {
    int id = v2[i].second;
    int diff = v1[id].first - v2[id].second;
    vector<pair<int, int> >::iterator it =
        upper_bound(v2.begin(), v2.end(), pair<int, int>(diff, 2000000));
    if (it == v2.begin()) continue;
    int val = query(0, 0, n - 1, i, i);
    int toUpd = (it - v2.begin());
    update(0, 0, n - 1, 0, toUpd - 1, 1 + val);
  }
  cout << query(0, 0, n - 1, 0, 0) << endl;
}
