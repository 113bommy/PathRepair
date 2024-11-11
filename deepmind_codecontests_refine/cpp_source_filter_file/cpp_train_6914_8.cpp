#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[310], l = 0, k = 0, d = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    l += a[i];
  }
  while (l > 0) {
    if (a[k] > 0) {
      a[k]--;
      cout << "P";
      l--;
    }
    if (d > 0)
      cout << "R";
    else
      cout << "L";
    k += d;
    if (k == n) d = -1;
    if (k < 0) d = 1;
  }
}
