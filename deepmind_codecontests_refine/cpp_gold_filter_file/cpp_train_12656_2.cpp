#include <bits/stdc++.h>
template <class T>
T Max(const T &a, const T &b) {
  return a > b ? a : b;
}
const int SN = 100000 + 10;
int sum[SN << 2], a[SN], max[SN << 2];
int n;
void Read(int &x) {
  int in = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    in = in * 10 + ch - '0';
    ch = getchar();
  }
  x = in * f;
}
void pushup(int rt) {
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
  max[rt] = Max(max[rt << 1 | 1], sum[rt << 1 | 1] + max[rt << 1]);
}
void modify(int pos, int C, int l, int r, int rt) {
  if (l == r) {
    sum[rt] = max[rt] = C;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    modify(pos, C, l, mid, rt << 1);
  else
    modify(pos, C, mid + 1, r, rt << 1 | 1);
  pushup(rt);
}
int Query() {
  int rt = 1, l = 1, r = n, ans = 0;
  if (max[rt] <= 0) return 0;
  while (l != r) {
    int mid = (l + r) >> 1;
    if (ans + max[rt << 1 | 1] > 0)
      l = mid + 1, rt = rt << 1 | 1;
    else
      r = mid, ans += sum[rt << 1 | 1], rt = rt << 1;
  }
  return l;
}
int main() {
  int opt, x, y;
  Read(n);
  a[0] = -1;
  for (int i = 1; i <= n; i++) {
    Read(x), Read(opt);
    switch (opt) {
      case 0:
        modify(x, -1, 1, n, 1);
        printf("%d\n", a[Query()]);
        break;
      case 1:
        Read(y);
        modify(x, 1, 1, n, 1);
        a[x] = y;
        printf("%d\n", a[Query()]);
        break;
    }
  }
  return 0;
}
