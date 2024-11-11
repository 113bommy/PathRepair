#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 7;
int n, m;
int a[MAX];
int h[MAX];
int ans[MAX];
int ind[MAX];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int l = 1, r = 0, z = 0;
  for (int i = 1; i <= m; i++) {
    int t, c;
    scanf("%d %d", &t, &c);
    h[c] = t;
    ind[c] = i;
    z = max(z, c);
  }
  for (int i = n; i > z; i--) ans[i] = a[i];
  int d = h[z];
  int max_ind = z;
  r = z;
  sort(a + 1, a + z + 1);
  ans[z] = (d == 1) ? a[r--] : a[l++];
  for (int i = z - 1; i; i--) {
    if (!ind[i] or ind[i] < max_ind)
      ans[i] = (d == 1) ? a[r--] : a[l++];
    else {
      max_ind = ind[i];
      d = h[i];
      ans[i] = (d == 1) ? a[r--] : a[l++];
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
