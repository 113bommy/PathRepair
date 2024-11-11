#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int min = INT_MAX, max = INT_MIN;
  int l = n, r = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
      l = i;
    }
    if (a[i] <= min) {
      min = a[i];
      r = i;
    }
  }
  if (l < r)
    cout << l + (n - r - 1) << endl;
  else
    cout << l + (n - r - 2) << endl;
  return 0;
}
