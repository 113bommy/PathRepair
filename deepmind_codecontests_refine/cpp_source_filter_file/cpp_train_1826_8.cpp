#include <bits/stdc++.h>
using namespace std;
int a[101], b[101], c[101], d[101];
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int value = 1, aa = 0, bb = 0, cc = 0, dd = 0;
  for (int i = 1; i <= m; i++) {
    if (i % 2 == 0 && i <= 2 * n) {
      a[aa] = i;
      aa++;
    }
    if (i % 2 == 0 && i > 2 * n) {
      b[bb] = i;
      bb++;
    }
    if (i % 2 == 1 && i <= 2 * n) {
      c[cc] = i;
      cc++;
    }
    if (i % 2 == 1 && i > 2 * n) {
      d[dd] = i;
      dd++;
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    if (d[i] > 0) {
      cout << d[i] << " ";
    }
    if (c[i] > 0) {
      cout << c[i] << " ";
    }
    if (b[i] > 0) {
      cout << b[i] << " ";
    }
    if (a[i] > 0) {
      cout << a[i] << " ";
    }
  }
  return 0;
}
