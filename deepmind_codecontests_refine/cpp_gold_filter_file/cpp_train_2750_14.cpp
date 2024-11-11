#include <bits/stdc++.h>
using namespace std;
int a[1010], n, i, tz, j, k, maximum = 1, piramide;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (j = 1; j < n - 1; j++)
    for (i = 1; i < n; i++)
      if (a[i] > a[i + 1]) {
        tz = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tz;
      }
  k = 1;
  for (i = 1; i <= n; i++)
    if (a[i] != a[i + 1]) {
      k = 1;
      piramide++;
    } else {
      k++;
      if (maximum < k) maximum = k;
    }
  cout << maximum << " " << piramide;
  return 0;
}
