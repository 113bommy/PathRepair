#include <bits/stdc++.h>
using namespace std;
int n, m, a[300005];
int tree[300005];
int Erfen(int l, int r, int lim) {
  int now = l;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (a[mid] - a[now] <= lim)
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}
void Insert(int x, int l, int r, int pos) {
  if (pos < l || pos > r) return;
  tree[x]++;
  if (l == r) return;
  int mid = (l + r) >> 1;
  Insert(x * 2, l, mid, pos);
  Insert(x * 2 + 1, mid + 1, r, pos);
}
int Query(int x, int l, int r, int L, int R) {
  if (r < L || R < l) return 0;
  if (L <= l && r <= R) return tree[x];
  int mid = l + r >> 1;
  return Query(x * 2, l, mid, L, R) + Query(x * 2 + 1, mid + 1, r, L, R);
}
bool Check(int lim) {
  if (a[n] - a[n - m + 1] > lim) return 0;
  memset(tree, 0, sizeof(tree));
  Insert(1, 1, n + 1, n - m + 1);
  Insert(1, 1, n + 1, n + 1);
  for (int i = n - m; i; i--) {
    int pos = Erfen(i, n, lim);
    if (a[pos] - a[i] > lim) continue;
    if (Query(1, 1, n + 1, i + m, pos + 1)) {
      Insert(1, 1, n + 1, i);
    }
  }
  return Query(1, 1, n + 1, 1, 1);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int l = 0, r = a[n] - a[1];
  while (l < r) {
    int mid = (l + r) >> 1;
    if (Check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d", l);
  return 0;
}
