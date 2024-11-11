#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, j, l, m;
  int a[4002], ctr = 0, ctr1 = 0;
  cin >> n >> k;
  a[n] = 1;
  for (int i = 0; i < k; i++) {
    cin >> j;
    if (j == 2) {
      cin >> l;
      a[l] = 1;
      ctr++;
    } else {
      cin >> l >> m;
      a[l] = 1;
      a[m] = 1;
      ctr += 2;
    }
  }
  int i = 1;
  while (i < n) {
    if (a[i] == 0) {
      if (i < n - 1 && a[i + 1] == 0) {
        a[i] = 1;
        a[i + 1] = 1;
        ctr1++;
        i += 2;
      } else {
        a[i] = 1;
        ctr1++;
        i++;
      }
    } else
      i++;
  }
  cout << ctr1 << " " << n - ctr - 1 << endl;
  return 0;
}
