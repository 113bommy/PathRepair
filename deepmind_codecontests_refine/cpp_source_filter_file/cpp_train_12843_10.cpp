#include <bits/stdc++.h>
using namespace std;
int main() {
  long int i, n, k, a[110], m, s = 0;
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    m = 0;
    cin >> a[i];
    while (a[i] != 0) {
      int j = a[i] % 10;
      a[i] = a[i] / 10;
      if (a[i] == 4 || a[i] == 7) m++;
    }
    if (m <= k) s++;
  }
  cout << s;
  return 0;
}
