#include <bits/stdc++.h>
using namespace std;
int n, m, p, q, k;
int tp, x, y, z;
struct node {
  int l, r, x;
  node(int a, int b, int c) {
    l = a;
    r = b;
    x = c;
  }
  node() {}
};
int ls[501000], rs[501000];
vector<node> c[10070];
set<int> s;
bool cross(int x1, int y1, int x2, int y2) {
  if (y1 < x2 || x1 > y2) return false;
  return true;
}
int main() {
  memset(ls, -1, sizeof ls);
  memset(rs, -1, sizeof rs);
  int cnt = 1;
  ls[1] = 1;
  rs[1] = 2;
  int sp = 3;
  for (int i = 2; i <= 200000; i++) {
    if ((1 << cnt) == i) {
      cnt++;
      ls[i] = sp++;
      rs[i] = sp++;
    } else {
      ls[i] = -1;
      rs[i] = sp++;
    }
  }
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) c[i].clear();
  for (int i = 1; i <= m; i++) {
    scanf("%d", &tp);
    if (tp == 1) {
      scanf("%d%d%d%d", &k, &p, &q, &x);
      c[k].push_back(node(p, q, x));
    } else {
      s.clear();
      scanf("%d%d", &p, &q);
      int lst = q;
      int rst = q;
      for (int ii = p; ii <= n; ii++) {
        for (int jj = 0; jj < c[ii].size(); jj++) {
          if (cross(lst, rst, c[ii][jj].l, c[ii][jj].r)) s.insert(c[ii][jj].x);
        }
        if (ls[lst] == -1)
          lst = rs[lst];
        else
          lst = ls[lst];
        rst = rs[rst];
      }
      cout << s.size() << endl;
    }
  }
  return 0;
}
