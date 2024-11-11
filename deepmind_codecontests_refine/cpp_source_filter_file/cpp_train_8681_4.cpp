#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, k, x, y, m1, m2, ind_1, ind_2, cn;
  scanf("%lld", &n);
  int val_1[n], val_2[n];
  for (i = 0; i < n; i++) val_1[i] = val_2[i] = 0;
  string s[n];
  for (i = 0; i < n; i++) cin >> s[i];
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      if (s[i][j] != 'E') {
        val_1[i] += 1;
        val_2[i] += 1;
      }
    }
  cn = 0;
  for (i = 0; i < n; i++)
    if (val_1[i] == 0) {
      cn = 1;
      break;
    }
  if (cn == 1)
    for (i = 0; i < n; i++)
      if (val_2[i] == 0) {
        cn = 2;
        break;
      }
  if (cn == 2) {
    cout << -1;
    return 0;
  }
  cn = 0;
  for (i = 0; i < n; i++)
    if (val_1[i] != 0) cn += 1;
  if (cn == n) {
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) {
        if (s[i][j] == '.') {
          cout << i + 1 << ' ' << j + 1 << endl;
          break;
        }
      }
  } else {
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) {
        if (s[j][i] == '.') {
          cout << j + 1 << ' ' << i + 1 << endl;
          break;
        }
      }
  }
  return 0;
}
