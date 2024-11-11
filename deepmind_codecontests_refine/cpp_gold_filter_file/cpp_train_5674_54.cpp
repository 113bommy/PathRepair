#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, n, m, x;
  cin >> n >> m;
  long long int b[n], c[n];
  for (i = 0; i < n; i++) c[i] = 0;
  for (i = 0; i < m; i++) {
    x = 0;
    for (j = 0; j < n; j++) {
      cin >> b[j];
      if (b[j] > x) x = b[j];
    }
    for (j = 0; j < n; j++) {
      if (b[j] == x) {
        c[j]++;
        break;
      }
    }
  }
  x = 0;
  for (i = 0; i < n; i++) {
    if (c[i] > x) x = c[i];
  }
  for (i = 0; i < n; i++) {
    if (c[i] == x) {
      cout << i + 1;
      break;
    }
  }
  return 0;
}
