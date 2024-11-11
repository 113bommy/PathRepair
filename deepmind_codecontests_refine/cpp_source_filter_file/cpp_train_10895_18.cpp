#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  x *= f;
}
struct qu {
  int l, x, id;
};
qu q[1000010];
int a[1000010], ans[1000010], er[1000010], qq;
int bs[30], nj, n;
bool cmp(qu x, qu y) { return x.l < y.l; }
void ins(int x) {
  for (int i = 22; i >= 0; --i)
    if (x & (1 << i)) {
      if (bs[i] == -1) {
        bs[i] = x;
        nj++;
        break;
      }
      x ^= bs[i];
    }
}
bool ifin(int x) {
  for (int i = 22; i >= 0; --i)
    if (x & (1 << i)) {
      if (bs[i] == -1)
        return 0;
      else
        x ^= bs[i];
    }
  return 1;
}
int main() {
  read(n);
  read(qq);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= qq; ++i) read(q[i].l), read(q[i].x), q[i].id = i;
  sort(q + 1, q + 1 + qq, cmp);
  q[0].l = 0;
  er[0] = 1;
  memset(bs, -1, sizeof(bs));
  for (int i = 1; i <= n; ++i) er[i] = (er[i - 1] * 2) % 1000000007;
  for (int i = 1; i <= n; ++i) {
    for (int j = q[i - 1].l + 1; j <= q[i].l; ++j) ins(a[j]);
    if (ifin(q[i].x))
      ans[q[i].id] = er[q[i].l - nj];
    else
      ans[q[i].id] = 0;
  }
  for (int i = 1; i <= qq; ++i) printf("%d\n", ans[i]);
  return 0;
}
