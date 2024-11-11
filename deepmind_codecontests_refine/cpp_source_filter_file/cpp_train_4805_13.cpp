#include <bits/stdc++.h>
using namespace std;
struct node {
  int d;
  int max_a, min_b, max_ab, max_bc, max_abc;
  void init_leaf(int v) {
    d = v;
    max_a = v;
    min_b = v;
    max_ab = max_abc = max_bc = -1123456;
  }
  void update(const node& l, const node& r) {
    d = l.d + r.d;
    max_a = max(l.max_a, l.d + r.max_a);
    min_b = min(l.min_b, l.d + r.min_b);
    max_ab = max(l.max_a - 2 * (l.d + r.min_b), max(l.max_ab, -l.d + r.max_ab));
    max_bc =
        max(-2 * (l.min_b) + l.d + r.max_a, max(l.max_bc, -l.d + r.max_bc));
    max_abc = max(max(l.max_abc, r.max_abc),
                  max(l.max_ab + l.d + r.max_a, l.max_a - l.d + r.max_bc));
    max_abc = max(max_abc, max_a);
  }
  void print() {
    printf("d:%d max_a:%d min_b:%d max_ab:%d max_bc:%d max_abc:%d\n", d, max_a,
           min_b, max_ab, max_bc, max_abc);
  }
};
node segt[612345];
int offset;
int a[212345];
char s[212345];
void init_tree(int n, int l, int r) {
  if (n >= offset) {
    segt[n].init_leaf(a[n - offset + 1]);
  } else {
    init_tree((n << 1), l, (l + r) / 2);
    init_tree(((n << 1) + 1), (l + r) / 2, r);
    segt[n].update(segt[(n << 1)], segt[((n << 1) + 1)]);
  }
}
void update_leaf(int at, int v) {
  if (a[at] == v) return;
  a[at] = v;
  int n = at + offset - 1;
  segt[n].init_leaf(v);
  n >>= 1;
  while (n) {
    segt[n].update(segt[(n << 1)], segt[((n << 1) + 1)]);
    n >>= 1;
  }
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  scanf("%s", s);
  n = 2 * (n - 1);
  offset = 1;
  while (offset < n) offset <<= 1;
  for (int i = 1; i <= n; i++) {
    a[i] = (s[i - 1] == '(' ? 1 : -1);
  }
  for (int i = n + 1; i <= offset; i++) {
    a[i] = 0;
  }
  init_tree(1, 1, offset + 1);
  printf("%d\n", segt[1].max_abc);
  while (q--) {
    int p1, p2;
    scanf("%d%d", &p1, &p2);
    int v1 = a[p1], v2 = a[p2];
    update_leaf(p1, v2);
    update_leaf(p2, v1);
    printf("%d\n", segt[1].max_abc);
  }
  return 0;
}
