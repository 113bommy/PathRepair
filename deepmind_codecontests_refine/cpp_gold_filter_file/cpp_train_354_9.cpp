#include <bits/stdc++.h>
using namespace std;
const int N = 21, M = 1 << 20 + 1;
int n, mm, a[M];
long long inv[N], inv2[N];
void build(int h, int l, int r) {
  if (h == 0) return;
  int m = (l + r) / 2;
  build(h - 1, l, m);
  build(h - 1, m + 1, r);
  vector<int> v;
  int i = l, j = m + 1, k, c;
  while (i <= m && j <= r) {
    if (a[i] < a[j]) {
      inv2[h] += (long long)(r - j + 1);
      v.push_back(a[i++]);
    } else if (a[j] < a[i]) {
      inv[h] += (long long)(m - i + 1);
      v.push_back(a[j++]);
    } else {
      k = i, c = a[i];
      while (k <= m && a[k] == c) k++;
      if (k <= r) inv[h] += (long long)(m - k + 1);
      v.push_back(a[j++]);
    }
  }
  while (i <= m) v.push_back(a[i++]);
  while (j <= r) v.push_back(a[j++]);
  for (int i = l, j = 0; i <= r; i++, j++) a[i] = v[j];
}
int main() {
  std::ios::sync_with_stdio(false);
  scanf("%d", &n);
  int m = 1 << n;
  mm = m;
  for (int i = 0; i < m; i++) scanf("%d", a + i);
  build(n, 0, m - 1);
  int q, h;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &h);
    for (int i = 0; i <= h; i++) swap(inv[i], inv2[i]);
    long long ans = 0;
    for (int i = 0; i <= n; i++) ans += inv[i];
    printf("%lld\n", ans);
  }
  return 0;
}
