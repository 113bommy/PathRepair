#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int *a = new int[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int imin = 0;
  int kmin = 10000000;
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = 0; j < n; j++)
      if (a[i] - a[j] != k * (i - j)) cur++;
    if (cur < kmin && k * i < a[i]) {
      imin = i;
      kmin = cur;
    }
  }
  cout << kmin << endl;
  for (int i = 0; i < n; i++) {
    if (a[i] - a[imin] > k * (i - imin))
      cout << "- " << i + 1 << ' ' << a[i] - a[imin] - k * (i - imin) << endl;
    else if (a[i] - a[imin] < k * (i - imin))
      cout << "+ " << i + 1 << ' ' << k * (i - imin) - (a[i] - a[imin]) << endl;
  }
  return 0;
}
