#include <bits/stdc++.h>
using namespace std;
int main() {
  int m = 0, e = 0, n, i, dif;
  cin >> n;
  int arr[n + 1];
  arr[0] = 0;
  for (i = 1; i <= n; i++) cin >> arr[i];
  for (i = 1; i <= n; i++) {
    dif = arr[i - 1] - arr[i];
    if (dif > 0)
      e += dif;
    else if (dif <= e)
      e += dif;
    else if (abs(dif) > e) {
      m += -dif - e;
      e = 0;
    }
  }
  cout << m;
  return 0;
}
