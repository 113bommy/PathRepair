#include <bits/stdc++.h>
using namespace std;
int f[1000020 * 4];
void insert(int x, int l, int r, int p, int v) {
  int m;
  if (l > p || r < p) return;
  if (l == r) {
    f[x] += v;
    return;
  }
  m = (l + r) >> 1;
  insert(x << 1, l, m, p, v);
  insert(x << 1 | 1, m + 1, r, p, v);
  f[x] = f[x << 1] + f[x << 1 | 1];
  return;
}
int kth(int x, int l, int r, int k) {
  int m;
  if (l == r) return l;
  m = (l + r) >> 1;
  if (f[x << 1] >= k) return kth(x << 1, l, m, k);
  return kth(x << 1 | 1, m + 1, r, x - f[x << 1]);
}
int main(void) {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    insert(1, 1, n, x, 1);
  }
  while (q--) {
    int k;
    scanf("%d", &k);
    if (k < 0)
      insert(1, 1, n, kth(1, 1, n, -k), -1);
    else
      insert(1, 1, n, k, 1);
  }
  if (!f[1])
    printf("0\n");
  else
    printf("%d\n", kth(1, 1, n, 1));
  return 0;
}
