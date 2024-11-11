#include <bits/stdc++.h>
using namespace std;
const int Maxn = 101000;
int tree[Maxn * 4];
int f[Maxn];
int N;
int h[Maxn];
void build(int j, int l, int r) {
  if (l == r) {
    tree[j] = h[l];
    if (h[l - 1] < h[l]) tree[j] = min(tree[j], h[l - 1] + 1);
    if (h[l + 1] < h[l]) tree[j] = min(tree[j], h[l + 1] + 1);
    f[l] = tree[j];
    return;
  }
  int mid = (l + r) / 2;
  build(j * 2, l, mid);
  build(j * 2 + 1, mid + 1, r);
  tree[j] = min(tree[j * 2], tree[j * 2 + 1]);
}
void modify(int j, int l, int r, int x, int y) {
  if (l == r) {
    tree[j] = y;
    return;
  }
  int mid = (l + r) / 2;
  if (mid >= x)
    modify(j * 2, l, mid, x, y);
  else
    modify(j * 2 + 1, mid + 1, r, x, y);
  tree[j] = min(tree[j * 2], tree[j * 2 + 1]);
}
int getMin(int j, int l, int r) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (tree[j * 2] == tree[j])
    return getMin(j * 2, l, mid);
  else
    return getMin(j * 2 + 1, mid + 1, r);
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &h[i]);
  h[0] = h[N + 1] = 0;
  build(1, 1, N);
  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    int x = getMin(1, 1, N);
    modify(1, 1, N, x, 1999999999);
    if (x < N && f[x + 1] < 1999999999) {
      f[x + 1] = min(f[x + 1], f[x] + 1);
      modify(1, 1, N, x + 1, f[x + 1]);
    }
    if (x > 1 && f[x - 1] < 1999999999) {
      f[x - 1] = min(f[x - 1], f[x] + 1);
      modify(1, 1, N, x - 1, f[x - 1]);
    }
    ans = f[x];
    f[x] = 1999999999;
  }
  printf("%d\n", ans);
  return 0;
}
