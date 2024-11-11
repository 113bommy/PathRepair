#include <bits/stdc++.h>
using namespace std;
int comp[212345], ptr;
int idx[212345];
map<int, int> place;
int h, m, n;
int merge(int x, int y) {
  if (x == -1) {
    return y;
  }
  return x;
}
struct segtree {
  int n;
  vector<int> tree;
  segtree(vector<int> base) {
    n = base.size();
    tree.resize(2 * n);
    for (int i = 0; i < n; ++i) {
      tree[i + n] = base[i];
    }
    for (int i = n - 1; i > 0; --i) {
      tree[i] = merge(tree[i + i], tree[i + i + 1]);
    }
  }
  int qry(int l) {
    int x = qry(l, n);
    if (x == -1) {
      return qry(0, l);
    }
    return x;
  }
  int qry(int l, int r) {
    int resl = -1, resr = -1;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) resl = merge(resl, tree[l++]);
      if (r & 1) resr = merge(tree[--r], resr);
    }
    return merge(resl, resr);
  }
  void upd(int pos, int val) {
    pos += n;
    tree[pos] = val;
    for (pos /= 2; pos > 0; pos /= 2) {
      tree[pos] = merge(tree[pos + pos], tree[pos + pos + 1]);
    }
  }
};
vector<int> base[212345];
void dfs(int x) {
  comp[x] = ptr;
  idx[x] = base[ptr].size();
  base[ptr].push_back(x);
  int nxt = (x + m) % h;
  if (comp[nxt] == -1) {
    dfs(nxt);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> h >> m >> n;
  int ans = 0;
  memset(comp, -1, sizeof comp);
  for (int i = 0; i < h; ++i) {
    if (comp[i] == -1) {
      dfs(i);
      ++ptr;
    }
  }
  vector<segtree> segts;
  for (int i = 0; i < ptr; ++i) {
    segts.push_back(segtree(base[i]));
  }
  while (n--) {
    char a;
    int id, hash;
    cin >> a >> id;
    if (a == '+') {
      cin >> hash;
      int pos = segts[comp[hash]].qry(idx[hash]);
      int dummy = idx[pos] - idx[hash];
      if (dummy < 0) {
        dummy += base[comp[hash]].size();
      }
      ans += dummy;
      segts[comp[pos]].upd(idx[pos], -1);
      place[id] = pos;
    } else {
      int pos = place[id];
      segts[comp[pos]].upd(idx[pos], pos);
    }
  }
  cout << ans << '\n';
  return 0;
}
