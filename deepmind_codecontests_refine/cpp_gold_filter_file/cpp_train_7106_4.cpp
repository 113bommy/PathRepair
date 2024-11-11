#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int j = 0; j < m; j++) cin >> b[j];
  int count, mn = 100000;
  for (int i = 0; i <= pow(2, 9) - 1; i++) {
    count = 0;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (((a[j] & b[k]) | i) == i) {
          if (count != (j + 1)) count++;
        }
      }
      if (count != (j + 1)) break;
    }
    if (count == n) mn = min(mn, i);
  }
  cout << mn;
  return 0;
}
