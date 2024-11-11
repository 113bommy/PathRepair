#include <bits/stdc++.h>
using namespace std;
int main() {
  int c[100], i, j, n, m, l;
  cin >> n;
  for (i = 0; i < n; i++) cin >> c[i];
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++) {
      if (c[i] < c[j]) {
        m = c[j] - c[i];
        c[j] -= m;
        c[i] += m;
      }
    }
  for (i = n - 1; i >= 0; i--) cout << c[i];
}
