#include <bits/stdc++.h>
using namespace std;
int n, k, m;
const int mxN = 2e5;
int tree[mxN * 2 * 4];
int lazy[mxN * 2 * 4];
int get(int le, int ri, int ql, int qr, int node) {
  if (lazy[node] != 0) {
    tree[node] += lazy[node];
    if (le != ri) {
      lazy[2 * node + 1] = lazy[node];
      lazy[2 * node + 2] = lazy[node];
    }
    lazy[node] = 0;
  }
  if (ri < ql || qr < le) return 0;
  if (ri <= qr && le >= ql) {
    return tree[node];
  } else {
    int mid = (le + ri) / 2;
    int ret = max(get(le, mid, ql, qr, node * 2 + 1),
                  get(mid + 1, ri, ql, qr, node * 2 + 2));
    tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
    return ret;
  }
}
int get(int ri) { return get(0, n * 2 - 1, 0, ri, 0); }
void upd(int le, int ri, int node, int idx, int val) {
  if (lazy[node] != 0) {
    tree[node] += lazy[node];
    if (le != ri) {
      lazy[2 * node + 1] += lazy[node];
      lazy[2 * node + 2] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (le > idx) return;
  if (le == ri) {
    tree[node] += val;
  } else if (idx >= ri) {
    tree[node] += val;
    lazy[2 * node + 1] += val;
    lazy[2 * node + 2] += val;
  } else {
    int mid = (le + ri) / 2;
    upd(le, mid, node * 2 + 1, idx, val);
    upd(mid + 1, ri, node * 2 + 2, idx, val);
    tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
  }
}
void upd(int idx, int val) { upd(0, n * 2 - 1, 0, idx, val); }
void build(int le, int ri, int node) {
  if (le > ri) return;
  if (le == ri) {
    tree[node] = le;
  } else {
    int mid = (ri + le) / 2;
    build(le, mid, 2 * node + 1);
    build(mid + 1, ri, 2 * node + 2);
    tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
  }
}
void build() { build(0, n * 2 - 1, 0); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k >> m;
  k--;
  set<pair<int, int> > pawns;
  build();
  map<int, int> speccolm;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (pawns.find(make_pair(x, y)) != pawns.end()) {
      pawns.erase(make_pair(x, y));
      y = y + abs(k - x);
      speccolm[y]--;
      upd(y, -1);
    } else {
      pawns.insert(make_pair(x, y));
      y = y + abs(k - x);
      speccolm[y]++;
      upd(y, 1);
    }
    if (speccolm[y] == 0) {
      speccolm.erase(y);
    }
    int qsize = n - 1;
    if (speccolm.size()) {
      qsize = max(qsize, speccolm.rbegin()->first);
    }
    cout << max(get(qsize) - n, 0) << endl;
  }
  return 0;
}
