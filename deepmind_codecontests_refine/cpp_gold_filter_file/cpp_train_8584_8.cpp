#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int tree[N * 4][60];
int a[N];
void init(int k, int m, int n) {
  if (m == n) {
    for (int j = 0; j < 60; ++j)
      if (j % a[m] == 0)
        tree[k][j] = 2;
      else
        tree[k][j] = 1;
    return;
  }
  int mid = m + n >> 1, z1 = k << 1, z2 = z1 + 1;
  init(z1, m, mid);
  init(z2, mid + 1, n);
  for (int j = 0; j < 60; ++j) {
    int p = (j + tree[z1][j]) % 60;
    tree[k][j] = tree[z1][j] + tree[z2][p];
  }
}
void modify(int k, int m, int n, int x, int y) {
  if (m > x || n < x) return;
  if (m == n) {
    for (int j = 0; j < 60; ++j)
      if (j % y == 0)
        tree[k][j] = 2;
      else
        tree[k][j] = 1;
    return;
  }
  int mid = m + n >> 1, z1 = k << 1, z2 = z1 + 1;
  modify(z1, m, mid, x, y);
  modify(z2, mid + 1, n, x, y);
  for (int j = 0; j < 60; ++j) {
    int p = (j + tree[z1][j]) % 60;
    tree[k][j] = tree[z1][j] + tree[z2][p];
  }
}
void query(int k, int m, int n, int l, int r, int &ans) {
  if (m > r || n < l) return;
  if (m >= l && n <= r) {
    ans += tree[k][ans % 60];
    return;
  }
  int mid = m + n >> 1, z1 = k << 1, z2 = z1 + 1;
  query(z1, m, mid, l, r, ans);
  query(z2, mid + 1, n, l, r, ans);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  init(1, 1, n);
  int m;
  scanf("%d", &m);
  while (m--) {
    int ch;
    while (ch = getchar(), !isupper(ch))
      ;
    if (ch == 'C') {
      int x, y;
      scanf("%d%d", &x, &y);
      modify(1, 1, n, x, y);
    } else {
      int x, y;
      scanf("%d%d", &x, &y);
      int ans = 0;
      query(1, 1, n, x, y - 1, ans);
      printf("%d\n", ans);
    }
  }
  return 0;
}
