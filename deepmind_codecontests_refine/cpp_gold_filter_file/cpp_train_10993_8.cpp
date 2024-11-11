#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, k = 1, m, t = 5;
  cin >> n;
  for (i = 1; i <= n; i++) {
    if (n - t <= 0)
      break;
    else
      n = n - t;
    t = 2 * t;
    k = k * 2;
  }
  m = n / k;
  if (n % k == 0) {
    if (m == 1) cout << "Sheldon";
    if (m == 2) cout << "Leonard";
    if (m == 3) cout << "Penny";
    if (m == 4) cout << "Rajesh";
    if (m == 5) cout << "Howard";
  } else {
    if (m + 1 == 1) cout << "Sheldon";
    if (m + 1 == 2) cout << "Leonard";
    if (m + 1 == 3) cout << "Penny";
    if (m + 1 == 4) cout << "Rajesh";
    if (m + 1 == 5) cout << "Howard";
  }
}
