#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  long long a[100000], min1 = 1e18;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < min1) min1 = a[i];
  }
  long long k = min1 / n;
  long long t = k * n;
  for (i = 0; i < n; i++) {
    a[i] -= t;
  }
  for (j = 0; j < 2; j++) {
    for (i = 0; i < n; i++) {
      if (a[i] - i <= 0) {
        cout << i + 1;
        return 0;
      } else
        a[i] -= n;
    }
  }
  return 0;
}
