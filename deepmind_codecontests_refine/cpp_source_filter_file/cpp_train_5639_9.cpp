#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j = 0;
  cin >> n;
  int a[n], b[n];
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    k += b[i] - a[i];
    if (k > j) j = k;
  }
  cout << j;
  return 0;
}
