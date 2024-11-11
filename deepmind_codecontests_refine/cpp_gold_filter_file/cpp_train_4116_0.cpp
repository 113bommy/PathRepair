#include <bits/stdc++.h>
using namespace std;
int n, m, p, lim;
int a[150005];
struct Node {
  int cnt;
  pair<int, int> nd[6];
  Node(int x = 0, int y = 0) {
    cnt = 1;
    nd[1] = make_pair(y, x);
    return;
  }
  void update(int w) {
    for (int i = 1; i <= cnt; ++i) nd[i].second += w;
    return;
  }
};
struct SGT {
  Node val[150005 << 2];
  int tag1[150005 << 2], tag2[150005 << 2];
  Node merge(Node x, Node y) {
    Node t = x;
    for (int i = 1; i <= y.cnt; ++i) {
      bool flag = false;
      for (int j = 1; j <= t.cnt; ++j)
        if (t.nd[j].second == y.nd[i].second) {
          t.nd[j].first += y.nd[i].first;
          flag = true;
          break;
        }
      if (!flag) {
        if (t.cnt < lim)
          t.nd[++t.cnt] = y.nd[i];
        else {
          int pos = 1;
          for (int j = 2; j <= t.cnt; ++j)
            if (t.nd[j].first < t.nd[pos].first) pos = j;
          if (t.nd[pos].first < y.nd[i].first) swap(t.nd[pos], y.nd[i]);
          for (int j = 1; j <= t.cnt; ++j) t.nd[j].first -= y.nd[i].first;
        }
      }
    }
    return t;
  }
  void push_up(int pos) {
    val[pos] = merge(val[pos << 1], val[pos << 1 | 1]);
    return;
  }
  void push_down(int pos, int l, int r) {
    int mid = (l + r) >> 1;
    if (tag1[pos]) {
      int w = tag1[pos];
      tag1[pos] = 0;
      val[pos << 1] = Node(w, mid - l + 1);
      val[pos << 1 | 1] = Node(w, r - mid);
      tag1[pos << 1] = tag1[pos << 1 | 1] = w;
      tag2[pos << 1] = tag2[pos << 1 | 1] = 0;
    }
    if (tag2[pos]) {
      int w = tag2[pos];
      tag2[pos] = 0;
      val[pos << 1].update(w);
      val[pos << 1 | 1].update(w);
      tag2[pos << 1] += w;
      tag2[pos << 1 | 1] += w;
    }
    return;
  }
  void build(int pos, int l, int r) {
    if (l == r) return val[pos] = Node(a[l], 1), void();
    int mid = (l + r) >> 1;
    build(pos << 1, l, mid);
    build(pos << 1 | 1, mid + 1, r);
    push_up(pos);
    return;
  }
  void update1(int pos, int l, int r, int nl, int nr, int w) {
    if (l >= nl && r <= nr) {
      val[pos] = Node(w, r - l + 1);
      tag1[pos] = w;
      tag2[pos] = 0;
      return;
    }
    int mid = (l + r) >> 1;
    push_down(pos, l, r);
    if (mid >= nl) update1(pos << 1, l, mid, nl, nr, w);
    if (mid < nr) update1(pos << 1 | 1, mid + 1, r, nl, nr, w);
    push_up(pos);
    return;
  }
  void update2(int pos, int l, int r, int nl, int nr) {
    if (l >= nl && r <= nr) {
      val[pos].update(1);
      tag2[pos]++;
      return;
    }
    int mid = (l + r) >> 1;
    push_down(pos, l, r);
    if (mid >= nl) update2(pos << 1, l, mid, nl, nr);
    if (mid < nr) update2(pos << 1 | 1, mid + 1, r, nl, nr);
    push_up(pos);
    return;
  }
  Node query(int pos, int l, int r, int nl, int nr) {
    if (l >= nl && r <= nr) return val[pos];
    int mid = (l + r) >> 1;
    push_down(pos, l, r);
    if (mid >= nr)
      return query(pos << 1, l, mid, nl, nr);
    else if (mid < nl)
      return query(pos << 1 | 1, mid + 1, r, nl, nr);
    else
      return merge(query(pos << 1, l, mid, nl, nr),
                   query(pos << 1 | 1, mid + 1, r, nl, nr));
  }
} T;
int main() {
  scanf("%d%d%d", &n, &m, &p);
  lim = 100 / p;
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  T.build(1, 1, n);
  while (m--) {
    int opt, l, r;
    scanf("%d%d%d", &opt, &l, &r);
    if (opt == 1) {
      int w;
      scanf("%d", &w);
      T.update1(1, 1, n, l, r, w);
    }
    if (opt == 2) {
      Node p = T.query(1, 1, n, l, r);
      printf("%d ", p.cnt);
      for (int i = 1; i <= p.cnt; ++i) printf("%d ", p.nd[i].second);
      puts("");
    }
  }
  return 0;
}
