#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int min = INT_MAX;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < min) min = a[i];
  }
  int k = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] % min != 0) {
      k = 1;
      break;
    }
  }
  if (k == 1)
    cout << -1;
  else
    cout << min;
}
