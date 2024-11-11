#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
int main() {
  long long x, n, i, rec = 0, j, k, m, l, d, r, e, q, p = 0;
  cin >> x;
  x = abs(x);
  if (x == 0) {
    cout << '0';
    return 0;
  }
  for (k = 1; k * (k + 1) / 2 < x; k++)
    ;
  if (((k + 1) / 2) % 2 == 0 && x % 2 == 0) {
    cout << k;
    return 0;
  }
  if (((k + 1) / 2) % 2 == 0 && x % 2 == 1) {
    while (((k + 1) / 2) % 2 == 0) k++;
    cout << k;
    return 0;
  }
  if (((k + 1) / 2) % 2 == 1 && x % 2 == 0) {
    while (((k + 1) / 2) % 2 == 1) k++;
    cout << k;
    return 0;
  }
  if (((k + 1) / 2) % 2 == 1 && x % 2 == 1) {
    cout << k;
    return 0;
  }
  return 0;
}
