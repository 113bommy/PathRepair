#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, k[10005], e, z, m, f[10005], x, p, j, w;
int main() {
  cin >> a >> b;
  for (c = 0; c < a * b; c++) {
    cin >> k[c];
  }
  for (d = 0; d < b; d++) {
    for (e = 0; e < a; e++) {
      if (k[z + e] > m) {
        m = k[z + e];
        x = e;
      }
    }
    f[x + 1]++;
    m = 0;
    z += a;
  }
  for (p = 0; p < b * 2; p++) {
    if (f[p] > w) {
      w = f[p];
      j = p;
    }
  }
  cout << j;
}
