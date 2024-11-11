#include <bits/stdc++.h>
using namespace std;
int a[16], f[16][65536], g[16][65536], h[65536], p[15], T, n;
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
      int j;
      for (j = 0; j < (1 << n); j++)
        if (__builtin_popcount(j) == i) {
          x.clear();
          y.clear();
          x.push_back(0);
          for (int k = 0; k < n; k++)
            if (j & (1 << k))
              y.push_back(k);
            else
              x.push_back(k);
          for (int k = 0; k < (1 << y.size()); k++) {
            h[k] = 0;
            for (int l = 0; l < y.size(); l++)
              if (k & (1 << l)) h[k] += a[y[l]];
          }
          for (int k = 0; k < (1 << y.size()); k++) f[0][k] = 23333333;
          f[0][0] = 0;
          for (int k = 1; k < x.size(); k++)
            for (int l = 0; l < (1 << y.size()); l++) {
              f[k][l] = 23333333;
              if (a[x[k]] > f[k - 1][l]) {
                f[k][l] = a[x[k]];
                g[k][l] = 0;
              } else
                for (int o = l; o; o = (o - 1) & l)
                  if (a[x[k]] + h[o] > f[k - 1][l ^ o] &&
                      a[x[k]] + h[o] < f[k][l]) {
                    f[k][l] = a[x[k]] + h[o];
                    g[k][l] = o;
                  }
            }
          if (f[x.size() - 1][(1 << y.size()) - 1] != 23333333) break;
        }
      if (j < (1 << n)) {
        cout << i << endl;
        break;
      }
    }
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = x.size() - 1, j = (1 << y.size()) - 1; i > 0; i--) {
      for (int k = 0; k < y.size(); k++)
        if (g[i][j] & (1 << k)) {
          cout << p[y[k]] + 1 << ' ' << p[x[i]] + 1 << endl;
          for (int l = y[k]; l < n; l++) p[l]--;
        }
      j ^= g[i][j];
    }
  }
}
