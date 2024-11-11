#include <bits/stdc++.h>
using namespace std;
int n, m, ret;
int a[205], aa[205], b[205];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  ret = a[0];
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
      int x = 0, y = 0, s = 0;
      for (int k = 0; k < n; k++) {
        if (k >= i && k <= j)
          aa[x++] = a[k], s += a[k];
        else
          b[y++] = a[k];
      }
      sort(aa, aa + x);
      sort(b, b + y);
      reverse(b, b + y);
      for (int k = 0; k < m; k++) {
        if (k >= x || k >= y) break;
        if (b[k] < aa[k]) break;
        s += b[k] - aa[k];
      }
      ret = max(ret, s);
    }
  cout << ret;
  return 0;
}
