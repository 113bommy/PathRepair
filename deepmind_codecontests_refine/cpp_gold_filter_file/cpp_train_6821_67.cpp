#include <bits/stdc++.h>
const double PI = acos(-1.0);
using namespace std;
int a[5005][5005];
int r[5005], c[5005], x[5005], y[5005];
int main() {
  ios ::sync_with_stdio(false);
  int n, m, k, i, j;
  while (cin >> n >> m >> k) {
    int p, q, w;
    for (i = 1; i <= k; i++) {
      cin >> p >> q >> w;
      if (p == 1) {
        r[q] = w;
        x[q] = i;
      } else {
        c[q] = w;
        y[q] = i;
      }
    }
    for (i = 1; i <= n; ++i) {
      for (j = 1; j <= m; ++j) {
        if (x[i] > y[j])
          printf("%d", r[i]);
        else if (x[i] < y[j])
          printf("%d", c[j]);
        else
          printf("0");
        if (j != m) cout << " ";
      }
      cout << endl;
    }
  }
}
