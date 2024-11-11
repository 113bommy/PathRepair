#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 3;
const int INF = numeric_limits<long long>::max() / 2;
struct pt {
  int b, p;
  bool operator<(const pt &pnt) const {
    return p == pnt.p ? b > pnt.b : p < pnt.p;
  }
};
int n, m;
vector<int> ar;
vector<pt> enemy;
vector<long long> sums;
void init() {
  cin >> n >> m;
  ar.resize(n);
  enemy.resize(m);
  sums.resize(n);
  for (int(i) = (0); (i) < (n); (i)++) {
    cin >> ar[i];
  }
  for (int(i) = (0); (i) < (m); (i)++) {
    cin >> enemy[i].b;
  }
  for (int(i) = (0); (i) < (m); (i)++) {
    cin >> enemy[i].p;
  }
}
struct node {
  long long minS;
  int maxA;
  long long add;
  node() {
    minS = INF;
    maxA = -1;
    add = 0;
  }
  node(int minS, int maxA) : minS(minS), maxA(maxA), add(0) {}
  node(const node &a, const node &b) {
    maxA = max(a.maxA, b.maxA);
    minS = min(a.minS, b.minS);
    add = 0;
  }
};
struct seg_tree {
  int ds;
  vector<node> tree;
  seg_tree(int n) {
    for (ds = 1; ds < n; ds *= 2)
      ;
    tree.assign(2 * ds + 1, node());
  }
  void build(vector<int> &ar, vector<long long> &sums) {
    build(1, 0, ds - 1, ar, sums);
  }
  void build(int v, int tl, int tr, vector<int> &ar, vector<long long> &sums) {
    if (tl == tr) {
      if (tl < (int((ar).size()))) {
        tree[v].minS = sums[tl];
        tree[v].maxA = ar[tl];
      }
      return;
    }
    int m = (tl + tr) / 2;
    build(v * 2, tl, m, ar, sums);
    build(v * 2 + 1, m + 1, tr, ar, sums);
    tree[v] = node(tree[v + v], tree[v + v + 1]);
  }
  void push(int v, int tl, int tr) {
    tree[v * 2].minS += tree[v].add;
    tree[v * 2].add += tree[v].add;
    tree[v * 2 + 1].minS += tree[v].add;
    tree[v * 2 + 1].add += tree[v].add;
    tree[v].add = 0;
  }
  node Get(int L, int R) { return Get(L, R, 1, 0, ds - 1); }
  node Get(int L, int R, int v, int l, int r) {
    if (r < L || R < l) {
      return node();
    }
    if (L <= l && r <= R) {
      return tree[v];
    } else {
      push(v, l, r);
      int m = (l + r) / 2;
      return node(Get(L, R, v * 2, l, m), Get(L, R, v + v + 1, m + 1, r));
    }
  }
  void Add(int L, int R, long long val) { Add(L, R, val, 1, 0, ds - 1); }
  void Add(int L, int R, long long val, int v, int tl, int tr) {
    if (tr < L || R < tl) return;
    if (L <= tl && tr <= R) {
      tree[v].add += val;
      tree[v].minS += val;
    } else {
      push(v, tl, tr);
      int m = (tl + tr) / 2;
      Add(L, R, val, v + v, tl, m);
      Add(L, R, val, v + v + 1, m + 1, tr);
      tree[v] = node(tree[v + v], tree[v + v + 1]);
    }
  }
};
void solve() {
  sort(enemy.begin(), enemy.end());
  sums[0] = ar[0];
  for (int(i) = (1); (i) < (n); (i)++) {
    sums[i] = sums[i - 1] + ar[i];
  }
  seg_tree tree(n);
  tree.build(ar, sums);
  int cnt = 0;
  for (int(cur) = (0); (cur) < (m); (cur)++) {
    int last = -1;
    {
      int l = 0, r = n - 1;
      for (; l <= r;) {
        int m = (l + r) / 2;
        long long mins = tree.Get(m, n - 1).minS;
        if (mins >= enemy[cur].p) {
          last = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
    }
    if (last == -1) continue;
    int last2 = -1;
    {
      int l = last, r = n - 1;
      for (; l <= r;) {
        int m = (l + r) / 2;
        int maxA = tree.Get(m, n - 1).maxA;
        if (maxA >= enemy[cur].b) {
          last2 = m;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
    }
    if (last2 == -1) continue;
    cnt++;
    tree.Add(last2, n - 1, -enemy[cur].p);
  }
  cout << cnt << endl;
}
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(0);
  init();
  solve();
  return 0;
}
