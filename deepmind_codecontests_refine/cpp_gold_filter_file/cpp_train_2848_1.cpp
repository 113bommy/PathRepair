#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int a[100005];
int n, k;
void solve() {
  int i, dem, da, luu, vt;
  vt = 0;
  dem = da = 0;
  m.clear();
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i + k - 1 <= n; i++) {
    if (m[a[i + k - 1]] == 0) {
      dem++, m[a[i + k - 1]] = 1, luu = a[i + k - 1];
    }
  }
  if (dem > 1) {
    printf("-1\n");
    return;
  }
  for (i = 1; i <= n; i++) {
    if (a[i] != luu) {
      vt = i;
    }
  }
  printf("%d\n", vt);
}
int main() {
  while (scanf("%d%d", &n, &k) > 0) solve();
  return 0;
}
