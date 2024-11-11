#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[11], b[11];
  cin >> n >> m;
  int i = 0, j = 0;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < m; i++) cin >> b[i];
  int k = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        cout << a[i] << " ";
        b[j] = -1;
      }
    }
  }
  return 0;
}
