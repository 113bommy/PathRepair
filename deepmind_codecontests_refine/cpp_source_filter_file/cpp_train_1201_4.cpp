#include <bits/stdc++.h>
using namespace std;
struct Node {
  Node *l, *r;
  int s, e, v;
  Node(int a, int b) : v(a), e(b), s(0), l(0), r(0) {}
  Node* L() {
    if (l == NULL) {
      l = new Node(v * 2, 0);
    }
    return l;
  }
  Node* R() {
    if (r == NULL) {
      r = new Node(v * 2 + 1, 0);
    }
    return r;
  }
  void up() { s = e + L()->s + R()->s; }
  void add(int m, int h, int q) {
    if (v == m) {
      e += q;
      s += q;
      return;
    }
    if (m >> (h - 2) & 1) {
      R()->add(m, h - 1, q);
    } else {
      L()->add(m, h - 1, q);
    }
    up();
  }
  double query(int m) {
    double ret;
    if (s <= m) {
      ret = m;
    } else if (L()->s > R()->s) {
      ret = (L()->query(max(m, R()->s + e)) + max(L()->s + e, m)) / 2;
    } else if (L()->s < R()->s) {
      ret = (R()->query(max(m, L()->s + e)) + max(R()->s + e, m)) / 2;
    } else {
      ret = L()->s + e;
    }
    return ret;
  }
};
int len(int s, int ret = 0) {
  while (s > 0) {
    ret++;
    s >>= 1;
  }
  return ret;
}
int main() {
  char ch[10];
  int n, m;
  cin >> n >> m;
  Node* rt = new Node(1, 0);
  for (int i = 0; i < m; i++) {
    scanf("%s", ch);
    if (ch[0] == 'a') {
      int x, y;
      scanf("%d %d", &x, &y);
      rt->add(x, len(x), y);
    } else {
      printf("%.8f\n", rt->query(0));
    }
  }
}
