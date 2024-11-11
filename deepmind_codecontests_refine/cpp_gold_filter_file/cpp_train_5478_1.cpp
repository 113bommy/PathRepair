#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, w, e, r, t, y;
  cin >> q;
  y = 0;
  r = 0;
  int v[q];
  int z[q];
  int x[q];
  for (int i = 0; i < q; i++) {
    cin >> z[i];
    x[i] = 0;
    v[i] = z[i];
  }
  if (q == 2) {
    if (z[0] == z[1])
      cout << "NO";
    else
      cout << "YES\n" << z[0] << " " << z[1];
  } else {
    for (int j = 1; j < q; j++) {
      if (z[0] != z[j])
        w = j;
      else
        y++;
    }
    for (int j = 0; j < q; j++) {
      if (z[w] == z[j] && j != w) r++;
    }
    if (y == r && y + r + 2 == q)
      cout << "YES\n" << z[0] << " " << z[w];
    else
      cout << "NO";
  }
}
