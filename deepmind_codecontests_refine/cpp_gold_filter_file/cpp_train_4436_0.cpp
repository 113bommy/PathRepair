#include <bits/stdc++.h>
const int N = 107;
using namespace std;
struct data {
  int u, v;
} f[N * N * N];
int n, m, a[N][N], spt;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  if (n < m) {
    for (int i = 1; i <= n; i++) {
      int tmp = *min_element(a[i] + 1, a[i] + m + 1);
      if (tmp == 0) continue;
      for (int j = 1; j <= m; j++) a[i][j] -= tmp;
      for (int j = 1; j <= tmp; j++) {
        spt++;
        f[spt].u = 1;
        f[spt].v = i;
      }
    }
    for (int i = 1; i <= m; i++) {
      int tmp = 1e9 + 7;
      for (int j = 1; j <= n; j++) tmp = min(tmp, a[j][i]);
      if (tmp == 0) continue;
      for (int j = 1; j <= n; j++) a[j][i] -= tmp;
      for (int j = 1; j <= tmp; j++) {
        spt++;
        f[spt].u = 2;
        f[spt].v = i;
      }
    }
  } else {
    for (int i = 1; i <= m; i++) {
      int tmp = 1e9 + 7;
      for (int j = 1; j <= n; j++) tmp = min(tmp, a[j][i]);
      if (tmp == 0) continue;
      for (int j = 1; j <= n; j++) a[j][i] -= tmp;
      for (int j = 1; j <= tmp; j++) {
        spt++;
        f[spt].u = 2;
        f[spt].v = i;
      }
    }
    for (int i = 1; i <= n; i++) {
      int tmp = *min_element(a[i] + 1, a[i] + m + 1);
      if (tmp == 0) continue;
      for (int j = 1; j <= m; j++) a[i][j] -= tmp;
      for (int j = 1; j <= tmp; j++) {
        spt++;
        f[spt].u = 1;
        f[spt].v = i;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int tmp = *max_element(a[i] + 1, a[i] + m + 1);
    if (tmp >= 1) {
      cout << -1;
      return 0;
    }
  }
  cout << spt << "\n";
  for (int i = 1; i <= spt; i++) {
    (f[i].u == 1) ? cout << "row " << f[i].v << "\n"
                  : cout << "col " << f[i].v << "\n";
  }
  return 0;
}
