#include <bits/stdc++.h>
using namespace std;
int a, s, d[403], f[403], g, h = -10000000, j, k, l, i, n, m;
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> d[i];
    d[n + i] = d[i];
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      for (a = 0; a <= 2 * n; a++) {
        f[a] = d[a];
      }
      sort(f + j, f + n + i);
      sort(f + i, f + j);
      k = i;
      s = 0;
      for (a = 0; a < m; a++) {
        if (n + i - 1 - s < j) break;
        if (f[k] <= f[n + i - s - 1])
          f[k] = f[n + i - 1 - s];
        else
          break;
        s++;
        if (f[k] > f[k + 1]) k++;
      }
      l = 0;
      for (a = i; a < j; a++) {
        l += f[a];
      }
      if (l > h) h = l;
    }
  }
  cout << h;
}
