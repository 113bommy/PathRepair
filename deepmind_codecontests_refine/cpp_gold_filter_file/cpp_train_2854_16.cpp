#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  if (n == 1 || n == 2) {
    cout << n;
    return 0;
  }
  int max = -1, count = 2;
  for (i = 2; i < n; i++) {
    if (a[i] == (a[i - 1] + a[i - 2])) {
      count += 1;
      if (i == n - 1)
        if (count > max) max = count;
    } else {
      if (count > max) max = count;
      count = 2;
    }
  }
  cout << max << "\n";
  return 0;
}
