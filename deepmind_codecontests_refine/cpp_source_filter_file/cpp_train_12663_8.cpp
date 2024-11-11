#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> sheet;
int sheetSize;
int root[100010], weight[100010];
string s, t;
int num;
inline int getID(const string& s) {
  if (sheet.count(s))
    return sheet[s];
  else
    return sheet[s] = ++sheetSize;
}
struct P_SegmentTree {
  struct Node {
    int lchild, rchild;
    int w;
  } nodes[100010 * 60];
  int _size;
  P_SegmentTree() {
    _size = 0;
    memset(nodes, 0, sizeof(nodes));
  }
  inline int update(int preVer, int l, int r, int p, int k) {
    int retRoot = ++_size;
    nodes[retRoot] = nodes[preVer];
    nodes[retRoot].w += k;
    if (l == r) return retRoot;
    int m = (l + r) >> 1;
    if (p <= m)
      nodes[retRoot].lchild = update(nodes[preVer].lchild, l, m, p, k);
    else
      nodes[retRoot].rchild = update(nodes[preVer].rchild, m + 1, r, p, k);
    return retRoot;
  }
  inline int query(int root, int l, int r, int L, int R) {
    if (L <= l && r <= R) return nodes[root].w;
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += query(nodes[root].lchild, l, m, L, R);
    if (R > m) ret += query(nodes[root].rchild, m + 1, r, L, R);
    return ret;
  }
};
P_SegmentTree Tree;
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> t;
    root[i] = root[i - 1], weight[i] = weight[i - 1];
    if (t[0] == 's') {
      cin >> s >> num;
      int id = getID(s);
      int p = Tree.query(weight[i], 1, 1000000000, id, id);
      if (p) root[i] = Tree.update(root[i], 1, 1000000000, p, -1);
      root[i] = Tree.update(root[i], 1, 1000000000, num, 1);
      weight[i] = Tree.update(weight[i], 1, 1000000000, id, num - p);
    }
    if (t[0] == 'r') {
      cin >> s;
      int id = getID(s);
      int p = Tree.query(weight[i], 1, 1000000000, id, id);
      if (p) root[i] = Tree.update(root[i], 1, 1000000000, p, -1);
      weight[i] = Tree.update(weight[i], 1, 1000000000, id, -p);
    }
    if (t[0] == 'q') {
      cin >> s;
      int id = getID(s);
      int p = Tree.query(weight[i], 1, 1000000000, id, id);
      if (!p)
        puts("-1");
      else if (p == 1)
        puts("0");
      else
        printf("%d\n", Tree.query(root[i], 1, 1000000000, 1, p - 1));
      fflush(stdout);
    }
    if (t[0] == 'u') {
      cin >> num;
      root[i] = root[i - num - 1], weight[i] = root[i - num - 1];
    }
  }
}
