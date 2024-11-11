#include <bits/stdc++.h>
int n, a[200005];
int dfs(int lef, int rig, int bit) {
  if (lef > rig) return 0;
  if (lef == rig) return 1;
  if (lef + 1 == rig) return 2;
  if (bit < 0) return 0;
  int mid = lef, t1 = 0, t2 = 0;
  while (mid <= n && (a[mid] & (1 << bit)) == 0) mid++;
  mid--;
  t1 = dfs(lef, mid, bit - 1) + int(mid < rig);
  t2 = dfs(mid + 1, rig, bit - 1) + int(lef <= mid);
  return std::max(t1, t2);
}
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  std::sort(a + 1, a + n + 1);
  printf("%d\n", n - dfs(1, n, 30));
  return 0;
}
