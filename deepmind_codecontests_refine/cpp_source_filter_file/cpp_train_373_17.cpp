#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
namespace segment_tree {
struct Node {
  long long a[5];
  int sum;
  inline void print() {
    for (int i = (0); i <= (4); i++) printf("%I64d ", a[i]);
    printf("%d \n", sum);
  }
} q[400010];
int root;
inline void update(int o, int y) {
  if (y > 0)
    q[o] = (Node){y, 0, 0, 0, 0, 1};
  else
    q[o] = (Node){0, 0, 0, 0, 0, 0};
}
inline void pushup(int o) {
  int l = q[2 * o].sum;
  for (int i = (0); i <= (4); i++)
    q[o].a[i] = q[2 * o].a[i] + q[2 * o + 1].a[((i - l) % 5 + 5) % 5];
  q[o].sum = q[2 * o].sum + q[2 * o + 1].sum;
}
inline void add(int l, int r, int o, int x, int y) {
  if (l == r) {
    update(o, y);
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid)
    add(l, mid, 2 * o, x, y);
  else
    add(mid + 1, r, 2 * o + 1, x, y);
  pushup(o);
}
}  // namespace segment_tree
struct ops {
  int op, x, y;
} a[400010];
pair<int, int> b[400010];
int cnt;
int len;
int main() {
  using namespace segment_tree;
  root = 1;
  int n = read();
  char op[10];
  for (int i = (1); i <= (n); i++) {
    scanf("%s", op);
    if (op[0] == 'a') {
      int x = read();
      a[i] = (ops){1, x, 0};
      b[++cnt] = make_pair(x, i);
    } else if (op[0] == 'd') {
      int x = read();
      a[i] = (ops){2, x, 0};
      b[++cnt] = make_pair(x, i);
    } else {
      a[i] = (ops){3, 0, 0};
    }
  }
  sort(b + 1, b + cnt + 1);
  for (int i = (1); i <= (cnt); i++) {
    if (b[i].first != b[i + 1].first) len++;
    a[b[i].second].y = len;
  }
  for (int i = (1); i <= (n); i++) {
    if (a[i].op == 1) {
      add(1, len, 1, a[i].y, a[i].x);
    } else if (a[i].op == 2) {
      add(1, len, 1, a[i].y, -a[i].x);
    } else {
      printf("%I64d\n", q[1].a[2]);
    }
  }
  return 0;
}
