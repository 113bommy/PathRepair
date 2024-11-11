#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, z = 0, p, c = 0, m, h;
  cin >> n;
  int v[100006];
  int vv[100006];
  for (i = 0; i < n; i++) {
    v[i] = -1;
    vv[i] = -1;
  }
  for (i = 0; i < n; i++) {
    cin >> m;
    v[m] = v[m] + 1;
    cin >> h;
    vv[h] = vv[h] + 1;
  }
  for (i = 0; i < n; i++) {
    if (v[i] != -1) {
      c++;
    }
    if (vv[i] != -1) {
      z++;
    }
  }
  cout << min(z, c);
}
