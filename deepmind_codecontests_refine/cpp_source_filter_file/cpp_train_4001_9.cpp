#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 20;
int imp[maxn];
struct Splay {
  int root;
  int size[maxn], fa[maxn], ch[maxn][2], max_val[maxn];
  inline int right_son(int fa, int x) { return ch[fa][1] == x; }
  inline void upd(int x) {
    size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
    max_val[x] = imp[x];
    max_val[x] = max(max_val[x], max_val[ch[x][0]]);
    max_val[x] = max(max_val[x], max_val[ch[x][1]]);
  }
  inline void rotate(int x) {
    int f = fa[x], gf = fa[f];
    int p = right_son(f, x), q = !p;
    ch[f][p] = ch[x][q];
    fa[ch[x][q]] = f;
    ch[x][q] = f;
    fa[f] = x;
    fa[x] = gf;
    if (gf)
      ch[gf][right_son(gf, f)] = x;
    else
      root = x;
    upd(f);
    upd(x);
  }
  inline void splay(int x) {
    int f, gf;
    while (fa[x]) {
      f = fa[x], gf = fa[f];
      if (!gf)
        rotate(x);
      else {
        if (right_son(gf, f) == right_son(f, x)) {
          rotate(f);
          rotate(x);
        } else {
          rotate(x);
          rotate(x);
        }
      }
    }
  }
  inline void insert(int pos, int val) {
    if (!root) {
      root = val;
      fa[val] = 0;
      ch[val][0] = ch[val][1] = 0;
      size[val] = 1;
      max_val[val] = imp[val];
      return;
    }
    int dir = 0;
    for (int cur = root; cur; cur = ch[cur][dir]) {
      dir = size[ch[cur][0]] + 1 < pos;
      if (dir) pos -= size[ch[cur][0]] + 1;
      if (!ch[cur][dir]) {
        ch[cur][dir] = val;
        fa[val] = cur;
        size[val] = 1;
        ch[val][0] = ch[val][1] = 0;
        max_val[val] = imp[val];
        splay(val);
        break;
      }
    }
  }
  inline void Print(int x) {
    if (!x) return;
    cout << x << " " << size[x] << " " << max_val[x] << endl;
    Print(ch[x][0]);
    Print(ch[x][1]);
  }
  inline int find_kth(int k) {
    int cur = root;
    while (1) {
      if (size[ch[cur][0]] + 1 == k) {
        splay(cur);
        return cur;
      }
      if (size[ch[cur][0]] >= k)
        cur = ch[cur][0];
      else {
        k -= size[ch[cur][0]] + 1;
        cur = ch[cur][1];
      }
    }
  }
  inline int findplace(int x, int val) {
    find_kth(x);
    if (max_val[ch[root][1]] < val) {
      if (imp[root] < val) return x;
      return x + 1;
    }
    int pos = x;
    int dir = 0;
    for (int cur = ch[root][1]; cur; cur = ch[cur][dir]) {
      if (max_val[cur] < val) {
        splay(cur);
        return pos;
      }
      if (max_val[ch[cur][1]] > val) {
        dir = 1;
        pos += size[ch[cur][0]] + 1;
      } else if (imp[cur] > val) {
        pos += size[ch[cur][0]];
        break;
      } else {
        dir = 0;
      }
    }
    return pos + 1;
  }
  inline void ans(int x) {
    if (!x) return;
    ans(ch[x][0]);
    printf("%d ", x);
    ans(ch[x][1]);
  }
} tree;
int main() {
  int n;
  scanf("%d", &n);
  int rank;
  for (int i = (1); i < (int)(n + 1); ++i) {
    scanf("%d %d", &imp[i], &rank);
    if (!tree.root) {
      tree.insert(1, i);
      continue;
    }
    if (!rank) {
      tree.insert(i, i);
      continue;
    }
    int pos = tree.findplace(max(i - rank, 1), imp[i]);
    tree.insert(pos, i);
  }
  tree.ans(tree.root);
  return 0;
}
