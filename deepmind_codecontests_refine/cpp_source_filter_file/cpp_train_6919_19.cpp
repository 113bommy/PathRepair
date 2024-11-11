#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, K, top, D;
struct P {
  int l, r, x, op;
} p[100010 * 2];
bool cmp(P a, P b) { return a.x < b.x; }
int lowbit(int l, int r) {
  int res = 0, sum = 0;
  for (int i = 0; i < D; i++) {
    int x = (r / (1 << i) - (l - 1) / (1 << i)) -
            (r / (1 << (i + 1)) - (l - 1) / (1 << (i + 1)));
    res |= ((x & 1) << i);
    sum += x;
  }
  res |= (((r - l + 1 - sum) & 1) << D);
  return res;
}
int ans;
struct Segment_Tree {
  int t[100010 * 30], tot, cov[100010 * 30], rt;
  int ls[100010 * 30], rs[100010 * 30];
  void update(int k, int l, int r) {
    if (cov[k])
      t[k] = lowbit(l, r);
    else
      t[k] = (t[ls[k]] ^ t[rs[k]]);
  }
  void modi(int &k, int l, int r, int x, int y, int z) {
    if (!k) k = ++tot;
    if (l >= x && r <= y) {
      cov[k] += z;
      update(k, l, r);
      return;
    }
    int mid = (l + r) / 2;
    if (mid >= x) modi(ls[k], l, mid, x, y, z);
    if (mid < y) modi(rs[k], mid + 1, r, x, y, z);
    update(k, l, r);
  }
} S;
int main() {
  n = read();
  m = read();
  K = read();
  while ((1 << D) <= K) D++;
  D--;
  for (int i = 1; i <= m; i++) {
    int x1 = read(), y1 = read(), x2 = read(), y2 = read();
    p[++top] = (P){y1, y2, x1, 1};
    p[++top] = (P){y1, y2, x2 + 1, -1};
  }
  sort(p + 1, p + top + 1, cmp);
  for (int i = 1; i <= top; i++) {
    if (p[i].x != p[i - 1].x) {
      int x = lowbit(p[i - 1].x + 1, p[i].x), y = S.t[S.rt], las = 0;
      int c1 = 0, c2 = 0;
      for (int j = D; j >= 1; j--) {
        c1 += ((x >> j) & 1);
        c2 += ((y >> j) & 1);
        if ((c1 * c2 - las) & 1) ans ^= (1 << j);
        las = c1 * c2;
      }
    }
    S.modi(S.rt, 1, n, p[i].l, p[i].r, p[i].op);
  }
  if (ans)
    puts("Hamed");
  else
    puts("Malek");
  return 0;
}
