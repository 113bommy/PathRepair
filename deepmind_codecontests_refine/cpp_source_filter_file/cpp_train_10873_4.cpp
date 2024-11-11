#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
long long add[N << 2], sum[N << 2], color[N << 1];
int n, m;
void down(int rt, int len) {
  if (add[rt]) {
    add[(rt << 1)] += add[rt];
    add[(rt << 1 | 1)] += add[rt];
    sum[(rt << 1)] += add[rt] * (len - (len >> 1));
    sum[(rt << 1 | 1)] += add[rt] * (len >> 1);
    add[rt] = 0;
    color[(rt << 1)] = color[(rt << 1 | 1)] = color[rt];
    color[rt] = 0;
  }
}
void build(int rt, int l, int r) {
  if (l == r) {
    color[rt] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build((rt << 1), l, mid);
  build((rt << 1 | 1), mid + 1, r);
}
void modify(int rt, int l, int r, int L, int R, int c) {
  if (L <= l && r <= R && color[rt]) {
    add[rt] += abs(color[rt] - c);
    sum[rt] += (r - l + 1) * abs(color[rt] - c);
    color[rt] = c;
    return;
  }
  down(rt, r - l + 1);
  int mid = (l + r) >> 1;
  if (L <= mid) modify((rt << 1), l, mid, L, R, c);
  if (mid < R) modify((rt << 1 | 1), mid + 1, r, L, R, c);
  color[rt] = (color[(rt << 1)] == color[(rt << 1 | 1)]) ? color[(rt << 1)] : 0;
  sum[rt] = sum[(rt << 1)] + sum[(rt << 1 | 1)];
}
long long query(int rt, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    return sum[rt];
  }
  down(rt, r - l + 1);
  long long t = 0ll;
  int mid = (l + r) >> 1;
  if (L <= mid) t += query((rt << 1), l, mid, L, R);
  if (mid < R) t += query((rt << 1 | 1), mid + 1, r, L, R);
  return t;
}
int main() {
  scanf("%d%d", &n, &m);
  build(1, 1, n);
  while (m--) {
    int op, l, r, x;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d%d", &l, &r, &x);
      modify(1, 1, n, l, r, x);
    } else {
      scanf("%d%d", &l, &r);
      printf("%I64d\n", query(1, 1, n, l, r));
    }
  }
  return 0;
}
