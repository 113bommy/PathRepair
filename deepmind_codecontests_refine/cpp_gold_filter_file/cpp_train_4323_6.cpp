#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, i, k = 0, l = 1;
  cin >> n;
  int a[n];
  if (n == 1)
    cout << 1;
  else {
    a[0] = 1;
    for (i = 2; i <= n; i++) {
      a[l] = 1;
      while (l >= 1 && a[l] == a[l - 1]) {
        a[l - 1]++;
        a[l] = 0;
        l--;
      }
      l++;
    }
    for (i = 0; i < l; i++) cout << a[i] << " ";
  }
  return 0;
}
