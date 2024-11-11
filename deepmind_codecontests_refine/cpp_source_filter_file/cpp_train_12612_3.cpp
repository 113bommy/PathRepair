#include <bits/stdc++.h>
int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
char s[100010];
int num[100010];
struct SEG_Tree {
  struct SEG {
    int l;
    int r;
    int f0;
    int f1;
    int f2;
    int f3;
    int sum;
    int min;
    int max;
    void init(char x) {
      f0 = f1 = f2 = f3 = 1;
      if (x == '(') {
        min = 0;
        max = 1;
        sum = 1;
      } else {
        min = -1;
        max = 0;
        sum = -1;
      }
    }
    void print() {
      printf("[%d, %d] = {%d, %d, %d, %d, %d, %d, %d}\n", l, r, min, max, sum,
             f0, f1, f2, f3);
    }
  } t[400010];
  void push_up(int cur) {
    t[cur].min = std::min(t[((cur) << 1)].min,
                          t[((cur) << 1)].sum + t[((cur) << 1 | 1)].min);
    t[cur].max = std::max(t[((cur) << 1)].max,
                          t[((cur) << 1)].sum + t[((cur) << 1 | 1)].max);
    t[cur].f0 =
        std::max(std::max(t[((cur) << 1)].f0, t[((cur) << 1 | 1)].f0),
                 std::max(t[((cur) << 1)].f2 + t[((cur) << 1 | 1)].max,
                          t[((cur) << 1 | 1)].f1 -
                              (t[((cur) << 1)].sum - t[((cur) << 1)].max)));
    t[cur].f1 =
        std::max(-t[((cur) << 1)].sum + t[((cur) << 1 | 1)].f1,
                 std::max(t[((cur) << 1)].f1,
                          t[((cur) << 1)].f3 + t[((cur) << 1 | 1)].max));
    t[cur].f2 =
        std::max(t[((cur) << 1 | 1)].sum + t[((cur) << 1)].f2,
                 std::max(t[((cur) << 1)].f2,
                          t[((cur) << 1 | 1)].f3 -
                              (t[((cur) << 1)].sum - t[((cur) << 1)].max)));
    t[cur].f3 = std::max(t[((cur) << 1)].f3 + t[((cur) << 1 | 1)].sum,
                         t[((cur) << 1 | 1)].f3 - t[((cur) << 1)].sum);
    t[cur].sum = t[((cur) << 1)].sum + t[((cur) << 1 | 1)].sum;
  }
  void build(int cur, int l, int r) {
    t[cur].l = l;
    t[cur].r = r;
    if (l == r) {
      t[cur].init(s[l]);
      num[l] = cur;
      return;
    }
    int mid = (l + r) >> 1;
    build(((cur) << 1), l, mid);
    build(((cur) << 1 | 1), mid + 1, r);
    push_up(cur);
  }
  void modify(int cur) {
    cur >>= 1;
    while (cur) {
      push_up(cur);
      cur >>= 1;
    }
  }
} t;
int main() {
  int n = (inp() << 1) - 2;
  int m = inp();
  scanf("%s", s + 1);
  t.build(1, 1, n);
  printf("%d\n", t.t[1].f0);
  while (m--) {
    int x = inp();
    int y = inp();
    std::swap(s[x], s[y]);
    t.t[num[x]].init(s[x]);
    t.t[num[y]].init(s[y]);
    t.modify(num[x]);
    t.modify(num[y]);
    printf("%d\n", t.t[1].f0);
  }
}
