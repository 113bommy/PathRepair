#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[1000], b[1000], m;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int cl = 0, ck = 0;
      int p = a[i] + b[j];
      for (int k = 0; k < n; k++)
        if (p == a[k]) {
          cl = 1;
          break;
        }
      for (int k = 0; k < m; k++)
        if (p == b[k]) {
          ck = 1;
          break;
        }
      if (cl == 0 && ck == 0) {
        cout << a[i] << " " << b[j] << '\n';
        return 0;
      }
    }
  }
}
