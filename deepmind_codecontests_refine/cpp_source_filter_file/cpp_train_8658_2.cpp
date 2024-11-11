#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, r, i, sum = 0, x = 1, mus = 0;
  cin >> n >> l >> r;
  for (i = 0; i < l; i++) {
    sum = sum + x;
    x = x * 2;
  }
  sum = sum + ((n - l) * (x / 2));
  x = 1;
  for (i = 0; i < r; i++) {
    mus = mus + x;
    x = x * 2;
  }
  mus = mus + (n - r);
  cout << mus << " " << sum;
  exit(0);
}
