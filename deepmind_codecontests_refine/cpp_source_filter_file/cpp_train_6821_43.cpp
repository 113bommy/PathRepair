#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  int r[n][2];
  int c[m][2];
  memset(r, 0, sizeof(r));
  memset(c, 0, sizeof(c));
  int cu = 1;
  while (k--) {
    int x, q, z;
    cin >> x >> q >> z;
    q--;
    if (x == 1) {
      r[q][1] = z;
      r[q][2] = cu;
    } else {
      c[q][1] = z;
      c[q][2] = cu;
    }
    cu++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (r[i][2] > c[j][2]) {
        cout << r[i][1];
      } else {
        cout << c[j][1];
      }
      cout << " ";
    }
    cout << "\n";
  }
  return 0;
}
