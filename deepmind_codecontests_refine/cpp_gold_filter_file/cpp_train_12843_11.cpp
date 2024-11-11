#include <bits/stdc++.h>
using namespace std;
long a, b, c, d, k, l, m, n, p, pas, pas1, pas2, i;
int main() {
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a;
    pas1 = 0;
    while (a > 0) {
      if (a % 10 == 4 || a % 10 == 7) {
        pas1++;
      }
      a = a / 10;
    }
    if (pas1 <= k) pas2++;
  }
  cout << pas2;
}
