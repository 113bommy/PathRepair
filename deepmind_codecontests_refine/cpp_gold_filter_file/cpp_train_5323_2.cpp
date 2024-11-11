#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int test, n, i, j, k, x, y, t, a, b;
  cin >> n;
  x = n / 7;
  for (i = x; i >= 0; i--) {
    k = i * 7;
    k = n - k;
    a = k / 4;
    b = i;
    if (k % 4 == 0) break;
  }
  if (((a * 4) + (b * 7)) == n) {
    for (i = 0; i < a; i++) cout << 4;
    for (i = 0; i < b; i++) cout << 7;
  } else
    cout << -1;
}
