#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, d;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> j >> k;
    if (i == 1)
      d = j;
    else {
      while (d >= j) j += k;
      d = j;
    }
  }
  cout << d;
  return 0;
}
