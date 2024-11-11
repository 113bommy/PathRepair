#include <bits/stdc++.h>
using namespace std;
const int M = 500000;
const int MAXN = (int)5e5 + 10;
struct segment {
  int sum, first, last, kol;
  segment(int sum = 0, int first = 0, int last = 0, int kol = 0)
      : sum(sum), first(first), last(last), kol(kol) {}
};
segment tree[4 * MAXN];
int mod[4 * MAXN];
int n;
void push(int v, int tl, int tr) {
  if (mod[v] != -1 && tl != tr) {
    mod[2 * v] = mod[v];
    mod[2 * v + 1] = mod[v];
    int tm = (tl + tr) / 2;
    tree[2 * v].sum = (tm - tl + 1) * mod[v];
    tree[2 * v + 1].sum = (tr - tm) * mod[v];
    tree[2 * v].first = mod[v];
    tree[2 * v + 1].first = mod[v];
    tree[2 * v].last = mod[v];
    tree[2 * v + 1].last = mod[v];
    if (mod[v] == 1) {
      tree[2 * v].kol = 1;
      tree[2 * v + 1].kol = 1;
    } else {
      tree[2 * v].kol = 0;
      tree[2 * v + 1].kol = 0;
    }
    mod[v] = -1;
  }
}
segment merges(segment child1, segment child2) {
  segment ans;
  ans.sum = child1.sum + child2.sum;
  ans.first = child1.first;
  ans.last = child2.last;
  ans.kol = child1.kol + child2.kol;
  if (child1.last == 1 && child2.first == 1) ans.kol--;
  return ans;
}
void update(int v, int tl, int tr, int l, int r, int val) {
  if (tl > r || tr < l) return;
  if (tl >= l && tr <= r) {
    tree[v].sum = (tr - tl + 1) * val;
    tree[v].first = val;
    tree[v].last = val;
    if (val == 1)
      tree[v].kol = 1;
    else
      tree[v].kol = 0;
    mod[v] = val;
    return;
  }
  push(v, tl, tr);
  int tm = (tl + tr) / 2;
  update(2 * v, tl, tm, l, r, val);
  update(2 * v + 1, tm + 1, tr, l, r, val);
  tree[v] = merges(tree[2 * v], tree[2 * v + 1]);
}
segment get(int v, int tl, int tr, int l, int r) {
  if (tl > r || tr < l) return {0, 0, 0, 0};
  if (tl >= l && tr <= r) return tree[v];
  int tm = (tl + tr) / 2;
  segment a = get(2 * v, tl, tm, l, r);
  segment b = get(2 * v + 1, tm + 1, tr, l, r);
  return merges(a, b);
}
unordered_map<int, int> c;
vector<pair<int, int>> v;
vector<int> p;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  v.resize(n);
  memset(mod, -1, 16 * MAXN);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    p.push_back(v[i].first);
    p.push_back(v[i].second);
  }
  sort(p.begin(), p.end());
  int cnt = 0;
  for (int i = 0; i < (int)p.size(); i++)
    if (c[p[i]] == 0) c[p[i]] = ++cnt;
  for (int i = 0; i < n; i++) {
    int l, r;
    l = c[v[i].first];
    r = c[v[i].second];
    r--;
    update(1, 0, MAXN, l, r, 1);
    cout << tree[1].kol << " ";
  }
}
