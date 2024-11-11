#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, c = 0, l = 0;
  cin >> n;
  int a[] = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};
  for (i = 0; i < 9; i++) {
    if (a[i] <= n) {
      c += (a[i] - l) * (i + 1);
      l += a[i];
    } else
      break;
  }
  if (n < 9) c += n;
  if (n > 9) {
    n = (n - a[i - 1]) * (i + 1);
    c += n;
  }
  cout << c;
  return 0;
}
