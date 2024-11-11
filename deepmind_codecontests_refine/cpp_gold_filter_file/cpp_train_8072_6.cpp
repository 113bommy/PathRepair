#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int l = 0;
  long long int r = n - 1;
  long long int countl = 0, countr = 0;
  long long int suml = 0, sumr = 0;
  while (l <= r) {
    if (suml <= sumr) {
      countl++;
      suml += a[l];
      l++;
    } else {
      countr++;
      sumr += a[r];
      r--;
    }
  }
  cout << countl << " " << countr << "\n";
}
