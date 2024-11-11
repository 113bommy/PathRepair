#include <bits/stdc++.h>
using namespace std;
inline int getint() {
  int res = 0, fh = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') fh = -1, ch = getchar();
  while (ch <= '9' && ch >= '0') res = res * 10 + ch - '0', ch = getchar();
  return res * fh;
}
int n, Q;
char s[1000001];
struct node {
  int a[6][6];
  node() { memset(a, 0x3f, sizeof(a)); }
} t[1000001];
node operator+(node a, node b) {
  node c;
  for (int i = 1; i <= 5; i++)
    for (int j = 1; j <= 5; j++)
      for (int k = 1; k <= 5; k++)
        c.a[i][j] = min(c.a[i][j], a.a[i][k] + b.a[k][j]);
  return c;
}
void build(int x, int l, int r) {
  if (l == r) {
    for (int i = 1; i <= 5; i++) t[x].a[i][i] = 0;
    if (s[l] == '2') t[x].a[1][1] = 1, t[x].a[1][2] = 0;
    if (s[l] == '0') t[x].a[2][2] = 1, t[x].a[2][3] = 0;
    if (s[l] == '1') t[x].a[3][3] = 1, t[x].a[3][4] = 0;
    if (s[l] == '7') t[x].a[4][4] = 1, t[x].a[4][5] = 0;
    if (s[l] == '6') t[x].a[4][4] = 1, t[x].a[5][5] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  t[x] = t[x << 1] + t[x << 1 | 1];
}
node query(int x, int l, int r, int l1, int r1) {
  if (l1 <= l && r <= r1) return t[x];
  int mid = (l + r) >> 1;
  if (r1 <= mid) return query(x << 1, l, mid, l1, r1);
  if (l1 > mid) return query(x << 1 | 1, mid + 1, r, l1, r1);
  return query(x << 1, l, mid, l1, r1) + query(x << 1 | 1, mid + 1, r, l1, r1);
}
int main() {
  n = getint();
  Q = getint();
  scanf("%s", s + 1);
  build(1, 1, n);
  while (Q--) {
    int x = getint(), y = getint();
    node res = query(1, 1, n, x, y);
    if (res.a[1][5] == 0x3f3f3f3f)
      printf("-1\n");
    else
      printf("%d\n", res.a[1][5]);
  }
  return 0;
}
