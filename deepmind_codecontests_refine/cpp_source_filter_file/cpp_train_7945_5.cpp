#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, c1 = 0, c2 = 0, c3 = 0, c4 = 0, k = 0;
  cin >> n;
  int a[n], b[n];
  for (i = 0; i <= n - 1; i++) cin >> a[i] >> b[i];
  for (i = 0; i <= n - 1; i++) {
    for (j = 0; j <= n - 1; j++) {
      if (i == j) continue;
      if (a[j] > a[i] && b[j] == b[i]) c1++;
      if (a[j] < a[i] && b[j] == b[i]) c2++;
      if (a[j] == a[i] && b[j] < b[i]) c3++;
      if (a[j] == a[i] && b[j] > b[i]) c4++;
    }
    if (c1 > 0 && c2 > 0 && c3 > 0 && c3 > 0) k++;
    c1 = 0;
    c2 = 0;
    c3 = 0;
    c4 = 0;
  }
  cout << k << endl;
  return 0;
}
