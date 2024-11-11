#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
 public:
  void update(int val, int p) { upd(1, 1, n, p, val); }
  int top() { return segm[1] + lazy[1]; }
  void add(int l, int r, int val) {
    if (!r || !val) return;
    updlazy(1, 1, n, l, r, val);
  }
  SegmentTree() {
    for (int i = 0; i < n * 4; ++i) segm[i] = (1e9 + 4);
  }

 private:
  int segm[(int)(2e6 + 4) * 4], lazy[(int)(2e6 + 4) * 4], n = (int)(2e6 + 4);
  void upd(int node, int l, int r, int poz, int val) {
    push(node);
    if (l == r) {
      lazy[node] = 0;
      segm[node] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if (poz <= mid)
      upd(node << 1, l, mid, poz, val);
    else
      upd(node << 1 | 1, mid + 1, r, poz, val);
    pull(node);
  }
  void updlazy(int node, int l, int r, int st, int dr, int val) {
    push(node);
    if (st <= l && r <= dr) {
      lazy[node] += val;
      push(node);
      return;
    }
    int mid = (l + r) >> 1;
    if (st <= mid) updlazy(node << 1, l, mid, st, dr, val);
    if (mid < dr) updlazy(node << 1 | 1, mid + 1, r, st, dr, val);
    pull(node);
  }
  void pull(int node) {
    segm[node] = min(segm[node << 1] + lazy[node << 1],
                     segm[node << 1 | 1] + lazy[node << 1 | 1]);
  }
  void push(int node) {
    if (!lazy[node]) return;
    lazy[node << 1] += lazy[node];
    lazy[node << 1 | 1] += lazy[node];
    segm[node] += lazy[node];
    lazy[node] = 0;
  }
};
struct item {
  int cost, cnt;
  item* child[30];
  item() {
    cost = cnt = 0;
    memset(child, 0, sizeof child);
  }
};
typedef item* itemPtr;
int n, k, timer, s[(int)(2e6 + 4)];
itemPtr T, v[(int)(2e6 + 4)];
SegmentTree Arb;
void add(int, char, int);
void dfs(itemPtr);
int main() {
  cin >> n;
  T = v[0] = new item();
  char c;
  for (int i = 1, p; i <= n; ++i) {
    cin >> p >> c;
    add(p, c, i);
  }
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    ++v[s[i]]->cnt;
  }
  dfs(T);
  for (int i = 0; i < n; ++i) cout << v[s[i]]->cost << ' ';
  return 0;
}
void dfs(itemPtr node) {
  int auxT;
  ++timer;
  auxT = timer;
  if (node->cnt) {
    node->cost = min(node->cost, Arb.top() + 1);
    Arb.update(node->cost, timer);
    Arb.add(1, timer, 1);
  } else
    Arb.update(node->cost, timer);
  for (int i = 0; i <= 'z' - 'a'; ++i) {
    if (node->child[i]) {
      node->child[i]->cost = node->cost + 1;
      dfs(node->child[i]);
    }
  }
  Arb.update((1e9 + 4), auxT);
}
void add(int p, char c, int id) {
  v[p]->child[c - 'a'] = new item();
  v[id] = v[p]->child[c - 'a'];
}
