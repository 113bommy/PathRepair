#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[100];
  long long n, k = 0, l, i;
  cin >> n;
  for (i = 1; i <= 7; i++) cin >> a[i];
  while (n > 0) {
    for (i = 1; i <= n; i++) {
      if (n >= a[i])
        n -= a[i];
      else {
        k = i;
        break;
      }
      if (n == 0) {
        k = i;
        break;
      }
    }
    if (k != 0) break;
  }
  cout << k << endl;
  return 0;
}
