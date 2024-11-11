#include <bits/stdc++.h>
using namespace std;
int a, b[5100], c[5100], d[5100], e, f, g, h, i, j, k, l, m, n, t[5100];
int main() {
  cin >> n;
  for (a = 1; a <= n; a++) {
    cin >> t[a];
    if (t[a] == 1) {
      e++;
      b[e] = a;
    }
    if (t[a] == 2) {
      f++;
      c[f] = a;
    }
    if (t[a] == 3) {
      g++;
      d[g] = a;
    }
  }
  int w = min(e, f);
  w = min(w, g);
  cout << w << endl;
  for (h = 1; h <= w; h++) {
    cout << b[h] << " " << c[h] << " " << d[h] << endl;
  }
}
