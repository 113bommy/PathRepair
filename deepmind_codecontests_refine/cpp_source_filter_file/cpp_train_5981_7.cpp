#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[1000000], m = 0, k = 0, l = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) m += a[i];
  m /= n;
  for (int i = 0; i < n; i++) {
    k += m - a[i];
    l += fabs(k);
  }
  cout << l;
  return 0;
}
