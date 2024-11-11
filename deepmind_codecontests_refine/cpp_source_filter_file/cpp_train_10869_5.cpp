#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, r = 1000, n, c, i1, i2;
  cin >> n >> a;
  int p = a;
  for (int i = 2; i <= n; i++) {
    cin >> c;
    int d = abs(c - p);
    if (d < r) {
      r = d;
      i1 = i - 1;
      i2 = 2;
    }
    p = c;
  }
  int d = abs(a - p);
  if (d < r) {
    i1 = n;
    i2 = 1;
  }
  cout << i1 << " " << i2;
  return 0;
}
